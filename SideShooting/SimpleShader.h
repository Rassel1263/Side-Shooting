#pragma once

class SimpleShader
{
private:
	LPD3DXEFFECT shader;
public:
	SimpleShader();
	virtual ~SimpleShader();

public:
	HRESULT Prepare();
	HRESULT Begin();
	HRESULT End();

	HRESULT SetTexture(const Texture* texture);
	HRESULT SetGlowValue(float value);
	HRESULT SetColorValue(D3DXVECTOR4 color);

	void Render(SimpleShader* shaderManager, const Texture* texture, Sprite& sprite, RenderInfo& ri, D3DXVECTOR4 color, float timer);
};

