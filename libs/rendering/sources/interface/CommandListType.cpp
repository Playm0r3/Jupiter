//
// Created by Warren on 23/09/2026.
//

#include <iostream>

#include "rendering/interface/CommandListType.h"

namespace jupiter::rendering::utils
{
    D3D12_COMMAND_LIST_TYPE getCommandListTypeFromCommandListType(CommandListType type)
    {
        switch (type)
        {
        case CommandListType::WM_COMMAND_LIST_TYPE_DIRECT:
            return D3D12_COMMAND_LIST_TYPE_DIRECT;
        default:
            std::cout << "[Soleil] Type de liste de commande non reconnu retour du type direct " << std::endl;
            return D3D12_COMMAND_LIST_TYPE_DIRECT;
        }
    }
}
