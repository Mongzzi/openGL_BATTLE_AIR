

#include "CoreFile/CCore.h"

// ������ â ȭ�� ���� 
glm::vec3 g_MainWindowColor = glm::vec3(0.0f, 0.0f, 0.0f);



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
	glutPostRedisplay();
}

GLvoid Myglut_Reshape(int width, int height)
{
	CCore::GetInst()->MyReshape(width, height);
	glutPostRedisplay();

}

GLvoid Myglut_DrawScene()
{
	glClearColor(g_MainWindowColor.x, g_MainWindowColor.y, g_MainWindowColor.z, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	CCore::GetInst()->MyDrawScene();
	
	glutSwapBuffers();
	return;

}

GLvoid Myglut_Timer(GLint value)
{


	CCore::GetInst()->MyTimer(1);
	glutPostRedisplay();
	glutTimerFunc(1, Myglut_Timer, 1);

}
