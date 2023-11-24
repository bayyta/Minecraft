#include "utils/timer.h"
#include "level/level.h"

#include <time.h>

int main()
{
	using namespace graphics;

	srand(time(NULL));

	Window window("Hello", 1280, 720);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	level::Level level(&window);

	Timer time;
	float timer = 0;
	float dt = 0.0f;
	float last = time.elapsed();
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();

		level.update(dt);
		level.render();

		window.update();

		frames++;
		dt = time.elapsed() - last;
		last = time.elapsed();
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
}