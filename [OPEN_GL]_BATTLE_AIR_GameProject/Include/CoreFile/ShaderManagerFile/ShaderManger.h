#pragma once

#include "../../HeaderFile/Game.h"


class CShaderProgramManger
{

public:
	// �̱������� �����մϴ�.
	DECLARE_SINGLE(CShaderProgramManger);

private:
	static GLuint ShaderProgramID;
	static GLuint ShaderProgramID_Texture;


public:
	static GLuint Get_ShaderProgramID()
	{
		/*if (ShaderProgramID != NULL)
			return ShaderProgramID;*/
		if (ShaderProgramID_Texture != NULL)
			return ShaderProgramID_Texture;
	}

	static GLuint Get_ShaderProgramID_Texture()
	{
		if (ShaderProgramID_Texture != NULL)
			return ShaderProgramID_Texture;
	}

private:
	GLuint m_fragmentShader;
	GLuint m_vertexShader;
	class CFileManager* m_fileManager;

private:
	GLuint m_fragmentShader_texture;
	GLuint m_vertexShader_texture;


public:
	bool Init();

	bool Make_VertexShaders();
	bool Make_FragmentShaders();
	bool InitShader();


public:
	// Texture �� ����� shader
	bool Make_FragmentShaders_Texrure();
	bool Make_VertexShaders_Texture();
	bool InitShader_Texture();


};


