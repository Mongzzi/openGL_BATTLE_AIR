#pragma once

#include "../../HeaderFile/Game.h"


class CShaderProgramManger
{

public:
	// �̱������� �����մϴ�.
	DECLARE_SINGLE(CShaderProgramManger);

private:
	static GLuint ShaderProgramID;

public:
	static GLuint Get_ShaderProgramID()
	{
		if (ShaderProgramID != NULL)
			return ShaderProgramID;
	}

private:
	GLuint fragmentShader;
	GLuint vertexShader;
	class CFileManager* m_fileManager;

public:
	bool Init();

	bool Make_VertexShaders();
	bool make_FragmentShaders();
	bool InitShader();


};


