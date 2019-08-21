
#include <lts/main.hpp>

int main(void)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	SDL_Window *window = SDL_CreateWindow("Window", 4, 4, 300, 200, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	glBegin(GL_TRIANGLES);
	glVertex2d(-0.4, -0.4);
	glVertex2d(0.4, -0.4);
	glVertex2d(0, 0.4);
	glEnd();
	SDL_GL_SwapWindow(window);

	SDL_Delay(2000);

	return 0;
}
