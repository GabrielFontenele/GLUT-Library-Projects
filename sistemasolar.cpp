#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

GLfloat angle, fAspect;

float angloMercurio = 0;
float angloVenus = 0;
float angloTerra = 0;
float angloLua = 0;
float angloMarte = 0;
float angloJupiter = 0;
float angloSaturno = 0;
float angloUrano = 0;
float angloNetuno = 0;

float rotateX = 0;
float rotateY = 0;
float rotateZ = 0;

float eyex = 0;
float eyey = 200;
float eyez = 500;


void Estrelas(){
	
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	srand(0);
 	for (int t=0;t<500;t++){
	glVertex3d((rand() % 1000)-500,(rand() % 1000)-500,(rand() % 1000)-500);
	}
	
	glEnd();	
}

void Sol(){
	glColor3f(1,1,0);
	glutSolidSphere(15,16,16);
}

void Mercurio(){
	glColor3f(1,1,10);
	glutSolidSphere(3,16,16);
}

void Venus(){
	glColor3f(1,0,0);
	glutSolidSphere(4.5,16,16);
}

void Terra(){
	glColor3f(0,0,1);
	glutSolidSphere(5,16,16);
}

void Lua(){
	glColor3f(0.5,0.5,0.5);
	glutSolidSphere(1,16,16);
}

void Marte(){
	glColor3f(1,0.2,0);
	glutSolidSphere(3.70,16,16);
}

void Jupiter(){
	glColor3f(0.35, 0.29, 0.15);
	glutSolidSphere(9,16,16);
}

void Saturno(){
	glColor3f(0.235,0.224,0.082);
	glutSolidSphere(8.3,16,16);
}

void Anel(float cx, float cy, float r, int num_segments){
glColor3f(0.224,0.224,0.224);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);

    }
    glEnd();
}

void Urano(){
	glColor3f(0.5,0.5,1.5);
	glutSolidSphere(6.50,16,16);
}

void Netuno(){
	glColor3f(0.5,0.5,0.8);
	glutSolidSphere(6.40,16,16);
}

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float raio = 12;
	float raiox = 15;
	glLoadIdentity();
	gluLookAt(eyex,eyey,eyez,0,0,0,0,1,0);
	
	glRotatef(rotateX,1,0,0);
	glRotatef(rotateY,0,1,0);
	glRotatef(rotateZ,0,0,1);
	Estrelas();
	Sol();
		glPushMatrix();
	   	   	glRotatef(90,1,0,0);
	   	   	Anel(0,0,30,50);
	   	   	Anel(0,0,70,50);
	   	   	Anel(0,0,105,50);
	   	   	Anel(0,0,140,50);
	   	   	Anel(0,0,180,50);
	   	   	Anel(0,0,230,50);
 	   		Anel(0,0,280,50);
  			Anel(0,0,330,50);
	   	   	glPopMatrix();
		glPushMatrix();
			glRotatef(angloMercurio,0,1,0);
			glTranslatef(30,0,0);
			Mercurio();
			glPopMatrix();
		glPushMatrix();
			glRotatef(angloVenus,0,1,0);
			glTranslatef(70,0,0);
			Venus();
			glPopMatrix();
		glPushMatrix();
			glRotatef(angloTerra,0,1,0);
			glTranslatef(105,0,0);
			Terra();
			glPushMatrix();
				glRotatef(angloLua,0,1,0);
				glTranslatef(7,0,0);
				Lua();
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glRotatef(angloMarte,0,1,0);
			glTranslatef(140,0,0);
			Marte();
		glPopMatrix();			
		glPushMatrix();
			glRotatef(angloJupiter,0,1,0);
			glTranslatef(180,0,0);
			Jupiter();
			glPopMatrix();	
		glPushMatrix();
			glRotatef(angloSaturno,0,1,0);
			glTranslatef(230,0,0);
			Saturno();
			for(int i = 0; i <= 3 ;i++){
			glPushMatrix();
				glRotatef(45,1,0,0);
				glTranslatef(0,0,0);
			   	Anel(0,0,raio,50);
			glPopMatrix();
				raio = raio + 0.3;
			}
			for(int i = 0; i <= 15 ;i++){
			glPushMatrix();
				glRotatef(45,1,0,0);
				glTranslatef(0,0,0);
			   	Anel(0,0,raiox,50);
			glPopMatrix();
				raiox = raiox + 0.3;
			}
		glPopMatrix();		
		glPushMatrix();
			glRotatef(angloUrano,0,1,0);
			glTranslatef(280,0,0);
			Urano();
			glPopMatrix();		
		glPushMatrix();
			glRotatef(angloNetuno,0,1,0);
			glTranslatef(330,0,0);
			Netuno();
			glPopMatrix();	

glutSwapBuffers();		
}

void Inicializa (void){ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	  
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);  
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	angle=45;
}

void TimerFunction(int value){
	angloMercurio += 6;
	if(angloMercurio >= 360) angloMercurio = 0;
	
	angloVenus += 4;
	if(angloVenus >= 360) angloVenus = 0;

	angloTerra += 3;
	if(angloTerra >= 360) angloTerra = 0;
	
	angloLua += 6;
	if(angloLua >= 360 ) angloLua = 0;
	
	angloMarte += 1.5;
	if(angloMarte >= 360) angloMarte = 0;
	
	angloJupiter +=0.3;
	if(angloJupiter >= 360) angloJupiter = 0;
	
	angloSaturno +=0.25;
	if(angloJupiter >= 360) angloSaturno = 0;
	
	angloUrano +=0.18;
	if(angloUrano >= 360) angloUrano = 0;
	
	angloNetuno +=0.15;
	if(angloNetuno >= 360) angloNetuno = 0;
	
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction,1);
}

void EspecificaParametrosVisualizacao(void){
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(angle,fAspect,1,3000);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();


}
 
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	if ( h == 0 ) h = 1;

	glViewport(0, 0, w, h);
 
srand(time(NULL));
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

void SpecialKeys(int key, int x, int y){
		switch (key) {
			case GLUT_KEY_UP : 
							rotateX -=3;
							break;
			case GLUT_KEY_DOWN : 
							rotateX +=3;
							break;
			case GLUT_KEY_LEFT : 
							rotateY +=3;
							break;
			case GLUT_KEY_RIGHT : 
							rotateY -=3;
							break;
			case GLUT_KEY_HOME : 
							eyey +=10;
							break;
			case GLUT_KEY_END : 
							eyey -=10;
							break;
			case GLUT_KEY_PAGE_UP : 
							eyez -=10;
							break;
			case GLUT_KEY_PAGE_DOWN : 
							eyez +=10;
							break;				
		}
		glLoadIdentity();
        	glutPostRedisplay();
        }

int main(int argc, char *argv[]){
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500,1000);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	TimerFunction(0);
	glutSpecialFunc(SpecialKeys);
	Inicializa();
	glutMainLoop();	
}