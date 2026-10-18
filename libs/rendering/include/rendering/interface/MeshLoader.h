//
// Created by Warren on 10/10/2026.
//

#ifndef JUPITER_MESHLOADER_H
#define JUPITER_MESHLOADER_H

#include <filesystem>
#include <fbxsdk.h>

namespace jupiter::rendering
{

    struct Vertex
    {
        float position[3];
        float normal[3];
        float texcoord[2];
    };

    struct MeshData
    {
        std::vector<Vertex> vertices;
        std::vector<uint32_t> indices;
    };

    class MeshLoader
    {

    public:

        MeshLoader() = default;
        virtual ~MeshLoader() = default;

        virtual void createMeshLoader();
        virtual void destroyMeshLoader();

        virtual std::vector<MeshData> loadMesh(const std::filesystem::path& paht);

    private:

        FbxManager* manager;
        FbxIOSettings* settings;
        FbxImporter* importer;

        void processNode(FbxNode* scene, std::vector<MeshData>& out);
        void processMesh(FbxMesh* mesh, MeshData& out);

    };
}

#endif //JUPITER_MESHLOADER_H
