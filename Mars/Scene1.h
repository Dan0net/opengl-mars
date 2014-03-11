//
//  Scene1.h
//  Mars
//
//  Created by Daniel M.C. on 16/12/2012.
//  Copyright (c) 2012 Daniel M.C. All rights reserved.
//

#ifndef __Mars__Scene1__
#define __Mars__Scene1__

#include "Scene.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

class Scene1: public Scene {
	protected:
		float LENGTH = 5.0f;
	public:
		void create();
		void render(float);
		void destroy();
};

#endif /* defined(__Mars__Scene1__) */
