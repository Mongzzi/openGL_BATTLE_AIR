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
	class CBuilding1* m_Building1;
	class CBuilding2* m_Building2;
	class CBuilding3* m_Building3;

	class CFloor* m_Floor[4]; // Floor �� 4�� �����ϰ� �� (1~4)��и鿡 ��ġ 
	class CFloor* m_Floor_test;
	class CTriangle* m_triangle;


	class CBullet* m_Missile;


private:

	stbi_uc* m_Airplane_Text_data = NULL;
	int m_Airplane_width = 0 , m_Airplane_height = 0;

	stbi_uc* m_Bullet_Text_data = NULL;
	int m_Bullet_width = 0, m_Bullet_height = 0;

public:
	void InitTexture_All();


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
	void Init_MainStage(SCENE_TYPE type);
	void Init_BeginStage(SCENE_TYPE type);
	void Init_EndStage(SCENE_TYPE type);


	bool Init(SCENE_TYPE type);

	void Input(float fDeltaTime);					// * �Է�
	int Update(float fDeltaTime);					// * ������Ʈ
	int LateUpdate(float fDeltaTime);				// * ������Ʈ ��ó��
	void Collision(float fDeltaTime);				// * �浹
	void Render(float fDeltaTime);					// * ���


};

