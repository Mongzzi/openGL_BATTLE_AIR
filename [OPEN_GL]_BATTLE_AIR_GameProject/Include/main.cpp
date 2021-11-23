
#include "CCore.h"
#include "Timer.h"


// =====================================================
// main : Myglut_(Func) : �����Լ��� ����/���� �մϴ�. 
// =====================================================

GLvoid Myglut_Mouse(int button, int state, int x, int y);
GLvoid Myglut_KeyBoard(unsigned char key, int x, int y);
GLvoid Myglut_Reshape(int width, int height);
GLvoid Myglut_DrawScene();
GLvoid Myglut_Timer(GLint value);

GLvoid MyglutFuncInit();

// =====================================================
// ������ �ʱ�ȭ �� �� �����մϴ�. (Init)->(Run)->(Delete)
// =====================================================

int main(int argc, char** argv)
{
	srand((unsigned int)time(NULL));

	// *** Ÿ�̸� �ʱ�ȭ ***
	if (!CTimer::GetInst()->Init())
		return false;


	// *** ���� �ʱ�ȭ ***
	if (!(CCore::GetInst()->Init(argc, argv)))
	{
		CCore::GetInst()->DestroyInst();
		return 0;

	}

	// *** glut �����Լ� �ʱ�ȭ ***
	MyglutFuncInit();

	// *** ���� ���� ���� ***
	CCore::GetInst()->Run();

	// *** ���� ������ ���� ***
	CCore::GetInst()->MyDataDelete();
	CCore::GetInst()->DestroyInst();

	return 0;

}


// =====================================================
// Myglut_(Func) ���� �������� �����ϴ� �Լ��� �Դϴ�...
// �������� ������ Core ���� �ϰ� �˴ϴ�... 
// 
// �̰��� ���Ǵ� �ܼ��� ȣ�� �����Դϴ�...
// (���� �Լ��θ� ȣ�� ����)
// =====================================================

GLvoid MyglutFuncInit()
{

	glutDisplayFunc(Myglut_DrawScene);
	glutReshapeFunc(Myglut_Reshape);
	glutMouseFunc(Myglut_Mouse);
	glutKeyboardFunc(Myglut_KeyBoard);
	glutTimerFunc(100, Myglut_Timer, 1);
}

GLvoid Myglut_Mouse(int button, int state, int x, int y)
{
	CCore::GetInst()->MyMouse(button, state, x, y);
	glutPostRedisplay();
}

GLvoid Myglut_KeyBoard(unsigned char key, int x, int y)
{
	CCore::GetInst()->MyKeyboard(key, x, y);
}

GLvoid Myglut_Reshape(int width, int height)
{
	CCore::GetInst()->MyReshape(width, height);
}

GLvoid Myglut_DrawScene()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	CTimer::GetInst()->Update();
	float fdeltatime = CTimer::GetInst()->GetDeltaTime();
	
	CCore::GetInst()->MyDrawScene(fdeltatime);
	glutSwapBuffers();

}

GLvoid Myglut_Timer(GLint value)
{

	glutPostRedisplay();
	glutTimerFunc(100, Myglut_Timer, 1);

}
