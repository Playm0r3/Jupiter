//
// Created by Warren on 10/10/2026.
//

#include "fbxsdk.h"

#include "rendering/interface/MeshLoader.h"

namespace jupiter::rendering
{

    void MeshLoader::createMeshLoader()
    {
        manager = FbxManager::Create();
        settings = FbxIOSettings::Create(manager, IOSROOT);
        manager->SetIOSettings(settings);
        importer = FbxImporter::Create(manager, "");
    }

    void MeshLoader::destroyMeshLoader()
    {
        manager->Destroy();
    }

    std::vector<MeshData> MeshLoader::loadMesh(const std::filesystem::path& path)
    {
        std::vector<MeshData> result{};

        if (!importer->Initialize(path.string().c_str(), -1, manager->GetIOSettings()))
            return result;

        FbxScene* scene = FbxScene::Create(manager, "");
        importer->Import(scene);

        FbxGeometryConverter converter{manager};
        converter.Triangulate(scene, true);

        processNode(scene->GetRootNode(), result);

        return result;
    }

    void MeshLoader::processNode(FbxNode* node, std::vector<MeshData>& out)
    {
        if (node == nullptr) return;

        if (FbxMesh* mesh = node->GetMesh())
        {
            MeshData data;
            processMesh(mesh, data);
            out.push_back(data);
        }

        for (int i = 0 ; i < node->GetChildCount(); i++)
            processNode(node->GetChild(i), out);
    }

    void MeshLoader::processMesh(FbxMesh* mesh, MeshData& out)
    {
        if (mesh->GetElementNormalCount() == 0)
            mesh->GenerateNormals(true, true);

        FbxStringList uvSetNames;
        mesh->GetUVSetNames(uvSetNames);
        const char* uvSet = uvSetNames.GetCount() > 0 ? uvSetNames.GetStringAt(0) : nullptr;

        FbxVector4* controlPoints = mesh->GetControlPoints();
        const int polygonCount = mesh->GetPolygonCount();

        out.vertices.reserve(polygonCount * 3);
        out.indices.reserve(polygonCount * 3);

        for (int p = 0; p < polygonCount; ++p)
        {
            for (int v = 0; v < 3; ++v)
            {
                const int cpIndex = mesh->GetPolygonVertex(p, v);
                const FbxVector4& pos = controlPoints[cpIndex];

                FbxVector4 normal(0, 0, 0, 0);
                mesh->GetPolygonVertexNormal(p, v, normal);

                FbxVector2 uv(0, 0);
                bool unmapped = false;
                if (uvSet)
                    mesh->GetPolygonVertexUV(p, v, uvSet, uv, unmapped);

                Vertex vertex{};
                vertex.position[0] = static_cast<float>(pos[0]);
                vertex.position[1] = static_cast<float>(pos[1]);
                vertex.position[2] = static_cast<float>(pos[2]);

                vertex.normal[0] = static_cast<float>(normal[0]);
                vertex.normal[1] = static_cast<float>(normal[1]);
                vertex.normal[2] = static_cast<float>(normal[2]);

                vertex.texcoord[0] = static_cast<float>(uv[0]);
                vertex.texcoord[1] = 1.0f - static_cast<float>(uv[1]); // flip V si API type Vulkan/DX

                out.vertices.push_back(vertex);
                out.indices.push_back(static_cast<uint32_t>(out.vertices.size() - 1));
            }
        }
    }
}
