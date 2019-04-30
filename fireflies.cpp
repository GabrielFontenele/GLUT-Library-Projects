#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#define TRUE 1
#define FALSE 0
#define boolean int

GLfloat angle, fAspect;


float rotateX = 0;
float rotateY = 0;
float rotateZ = 0;

float eyex = 0;
float eyey = 125;
float eyez = 200;

float x = 0;
float y = 30;
int cont = 0;
int mUM = -1;



typedef struct no *pno;
typedef pno vag;

typedef struct no {
	int cor;
	int movR;
	float movD;
	float angloVag;
	float movH;

} Vag;

void criaVag(vag *a)
{
	*a = (pno)malloc(sizeof(struct no));
	(*a)->cor = 1;
	(*a)->movR = 1;
	(*a)->movD = 30;
	(*a)->angloVag = 0;
	(*a)->movH = 0;
}

vag g;
vag g1;
vag g2;
vag g3;
vag g4;


void Estrelas()
{

	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	srand(0);
	for (int t = 0; t < 500; t++) {
		glVertex3d((rand() % 1000) - 500, (rand() % 1000) - 500, (rand() % 1000) - 500);
	}

	glEnd();
}



void Anel(float cx, float cy, float r, int num_segments)
{

	for(int i = 0; i < num_segments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);

	}

}


void VagM(int seed, int h, vag *a)
{
	srand(GetTickCount() + seed);

	glRotatef((*a)->angloVag, 0, 1, 0);
	glTranslatef((*a)->movD, h, 0);




	if( 1 == (rand() % 120))
		(*a)->movR = (*a)->movR * mUM;


	if( 1 == (rand() % 4)) {
		if( 1 == (rand() % 2) && (*a)->movD < 100) {
			(*a)->movD += 1;
		} else {
			if((*a)->movD > 0)
				(*a)->movD += -1;


		}
	}

	if((*a)->movR == 1) {
		(*a)->angloVag = (*a)->angloVag + 2.5;
	} else {
		(*a)->angloVag = (*a)->angloVag - 2.5;
	}



	if((*a)->angloVag >= 360) (*a)->angloVag = 0;


	glColor3f(0, 0, 0);
	if( 1 == (rand() % 10)) {
		glColor3f(1, 1, 0);

		/*GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0};
		GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};
		GLfloat luzEspecular[4] = {1, 1, 1, 1.0};
		GLfloat posicaoLuz[4] = {0.0, 50.0, 50.0, 1.0};

		GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};


		GLint especMaterial = 60;

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		glShadeModel(GL_SMOOTH);

		glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

		glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

		glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
		glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
		glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);
*/

	}
	
	
	glutSolidSphere(1, 16, 16);
	
	glRotated(90,0,1,0);
		glPushMatrix();
		
		glRotated(45,1,0,0);
 	    glTranslated(0,1,0);
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		Anel(0,0,0.5,300);
		glEnd();
	  	glPopMatrix();
	  	
	glPushMatrix();
		
		glRotated(-45,1,0,0);
 	    glTranslated(0,1,0);
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		Anel(0,0,0.5,300);
		glEnd();
	  	glPopMatrix();
}


void Luz()
{
	glPushMatrix();
	
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	
	glTranslated(0, -10, 0);
	glRotated(90, 1, 0, 0);

	glColor3f(0.199, 0, 1);
	
	gluCylinder(qobj, 2.2, 2.2, 25, 25, 25);
	
	
		for (int u = 0; u <= 360; u=u+12){
			glPushMatrix();
			glColor3f(0.144, 0.144, 0.144);
			glRotatef(u,0,0,1);
		   	glTranslated(9.7, 0, 0);
			
		   	gluCylinder(qobj, 0.3, 0.3, 25, 25, 25);
			   	   glPopMatrix();
		}

	glPushMatrix();
	
	glColor3f(0.144, 0.144, 0.144);
	glBegin(GL_POLYGON);
	Anel(0, 0, 10, 200);
	glEnd();
	
	glPushMatrix();
	
	glTranslated(0, 0, 25);
	glColor3f(0.144, 0.144, 0.144);
	glBegin(GL_POLYGON);
	Anel(0, 0, 10, 200);
	
	glEnd();
		
	glutSolidTorus(0.7,9.8,25,25);


	
	
	glPopMatrix();
	
	glutSolidTorus(0.7,9.8,25,25);

	glPopMatrix();
}





void Desenha(void)
{







	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);

	glRotatef(rotateX, 1, 0, 0);
	glRotatef(rotateY, 0, 1, 0);
	glRotatef(rotateZ, 0, 0, 1);

	glColor3f(0.0, 0.1020, 0.0);


	glPushMatrix();

	glTranslated(-100, -50, -100);
	int h = 2;
	for (int n = 0; n < 200; n = n + h) {
		for (int b = 0; b < 200; b = b + h) {

			glBegin(GL_POLYGON);

			glVertex3d(n, 0, b);
			glVertex3d(n, 0, b + h);
			glVertex3d(n + h, 0, b + h);
			glVertex3d(n + h, 0, b);

			glEnd();

		}

	}

	glPopMatrix();


	Estrelas();

	glPushMatrix();
		Luz();
		glPopMatrix();
		
		
	glPushMatrix();
		VagM(1, -20, &g);
		glPopMatrix();
	glPushMatrix();
		VagM(2, -30, &g1);
		glPopMatrix();
	glPushMatrix();
		VagM(3, -20, &g2);
		glPopMatrix();
	glPushMatrix();
		VagM(4, -20, &g3);
		glPopMatrix();
	glPushMatrix();
		VagM(5, 0, &g4);
		glPopMatrix();





	glutSwapBuffers();
}

void Inicializa (void)
{

	criaVag(&g);
	criaVag(&g1);
	criaVag(&g2);
	criaVag(&g3);
	criaVag(&g4);

	GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0};
	GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};
	GLfloat luzEspecular[4] = {1, 1, 1, 1.0};
	GLfloat posicaoLuz[4] = {0.0, 50.0, 50.0, 1.0};

	GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
	GLint especMaterial = 60;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	angle = 45;
}

void TimerFunction(int value)
{

	glutPostRedisplay();
	glutTimerFunc(33 , TimerFunction, 1);
}

void EspecificaParametrosVisualizacao(void)
{
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(angle, fAspect, 1, 3000);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();


}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	if ( h == 0 ) h = 1;

	glViewport(0, 0, w, h);


	fAspect = (GLfloat)w / (GLfloat)h;

	EspecificaParametrosVisualizacao();
}

void SpecialKeys(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP :
		rotateX -= 3;
		break;
	case GLUT_KEY_DOWN :
		rotateX += 3;
		break;
	case GLUT_KEY_LEFT :
		rotateY += 3;
		break;
	case GLUT_KEY_RIGHT :
		rotateY -= 3;
		break;
	case GLUT_KEY_HOME :
		eyey += 10;
		break;
	case GLUT_KEY_END :
		eyey -= 10;
		break;
	case GLUT_KEY_PAGE_UP :
		eyez -= 10;
		break;
	case GLUT_KEY_PAGE_DOWN :
		eyez += 10;
		break;
	}
	glLoadIdentity();
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1600, 900);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	TimerFunction(500);
	glutSpecialFunc(SpecialKeys);
	Inicializa();
	glutMainLoop();
}
