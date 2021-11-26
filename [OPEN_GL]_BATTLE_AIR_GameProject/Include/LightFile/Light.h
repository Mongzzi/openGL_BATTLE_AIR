#pragma once
#include "../HeaderFile/Game.h"


class CLight
{

public:
	CLight();
	~CLight();

private:
	glm::vec3 m_LightPos;
	glm::vec3 m_LightColor;
	glm::vec3 m_ViewPos;

	
public:
	void UpdateViewPos(glm::vec3 CameraPos);



public:

	bool Init();
	void Input(float fDeltaTime);					// * �Է�
	int Update(float fDeltaTime);					// * ������Ʈ
	int LateUpdate(float fDeltaTime);				// * ������Ʈ ��ó��
	void Collision(float fDeltaTime);				// * �浹
	void Render(float fDeltaTime);					// * ���

};

