#include "Scene.h"
#include "SceneManager.h"
#include "../LightFile/Light.h"
#include "../CameraFile/Camera.h"
#include "../CoreFile/ShaderManagerFile/ShaderManger.h"
#include "../ObjectFile/AxisFile/Axis.h"

#include "../ObjectFile/AirplaneFile/Airplane.h"
#include "../ObjectFile/MonsterFile/Monster.h"
#include "../ObjectFile/BackgroundFile/Background.h"
#include "../ObjectFile/BuildingFile/Building1.h"
#include "../ObjectFile/BuildingFile/Building2.h"
#include "../ObjectFile/BuildingFile/Building3.h"



#include "../ObjectFile/FloorFile/Floor.h"
#include "../ObjectFile/TriangleFile/Triangle.h"
#include "../SoundFile/SoundManager.h"

#include "../ObjectFile/BulletFile/Bullet.h"



CScene::CScene()
{
	m_bEnable = false;


}

CScene::~CScene()
{
	if (m_Camera != nullptr)
		delete m_Camera;

	if (m_Light != nullptr)
		delete m_Light;
	
	if (m_Airplane != nullptr)
		delete m_Airplane;

	if (m_Monster != nullptr)
		delete m_Monster;

	if (m_Background != nullptr)
		delete m_Background;

	if (m_Building1 != nullptr)
		delete m_Building1;

	if (m_Building2 != nullptr)
		delete m_Building2;

	if (m_Building3 != nullptr)
		delete m_Building3;

	if (m_triangle != nullptr)
		delete m_triangle;

	if (m_Floor != nullptr)
		delete[] m_Floor;


	stbi_image_free(m_Airplane_Text_data);
	stbi_image_free(m_Bullet_Text_data);

}

void CScene::InitTexture_All()
{

	// *** ����� �ؽ�ó ������ ���� ***
	const char* filename = "./ObjectFile/AirplaneFile/airplane_body_diffuse_v1.jpg";
	int widthImage = 0, heightImage = 0, numberOfChannel = 0;
	m_Airplane_Text_data = stbi_load(filename, &widthImage, &heightImage, &numberOfChannel, STBI_rgb);
	m_Airplane_width = widthImage;
	m_Airplane_height = heightImage;

	cout << widthImage << " " << heightImage << endl;

	if (!m_Airplane_Text_data) {
		fprintf(stderr, "Cannot load file image %s\nSTB Reason: %s\n", filename, stbi_failure_reason());
		exit(0);
	}

	// *** �̻���( Bullet ) �ؽ�ó ������ ���� ***
	filename = "./ObjectFile/BulletFile/MissileTexture.png";
	m_Bullet_Text_data = stbi_load(filename, &widthImage, &heightImage, &numberOfChannel, STBI_rgb);
	m_Bullet_width = widthImage;
	m_Bullet_height = heightImage;

	cout << widthImage << " " << heightImage << endl;

	if (!m_Bullet_Text_data) {
		fprintf(stderr, "Cannot load file image %s\nSTB Reason: %s\n", filename, stbi_failure_reason());
		exit(0);
	}


	// *** Red �ؽ�ó ������ ���� ***
	filename = "./ObjectFile/HexaheronFile/Red.png";
	m_RedPng_Text_data = stbi_load(filename, &widthImage, &heightImage, &numberOfChannel, STBI_rgb);
	m_RedPng_width = widthImage;
	m_RedPng_height = heightImage;

	cout << widthImage << " " << heightImage << endl;

	if (!m_RedPng_Text_data) {
		fprintf(stderr, "Cannot load file image %s\nSTB Reason: %s\n", filename, stbi_failure_reason());
		exit(0);
	}


	

		// *** Grass �ؽ�ó ������ ���� ***
	filename = "./ObjectFile/FloorFile/grass.jpg";
	m_Grass_Text_dtat = stbi_load(filename, &widthImage, &heightImage, &numberOfChannel, STBI_rgb);
	m_Grass_width = widthImage;
	m_Grass_height = heightImage;

	cout << m_Grass_width << " " << m_Grass_height << endl;

	if (!m_Grass_Text_dtat) {
		fprintf(stderr, "Cannot load file image %s\nSTB Reason: %s\n", filename, stbi_failure_reason());
		exit(0);
	}


}

void CScene::UpdateProjectionMat()
{
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)WINDOW_SIZE_WIDTH / (float)WINDOW_SIZE_HEIGHT, 0.1f, 1000.0f);
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, -2.0)); //--- ������ �ణ �ڷ� �̷���
	unsigned int projectionLocation = glGetUniformLocation(CShaderProgramManger::Get_ShaderProgramID(), "projectionTransform"); //--- ���� ��ȯ �� ����
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);

}

