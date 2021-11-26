#pragma once

#include "../HeaderFile/Game.h"
	// =====================================================
	// < �� ��Ģ > : ��� Ŭ������ �� 5������ �⺻ �Լ��� �����ϴ�. 
	//		
	//	 ++ Core �̿��� ' �� ü ' �� void Init()���� 
	// 	    �� 6���� �⺻ �Լ��� �������� ����մϴ�. 
	// 	    Init ������ �Ű� ������ ���������� ���� 
	// =====================================================

class CCore
{


public:
	// ��ũ�η� ���ǵ� �̱��� 
	DECLARE_SINGLE(CCore);

private:
	RESOLUTION	m_tRS; // �ػ� �Դϴ�. ( â ũ�� ���� )
	class CShaderProgramManger* m_ShaderProgramManager = nullptr;

private:
	GLfloat m_fDeltaTime = 0.0f;


public:
	bool Init(int argc, char** argv);
	void Run();

	bool MyProgramInit();
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

