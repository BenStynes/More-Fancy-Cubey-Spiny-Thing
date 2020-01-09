#include <Game.h>

bool updatable = false;
vector3 yeet[8] = { {-1.0f,-1.0f,1.0f },{1.0f,-1.0f,1.0f }, {1.0f,1.0f,1.0f }, 
{-1.0f,1.0f,1.0f }, {-1.0f,-1.0f,-1.0f }, {1.0f,-1.0f,-1.0f }, 
{1.0f,1.0f,-1.0f }, {-1.0f,1.0f,-1.0f } };
Matrix3 reee;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning){

		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	
	
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	setUp();
	
	if (elapsed.asSeconds() >= 1.0f/60)
	{
		clock.restart();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 dik = reee.RotationX(rotationAngle) * yeet[i];
				yeet[i].setX(dik.getX());
				yeet[i].setY(dik.getY());
				yeet[i].setZ(dik.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 dik = reee.RotationY(rotationAngle) * yeet[i];
				yeet[i].setX(dik.getX());
				yeet[i].setY(dik.getY());
				yeet[i].setZ(dik.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 dik = reee.RotationZ(rotationAngle) * yeet[i];
				yeet[i].setX(dik.getX());
				yeet[i].setY(dik.getY());
				yeet[i].setZ(dik.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 dik = reee.Translate(5, 0) * yeet[i];
				yeet[i].setX(dik.getX());
				yeet[i].setY(dik.getY());
				yeet[i].setZ(dik.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 dik = reee.Translate(0, 5) * yeet[i];
				yeet[i].setX(dik.getX());
				yeet[i].setY(dik.getY());
				yeet[i].setZ(dik.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 dik = reee.Scale3D(101) * yeet[i];
				yeet[i].setX(dik.getX());
				yeet[i].setY(dik.getY());
				yeet[i].setZ(dik.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 dik = reee.Scale3D(99) * yeet[i];
				yeet[i].setX(dik.getX());
				yeet[i].setY(dik.getY());
				yeet[i].setZ(dik.getZ());

			}
		}
	}
}

void Game::draw()
{


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();

	glTranslatef(0, 0, -8);
	glCallList(1);

	window.display();

}

void Game::unload()
{
	
}

void Game::setUp()
{
	glEnable(GL_CULL_FACE);

	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(yeet[0].getX(), yeet[0].getY(), yeet[0].getZ());
		glVertex3f(yeet[1].getX(), yeet[1].getY(), yeet[1].getZ());
		glVertex3f(yeet[2].getX(), yeet[2].getY(), yeet[2].getZ());

		glVertex3f(yeet[2].getX(), yeet[2].getY(), yeet[2].getZ());
		glVertex3f(yeet[3].getX(), yeet[3].getY(), yeet[3].getZ());
		glVertex3f(yeet[0].getX(), yeet[0].getY(), yeet[0].getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(yeet[4].getX(), yeet[4].getY(), yeet[4].getZ());
		glVertex3f(yeet[7].getX(), yeet[7].getY(), yeet[7].getZ());
		glVertex3f(yeet[6].getX(), yeet[6].getY(), yeet[6].getZ());

		glVertex3f(yeet[6].getX(), yeet[6].getY(), yeet[6].getZ());
		glVertex3f(yeet[5].getX(), yeet[5].getY(), yeet[5].getZ());
		glVertex3f(yeet[4].getX(), yeet[4].getY(), yeet[4].getZ());

		//top
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(yeet[3].getX(), yeet[3].getY(), yeet[3].getZ());
		glVertex3f(yeet[2].getX(), yeet[2].getY(), yeet[2].getZ());
		glVertex3f(yeet[6].getX(), yeet[6].getY(), yeet[6].getZ());

		glVertex3f(yeet[6].getX(), yeet[6].getY(), yeet[6].getZ());
		glVertex3f(yeet[7].getX(), yeet[7].getY(), yeet[7].getZ());
		glVertex3f(yeet[3].getX(), yeet[3].getY(), yeet[3].getZ());


		//bottom
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(yeet[4].getX(), yeet[4].getY(), yeet[4].getZ());
		glVertex3f(yeet[5].getX(), yeet[5].getY(), yeet[5].getZ());
		glVertex3f(yeet[1].getX(), yeet[1].getY(), yeet[1].getZ());

		glVertex3f(yeet[1].getX(), yeet[1].getY(), yeet[1].getZ());
		glVertex3f(yeet[0].getX(), yeet[0].getY(), yeet[0].getZ());
		glVertex3f(yeet[4].getX(), yeet[4].getY(), yeet[4].getZ());

		//side1
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(yeet[1].getX(), yeet[1].getY(), yeet[1].getZ());
		glVertex3f(yeet[5].getX(), yeet[5].getY(), yeet[5].getZ());
		glVertex3f(yeet[6].getX(), yeet[6].getY(), yeet[6].getZ());

		glVertex3f(yeet[6].getX(), yeet[6].getY(), yeet[6].getZ());
		glVertex3f(yeet[2].getX(), yeet[2].getY(), yeet[2].getZ());
		glVertex3f(yeet[1].getX(), yeet[1].getY(), yeet[1].getZ());
		//side2
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(yeet[0].getX(), yeet[0].getY(), yeet[0].getZ());
		glVertex3f(yeet[3].getX(), yeet[3].getY(), yeet[3].getZ());
		glVertex3f(yeet[7].getX(), yeet[7].getY(), yeet[7].getZ());

		glVertex3f(yeet[7].getX(), yeet[7].getY(), yeet[7].getZ());
		glVertex3f(yeet[4].getX(), yeet[4].getY(), yeet[4].getZ());
		glVertex3f(yeet[0].getX(), yeet[0].getY(), yeet[0].getZ());
		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