void CScene::UpdateOrthoMat()
{
	glm::mat4 Ortho = glm::mat4(1.0f);
	Ortho = glm::ortho(-1.5f, 1.5f, -1.5f, 1.5f, 0.1f, 50.0f);
	Ortho = glm::translate(Ortho, glm::vec3(0.0, 0.0, -1.0)); //--- ������ �ణ �ڷ� �̷���
	unsigned int projectionLocation = glGetUniformLocation(CShaderProgramManger::Get_ShaderProgramID(), "projectionTransform"); //--- ���� ��ȯ �� ����
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &Ortho[0][0]);

}

void CScene::Init_MainStage(SCENE_TYPE type)
{
	// �ؽ�ó �������� �����մϴ�. 
	InitTexture_All();

	if (CSoundManager::GetInst()->Init())
	{
		cout << "Sound File Load Success" << endl;

	}


	if (m_Airplane == nullptr)
	{
		m_Airplane = new CAirplane;
		// Init( scale color Pivot FileName )  
		m_Airplane->Init(glm::vec3(1.0f, 1.3f, 0.5f), glm::vec3(255.0f / 255.0f, 153.0f / 255.0f, rand() % 255 / 255.0f),
			glm::vec3(0.0f, 0.0f, 0.0f), "./ObjectFile/AirplaneFile/airplane3.obj",
			m_Airplane_Text_data, m_Bullet_Text_data, m_RedPng_Text_data,
			m_Airplane_width, m_Airplane_height, 
			m_Bullet_width, m_Bullet_height,
			m_RedPng_width, m_RedPng_height);
	}

	if (m_Monster == nullptr)
	{
		m_Monster = new CMonster;
		m_Monster->Init(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(255.0f / 255.0f, 153.0f / 255.0f, rand() % 255 / 255.0f),
			glm::vec3(0.0f, 0.0f, -0.0f), "./ObjectFile/MonsterFile/monster.obj", m_RedPng_Text_data,
			m_RedPng_width, m_RedPng_height);

	}
	// missile �ʱ�ȭ 
	/*if (m_Missile == nullptr)
	{
		m_Missile = new CBullet;
		m_Missile->Init(glm::vec3(2.0f / 3, 0.5f / 3, 0.5f / 3), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(5.0f, 1.0f, 5.0f),
			"./ObjectFile/BulletFile/Missile.obj", m_Airplane->GetAngleLR());

	}*/


	if (m_Camera == nullptr)
	{
		m_Camera = new CCamera;
		// ī�޶� ��ġ , �ٶ󺸰��ִ� ������ ����� �Ǻ��������� �����ǹǷ� �Ʒ� �Ķ���� ������ �ǹ� ����
		m_Camera->Init(glm::vec3(0.01f, 5.0f, 2.0f), glm::vec3(0.001f, 5.0f, -2.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	}
	if (m_Light == nullptr)
	{
		m_Light = new CLight;
		m_Light->Init(glm::vec3(0.0f, 5.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	}

	if (m_Axis == nullptr)
	{
		m_Axis = new CAxis;
		m_Axis->Init(0.0f);
	}

	if (m_Background == nullptr)
	{
		m_Background = new CBackground;
		m_Background->Init(glm::vec3(500.0f, 500.0f, 500.0f), glm::vec3(1.0, 1.0, 1.0),
			glm::vec3(0.0f, 0.0f, 0.0f), "./ObjectFile/BackgroundFile/sphere.obj");

	}

	if (m_Building1 == nullptr)
	{
		m_Building1 = new CBuilding1;
		m_Building1->Init(glm::vec3(3.0f, 1.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(3.0f, 3.0f, 3.0f), "./ObjectFile/BuildingFile/BrownTown.obj");

	}

	if (m_Building2 == nullptr)
	{
		m_Building2 = new CBuilding2;
		m_Building2->Init(glm::vec3(3.0f, 5.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(-3.0f, -3.0f, -3.0f), "./ObjectFile/BuildingFile/WindMill.obj");

	}

	if (m_Building3 == nullptr)
	{
		m_Building3 = new CBuilding3;
		m_Building3->Init(glm::vec3(15.0f, 3.0f, 15.0f), glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(-10.0f, 3.0f, -3.0f), "./ObjectFile/BuildingFile/top.obj");

	}


	for (int i = 0; i < 4; ++i)
	{
		if (m_Floor[i] == nullptr)
		{
			m_Floor[i] = new CFloor;
			m_Floor[i]->Init(m_Grass_Text_dtat, m_Grass_width, m_Grass_height);

		}

	}


}

void CScene::Init_BeginStage(SCENE_TYPE type)
{
}

void CScene::Init_EndStage(SCENE_TYPE type)
{
}

bool CScene::Init(SCENE_TYPE type)
{
	switch (type)
	{
	case NONE:
		break;
	case BEGIN:
		Init_BeginStage(type);
		break;
	case MAIN_STAGE:
		Init_MainStage(type);
		break;
	case END:
		Init_EndStage(type);

		break;
	default:
		break;
	}
	if (type == SCENE_TYPE::MAIN_STAGE)
	{
	
	}
	


	return true;
}

void CScene::Input(float fDeltaTime)
{

	if (m_Airplane != nullptr)
	{
		m_Airplane->Input(fDeltaTime);
	}

	//if (m_Camera != nullptr)
	//{
	//	m_Camera->Input(fDeltaTime);
	//}

}

int CScene::Update(float fDeltaTime)
{

	if (m_Airplane != nullptr)
	{
		m_Airplane->Update(fDeltaTime);
		m_Airplane->Update_Rotate_LR(0.0f, 0.0f, 1.0f);

	}

	if (m_Missile != nullptr)
	{
		m_Missile->Update_Rotate_LR(0.0f, 1.0f, 0.0f);
		//m_Missile->Update(fDeltaTime);


	}

	if (m_Camera != nullptr)
	{
		m_Camera->UpdateCameraPos(m_Airplane->GetPivot(), m_Airplane->GetAngleLR());
		m_Camera->UpdateCameraDirection(m_Airplane->GetAngleLR());

		m_Camera->Update(fDeltaTime);

	}

	// ====================================================================
	// F L O O R ��ġ ( 1 ~ 4 ��и� ) ��ġ�� Floor ��ü �̵� - ó�� ������ (0.0f , 0.0f , 0.0f) ��ġ
	// ====================================================================

	if (m_Floor[0] != nullptr)
	{
		GLfloat size = m_Floor[0]->GetSize();
		m_Floor[0]->Update_TranslateForm(size, 0.0f, -size); // 1 ��и� 

	}
	if (m_Floor[1] != nullptr)
	{
		GLfloat size = m_Floor[1]->GetSize();
		m_Floor[1]->Update_TranslateForm(-size, 0.0f, -size); // 2 ��и� 

	}
	if (m_Floor[2] != nullptr)
	{
		GLfloat size = m_Floor[2]->GetSize();
		m_Floor[2]->Update_TranslateForm(-size, 0.0f, size); // 3 ��и� 

	}
	if (m_Floor[3] != nullptr)
	{
		GLfloat size = m_Floor[3]->GetSize();
		m_Floor[3]->Update_TranslateForm(size, 0.0f, size); // 4 ��и� 

	}
	// ====================================================================
	// ====================================================================

	return 0;
}

int CScene::LateUpdate(float fDeltaTime)
{
	if (m_Airplane != nullptr)
	{
		m_Airplane->LateUpdate(fDeltaTime);
	}
	return 0;
}

void CScene::Collision(float fDeltaTime)
{
	if (m_Airplane != nullptr)
	{
		m_Airplane->Collision(fDeltaTime);
	}
}

void CScene::Render(float fDeltaTime)
{
	
	UpdateProjectionMat();

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	

	if (m_Camera != nullptr)
		m_Camera->Render(fDeltaTime);

	if (m_Light != nullptr)
		m_Light->Render(fDeltaTime, m_Camera);

	if (m_Axis != nullptr)
		m_Axis->Render(fDeltaTime);

	for (int i = 0; i < 4; ++i)
	{
		if (m_Floor[i] != nullptr)
			m_Floor[i]->Render();
	}

	//if (m_Floor_test != nullptr)
	//	m_Floor_test->Render();

	if (m_Airplane != nullptr)
		m_Airplane->Render(fDeltaTime);

	
	if (m_Missile != nullptr)
	{
		m_Missile->Render(fDeltaTime);

	}


	if (m_Monster != nullptr)
		m_Monster->Render(fDeltaTime);

	if (m_Background != nullptr)
		m_Background->Render(fDeltaTime);

	if (m_Building1 != nullptr)
		m_Building1->Render(fDeltaTime);

	if (m_Building2 != nullptr)
		m_Building2->Render(fDeltaTime);

	if (m_Building3 != nullptr)
		m_Building3->Render(fDeltaTime);
}


