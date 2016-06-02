/*
Autor : Diego A Perez A
CI : 19754458
*/

#include <iostream>
#include <fstream>
#include "figura.h"
figura * fig;float angle=0.0;
punto * inicio_r;
punto * fin_r;
punto * aux;
punto * aux2;
cara * caraaux;
int distanciax =0;int distanciay=0; int distanciaanteriorx=0; int distanciaanteriory=0;
int antex =0, antey=0;
int num=0;int escalari=0;
int despliegue=1;
bool inicio=true;bool iluminado=true;
bool rotar=false;bool escalar=false;bool trasladar=false;bool xpisado=false;bool ypisado=false;bool zpisado=false;bool normales=false; bool bb=false;
bool pintar =false,tipo=true;bool ortopara=false;bool antiA=false;bool moverl1=false;bool moverl2=false;
float r =0.0, g = 0.0, b=1.0;
float r1 = 0.0, g1 =0.0, b1=0.0;
float r2 = 0.0, g2 =0.0, b2=0.0;
GLfloat specReflection[] = { 0.8f, 0.8f, 0.8f, 1.0f };

GLfloat light_ambient[] = {0.0f,0.0f,0.0f,0.0f};
GLfloat light_diffuse[] = {0.0f,1.0f,0.0f,0.0f};
GLfloat light_specular[] = {1.0f,1.0f,1.0f,0.0f};
GLfloat light_position[] = {0.5f,0.0f,0.25f,0.0f};

GLfloat light_ambient1[] = {0.0f,0.0f,0.0f,0.0f};
GLfloat light_diffuse1[] = {0.0f,0.0f,1.0f,0.0f};
GLfloat light_specular1[] = {1.0f,1.0f,1.0f,0.0f};
GLfloat light_position1[] = {-0.5f,0.0f,0.25f,0.0f};

static GLint fogMode;

