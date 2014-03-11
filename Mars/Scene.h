//
//  Scene.h
//  Mars
//
//  Created by Daniel M.C. on 16/12/2012.
//  Copyright (c) 2012 Daniel M.C. All rights reserved.
//

#ifndef __Mars__Scene__
#define __Mars__Scene__

#include <vector>
#include "ShaderProgram.h"
#include "Mesh.h"

class Scene {
	protected:
		float LENGTH = 0.0f;
		std::vector<ShaderProgram *> shaders;
		std::vector<Mesh *> meshes;
	public:
		float getLength();
		virtual void create()=0;
		virtual void render(float)=0;
		virtual void destroy()=0;
};
#endif /* defined(__Mars__Scene__) */
