/*
	File: ShaderProgram.h
	Author: Abramov Nickolai
	Description: common interface for GLSL and Cg program
*/

#ifndef _SHADER_PROGRAM_H
#define _SHADER_PROGRAM_H

class ShaderProgram
{
public:
	virtual void Bind(int passNumber = 0) = 0;
	virtual void Unbind() = 0;
	virtual void CreateFromFile(const char* vertexProgramFileName, const char* fragmentProgramFileName) = 0;
	virtual void CreateFromString(const char* vertexProgram, const char* fragmentProgram) = 0;
	virtual void CreateFromRFX(const char* fileName, const char* effectGroup, const char* effectName) = 0;
	virtual void Clear() = 0;
	virtual int GetPassCount() const = 0;
	virtual bool SetUniformVector4f( const char * name, const float* value) = 0;
	virtual bool SetUniformVector4f( int loc, const float* value) = 0;
	virtual bool SetUniformVector3f( const char * name, const float* value) = 0;
	virtual bool SetUniformVector3f( int loc, const float* value) = 0;
	virtual bool SetUniformVector2f( const char * name, const float* value) = 0;
	virtual bool SetUniformVector2f( int loc, const float* value) = 0;
	virtual bool SetUniformFloat( const char * name, float value) = 0;
	virtual bool SetUniformFloat( int loc, float value) = 0;
	virtual bool SetUniformMatrix4f( const char * name, const float* value) = 0;
	virtual bool SetUniformMatrix4f( int loc, const float* value) = 0;
	virtual bool SetUniformMatrix3f( const char * name, const float*  value) = 0;
	virtual bool SetUniformMatrix3f( int loc, const float*  value) = 0;
	virtual bool SetUniformInt( const char * name, int value) = 0;
	virtual bool SetUniformInt( int loc, int value) = 0;
	virtual bool SetTexture( const char * name, int texUnit) = 0;
	virtual bool SetTexture( int loc, int texUnit) = 0;
	virtual int GetUniformLocation( const char * name) = 0;
	virtual int GetAttribLocation(const char* attrib) = 0;
};

#endif