float trans [16]= {1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0};
float scalex=1.0, scaley=1.0, scalez=1.0;
float translatex=0.0, translatey=0.0, translatez=0.0;
float translatexr=0.0, translateyr=0.0, translatezr=0.0;
float Abs(float x)
{
	if(x > 0)
		return(x);
	else
		return (-x);
}
void comienzo()
{
	glPushMatrix();
	fig->Draw2(normales,bb,tipo,r,g,b);
	glPushMatrix();
	if(iluminado)
	{
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glTranslatef(light_position[0],light_position[1],light_position[2]);
		glColor3f(0.0f,0.0f,0.0f);
		glutSolidSphere(0.02,100,100);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glTranslatef(light_position1[0],light_position1[1],light_position1[2]);
		glColor3f(0.0f,0.0f,0.0f);
		glutSolidSphere(0.02,100,100);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}
	glPopMatrix();
}
void flat()
{
	glShadeModel(GL_FLAT);
	tipo =false;
}
void gouraud()
{
	glShadeModel(GL_SMOOTH);
	tipo = true;
}
void fog()
{
	printf("fog\n");
	 glEnable(GL_FOG);
   {
      GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};

      fogMode = GL_EXP;
      glFogi (GL_FOG_MODE, fogMode);
      glFogfv (GL_FOG_COLOR, fogColor);
      glFogf (GL_FOG_DENSITY, 0.35);
      glHint (GL_FOG_HINT, GL_DONT_CARE);
      glFogf (GL_FOG_START, 1.0);
      glFogf (GL_FOG_END, 5.0);
   }
	glClearColor (0.5, 0.5, 0.5, 0.0);
}
void desactivarfog()
{
	glDisable(GL_FOG);
	glClearColor (1.0, 1.0, 1.0, 0.0);
}
void Escalar(float scalex, float scaley, float scalez)
{
	inicio=false;
	glPushMatrix();
	glLoadIdentity();
	if(iluminado)
	{
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glTranslatef(light_position[0],light_position[1],light_position[2]);
		glColor3f(0.0f,0.0f,0.0f);
		glutSolidSphere(0.02,100,100);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glTranslatef(light_position1[0],light_position1[1],light_position1[2]);
		glColor3f(0.0f,0.0f,0.0f);
		glutSolidSphere(0.02,100,100);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}
	glTranslatef(translatexr,translateyr,translatezr);
	glScalef(scalex,scaley,scalez);
	glTranslatef(-translatexr,-translateyr,-translatezr);
	glMultMatrixf(trans);
	glGetFloatv(GL_MODELVIEW_MATRIX,trans);
	fig->Draw2(normales,bb,tipo,r,g,b);
	glPopMatrix();
}
void Trasladar(float translatex,float translatey,float translatez)
{
	inicio=false;
	glPushMatrix();
	glLoadIdentity();
	glPushMatrix();
	if(iluminado)
	{
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glTranslatef(light_position[0],light_position[1],light_position[2]);
		glColor3f(0.0f,0.0f,0.0f);
		glutSolidSphere(0.02,100,100);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glTranslatef(light_position1[0],light_position1[1],light_position1[2]);
		glColor3f(0.0f,0.0f,0.0f);
		glutSolidSphere(0.02,100,100);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}
	glTranslatef(translatex,translatey,translatez);
	glMultMatrixf(trans);
	glGetFloatv(GL_MODELVIEW_MATRIX,trans);
	fig->Draw2(normales,bb,tipo,r,g,b);
	glPopMatrix();
}
void Rotar(float angle)
{
	inicio=false;
	glPushMatrix();
	glLoadIdentity();
	glPushMatrix();
	if(iluminado)
	{
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glTranslatef(light_position[0],light_position[1],light_position[2]);
		glColor3f(0.0f,0.0f,0.0f);
		glutSolidSphere(0.02,100,100);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glTranslatef(light_position1[0],light_position1[1],light_position1[2]);
		glColor3f(0.0f,0.0f,0.0f);
		glutSolidSphere(0.02,100,100);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}
	glTranslatef(translatexr,translateyr,translatezr);
	glRotatef(angle,fig->rotar->vx,fig->rotar->vy,fig->rotar->vz);
	glTranslatef(-translatexr,-translateyr,-translatezr);
	glMultMatrixf(trans);
	glGetFloatv(GL_MODELVIEW_MATRIX,trans);
	fig->Draw2(normales,bb,tipo,r,g,b);
	glPopMatrix();
}
float max(float a,float b)
{
	if(a > b)
		return(a);
	else
		return (b);
}
float GlutToOpenglx(float x)
{
		int auxx=glutGet(GLUT_WINDOW_WIDTH)>>1;
		//printf("%d\n",auxx);
		x=(x/auxx) - 1;
		//x = (float)(2*x-(glutGet(GLUT_WINDOW_WIDTH)-1) )/(glutGet(GLUT_WINDOW_WIDTH)-1);
		return x;
}
void anti()
{
	printf("activando anti\n");
	glBlendFunc (GL_SRC_ALPHA_SATURATE, GL_ONE_MINUS_SRC_ALPHA);
	antiA=true;
}
void desanti()
{
	antiA=false;
}
float GlutToOpengly(float y)
{
		int auxy=glutGet(GLUT_WINDOW_HEIGHT)>>1;
		y=((y/auxy)-1)*-1;
		//y= (float)((glutGet(GLUT_WINDOW_HEIGHT)-1)-2*y)/(glutGet(GLUT_WINDOW_HEIGHT)-1);
		return y;
}
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	if(ortopara)
	{
		glOrtho (-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 100.0f);
	}else
	{
		gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,500.0f);
	}
	gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}
