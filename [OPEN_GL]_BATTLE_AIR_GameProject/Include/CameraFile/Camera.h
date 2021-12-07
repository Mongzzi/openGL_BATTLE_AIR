#pragma once

#include "../HeaderFile/Game.h"

class CCamera
{

public:
	CCamera();
	~CCamera();


private:
	// ī�޶� ���� ����
	glm::vec3		m_cameraPos = glm::vec3();	//--- ī�޶� ��ġ
	glm::vec3		m_cameraDirection = glm::vec3();	//--- ī�޶� �ٶ󺸴� ����
	glm::vec3		m_cameraUp = glm::vec3();  //--- ī�޶� ���� ����

	glm::mat4 m_Translate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Rotate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Scale_Mat = glm::mat4(1.0f);

	glm::mat4 m_View = glm::mat4(1.0f);
	glm::mat4 m_View_Mat_Result = glm::mat4(1.0f);
	

private:
	friend class CLight;


public:
	void UPdate_Pivot_From_Airplane(glm::vec3 air_pivot, float xpos, float ypos, float zpos);

	void UPdate_Dir_From_Airplane(glm::vec3 air_dir);

	void UPdate_Camera_Mat_From_Airplane(glm::mat4 trans, glm::mat4 rotate, glm::mat4 scale);

	void UpdateCameraMat(float fDeltaTime);


public:


	bool Init(glm::vec3 CameraPos, glm::vec3 CameraDir, glm::vec3 CameraUp);

	void Input(float fDeltaTime);					// * �Է�
	int Update(float fDeltaTime);					// * ������Ʈ
	int LateUpdate(float fDeltaTime);				// * ������Ʈ ��ó��
	void Collision(float fDeltaTime);				// * �浹
	void Render(float fDeltaTime);					// * ���


};