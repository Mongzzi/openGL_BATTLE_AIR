#pragma once
#include "../../HeaderFile/Game.h"


// ** ** ** ** ** ** **** ** ** ** ** ** **** ** ** ** ** ** **** ** ** ** ** ** **** ** ** ** ** ** **** ** ** ** ** ** **
// ** ** A X I S ** ** ** ** A X I S ** ** ** ** A X I S ** ** ** ** A X I S ** ** ** ** A X I S ** ** ** ** A X I S ** ** 
// ** ** ** ** ** ** **** ** ** ** ** ** **** ** ** ** ** ** **** ** ** ** ** ** **** ** ** ** ** ** **** ** ** ** ** ** **

class CAxis
{
public:
	CAxis();
	~CAxis();

private:
	GLuint		m_VAO;
	GLuint		m_VBO[2];

private:
	glm::vec3 m_Position[6];
	glm::vec3 m_Normal[6];
	glm::vec3 m_Colors[6];
	GLfloat	  m_Size = 1.0f;

private:
	// ��� ���� 
	glm::mat4 m_Translate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Rotate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Scale_Mat = glm::mat4(1.0f);
	// ������ �� ����� ����
	glm::mat4 m_ModelMatrix_Result = glm::mat4(1.0f);



public:
	// ** ��� ������Ʈ �Լ� ** 
	void Update_TranslateForm(GLfloat dx = 0.0f, GLfloat dy = 0.0f, GLfloat dz = 0.0f);
	void Update_RotateForm(GLfloat Time, GLfloat Axis_x = 0.0f, GLfloat Axis_y = 0.0f, GLfloat Axis_z = 1.0f);
	void Update_ScaleForm(GLfloat sx = 1.0f, GLfloat sy = 1.0f, GLfloat sz = 1.0f);
	// ** ��� ���� �Լ� ** 
	void Update_ModelTransform(float fDeltaTime);


public:
	void InitBuffer();



public:
	void Init(GLfloat pivot = 0.0f);

	void Input(float fDeltaTime);					// * �Է�
	int Update(float fDeltaTime);					// * ������Ʈ
	int LateUpdate(float fDeltaTime);				// * ������Ʈ ��ó��
	void Collision(float fDeltaTime);				// * �浹
	void Render(float fDeltaTime);					// * ���


};