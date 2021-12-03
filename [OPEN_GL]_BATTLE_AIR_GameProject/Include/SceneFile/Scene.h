#pragma once

#include "../HeaderFile/Game.h"



class CScene
{
private:

	CScene();
	~CScene();

private:
	friend class CSceneManager;


	//private:
		/*
		1. ���� ����
		2. �÷��̾� ����
		3. ���� ���� ����
		*/

private:
	// ( false : ȭ�� ��Ȱ��ȭ , true : ȭ�� Ȱ��ȭ )
	// ȭ�鿡 ���� Ȱ��ȭ ���� �Դϴ�. 
	GLboolean m_bEnable = false;

private:
	class CCamera*	m_Camera;
	class CLight*	m_Light;
	class CAxis*	m_Axis;


// **************************************
// Test For Load OBJ File Render !! 
// **************************************
private:
	class CAirplane* m_Airplane;
	class CMonster* m_Monster;
	class CBackground* m_Background;
	
	
	class CFloor* m_Floor[4]; // Floor �� 4�� �����ϰ� �� (1~4)��и鿡 ��ġ 
	class CFloor* m_Floor_test;
	class CTriangle* m_triangle;



public:
	bool GetEnable()
	{
		return m_bEnable;
	}
	void SetEnable(bool enable)
	{
		m_bEnable = enable;
	}

public:
	void UpdateProjectionMat();
	void UpdateOrthoMat();


public:

	bool Init();

	void Input(float fDeltaTime);					// * �Է�
	int Update(float fDeltaTime);					// * ������Ʈ
	int LateUpdate(float fDeltaTime);				// * ������Ʈ ��ó��
	void Collision(float fDeltaTime);				// * �浹
	void Render(float fDeltaTime);					// * ���


};

