#pragma once

#include "../../HeaderFile/Game.h"


// �ﰢ�� 
class CTriangle
{
public:
	CTriangle();
	~CTriangle();

private:
	GLuint m_VAO;
	GLuint m_VBO[3];
	GLuint m_EBO;

public:
	GLboolean m_bEnable = GL_TRUE;


private:
	glm::vec3 m_Position[3];
	glm::vec3 m_Normal[3];
	glm::vec2 m_Texture[3];


	glm::vec3 m_Colors[3];
	GLuint m_Index[3] = { 0,1,2 };

	GLfloat m_Size = 0.4f;

private:
	// ��� ���� 
	glm::mat4 m_Translate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Rotate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Scale_Mat = glm::mat4(1.0f);
	// ������ �� ����� ����
	glm::mat4 m_ModelMatrix_Result = glm::mat4(1.0f);

private:

	unsigned int m_texture;
public:
	void InitTexture_1(stbi_uc* textData3,
		int text_width, int text_height);

	void InitBuffer();

public:
	// �ʱ�ȭ ( ��ġ + �� + Buffer ��� )
	void Init(glm::vec3 Pos0, glm::vec3 Pos1, glm::vec3 Pos2,
		GLfloat R, GLfloat G, GLfloat B, glm::vec3 Normal1, glm::vec3 Normal2, glm::vec3 Normal3,
		glm::vec2 tex1, glm::vec2 tex2, glm::vec2 tex3, stbi_uc* textData3,
		int text_width, int text_height);

	void InitTexture(glm::vec2 Pos0, glm::vec2 Pos1, glm::vec2 Pos2);
	//  �ﰢ���� 0,1,2 ��ġ ���� �޽��ϴ�. 
	void InitPosition(glm::vec3 Pos0, glm::vec3 Pos1, glm::vec3 Pos2);
	void InitNormal(glm::vec3 Nor0, glm::vec3 Nor1, glm::vec3 Nor2);

	// �ﰢ���� R G B ���� �����մϴ�. 
	void InitColor(GLfloat R, GLfloat G, GLfloat B);
	// �̵� ��� ������Ʈ 
	void Update_TranslateForm(GLfloat dx = 0.0f, GLfloat dy = 0.0f, GLfloat dz = 0.0f);
	// ȸ�� ��� ������Ʈ
	void Update_RotateForm(GLfloat Time, GLfloat Axis_x = 0.0f, GLfloat Axis_y = 0.0f, GLfloat Axis_z = 1.0f);
	// ���� ��� ������Ʈ 
	void Update_ScaleForm(GLfloat sx = 1.0f, GLfloat sy = 1.0f, GLfloat sz = 1.0f);
	// �̵� / ȸ�� / ���� �� ���� ��� ������Ʈ ( modelTransform �� ���� ���� )
	void Update_ModelTransform();

public:

	void Render(RENDER_TYPE renderType);

};

