//
//  ShaderProgram.h
//  Mars
//
//  Created by Daniel M.C. on 16/12/2012.
//  Copyright (c) 2012 Daniel M.C. All rights reserved.
//

#ifndef Mars_ShaderProgram
#define Mars_ShaderProgram

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

class ShaderProgram {
	const char * name;
	GLuint id;
public:
	ShaderProgram ();
	ShaderProgram (const char *);
	~ShaderProgram();
	GLuint addShader (const char *, GLenum);
	void linkProgram ();
	void use ();
	GLuint getID();
};

#endif
