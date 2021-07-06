#include "DXUT.h"
#include "Input.h"

void Input::Start()
{
	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyOld, 0, sizeof(m_KeyOld));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	SetKeyboardState(m_KeyCur);
}

int Input::Update()
{
	int i = 0;

	memcpy(m_KeyOld, m_KeyCur, sizeof(m_KeyOld));

	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	GetKeyboardState(m_KeyCur);


	for (i = 0; i < 256; ++i)
	{
		BYTE	vKey = m_KeyCur[i] & 0x80;	// 현재의 키보드 상태를 읽어온다.
		m_KeyCur[i] = (vKey) ? 1 : 0;		// 키보드 상태를 0과 1로 정한다.

		INT nOld = m_KeyOld[i];
		INT nCur = m_KeyCur[i];

		if (0 == nOld && 1 == nCur)	m_KeyMap[i] = EInputState::EINPUT_DOWN;	// Down
		else if (1 == nOld && 0 == nCur)	m_KeyMap[i] = EInputState::EINPUT_UP;	// Up
		else if (1 == nOld && 1 == nCur)	m_KeyMap[i] = EInputState::EINPUT_PRESS;	// Press
		else				m_KeyMap[i] = EInputState::EINPUT_NONE;	// NONE
	}

	return 0;
}

bool Input::KeyDown(int nKey)
{
	return (m_KeyMap[nKey] == EInputState::EINPUT_DOWN);
}

bool Input::KeyUp(int nKey)
{
	return (m_KeyMap[nKey] == EInputState::EINPUT_UP);
}

bool Input::KeyPress(int nKey)
{
	return (m_KeyMap[nKey] == EInputState::EINPUT_PRESS);
}

bool Input::GetMouse(MOUSE mouse)
{
	return mouseState[(int)mouse];
}

void Input::SetMouse(MOUSE mouse, int n)
{
	mouseState[(int)mouse] = n;
}