void menuApp(int value)
{
	if(value == 1)
	{
		bb=true;
	}
	if(value == 2)
	{
		bb=false;
	}
	if(value == 3)
	{
		normales=true;
		
	}
	if(value == 4)
	{
		normales=false;
	}
	if(value == 5)
	{
		ortopara=true;
		ReSizeGLScene(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));

	}
	if(value == 6)
	{
		ortopara=false;
		ReSizeGLScene(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
	}
	if(value == 7)
	{
		fog();
	}
	if(value == 8)
	{
		desactivarfog();
	}
	if(value == 9)
	{
		glEnable(GL_CULL_FACE);
	}
	if(value == 10)
	{
		glDisable(GL_CULL_FACE);
	}
	if(value == 11)
	{
		glEnable(GL_DEPTH_TEST);
	}
	if(value == 12)
	{
		glDisable(GL_DEPTH_TEST);
	}
	if(value == 13)
	{
		flat();
	}
	if(value == 14)
	{
		gouraud();
	}
	if(value == 15)
	{
		printf("activando anti\n");
		anti();
	}
	if(value == 16)
	{
		desanti();
	}
	if(value == 17)
	{
		glEnable(GL_LIGHTING);
		iluminado=true;
	}
	if(value == 18)
	{
		glDisable(GL_LIGHTING);
		iluminado=false;
	}
	if(value==19)
	{
		glEnable(GL_COLOR_MATERIAL);
	}
	if(value==20)
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING);
	}
	if(value==21)
	{
		exit(0);
	}
	pintar=true;
}
void menuApp2(int value)
{
	if(value == 1)
	{
		despliegue=1;
	}
	if(value == 2)
	{
		despliegue=2;
	}
	if(value == 3)
	{
		despliegue=3;
	}
	pintar=true;
}
void menuApp3(int value)
{
	if(value == 1)
	{
		r=1.0;g=1.0;b=1.0;
	}
	if(value == 2)
	{
		r=1.0;g=1.0;b=0.0;
	}
	if(value == 3)
	{
		r=0.0;g=1.0;b=0.0;
	}
	if(value == 4)
	{
		r=0.0;g=1.0;b=1.0;
	}
	if(value == 5)
	{
		r=0.0;g=0.0;b=1.0;
	}
	if(value == 6)
	{
		r=1.0;g=0.0;b=1.0;
	}
	if(value == 7)
	{
		r=1.0;g=0.0;b=0.0;
	}
	pintar=true;
}
void menu_luz1(int value)
{
	if(value ==1)
	{
		glDisable(GL_LIGHT0);
	}
	if(value ==2)
	{
		glEnable(GL_LIGHT0);
	}
	if(value ==3)
	{
		moverl1=true;
		moverl2=false;
	}
	pintar=true;
}
void menu_luz2(int value)
{
	if(value ==1)
	{
		glDisable(GL_LIGHT1);
	}
	if(value ==2)
	{
		glEnable(GL_LIGHT1);
	}
	if(value ==3)
	{
		moverl1=false;
		moverl2=true;
	}
	pintar=true;
}
void menu_difusa_l1(int value)
{
	if(value == 1)
	{
		r1=1.0;g1=1.0;b1=1.0;
	}
	if(value == 2)
	{
		r1=1.0;g1=1.0;b1=0.0;
	}
	if(value == 3)
	{
		r1=0.0;g1=1.0;b1=0.0;
	}
	if(value == 4)
	{
		r1=0.0;g1=1.0;b1=1.0;
	}
	if(value == 5)
	{
		r1=0.0;g1=0.0;b1=1.0;
	}
	if(value == 6)
	{
		r1=1.0;g1=0.0;b1=1.0;
	}
	if(value == 7)
	{
		r1=1.0;g1=0.0;b1=0.0;
	}
	light_diffuse[0]=r1;light_diffuse[1]=g1;light_diffuse[2]=b1;
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	pintar=true;
}
void menu_ambiental_l1(int value)
{
	if(value == 1)
	{
		r1=1.0;g1=1.0;b1=1.0;
	}
	if(value == 2)
	{
		r1=1.0;g1=1.0;b1=0.0;
	}
	if(value == 3)
	{
		r1=0.0;g1=1.0;b1=0.0;
	}
	if(value == 4)
	{
		r1=0.0;g1=1.0;b1=1.0;
	}
	if(value == 5)
	{
		r1=0.0;g1=0.0;b1=1.0;
	}
	if(value == 6)
	{
		r1=1.0;g1=0.0;b1=1.0;
	}
	if(value == 7)
	{
		r1=1.0;g1=0.0;b1=0.0;
	}
	light_ambient[0]=r1;light_ambient[1]=g1;light_ambient[2]=b1;
	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	pintar=true;
}
void menu_especular_l1(int value)
{
	if(value == 1)
	{
		r1=1.0;g1=1.0;b1=1.0;
	}
	if(value == 2)
	{
		r1=1.0;g1=1.0;b1=0.0;
	}
	if(value == 3)
	{
		r1=0.0;g1=1.0;b1=0.0;
	}
	if(value == 4)
	{
		r1=0.0;g1=1.0;b1=1.0;
	}
	if(value == 5)
	{
		r1=0.0;g1=0.0;b1=1.0;
	}
	if(value == 6)
	{
		r1=1.0;g1=0.0;b1=1.0;
	}
	if(value == 7)
	{
		r1=1.0;g1=0.0;b1=0.0;
	}
	light_specular[0]=r1;light_specular[1]=g1;light_specular[2]=b1;
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
	pintar=true;
}
void menu_difusa_l2(int value)
{
	if(value == 1)
	{
		r1=1.0;g1=1.0;b1=1.0;
	}
	if(value == 2)
	{
		r1=1.0;g1=1.0;b1=0.0;
	}
	if(value == 3)
	{
		r1=0.0;g1=1.0;b1=0.0;
	}
	if(value == 4)
	{
		r1=0.0;g1=1.0;b1=1.0;
	}
	if(value == 5)
	{
		r1=0.0;g1=0.0;b1=1.0;
	}
	if(value == 6)
	{
		r1=1.0;g1=0.0;b1=1.0;
	}
	if(value == 7)
	{
		r1=1.0;g1=0.0;b1=0.0;
	}
	light_diffuse1[0]=r1;light_diffuse1[1]=g1;light_diffuse1[2]=b1;
	glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse1);
	pintar=true;
}
void menu_ambiental_l2(int value)
{
	if(value == 1)
	{
		r1=1.0;g1=1.0;b1=1.0;
	}
	if(value == 2)
	{
		r1=1.0;g1=1.0;b1=0.0;
	}
	if(value == 3)
	{
		r1=0.0;g1=1.0;b1=0.0;
	}
	if(value == 4)
	{
		r1=0.0;g1=1.0;b1=1.0;
	}
	if(value == 5)
	{
		r1=0.0;g1=0.0;b1=1.0;
	}
	if(value == 6)
	{
		r1=1.0;g1=0.0;b1=1.0;
	}
	if(value == 7)
	{
		r1=1.0;g1=0.0;b1=0.0;
	}
	light_ambient1[0]=r1;light_ambient1[1]=g1;light_ambient1[2]=b1;
	glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient1);
	pintar=true;
}
void menu_especular_l2(int value)
{
	if(value == 1)
	{
		r1=1.0;g1=1.0;b1=1.0;
	}
	if(value == 2)
	{
		r1=1.0;g1=1.0;b1=0.0;
	}
	if(value == 3)
	{
		r1=0.0;g1=1.0;b1=0.0;
	}
	if(value == 4)
	{
		r1=0.0;g1=1.0;b1=1.0;
	}
	if(value == 5)
	{
		r1=0.0;g1=0.0;b1=1.0;
	}
	if(value == 6)
	{
		r1=1.0;g1=0.0;b1=1.0;
	}
	if(value == 7)
	{
		r1=1.0;g1=0.0;b1=0.0;
	}
	light_specular1[0]=r1;light_specular1[1]=g1;light_specular1[2]=b1;
	glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular1);
	pintar=true;
}
void init()
{
	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);

	glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse1);
	glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular1);
	glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
	
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specReflection);
	glMateriali(GL_FRONT, GL_SHININESS, 10.0f);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

}
void renderScene (void)
{
	void init();
	{
		int submenu_despliegue, submenu_color_objeto,submenu_luz1, submenu_luz2,diffusa_l1, ambiental_l1, especular_l1, modificar_color;
		int diffusa_l2, ambiental_l2, especular_l2,modificar_color2;
		diffusa_l1 = glutCreateMenu(menu_difusa_l1);
		glutAddMenuEntry ("Blanco",1);
		glutAddMenuEntry ("Amarillo",2);
		glutAddMenuEntry ("Verde",3);
		glutAddMenuEntry ("Cyan",4);
		glutAddMenuEntry ("Azul",5);
		glutAddMenuEntry ("Magenta",6);
		glutAddMenuEntry ("Rojo",7);
		ambiental_l1 = glutCreateMenu(menu_ambiental_l1);
		glutAddMenuEntry ("Blanco",1);
		glutAddMenuEntry ("Amarillo",2);
		glutAddMenuEntry ("Verde",3);
		glutAddMenuEntry ("Cyan",4);
		glutAddMenuEntry ("Azul",5);
		glutAddMenuEntry ("Magenta",6);
		glutAddMenuEntry ("Rojo",7);
		especular_l1=glutCreateMenu(menu_especular_l1);
		glutAddMenuEntry ("Blanco",1);
		glutAddMenuEntry ("Amarillo",2);
		glutAddMenuEntry ("Verde",3);
		glutAddMenuEntry ("Cyan",4);
		glutAddMenuEntry ("Azul",5);
		glutAddMenuEntry ("Magenta",6);
		glutAddMenuEntry ("Rojo",7);

		diffusa_l2 = glutCreateMenu(menu_difusa_l2);
		glutAddMenuEntry ("Blanco",1);
		glutAddMenuEntry ("Amarillo",2);
		glutAddMenuEntry ("Verde",3);
		glutAddMenuEntry ("Cyan",4);
		glutAddMenuEntry ("Azul",5);
		glutAddMenuEntry ("Magenta",6);
		glutAddMenuEntry ("Rojo",7);
		ambiental_l2 = glutCreateMenu(menu_ambiental_l2);
		glutAddMenuEntry ("Blanco",1);
		glutAddMenuEntry ("Amarillo",2);
		glutAddMenuEntry ("Verde",3);
		glutAddMenuEntry ("Cyan",4);
		glutAddMenuEntry ("Azul",5);
		glutAddMenuEntry ("Magenta",6);
		glutAddMenuEntry ("Rojo",7);
		especular_l2=glutCreateMenu(menu_especular_l2);
		glutAddMenuEntry ("Blanco",1);
		glutAddMenuEntry ("Amarillo",2);
		glutAddMenuEntry ("Verde",3);
		glutAddMenuEntry ("Cyan",4);
		glutAddMenuEntry ("Azul",5);
		glutAddMenuEntry ("Magenta",6);
		glutAddMenuEntry ("Rojo",7);

		modificar_color = glutCreateMenu(menu_luz1);
		glutAddSubMenu ("Difusa",diffusa_l1);
		glutAddSubMenu ("Especular",especular_l1);
		glutAddSubMenu ("Ambiental",ambiental_l1);

		modificar_color2 = glutCreateMenu(menu_luz1);
		glutAddSubMenu ("Difusa",diffusa_l2);
		glutAddSubMenu ("Especular",especular_l2);
		glutAddSubMenu ("Ambiental",ambiental_l2);

		submenu_luz1=glutCreateMenu(menu_luz1);
		glutAddMenuEntry ("Apagar luz",1);
		glutAddMenuEntry ("Prender luz",2);
		glutAddMenuEntry ("Mover luz",3);
		glutAddSubMenu ("Color",modificar_color);

		submenu_luz2=glutCreateMenu(menu_luz2);
		glutAddMenuEntry ("Apagar luz",1);
		glutAddMenuEntry ("Prender luz",2);
		glutAddMenuEntry ("Mover luz",3);
		glutAddSubMenu ("Color",modificar_color2);

		submenu_despliegue=glutCreateMenu(menuApp2);
		glutAddMenuEntry ("Relleno",1);
		glutAddMenuEntry ("Mallado",2);
		glutAddMenuEntry ("Puntos",3);

		submenu_color_objeto=glutCreateMenu(menuApp3);
		glutAddMenuEntry ("Blanco",1);
		glutAddMenuEntry ("Amarillo",2);
		glutAddMenuEntry ("Verde",3);
		glutAddMenuEntry ("Cyan",4);
		glutAddMenuEntry ("Azul",5);
		glutAddMenuEntry ("Magenta",6);
		glutAddMenuEntry ("Rojo",7);
		glutCreateMenu (menuApp);
		glutAddMenuEntry ("Mostrar Bounding Box",1);
		glutAddMenuEntry ("Ocultar Bounding Box",2);
		glutAddMenuEntry ("Mostrar Vector Normal",3);
		glutAddMenuEntry ("Ocultar Vector Normal",4);
		glutAddMenuEntry ("Activar Proyeccion Ortogonal",5);
		glutAddMenuEntry ("Activar Proyeccion Paralela",6);
		glutAddMenuEntry ("Mostrar Fog",7);
		glutAddMenuEntry ("Ocultar Fog",8);
		glutAddMenuEntry ("Activar BackFace Culling",9);
		glutAddMenuEntry ("Desactivar BackFace Culling",10);
		glutAddMenuEntry ("Activar Zbuffer",11);
		glutAddMenuEntry ("Desactivar Zbuffer",12);
		glutAddMenuEntry ("Activar sombreado flat",13);
		glutAddMenuEntry ("Activar sombreado gouraud",14);
		glutAddMenuEntry ("Activar antiallising",15);
		glutAddMenuEntry ("Desactivar antiallising",16);
		glutAddMenuEntry ("Activar iluminado",17);
		glutAddMenuEntry ("Desactivar iluminado",18);
		glutAddSubMenu ("Despliegue",submenu_despliegue);
		glutAddSubMenu ("Color Objeto",submenu_color_objeto);
		glutAddSubMenu ("Luz 1",submenu_luz1);
		glutAddSubMenu ("Luz 2",submenu_luz2);
		glutAddMenuEntry ("Salir",21);
		glutAttachMenu (GLUT_RIGHT_BUTTON);
	}
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(antiA)
	{
		glEnable (GL_BLEND);
		glEnable (GL_POLYGON_SMOOTH);
		
		printf("activando anti render\n");
	}else
	{
		glDisable (GL_BLEND);
	}	
	if(despliegue == 1)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	if(despliegue == 2)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	if(despliegue == 3)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	}
	if(inicio)
		comienzo();
	if(escalar)
		Escalar(scalex,scaley,scalez);
	if(rotar)
		Rotar(angle);
	if(trasladar)
		Trasladar(translatex,translatey,translatez);

	glutSwapBuffers();
}
void processSpecialKeys(int key, int x, int y) {
	
}

