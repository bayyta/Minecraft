#include "level.h"

namespace level {

	Level::Level(graphics::Window* window)
		: m_Window(window)
	{
		init();
	}

	Level::~Level()
	{
		delete grass;
		delete dirt;
		delete stone;
		delete m_Player;
	}

	void Level::init() {
		using namespace graphics;

		GLint texIDs[] =
		{
			0, 1, 2, 3, 4, 5
		};

		grass = new Texture("res/grass_sheet.png");
		dirt = new Texture("res/dirt_sheet.png");
		stone = new Texture("res/stone_sheet.png");
		shader = new Shader("shaders/batch.vert", "shaders/batch.frag");
		m_Camera = new Camera(shader);

		shader->enable();
		shader->setUniform1iv("textures", texIDs, sizeof(texIDs) / sizeof(GLint));
		m_Camera->init();
		shader->disable();

		Block* block = new Block(glm::vec3(1.0f, 1.0f, 1.0f));
		batch3d = new Batch3D(block, shader);

		generateLevel();

		m_Player = new entity::Player(block, new Renderable(glm::vec3(rand() % 100, rand() % 100, -rand() % 100), grass), glm::vec3(1.0f), m_Window);
	}

	void Level::generateLevel()
	{
		unsigned int width = 50, height = 50;
		double xd = 2.0;
		double yd = 2.0;
		float bottom = -48;
		unsigned int seed = 239;

		PerlinNoise pn(seed);
		int count = 0;
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				double x = (double)j / ((double)width);
				double y = (double)i / ((double)height);

				double n = pn.noise(xd * x, yd * y, 0.8);

				// Wood like structure
				//n = 20 * pn.noise(x, y, 0.8);
				//n = n - floor(n);

				float yc = floor(n * -32);
				batch3d->add(new graphics::Renderable(glm::vec3(j, yc, -i), grass));
				while (yc > bottom)
				{
					yc--;
					if (yc > bottom + 10)
						batch3d->add(new graphics::Renderable(glm::vec3(j, yc, -i), dirt));
					else
						batch3d->add(new graphics::Renderable(glm::vec3(j, yc, -i), stone));
					count++;
				}
			}
		}
		std::cout << count << std::endl;
	}

	void Level::update(float dt) {
		shader->enable();
		m_Camera->setPosition(m_Player->getPosition());
		m_Camera->setRotation(m_Player->getRotation());
		m_Camera->update(dt);

		m_Player->update(dt);
	}

	void Level::render() {
		batch3d->render();
	}

}