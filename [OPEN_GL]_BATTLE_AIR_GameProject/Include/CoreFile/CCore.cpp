//#include "CCore.h"
//#include "Timer.h"
//#include "SceneManager.h"
//#include "ShaderManger.h"

#include "CCore.h"
#include "TimerFile/Timer.h"
#include "../SceneFile/SceneManager.h"
#include "ShaderManagerFile/ShaderManger.h"


//DEFINITION_SINGLE(CCore);
CCore* CCore::m_pInst = nullptr;

CCore::CCore()
{

}

CCore::~CCore()
{

}

bool CCore::Init(int argc, char** argv)
{
	// ȭ�� �ػ� ���� ( â ũ�� )
	m_tRS.iW = WINDOW_SIZE_WIDTH;
	m_tRS.iH = WINDOW_SIZE_HEIGHT;
	


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(m_tRS.iW, m_tRS.iH);
	glutCreateWindow("Example5");
	glewExperimental = GL_TRUE;
	glewInit();

	MyProgramInit();


	return true;
}

bool CCore::MyProgramInit()
{
	// *** Ÿ�̸� �ʱ�ȭ ***
	if (!CTimer::GetInst()->Init())
		return false;

	// ** ��� ������ �ʱ�ȭ ** 
	if (!CSceneManager::GetInst()->Init())
		return false;

	// **  ���̴� ���α׷� ������ �ʱ�ȭ ** 
	if (!CShaderProgramManger::GetInst()->Init())
		return false;





	return true;

}

void CCore::MyDataDelete()
{
}

void CCore::Logic()
{
}

void CCore::Input(float fDeltaTime)
{
	CSceneManager::GetInst()->Input(fDeltaTime);


}

int CCore::Update(float fDeltaTime)
{
	CSceneManager::GetInst()->Update(fDeltaTime);

	return 0;
}

int CCore::LateUpdate(float fDeltaTime)
{

	CSceneManager::GetInst()->LateUpdate(fDeltaTime);

	return 0;
}

void CCore::Collision(float fDeltaTime)
{
	CSceneManager::GetInst()->Collision(fDeltaTime);


}

void CCore::Render(float fDeltaTime)
{
	
	CSceneManager::GetInst()->Render(fDeltaTime);

	return;

}

void CCore::Run()
{
	glutMainLoop();

}

GLvoid CCore::MyReshape(int width, int height)
{


	glViewport(0, 0, width, height);
	return;

}

GLvoid CCore::MyKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{


	default:
		break;
	}

	return;

}

GLvoid CCore::MyMouse(int button, int state, int x, int y)
{
	// =================================================================
	// ������ Ű ��ǥ�� openGL ��ǥ x y �� ��ȯ �մϴ�. 
	// =================================================================

	GLfloat openGL_x = (x - m_tRS.iW / 2.0f) * (2.0f / m_tRS.iW);
	GLfloat openGL_y = -1 * (y - m_tRS.iH / 2.0f) * (2.0f / m_tRS.iH);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout << "WINDOW : ( " << x << " , " << y << " )  |  " <<
			"OPEN_GL : ( " << openGL_x << " , " << openGL_y << " )" << endl;
	}


	return;
}

GLvoid CCore::MyDrawScene()
{
	
	Render(m_fDeltaTime);
	//cout << " DrawScene : "<< m_fDeltaTime << endl;

	return;
}

GLvoid CCore::MyTimer(GLint value)
{

	CTimer::GetInst()->Update();
	m_fDeltaTime = CTimer::GetInst()->GetDeltaTime();
	//cout << fdeltatime << endl;


	Input(m_fDeltaTime);
	Update(m_fDeltaTime);
	LateUpdate(m_fDeltaTime);
	Collision(m_fDeltaTime);
	 // Render
	//cout << " MyTimer : " << m_fDeltaTime << endl;

	

	return;

}
