#pragma once

#include "../HeaderFile/Game.h"

class CCamera
{

public:
	CCamera();
	~CCamera();


private:
	// 카메라 관련 변수
	glm::vec3		m_cameraPos = glm::vec3();	//--- 카메라 위치
	glm::vec3		m_cameraDirection = glm::vec3();	//--- 카메라 바라보는 방향
	glm::vec3		m_cameraUp = glm::vec3();  //--- 카메라 위쪽 방향

	glm::mat4 m_Translate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Rotate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Scale_Mat = glm::mat4(1.0f);

	glm::mat4 m_View = glm::mat4(1.0f);
	glm::mat4 m_View_Mat_Result = glm::mat4(1.0f);

private:
	GLfloat m_Direction_Length = 100.0f;

	

private:
	friend class CLight;


public:
	void UpdateCameraMat(float fDeltaTime);

public:
	void UpdateCameraPos(glm::vec3 AirplanePos, GLfloat airplane_Angle);
	void UpdateCameraDirection(GLfloat airplane_Angle);


public:


	bool Init(glm::vec3 CameraPos, glm::vec3 CameraDir, glm::vec3 CameraUp);

	void Input(float fDeltaTime);					// * 입력
	int Update(float fDeltaTime);					// * 업데이트
	int LateUpdate(float fDeltaTime);				// * 업데이트 후처리
	void Collision(float fDeltaTime);				// * 충돌
	void Render(float fDeltaTime);					// * 출력


};