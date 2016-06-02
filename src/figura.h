#pragma comment (lib, "lib/glut32.lib")
#include "cara.h"
#include <stdio.h>
#include <math.h>
#include "glut.h"
class figura
{	
	public:
		punto * mins;
		punto * maxs;
		punto * centro;
		punto * rotar;
		vector<punto*> v;
		vector<cara*> caras;
		vector <punto*> gnormales;
		figura();
		void normales(bool tipo);
		void boundingb();
		void Draw2(bool norm, bool bb,bool tipo,float r, float g, float b);
		void Draw(float angle,float * trans,float scalex, float scaley, float scalez,float translatex,float translatey,float translatez,bool normales);
		void Trasladar();
		void normalizar(float norm);
};