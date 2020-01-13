#include <Game.h>

bool updatable = false;
vector3 vectorsPos[8] = { {-1.0f,-1.0f,1.0f },{1.0f,-1.0f,1.0f }, {1.0f,1.0f,1.0f }, 
{-1.0f,1.0f,1.0f }, {-1.0f,-1.0f,-1.0f }, {1.0f,-1.0f,-1.0f }, 
{1.0f,1.0f,-1.0f }, {-1.0f,1.0f,-1.0f } };
Matrix3 matrix;

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
				vector3 localvect = matrix.RotationX(rotationAngle) * vectorsPos[i];
				vectorsPos[i].setX(localvect.getX());
				vectorsPos[i].setY(localvect.getY());
				vectorsPos[i].setZ(localvect.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 localvect = matrix.RotationY(rotationAngle) * vectorsPos[i];
				vectorsPos[i].setX(localvect.getX());
				vectorsPos[i].setY(localvect.getY());
				vectorsPos[i].setZ(localvect.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 localvect = matrix.RotationZ(rotationAngle) * vectorsPos[i];
				vectorsPos[i].setX(localvect.getX());
				vectorsPos[i].setY(localvect.getY());
				vectorsPos[i].setZ(localvect.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			for (int i = 0; i < 8; i++)
			{
				float localZ = vectorsPos[i].getZ();
				vectorsPos[i].setZ(1);
				vector3 localvect = matrix.Translate(0, -0.5) * vectorsPos[i];
				vectorsPos[i].setX(localvect.getX());
				vectorsPos[i].setY(localvect.getY());
				vectorsPos[i].setZ(localZ);

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			for (int i = 0; i < 8; i++)
			{
				float localZ = vectorsPos[i].getZ();
				vectorsPos[i].setZ(1);
				vector3 localvect = matrix.Translate(0, 0.5) * vectorsPos[i];
				vectorsPos[i].setX(localvect.getX());
				vectorsPos[i].setY(localvect.getY());
				vectorsPos[i].setZ(localZ);

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			for (int i = 0; i < 8; i++)
			{
				float localZ = vectorsPos[i].getZ();
				vectorsPos[i].setZ(1);
				vector3 localvect = matrix.Translate(0.5, 0) * vectorsPos[i];
				vectorsPos[i].setX(localvect.getX());
				vectorsPos[i].setY(localvect.getY());
				vectorsPos[i].setZ(localZ);

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			for (int i = 0; i < 8; i++)
			{
				float localZ = vectorsPos[i].getZ();
				vectorsPos[i].setZ(1);
				vector3 localvect = matrix.Translate(-0.5, 0) * vectorsPos[i];
				vectorsPos[i].setX(localvect.getX());
				vectorsPos[i].setY(localvect.getY());
				vectorsPos[i].setZ(localZ);

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			for (int i = 0; i < 8; i++)
			{

				vector3 localvect = matrix.Scale3D(101) * vectorsPos[i];
				vectorsPos[i].setX(localvect.getX());
				vectorsPos[i].setY(localvect.getY());
				vectorsPos[i].setZ(localvect.getZ());

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			for (int i = 0; i < 8; i++)
			{
				vector3 localvect = matrix.Scale3D(99) * vectorsPos[i];
				vectorsPos[i].setX(localvect.getX());
				vectorsPos[i].setY(localvect.getY());
				vectorsPos[i].setZ(localvect.getZ());

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
		glVertex3f(vectorsPos[0].getX(), vectorsPos[0].getY(), vectorsPos[0].getZ());
		glVertex3f(vectorsPos[1].getX(), vectorsPos[1].getY(), vectorsPos[1].getZ());
		glVertex3f(vectorsPos[2].getX(), vectorsPos[2].getY(), vectorsPos[2].getZ());

		glVertex3f(vectorsPos[2].getX(), vectorsPos[2].getY(), vectorsPos[2].getZ());
		glVertex3f(vectorsPos[3].getX(), vectorsPos[3].getY(), vectorsPos[3].getZ());
		glVertex3f(vectorsPos[0].getX(), vectorsPos[0].getY(), vectorsPos[0].getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(vectorsPos[4].getX(), vectorsPos[4].getY(), vectorsPos[4].getZ());
		glVertex3f(vectorsPos[7].getX(), vectorsPos[7].getY(), vectorsPos[7].getZ());
		glVertex3f(vectorsPos[6].getX(), vectorsPos[6].getY(), vectorsPos[6].getZ());

		glVertex3f(vectorsPos[6].getX(), vectorsPos[6].getY(), vectorsPos[6].getZ());
		glVertex3f(vectorsPos[5].getX(), vectorsPos[5].getY(), vectorsPos[5].getZ());
		glVertex3f(vectorsPos[4].getX(), vectorsPos[4].getY(), vectorsPos[4].getZ());

		//top
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(vectorsPos[3].getX(), vectorsPos[3].getY(), vectorsPos[3].getZ());
		glVertex3f(vectorsPos[2].getX(), vectorsPos[2].getY(), vectorsPos[2].getZ());
		glVertex3f(vectorsPos[6].getX(), vectorsPos[6].getY(), vectorsPos[6].getZ());

		glVertex3f(vectorsPos[6].getX(), vectorsPos[6].getY(), vectorsPos[6].getZ());
		glVertex3f(vectorsPos[7].getX(), vectorsPos[7].getY(), vectorsPos[7].getZ());
		glVertex3f(vectorsPos[3].getX(), vectorsPos[3].getY(), vectorsPos[3].getZ());


		//bottom
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(vectorsPos[4].getX(), vectorsPos[4].getY(), vectorsPos[4].getZ());
		glVertex3f(vectorsPos[5].getX(), vectorsPos[5].getY(), vectorsPos[5].getZ());
		glVertex3f(vectorsPos[1].getX(), vectorsPos[1].getY(), vectorsPos[1].getZ());

		glVertex3f(vectorsPos[1].getX(), vectorsPos[1].getY(), vectorsPos[1].getZ());
		glVertex3f(vectorsPos[0].getX(), vectorsPos[0].getY(), vectorsPos[0].getZ());
		glVertex3f(vectorsPos[4].getX(), vectorsPos[4].getY(), vectorsPos[4].getZ());

		//side1
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(vectorsPos[1].getX(), vectorsPos[1].getY(), vectorsPos[1].getZ());
		glVertex3f(vectorsPos[5].getX(), vectorsPos[5].getY(), vectorsPos[5].getZ());
		glVertex3f(vectorsPos[6].getX(), vectorsPos[6].getY(), vectorsPos[6].getZ());

		glVertex3f(vectorsPos[6].getX(), vectorsPos[6].getY(), vectorsPos[6].getZ());
		glVertex3f(vectorsPos[2].getX(), vectorsPos[2].getY(), vectorsPos[2].getZ());
		glVertex3f(vectorsPos[1].getX(), vectorsPos[1].getY(), vectorsPos[1].getZ());
		//side2
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(vectorsPos[0].getX(), vectorsPos[0].getY(), vectorsPos[0].getZ());
		glVertex3f(vectorsPos[3].getX(), vectorsPos[3].getY(), vectorsPos[3].getZ());
		glVertex3f(vectorsPos[7].getX(), vectorsPos[7].getY(), vectorsPos[7].getZ());

		glVertex3f(vectorsPos[7].getX(), vectorsPos[7].getY(), vectorsPos[7].getZ());
		glVertex3f(vectorsPos[4].getX(), vectorsPos[4].getY(), vectorsPos[4].getZ());
		glVertex3f(vectorsPos[0].getX(), vectorsPos[0].getY(), vectorsPos[0].getZ());
		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

