#pragma once

struct Texture
{
	LPDIRECT3DTEXTURE9 src;
	D3DXIMAGE_INFO info;
};

class TextureManager : public SingleTon<TextureManager>
{
	std::map<std::wstring, Texture*> textures;
public:
	virtual ~TextureManager();
	const Texture* GetTexture(std::wstring _filePath);
};