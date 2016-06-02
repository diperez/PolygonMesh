
#include "figura.h"

figura::figura()
{
}
void figura::boundingb()
{	 
	glBegin(GL_LINES);
	//cara de frente
	glVertex3f(this->maxs->vx,this->mins->vy,this->mins->vz);
	glVertex3f(this->maxs->vx,this->maxs->vy,this->mins->vz);
	glVertex3f(this->maxs->vx,this->maxs->vy,this->mins->vz);
	glVertex3f(this->mins->vx,this->maxs->vy,this->mins->vz);
	glVertex3f(this->mins->vx,this->maxs->vy,this->mins->vz);
	glVertex3f(this->mins->vx,this->mins->vy,this->mins->vz);
	glVertex3f(this->mins->vx,this->mins->vy,this->mins->vz);
	glVertex3f(this->maxs->vx,this->mins->vy,this->mins->vz);
	//cara de derecha
	glVertex3f(this->maxs->vx,this->mins->vy,this->maxs->vz);
	glVertex3f(this->maxs->vx,this->maxs->vy,this->maxs->vz);
	glVertex3f(this->maxs->vx,this->maxs->vy,this->maxs->vz);
	glVertex3f(this->maxs->vx,this->maxs->vy,this->mins->vz);
	glVertex3f(this->maxs->vx,this->maxs->vy,this->mins->vz);
	glVertex3f(this->maxs->vx,this->mins->vy,this->mins->vz);
	glVertex3f(this->maxs->vx,this->mins->vy,this->mins->vz);
	glVertex3f(this->maxs->vx,this->mins->vy,this->maxs->vz);
	
	//cara izq
	glVertex3f(this->mins->vx,this->mins->vy,this->maxs->vz);
	glVertex3f(this->mins->vx,this->maxs->vy,this->maxs->vz);
	glVertex3f(this->mins->vx,this->maxs->vy,this->maxs->vz);
	glVertex3f(this->mins->vx,this->maxs->vy,this->mins->vz);
	glVertex3f(this->mins->vx,this->maxs->vy,this->mins->vz);
	glVertex3f(this->mins->vx,this->mins->vy,this->mins->vz);
	glVertex3f(this->mins->vx,this->mins->vy,this->mins->vz);
	glVertex3f(this->mins->vx,this->mins->vy,this->maxs->vz);
	//atraz
	glVertex3f(this->maxs->vx,this->mins->vy,this->maxs->vz);
	glVertex3f(this->maxs->vx,this->maxs->vy,this->maxs->vz);
	glVertex3f(this->maxs->vx,this->maxs->vy,this->maxs->vz);
	glVertex3f(this->mins->vx,this->maxs->vy,this->maxs->vz);
	glVertex3f(this->mins->vx,this->maxs->vy,this->maxs->vz);
	glVertex3f(this->mins->vx,this->mins->vy,this->maxs->vz);
	glVertex3f(this->mins->vx,this->mins->vy,this->maxs->vz);
	glVertex3f(this->maxs->vx,this->mins->vy,this->maxs->vz);
	glEnd();
}
void figura ::normales(bool tipo)
{
	if(!tipo)
	{
		printf("pintando con centro\n");
		for(unsigned int i = 0; i<caras.size();i++)
		{
			glBegin(GL_LINES);
			glColor3f(0.0f,0.0f,0.0f);
				glVertex3f(this->caras[i]->centro->vx,this->caras[i]->centro->vy,this->caras[i]->centro->vz);
				glVertex3f(this->caras[i]->centro->vx + this->caras[i]->normal->vx, this->caras[i]->centro->vy +this->caras[i]->normal->vy,this->caras[i]->centro->vz+this->caras[i]->normal->vz);
			glEnd();
		}
	}else
	{
		printf("pintando con vertices\n");
		for(unsigned int i = 0; i<v.size();i++)
		{
			glBegin(GL_LINES);
			glColor3f(0.0f,1.0f,0.0f);
			glVertex3f(this->v[i]->vx,this->v[i]->vy,this->v[i]->vz);
			glVertex3f(this->v[i]->vx+ this->gnormales[i]->vx,this->v[i]->vy+ this->gnormales[i]->vy,this->v[i]->vz+ this->gnormales[i]->vz);
			glEnd();
		}
	}
	
}
void figura::Draw2(bool norm,bool bb,bool tipo, float r, float g, float b)
{
	glPushMatrix();
	int k=0;
	for(unsigned int i=0;i<caras.size(); i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(r,g,b);
		int n=caras[i]->n;
		for(int j=0;j <n;j++)
		{
			if(tipo)
			{
				glNormal3f(this->gnormales[this->caras[i]->c[j]]->vx,this->gnormales[this->caras[i]->c[j]]->vy,this->gnormales[this->caras[i]->c[j]]->vz);
			}else{
				glNormal3f(this->caras[i]->normal->vx,this->caras[i]->normal->vy,this->caras[i]->normal->vz);
			}
			glVertex3f(this->v[this->caras[i]->c[j]]->vx,this->v[this->caras[i]->c[j]]->vy,this->v[this->caras[i]->c[j]]->vz);
		}
		glEnd();
		k++;
	}
	if(norm)
	{
		normales(tipo);
	}
	if(bb)
	{
		boundingb();
	}
	glPopMatrix();
}
void figura::Draw(float angle,float *trans,float scalex, float scaley, float scalez,float translatex,float translatey,float translatez,bool norm)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	//glGetFloatv(GL_MODELVIEW_MATRIX,trans);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(translatex,translatey,translatez);
	glRotatef(angle,this->rotar->vx,this->rotar->vy,this->rotar->vz);
	glTranslatef(-translatex,-translatey,-translatez);
	glMultMatrixf(trans);
	glGetFloatv(GL_MODELVIEW_MATRIX,trans);
	glScalef(scalex,scaley,scalez);
	Draw2(norm,norm,norm,1.0,1.0,1.0);
	if(norm)
	{
		normales(norm);
	}

	glPopMatrix();

}

void figura::normalizar(float norm)
{
	printf("normalizacion con %f \n", norm);
	this->centro=new punto();

	this->maxs->vx = this->maxs->vx/norm;
	this->maxs->vy = this->maxs->vy/norm;
	this->maxs->vz = this->maxs->vz/norm;
	
	this->mins->vx = this->mins->vx/norm;
	this->mins->vy = this->mins->vy/norm;
	this->mins->vz = this->mins->vz/norm;

	this->centro->vx = ((this->maxs->vx + this->mins->vx)/2);
	this->centro->vy = ((this->maxs->vy + this->mins->vy)/2);
	this->centro->vz = ((this->maxs->vz + this->mins->vz)/2);
	printf("centro x =%f , centro y=%f , centro z =%f\n ",this->centro->vx,this->centro->vy,this->centro->vz);
	for(unsigned int i=0; i< this->v.size(); i++)
	{
		this->v[i]->vx = (this->v[i]->vx/norm) - this->centro->vx;
		this->v[i]->vy = (this->v[i]->vy/norm) - this->centro->vy;
		this->v[i]->vz = (this->v[i]->vz/norm) - this->centro->vz;
	}
	this->maxs->vx -= this->centro->vx;
	this->maxs->vy -= this->centro->vy;
	this->maxs->vz -= this->centro->vz;
	
	this->mins->vx -= this->centro->vx;
	this->mins->vy -= this->centro->vy;
	this->mins->vz -= this->centro->vz;
}