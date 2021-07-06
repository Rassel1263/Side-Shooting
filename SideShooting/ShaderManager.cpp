#include "DXUT.h"
#include "ShaderManager.h"

ShaderManager::~ShaderManager()
{
    for (auto& effect : effects)
    {
        effect.second->Release();
    }
}

HRESULT ShaderManager::CreateEffect(std::string name, LPCWSTR filePath, DWORD flag)
{
#ifndef _DEBUG
    flag != D3DXSHADER_DEBUG;
#endif // !define _DEBUG

    LPD3DXBUFFER pError; // CreateEffect �������� ��
    LPD3DXEFFECT pEffect; // ���̴� ���

    if (SUCCEEDED(D3DXCreateEffectFromFile(DXUTGetD3D9Device(), filePath, NULL, NULL, flag,
        NULL, &pEffect, &pError)))
    {
        auto founded = effects.find(name);

        if (founded != effects.end())
        {
            if (founded->second)
            {
                SAFE_RELEASE(founded->second);
            }
            effects.erase(name);
        }
        effects.insert(std::make_pair(name, pEffect));

        return S_OK;
    }
    else
    {
        if (pError)
        {
            std::cout << (char*)pError->GetBufferPointer() << std::endl;
            pError->Release();

            return E_FAIL;
        }
    }


    return S_OK;
}

LPD3DXEFFECT& ShaderManager::GetEffect(std::string name)
{
    return effects[name];
}