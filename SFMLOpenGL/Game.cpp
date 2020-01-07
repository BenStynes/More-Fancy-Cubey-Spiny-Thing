#include <Game.h>

bool updatable = false;
vector3 yeet[8] = { {-1.0f,-1.0f,1.0f },{1.0f,-1.0f,1.0f }, {1.0f,1.0f,1.0f }, 
{-1.0f,1.0f,1.0f }, {-1.0f,-1.0f,-1.0f }, {1.0f,-1.0f,-1.0f }, 
{1.0f,1.0f,-1.0f }, {-1.0f,1.0f,-1.0f } };


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
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
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(yeet[0].getX(), yeet[0].getZ(), yeet[0].getZ());
		glVertex3f(yeet[1].getX(), yeet[1].getZ(), yeet[1].getZ());
		glVertex3f(yeet[2].getX(), yeet[2].getZ(), yeet[2].getZ());

		glVertex3f(yeet[0].getX(), yeet[0].getZ(), yeet[0].getZ());
		glVertex3f(yeet[1].getX(), yeet[1].getZ(), yeet[1].getZ());
		glVertex3f(yeet[2].getX(), yeet[2].getZ(), yeet[2].getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(yeet[4].getX(), yeet[4].getZ(), yeet[4].getZ());
		glVertex3f(yeet[7].getX(), yeet[7].getZ(), yeet[7].getZ());
		glVertex3f(yeet[6].getX(), yeet[6].getZ(), yeet[6].getZ());

		glVertex3f(yeet[6].getX(), yeet[6].getZ(), yeet[6].getZ());
		glVertex3f(yeet[5].getX(), yeet[5].getZ(), yeet[5].getZ());
		glVertex3f(yeet[4].getX(), yeet[4].getZ(), yeet[4].getZ());

		//top
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(yeet[3].getX(), yeet[3].getZ(), yeet[3].getZ());
		glVertex3f(yeet[2].getX(), yeet[2].getZ(), yeet[2].getZ());
		glVertex3f(yeet[6].getX(), yeet[6].getZ(), yeet[6].getZ());

		glVertex3f(yeet[6].getX(), yeet[6].getZ(), yeet[6].getZ());
		glVertex3f(yeet[7].getX(), yeet[7].getZ(), yeet[7].getZ());
		glVertex3f(yeet[3].getX(), yeet[3].getZ(), yeet[3].getZ());


		//bottom
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(yeet[4].getX(), yeet[4].getZ(), yeet[4].getZ());
		glVertex3f(yeet[5].getX(), yeet[5].getZ(), yeet[5].getZ());
		glVertex3f(yeet[1].getX(), yeet[1].getZ(), yeet[1].getZ());

		glVertex3f(yeet[1].getX(), yeet[1].getZ(), yeet[1].getZ());
		glVertex3f(yeet[0].getX(), yeet[0].getZ(), yeet[0].getZ());
		glVertex3f(yeet[4].getX(), yeet[4].getZ(), yeet[4].getZ());

		//side1
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(yeet[1].getX(), yeet[1].getZ(), yeet[1].getZ());
		glVertex3f(yeet[5].getX(), yeet[5].getZ(), yeet[5].getZ());
		glVertex3f(yeet[6].getX(), yeet[6].getZ(), yeet[6].getZ());

		glVertex3f(yeet[6].getX(), yeet[6].getZ(), yeet[6].getZ());
		glVertex3f(yeet[2].getX(), yeet[2].getZ(), yeet[2].getZ());
		glVertex3f(yeet[1].getX(), yeet[1].getZ(), yeet[1].getZ());
		//side2
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(yeet[0].getX(), yeet[0].getZ(), yeet[0].getZ());
		glVertex3f(yeet[3].getX(), yeet[3].getZ(), yeet[3].getZ());
		glVertex3f(yeet[7].getX(), yeet[7].getZ(), yeet[7].getZ());

		glVertex3f(yeet[7].getX(), yeet[7].getZ(), yeet[7].getZ());
		glVertex3f(yeet[4].getX(), yeet[4].getZ(), yeet[4].getZ());
		glVertex3f(yeet[0].getX(), yeet[0].getZ(), yeet[0].getZ());
		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		/*rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}*/
	}
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis
	glTranslatef(0, 0, -8);
	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

