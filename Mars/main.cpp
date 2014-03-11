#include "Mars.h"

#include "Scene.h"
#include "Scene1.h"
#include "ShaderProgram.h"

Scene* current_scene;
std::vector<Scene *> scenes;

void Setup() {
	scenes.push_back(new Scene1());
	scenes[0]->create();
	
	current_scene = scenes[0];
}

void Render(float time) {
	current_scene->render(time);
}

int main( void ) {
	if(!glfwInit()) {
		exit( EXIT_FAILURE );
	}
	
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 16);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if(!glfwOpenWindow(SCREEN_WIDTH, SCREEN_HEIGHT, 8,8,8,8,24,8, GLFW_WINDOW)) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	printf("*** OpenGL %s | GLSL %s ***\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));
	
	glewExperimental = GL_TRUE;
	glewInit();
	glGetError();
	
	glfwSwapInterval(1);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glfwSetTime(0.0);
	
	glDisable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	Setup();
	
	int frames = 0;
	float elapsedTime = 0;
	do{
		float time = (float) glfwGetTime();
		Render(time);
		glfwSwapBuffers();
		
		/* FPS Counter */
		if((glfwGetTime()-elapsedTime) > 4.0){
			int fps = (float) ceil(frames / (glfwGetTime()-elapsedTime));
			printf("*** FPS: %d ***\n", fps);
			frames = 0;
			elapsedTime = time;
		}
		frames++;
		
	} while(!(glfwGetKey(GLFW_KEY_ESC) || glfwGetKey(81)) && glfwGetWindowParam(GLFW_OPENED));
	
	glfwTerminate();
	exit( EXIT_SUCCESS );
}
