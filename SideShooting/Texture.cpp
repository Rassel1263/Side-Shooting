#include "DXUT.h"

TextureManager::~TextureManager()
{
	for (auto texture : textures)
	{
		SAFE_RELEASE(texture.second->src);
		delete texture.second;
	}
}

const Texture* TextureManager::GetTexture(std::wstring _filePath)
{
	auto tf = textures.find(_filePath);

	if (tf != textures.end())
		return tf->second;

	Texture* texture = new Texture();

	if (FAILED(D3DXCreateTextureFromFileExW(DXUTGetD3D9Device(),
		_filePath.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		0,
		0,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		&texture->info,
		0,
		&texture->src)))
	{
		delete texture;
		return nullptr;
	}


	return textures.insert({ _filePath, texture }).first->second;
}
