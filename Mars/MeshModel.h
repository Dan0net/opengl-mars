//
//  MeshModel.h
//  Mars
//
//  Created by Daniel M.C. on 16/12/2012.
//  Copyright (c) 2012 Daniel M.C. All rights reserved.
//

#ifndef __Mars__MeshModel__
#define __Mars__MeshModel__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <map>

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/glfw.h>

#include "Mesh.h"

class MeshModel: public Mesh {
	void indexVBO(std::vector<glm::vec3> & in_vertices,
								std::vector<glm::vec2> & in_uvs,
								std::vector<glm::vec3> & in_normals,
								
								std::vector<unsigned short> & out_indices,
								std::vector<glm::vec3> & out_vertices,
								std::vector<glm::vec2> & out_uvs,
								std::vector<glm::vec3> & out_normals
);
public:
	MeshModel(const char *);
	void draw();
};

#endif /* defined(__Mars__MeshModel__) */
