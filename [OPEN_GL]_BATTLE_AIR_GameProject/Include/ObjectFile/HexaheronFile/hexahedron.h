#pragma once
#include "../../HeaderFile/Game.h"



// *****************  �� �� ü ************************
class Chexahedron
{
public:
	Chexahedron();
	~Chexahedron();

private:
	class CTriangle* m_Tri[12]{ nullptr };
	glm::vec3 m_Position[8];

	GLfloat m_W = 0.0f;	// ���� 
	GLfloat m_D = 0.0f; // ����
	GLfloat m_H = 0.0f; // ����

private:
	// ��� ���� 
	glm::mat4 m_Translate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Rotate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Scale_Mat = glm::mat4(1.0f);

	// ������ �� ����� ����
	glm::mat4 m_ModelMatrix_Result = glm::mat4(1.0f);

	// ������ ����
	glm::vec3 m_Pivot = glm::vec3(1.0f);
	glm::vec3 m_Movedist = glm::vec3(0.0f, 0.0f, 0.0f);


public:
	// 3�������� Pivot ���� �������� ����ü ��ǥ���� �����մϴ�. 
	void InitPosition(glm::vec3 Pivot = glm::vec3(0.0f, 0.0f, 0.0f));

public:
	void SetColor(glm::vec3 RGB);
	// ���� ���� ���� 
	void Init(GLfloat W, GLfloat D, GLfloat H, glm::vec3 pivot, const char* filepath);

public:
	void Update_TranslateForm(glm::mat4 airplane_translateMat);
	void Update_RotateForm(glm::mat4 airplane_RotateMat);
	void Update_ScaleForm(glm::mat4 airplane_ScaleMat);

	void Update_ModelTransform();

	void Render();
	

};
