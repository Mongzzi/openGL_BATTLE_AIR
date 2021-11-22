#pragma once

#include "Game.h"

class CCore
{

private:
	CCore();
	~CCore();

// =====================================================
	// �̱��� ���� 
private:
	static CCore* m_pInst;
public:

	// �̱��� ��ü�� �����ϰ� �����Ǿ��ִٸ� 
	// �� ���� ��ü�� ��ȯ�ϴ� �Լ� �Դϴ�.
	static CCore* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CCore;
		return m_pInst;
	}

	// �̱��� ��ü�� delete �ϴ� �Լ� �Դϴ�. 
	static void DestroyInst()
	{
		if (m_pInst != nullptr)
			delete m_pInst;
		m_pInst = nullptr;

	}
// =====================================================

	// ���߿��� �Ʒ� ��ũ�η� �̱����� ������ �̴ϴ�. 
	// ���ݵ� ���� �����ε� �ϴ� �ľ��ϱ� ���ϰ� �̷��� �س����~
//public:
//	DECLARE_SINGLE(CCore);

// =====================================================


public:
	bool Init(int argc, char** argv);
	void Run();

	void MyProgramInit();
	void MyDataDelete();

public:
	void Logic();

	void Input(float fDeltaTime);					// * �Է�
	int Update(float fDeltaTime);					// * ������Ʈ
	int LateUpdate(float fDeltaTime);				// * ������Ʈ ��ó��
	void Collision(float fDeltaTime);				// * �浹
	void Render(float fDeltaTime);					// * ���


public:
	GLvoid MyReshape(int width, int height);
	GLvoid MyKeyboard(unsigned char key, int x, int y);
	GLvoid MyMouse(int button, int state, int x, int y);
	GLvoid MyDrawScene();
	GLvoid MyTimer(GLint value);


};

