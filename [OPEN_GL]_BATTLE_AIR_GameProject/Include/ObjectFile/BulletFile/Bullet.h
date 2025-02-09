#pragma once


#include "../../HeaderFile/Game.h"



class CBullet
{
public:
	CBullet();
	~CBullet();


	// ==========================
	//obj 파일 관련 변수들...
	// ==========================
private:
	static std::vector< glm::vec3 > m_outvertex;	// 정점			리스트
	static std::vector< glm::vec3 > m_outnormal;	// 법선벡터		리스트
	static std::vector< glm::vec2 > m_outuv;		// 텍스처 uv	리스트

	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec3 > temp_normals;
	std::vector< glm::vec2 > temp_uvs;

	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;

private:
	// 텍스처 데이터 저장 
	stbi_uc* m_Bullet_Text_data = NULL;
	int m_Bullet_width = 0, m_Bullet_height = 0;

private:
	static GLint* m_Tri_Num2;	// 삼각형 개수 
	static GLint m_Tri_Num;

private:
	float sumX = 0.0, sumY = 0.0, sumZ = 0.0;
	float aveX, aveY, aveZ;
	float scaleX, scaleY, scaleZ;
	float minX = 0.0, minY = 0.0, minZ = 0.0;
	float maxX = 0.0, maxY = 0.0, maxZ = 0.0;
	float scaleAll;
	// ==========================
	// ==========================

private:
	GLuint m_VAO;
	GLuint m_VBO[2];

private:
	// 현재 위치
	glm::vec3 m_Pivot = glm::vec3(0.0f, 0.0f, 0.0f);
	// Airplane Color 
	glm::vec3 m_Color;
	// Airplane Speed 
	GLfloat m_Speed = 15.0f;
	GLfloat m_Angle = 0.0f;
	GLfloat m_Limit_dist = 100;
	GLfloat m_dist = 0.0f;


	// 폭발 여부 표시 ( 충돌 했는지 혹은 사정거리 이상 지나면 사라지라는 신호 )
	GLboolean m_bEnable = true;


public:
	bool GetEnable() { return m_bEnable; }
	glm::vec3 GetCollide_Position(int idx);


public:
	// collide box [ *** 충돌 박스 *** ]
	class Chexahedron* m_CollideBox;


private:
	// 행렬 모음 
	glm::mat4 m_Translate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Rotate_Mat = glm::mat4(1.0f);
	glm::mat4 m_Scale_Mat = glm::mat4(1.0f);
	// 적용할 모델 헹렬의 최종
	glm::mat4 m_ModelMatrix_Result = glm::mat4(1.0f);

private:
	// Angle ( for Updating Move Vector )
	glm::mat4 m_Rotate_Mat_LR = glm::mat4(1.0f);

private:
	unsigned int m_texture;

public:
	glm::vec3 GetPivot() { return m_Pivot; }

public:
	int loadObj_normalize_center(const char* filename);

public:
	void InitBuffer();

public:
	// ** 행렬 업데이트 함수 ** 
	void Update_TranslateForm(glm::vec3 translate);
	void Update_RotateForm(GLfloat Time, GLfloat Axis_x = 0.0f, GLfloat Axis_y = 0.0f, GLfloat Axis_z = 1.0f);
	void Update_ScaleForm(GLfloat sx = 1.0f, GLfloat sy = 1.0f, GLfloat sz = 1.0f);

	void Update_Rotate_LR(GLfloat Axis_x, GLfloat Axis_y, GLfloat Axis_z);

	// ** 행렬 최종 함수 ** 
	void Update_ModelTransform(float fDeltaTime);
	void InitTexture_1(stbi_uc* textData2, int width, int height);

public:
	void Init(glm::vec3 scaleInfo, glm::vec3 color, glm::vec3 pivot, const char* filename, GLfloat angle, stbi_uc* textData2, int text_width, int text_height);

	void Input(float fDeltaTime);					// * 입력
	int Update(float fDeltaTime);					// * 업데이트
	int LateUpdate(float fDeltaTime);				// * 업데이트 후처리
	void Collision(float fDeltaTime);				// * 충돌
	void Render(float fDeltaTime);					// * 출력


};

