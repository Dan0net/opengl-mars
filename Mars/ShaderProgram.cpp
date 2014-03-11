//
//  ShaderProgram.cpp
//  Mars
//
//  Created by Daniel M.C. on 16/12/2012.
//  Copyright (c) 2012 Daniel M.C. All rights reserved.
//
#include "ShaderProgram.h"

ShaderProgram::ShaderProgram () {}

ShaderProgram::ShaderProgram (const char * _name) {
	name = _name;
	id = glCreateProgram();
}

GLuint ShaderProgram::addShader(const char * filePath, GLenum shaderType){
	FILE *fptr = fopen(filePath, "rb");
  if (!fptr) {
  	fprintf(stderr, "failed to open %s\n", filePath);
    exit(1);
  }
  fseek(fptr, 0, SEEK_END);
  long length = ftell(fptr);
  GLchar *buf = (GLchar*) malloc(length+1);
  fseek(fptr, 0, SEEK_SET);
  fread(buf, length, 1, fptr);
  fclose(fptr);
  buf[length] = 0;
	
	GLuint shader = glCreateShader(shaderType);
	
	glShaderSource(shader, 1, (const char **)&buf, NULL);
	glCompileShader(shader);
	
	int logLength;
	
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
	
	if(logLength){
		char* logMsg = new char[logLength];
		glGetShaderInfoLog(shader, logLength, NULL, &logMsg[0]);
		fprintf(stderr, "Shader %s: %s\n", filePath, &logMsg[0]);
		exit(1);
	}
	
	glAttachShader(id, shader);
	glDeleteShader(shader);
	
	return shader;
}

void ShaderProgram::linkProgram(){
	glLinkProgram(id);
	
	int logLength;
	
	glGetProgramiv(id, GL_INFO_LOG_LENGTH, &logLength);
	
	if(logLength){
		char* logMsg = new char[logLength];
		glGetProgramInfoLog(id, logLength, NULL, &logMsg[0]);
		fprintf(stderr, "Program %s: %s\n", name, &logMsg[0]);
		exit(1);
	}
}

void ShaderProgram::use () {
	glUseProgram(id);
}

GLuint ShaderProgram::getID() {
	return id;
}

ShaderProgram::~ShaderProgram() {
	printf("destorying %s", name);
	glDeleteProgram(id);
}