void pasivo (int x, int y)
{
	xpisado=false;ypisado=false;zpisado=false;
	if(pintar)
	{
		renderScene();
		pintar=false;
	}

}
void teclado (unsigned char key, int x, int y)
{
	if(key == 120)
	{
		xpisado=true;
	}
	if(key == 121)
	{
		ypisado=true;
	}
	if(key == 122)
	{
		zpisado=true;
	}
	if(key == 49)
	{
		glDisable(GL_LIGHT0);
		renderScene();
	}
	if(key == 50)
	{
		glEnable(GL_LIGHT0);
		renderScene();
	}
	if(key == 51)
	{
		glDisable(GL_LIGHT1);
		renderScene();
	}
	if(key == 52)
	{
		glEnable(GL_LIGHT1);
		renderScene();
	}
	if(key == 100)
	{
		translatex+=0.1;
		translatexr+=0.1;
		trasladar=true;
		rotar=false;
		escalar=false;
		inicio=false;
		renderScene();
		translatex=0.0;
	}
	if(key == 97)
	{
		translatex-=0.1;
		translatexr-=0.1;
		trasladar=true;
		rotar=false;
		escalar=false;
		inicio=false;
		renderScene();
		translatex=0.0;
	}
	if(key == 115)
	{
		translatey-=0.1;
		translateyr-=0.1;
		trasladar=true;
		rotar=false;
		escalar=false;
		inicio=false;
		renderScene();
		translatey=0.0;
	}
	if(key == 119)
	{
		translatey+=0.1;
		translateyr+=0.1;
		trasladar=true;
		rotar=false;
		escalar=false;
		renderScene();
		translatey=0.0;
	}
	if(key == 101)
	{
		translatez-=0.1;
		translatezr-=0.1;
		trasladar=true;
		rotar=false;
		escalar=false;
		renderScene();
		translatez=0.0;
	}
	if(key == 99)
	{
		translatez+=0.1;
		translatezr+=0.1;
		trasladar=true;
		rotar=false;
		escalar=false;
		inicio=false;
		renderScene(); 
		translatez=0.0;
	}
	if(key == 104)//h
	{
		if(moverl1)
		{
			light_position[0]-=0.1;
			glLightfv(GL_LIGHT0,GL_POSITION,light_position);
			renderScene();
		}
		if(moverl2)
		{
			light_position1[0]-=0.1;
			glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
			renderScene();
		}
	}
	if(key == 107)//k
	{
		if(moverl1)
		{
			light_position[0]+=0.1;
			glLightfv(GL_LIGHT0,GL_POSITION,light_position);
			renderScene();
		}
		if(moverl2)
		{
			light_position1[0]+=0.1;
			glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
			renderScene();
		}
	}
	if(key == 106)//j
	{
		if(moverl1)
		{
			light_position[1]-=0.1;
			glLightfv(GL_LIGHT0,GL_POSITION,light_position);
			renderScene();
		}
		if(moverl2)
		{
			light_position1[1]-=0.1;
			glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
			renderScene();
		}
	}
	if(key == 117)//u
	{
		if(moverl1)
		{
			light_position[1]+=0.1;
			glLightfv(GL_LIGHT0,GL_POSITION,light_position);
			renderScene();
		}
		if(moverl2)
		{
			light_position1[1]+=0.1;
			glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
			renderScene();
		}
	}
	if(key == 109)//m
	{
		
		if(moverl1)
		{
			light_position[2]+=0.1;
			glLightfv(GL_LIGHT0,GL_POSITION,light_position);
			renderScene();
		}
		if(moverl2)
		{
			light_position1[2]+=0.1;
			glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
			renderScene();
		}
	}
	if(key == 105)//i
	{
		if(moverl1)
		{
			light_position[2]-=0.1;
			glLightfv(GL_LIGHT0,GL_POSITION,light_position);
			renderScene();
		}
		if(moverl2)
		{
			light_position1[2]-=0.1;
			glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
			renderScene();
		}
	}
	printf("%d\n",key);
}
void click (int boton, int estado, int x, int y)
{
	if(boton == GLUT_MIDDLE_BUTTON)
	{
		if(estado==GLUT_UP)
		{
			scalex=scaley=scalez=1.0;
		}
		rotar = false;
		escalar=true;
		trasladar=false;
		num=0;
	}
	if(boton == GLUT_LEFT_BUTTON)
	{
		escalar=false;
		rotar = true;
		trasladar=false;
		num=0;
		angle=0;
	}
	if(estado==GLUT_UP)
	{
		glLoadIdentity();
		glLoadMatrixf(trans);
	}
	
}
void movimiento (int x, int y)
{
	if(rotar)
	{
		if(num % 3 == 0)
		{
			distanciaanteriorx=Abs(x - antex);
			distanciaanteriory=Abs(y - antey);
		}
		if(num==0)
		{
			inicio_r=new punto();
			fin_r=new punto();
			inicio_r->vx=GlutToOpenglx(x);
			inicio_r->vy=GlutToOpengly(y);
			inicio_r->vz=-1;
			antex = x;
			antey = y;
		}
		num++;
		distanciax = Abs(x - antex);
		distanciay = Abs(y - antey);
		if(distanciaanteriorx < distanciax || distanciaanteriory < distanciay)
		{
			num=0;
		}
		fin_r->vx=GlutToOpenglx(x);
		fin_r->vy=GlutToOpengly(y);
		fin_r->vz=-1;
		//calculando el vector
		aux->vx=(fin_r->vx - inicio_r->vx);
		aux->vy=(fin_r->vy - inicio_r->vy);
		aux->vz=-1;
		//angulo
		angle= -sqrt( pow(aux->vx,2) +  pow(aux->vy,2) + pow(aux->vz,2));
		//vector normal
		fig->rotar->vx= inicio_r->vy * fin_r->vz - inicio_r->vz * fin_r->vy;
		fig->rotar->vy=-( inicio_r->vx *  fin_r->vz - fin_r->vx * inicio_r->vz);
		fig->rotar->vz=(inicio_r->vx * fin_r->vy) - (inicio_r->vy * fin_r->vx);
		if(angle>=360)
			angle=0;
	}
	if(escalar)
	{
		if(num == 0)
		{
			escalari=y;
		}
		if(xpisado)
		{
			if(escalari < y)
			{
				scalex-=0.0001;
				if(scalex <0.0)
						{
							scalex=0.0;
						}
			}
			if(escalari>y)
				scalex+=0.0001;
		}else
		{
			if(ypisado)
			{
				if(escalari < y)
				{
					scaley-=0.0001;
					if(scaley <0.0)
					{
						scaley=0.0;
					}
				}
				if(escalari>y)
					scaley+=0.0001;
			}else
			{
				if(zpisado)
				{
					if(escalari < y)
					{
						scalez-=0.0001;
						if(scalez <0.0)
						{
							scalez=0.0;
						}
					}
					if(escalari>y)
						scalez+=0.0001;
				}else
				{
					if(escalari < y)
					{
						scalex-=0.0001;scaley-=0.0001;scalez-=0.0001;
						if(scalex <0.0)
						{
							scalex=0.0;
						}
						if(scaley <0.0)
						{
							scaley=0.0;
						}
						if(scalez <0.0)
						{
							scalez=0.0;
						}
					}
					if(escalari > y)
					{
						scalex+=0.0001;scaley+=0.0001;scalez+=0.0001;
					}
				}
			}
		}
		num++;
	}
	renderScene();
}

