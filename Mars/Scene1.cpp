//
//  Scene1.cpp
//  Mars
//
//  Created by Daniel M.C. on 16/12/2012.
//  Copyright (c) 2012 Daniel M.C. All rights reserved.
//

#include "Scene1.h"
#include "MeshModel.h"

void Scene1::create() {
	shaders.push_back(new ShaderProgram("test"));
	shaders[0]->addShader("shader_texture.vert", GL_VERTEX_SHADER);
	shaders[0]->addShader("shader_texture.frag", GL_FRAGMENT_SHADER);
	shaders[0]->linkProgram();
	
	glBindAttribLocation(shaders[0]->getID(), 0, "in_Position");
	glBindAttribLocation(shaders[0]->getID(), 1, "in_Normal");
	glBindAttribLocation(shaders[0]->getID(), 2, "in_UV");
	glBindFragDataLocation(shaders[0]->getID(), 0, "FragColor");
	
	shaders[0]->use();

	meshes.push_back(new MeshModel("asteroid1.obj"));
	glUniform1f(glGetUniformLocation(shaders[0]->getID(), "in_Texture"), 0);

}

void Scene1::destroy() {
	shaders.clear();
}

float angle = 0;

void Scene1::render(float time) {
	angle += 1;
	glm::mat4 Projection = glm::perspective(45.0f, 1.f, 0.1f, 100.0f);
	glm::mat4 View = glm::mat4(1.);
	View = glm::translate(View, glm::vec3(0.f, 0.f, -4.0f));
	glm::mat4 Model = glm::mat4(1.0);
	//	Model = glm::rotate(Model, angle * -0.5f, glm::vec3(1.f, 0.0f, 0.f));
	Model = glm::rotate(Model, angle * 0.5f, glm::vec3(0.f, 1.f, 0.f));
	Model = glm::rotate(Model, angle * 0.5f, glm::vec3(0.f, 0.f, 1.f));
	
	glm::mat4 MVP = Projection * View * Model;
	glm::vec3 lightPos = glm::vec3(3,0,3);
	glUniformMatrix4fv(glGetUniformLocation(shaders[0]->getID(), "MVP"), 1, GL_FALSE, glm::value_ptr(MVP));
	glUniformMatrix4fv(glGetUniformLocation(shaders[0]->getID(), "M"), 1, GL_FALSE, glm::value_ptr(Model));
	glUniformMatrix4fv(glGetUniformLocation(shaders[0]->getID(), "V"), 1, GL_FALSE, glm::value_ptr(View));
	glUniform3f(glGetUniformLocation(shaders[0]->getID(), "in_LightPosition"), lightPos.x, lightPos.y, lightPos.z);
	glUniform1f(glGetUniformLocation(shaders[0]->getID(), "in_LightPower"), 1.5f);
	glUniform3f(glGetUniformLocation(shaders[0]->getID(), "in_Color"), 1.0, 1.0, 1.0);
	
	meshes[0]->draw();
}