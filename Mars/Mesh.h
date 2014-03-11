//
//  Mesh.h
//  Mars
//
//  Created by Daniel M.C. on 16/12/2012.
//  Copyright (c) 2012 Daniel M.C. All rights reserved.
//

#ifndef __Mars__Mesh__
#define __Mars__Mesh__

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

class Mesh {
	protected:
		std::vector<glm::vec3> verts;
		std::vector<glm::vec3> normals;
		std::vector<unsigned short> indicies;
		std::vector<glm::vec2> uvs;
		GLuint id;
	public:
		virtual void draw()=0;
};

#endif /* defined(__Mars__Mesh__) */