int main (int argc, char *argv [])
{
	int V, W, Z,cont,C;
	float maxX, minX, maxY, minY, maxZ, minZ,distx, disty, distz;;
	minX = minY = minZ =10000.0;
	maxX = maxY = maxZ = -100000.0;
	punto * A;
	punto * B;
	fig = new figura();
	char c [256];
	char d [1000];
	aux=new punto();
	aux2=new punto();
	printf("ruta y nombre del objeto a desplegar\n");
	scanf("%s",d);
	ifstream entrada(d);
	entrada.getline(c,100);
	entrada >> V >> W >> Z ;
	cont = V;
	for(int i=0;i<cont;i++)
	{
		A= new punto();
		entrada >> A->vx >> A->vy >> A->vz ;

		if(A->vx<minX)
			minX=A->vx;
		if(A->vx>maxX)
			maxX=A->vx;
		if(A->vy<minY)
			minY=A->vy;
		if(A->vy>maxY)
			maxY=A->vy;
		if(A->vz<minZ)
			minZ=A->vz;
		if(A->vz>maxZ)
			maxZ=A->vz;

		fig->v.push_back(A);

	}
	fig->maxs =new punto();
	fig->mins =new punto();
	fig->rotar=new punto();
	fig->mins->vx = minX;
	fig->mins->vy = minY;
	fig->mins->vz = minZ;
	fig->maxs->vx = maxX;
	fig->maxs->vy = maxY;
	fig->maxs->vz = maxZ;
	cont = W;

	distx = Abs(fig->maxs->vx - fig->mins->vx);
	disty = Abs(fig->maxs->vy - fig->mins->vx);
	distz = Abs(fig->maxs->vz - fig->mins->vz);
	fig->normalizar(max(max(distx,disty),distz));
	for(int i=0;i<W;i++)
	{
		entrada >> Z ;
		caraaux = new cara();
		caraaux->n = Z;
		//fig->c.push_back(Z);
		
		for(int j=0;j<Z;j++)
		{
			entrada >> C ;
			caraaux->c.push_back(C);
			//fig->c.push_back(C);
		}
		fig->caras.push_back(caraaux);
	}
	for(unsigned int i =0;i<fig->caras.size();i++)
	{
		A=new punto();
		//printf("p2 - p1\n");
		aux->vx = fig->v[fig->caras[i]->c[1]]->vx - fig->v[fig->caras[i]->c[0]]->vx;
		aux->vy = fig->v[fig->caras[i]->c[1]]->vy - fig->v[fig->caras[i]->c[0]]->vy;
		aux->vz = fig->v[fig->caras[i]->c[1]]->vz - fig->v[fig->caras[i]->c[0]]->vz;

		//printf("p3-p1");
		aux2->vx = fig->v[fig->caras[i]->c[2]]->vx - fig->v[fig->caras[i]->c[0]]->vx;
		aux2->vy = fig->v[fig->caras[i]->c[2]]->vy - fig->v[fig->caras[i]->c[0]]->vy;
		aux2->vz = fig->v[fig->caras[i]->c[2]]->vz - fig->v[fig->caras[i]->c[0]]->vz;
		
		//printf("vector p2 - p1 , x = %f, y= %f, z = %f\n",aux2->vx,aux2->vy,aux2->vz);
		//printf("vector p3 - p1 , x = %f, y= %f, z = %f\n",aux2->vx,aux2->vy,aux2->vz);

		A->vx = aux->vy * aux2->vz - aux->vz * aux2->vy;
		A->vy = aux->vz * aux2->vx - aux->vx * aux2->vz;
		A->vz = aux->vx * aux2->vy - aux->vy * aux2->vx;

		float norma = sqrt(pow(A->vx,2) + pow(A->vy,2) + pow(A->vz,2));

		B = new punto();
		B->vx=0.0;
		B->vy=0.0;
		B->vz=0.0;
		for(unsigned int j = 0; j< fig->caras[i]->c.size();j++)
		{
			B->vx += fig->v[fig->caras[i]->c[j]]->vx;
			B->vy += fig->v[fig->caras[i]->c[j]]->vy;
			B->vz += fig->v[fig->caras[i]->c[j]]->vz;
		}
		B->vx = B->vx/fig->caras[i]->c.size();
		B->vy = B->vy/fig->caras[i]->c.size();
		B->vz = B->vz/fig->caras[i]->c.size();
		A->vx = (float)A->vx/ (norma *10);
		A->vy = (float)A->vy / (norma * 10);
		A->vz = (float)A->vz / (norma * 10);
		fig->caras[i]->centro = B;
		fig->caras[i]->normal = A;
	}
	int l=0;
	for(unsigned int i=0;i<fig->v.size();i++)//recorrer puntos
	{
		A=new punto();
		A->vx=0.0;A->vy=0.0;A->vz=0.0;
		for(unsigned int j=0;j<fig->caras.size();j++)//recorrer caras
		{
			for(unsigned int k=0;k<fig->caras[j]->c.size();k++)
			{
				if(i == fig->caras[j]->c[k])
				{
					A->vx+=fig->caras[j]->normal->vx;
					A->vy+=fig->caras[j]->normal->vy;
					A->vz+=fig->caras[j]->normal->vz;
					l++;
				}

			}
		}
		A->vx = A->vx / l;
		A->vy = A->vy / l;
		A->vz = A->vz / l;
		fig->gnormales.push_back(A);
		l=0;
	}
	printf("%d\n",fig->gnormales.size());
	printf("%d\n",fig->caras.size());
	entrada.close();
	
	glutInit (&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ACCUM | GLUT_DEPTH);
	glutInitWindowPosition (100, 100);
	glutInitWindowSize (500, 500);
	glutCreateWindow ("Tarea#3");
	glClearColor(1.0,1.0,1.0,0.0);
	init();
	//glEnable(GL_LINE_STIPPLE);
	glutDisplayFunc (renderScene);
	glutReshapeFunc(ReSizeGLScene);
	glutMotionFunc(movimiento);
	glutMouseFunc(click);
	glutKeyboardFunc(teclado);
	glutSpecialFunc(processSpecialKeys); 
	glutPassiveMotionFunc(pasivo);
	glutMainLoop ();

}