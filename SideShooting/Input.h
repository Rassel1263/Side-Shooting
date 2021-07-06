#pragma once

enum class EInputState
{
	EINPUT_NONE = 0,
	EINPUT_DOWN,
	EINPUT_UP,
	EINPUT_PRESS
};

enum class MOUSE
{
	RMOUSE,
	LMOUSE,
};

class Input : public SingleTon<Input>
{
protected:
	BYTE	m_KeyCur[256];	// ������ ����
	BYTE	m_KeyOld[256];	// ������ ����
	EInputState	m_KeyMap[256];	// Ű���� ��

	bool mouseState[2];
public:
	int wheelCount = 0;
	D3DXVECTOR2 mousePos = { 0, 0 };

	void Start();
	int	Update();

	bool	KeyDown(int nKey);
	bool	KeyUp(int nKey);
	bool	KeyPress(int nKey);
	bool    GetMouse(MOUSE mouse);
	void     SetMouse(MOUSE mouse, int n);
};
