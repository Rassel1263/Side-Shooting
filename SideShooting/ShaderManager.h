#pragma once

class ShaderManager : public SingleTon<ShaderManager>
{
private:
	std::map<std::string, LPD3DXEFFECT> effects;

public:
	virtual ~ShaderManager();
	// Effect ����
	HRESULT CreateEffect(std::string name, LPCWSTR filename, DWORD flag);
	// Effect ������
	LPD3DXEFFECT& GetEffect(std::string name);
};

