#include"Star.h"
#define _USE_MATH_DEFINES
#include <math.h>

Star::Star(int ID, double radius, double rotation_period, double rotation_angle,
	double revolution_radius, double revolution_period, double revolution_angle,double angle)
{
	Star();
	this->ID = ID;
	this->radius = radius;
	this->rotation_period = rotation_period;
	this->rotation_angle = rotation_angle;
	this->revolution_radius = revolution_radius;
	this->revolution_period = revolution_period;
	this->revolution_angle = revolution_angle;
	this->angle = angle;
}

Star::Star()
{
	SetValue(rotaVector[SUN], 0.0f, 0.0f, -1.0f);	
	SetValue(rotaVector[MERCURY], 1.0f, 0.0f, 1.0f);
	SetValue(rotaVector[VENUS], -1.0f, 0.0f, 1.0f);
	SetValue(rotaVector[EARTH], 2.0f, 0.0f, -1.0f);
	SetValue(rotaVector[MARS], -1.0f, 0.0f, -2.0f);
	SetValue(rotaVector[JUPITER], 3.0f, 0.0f, 2.0f);
	SetValue(rotaVector[STATURN], -2.0f, 0.0f, 3.0f);
	SetValue(rotaVector[URANUS], 1.0f, 0.0f, -2.0f);
	SetValue(rotaVector[NEPTUNE], -2.0f, 0.0f, -1.0f);
	SetValue(rotaVector[MOON], -2.0f, 0.0f, -1.0f);
	SetValue(rotaVector[LO], -1.0f, 0.0f, 1.0f);
	SetValue(rotaVector[EUROPA], 2.0f, 0.0f, -1.0f);
	SetValue(rotaVector[GANYMEDA], 3.0f, 0.0f, 2.0f);
	SetValue(rotaVector[CALLISO], -2.0f, 0.0f, 3.0f);

}

void Star::Mertial(GLfloat* emission,GLfloat* ambient, GLfloat* diffuse, GLfloat* specular, GLfloat shininess)
{
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);			//�Լ�����
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);			//������
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);			//������
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);			//���淴��
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);			//����ָ��
}

void Star::DrawStar(bool run)
{
	if (run)
	{
		//���㹫ת�Ƕ�
		if (this->revolution_period != 0)
			this->angle += (float)(1 / this->revolution_period);
		while (this->angle >= 360)
			this->angle = this->angle - 360;

		//������ת�Ƕ�
		bool flag = (rotation_period < 0) ? false : true;
		if (this->rotation_period != 0)
			this->rotationAngle += (float)(1 / this->rotation_period * flag);
		while (this->rotationAngle >= 360)
			this->rotationAngle = this->rotationAngle - 360;
	}

	glPushMatrix();

	//��ת������
	glRotatef(this->revolution_angle, rotaVector[this->ID][0], rotaVector[this->ID][1], rotaVector[this->ID][2]);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);						//��ת
	glTranslatef(this->revolution_radius, 0.0f, 0.0f);		//��ת�뾶
	//glRotatef(rotationAngle, 0.0f, 1.0f * flag, 0.0f);	//��ת
	glutSolidSphere(this->radius, 80.0f, 80.0f);
	
	glPopMatrix();

}

//��������ʱ���������Ǻ��棬��ΪҪ�õ����ǵĲ���
void Star::DrawStaellite(Star& Planet,bool run)
{
	if (run)
	{
		//�������ǹ�ת�Ƕ�
		if (this->revolution_period != 0)
			this->angle += (float)(1 / this->revolution_period);
		while (this->angle >= 360)
			this->angle = this->angle - 360;

		//����������ת�Ƕ�
		bool flag = (rotation_period < 0) ? false : true;
		if (this->rotation_period != 0)
			this->rotationAngle += (float)(1 / this->rotation_period * flag);
		while (this->rotationAngle >= 360)
			this->rotationAngle = this->rotationAngle - 360;
	}

	glPushMatrix();

	//���ǹ�ת������
	glRotatef(Planet.revolution_angle, rotaVector[Planet.ID][0], rotaVector[Planet.ID][1], rotaVector[Planet.ID][2]);
	glRotatef(Planet.angle, 0.0f, 1.0f, 0.0f);						//���ǹ�ת
	glTranslatef(Planet.revolution_radius, 0.0f, 0.0f);				//���ǹ�ת�뾶
	//glRotatef(rotationAngle, 0.0f, 1.0f * flag, 0.0f);			//������ת

	//���ǹ�ת������
	glRotatef(this->revolution_angle, rotaVector[this->ID][0], rotaVector[this->ID][1], rotaVector[this->ID][2]);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);								//���ǹ�ת
	glTranslatef(this->revolution_radius, 0.0f, 0.0f);				//���ǹ�ת�뾶
	glutSolidSphere(this->radius, 80.0f, 80.0f);

	glPopMatrix();
}

//���ƹ�ת���
void Star::DrawOrbit()
{                  
	glPushMatrix();
	//��ת������
	glRotatef(this->revolution_angle, rotaVector[this->ID][0], rotaVector[this->ID][1], rotaVector[this->ID][2]);
	glDisable(GL_LIGHTING);
	glColor3f(1.0f,1.0f, 1.0f);                      //�����߶λ�����ɫ  
	GLfloat r = this->revolution_radius;
	GLfloat x1, z1, x2, z2, y = 0;
	int NUM = (((int)r / 8000) + 1 ) * 360;
	for (int i = 0; i < NUM; i += 2)
	{
		x1 = cos(1.0 * i / NUM * 2 * M_PI) * r;
		z1 = sin(1.0 * i / NUM * 2 * M_PI) * r;
		x2 = cos(1.0 * (i+1) /NUM * 2 * M_PI) * r;
		z2 = sin(1.0 * (i+1) / NUM * 2 * M_PI) * r;
		glBegin(GL_LINES);
		glVertex3f(x1, y, z1);
		glVertex3f(x2, y, z2);
		glEnd();
	}
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Star::DrawSatelliteOrbit(Star& Planet)
{
	glPushMatrix();

	//���ǹ�ת������
	glRotatef(Planet.revolution_angle, rotaVector[Planet.ID][0], rotaVector[Planet.ID][1], rotaVector[Planet.ID][2]);
	glRotatef(Planet.angle, 0.0f, 1.0f, 0.0f);						//���ǹ�ת
	glTranslatef(Planet.revolution_radius, 0.0f, 0.0f);				//���ǹ�ת�뾶

	//��ת������
	glRotatef(this->revolution_angle, rotaVector[this->ID][0], rotaVector[this->ID][1], rotaVector[this->ID][2]);
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);                      //�����߶λ�����ɫ  
	GLfloat r = this->revolution_radius;
	GLfloat x1, z1, x2, z2, y = 0;
	int NUM = (((int)r / 8000) + 1) * 360;
	for (int i = 0; i < NUM; i += 2)
	{
		x1 = cos(1.0 * i / NUM * 2 * M_PI) * r;
		z1 = sin(1.0 * i / NUM * 2 * M_PI) * r;
		x2 = cos(1.0 * (i + 1) / NUM * 2 * M_PI) * r;
		z2 = sin(1.0 * (i + 1) / NUM * 2 * M_PI) * r;
		glBegin(GL_LINES);
		glVertex3f(x1, y, z1);
		glVertex3f(x2, y, z2);
		glEnd();
	}
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Star::SetValue(GLfloat* Str, GLfloat v1, GLfloat v2, GLfloat v3)
{
	Str[0] = v1;
	Str[1] = v2;
	Str[2] = v3;
}

void Star::DrawRing(GLfloat R, GLfloat Width)
{
	glPushMatrix();
	//��ת������
	glRotatef(this->revolution_angle, rotaVector[this->ID][0], rotaVector[this->ID][1], rotaVector[this->ID][2]);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);						//��ת
	glTranslatef(this->revolution_radius, 0.0f, 0.0f);		//��ת�뾶

	//������
	glRotatef(this->rotation_angle, rotaVector[this->ID][0], rotaVector[this->ID][1], rotaVector[this->ID][2]);
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);                      //�����߶λ�����ɫ  
	GLfloat r = R;
	GLfloat x1, z1, x2, z2, y = 0;
	int NUM = (((int)r / 8000) + 1) * 180;
	for (; r < R + Width; r += 10.0f) {
		for (int i = 0; i < NUM; i += 2)
		{
			x1 = cos(1.0 * i / NUM * 2 * M_PI) * r;
			z1 = sin(1.0 * i / NUM * 2 * M_PI) * r;
			x2 = cos(1.0 * (i + 1) / NUM * 2 * M_PI) * r;
			z2 = sin(1.0 * (i + 1) / NUM * 2 * M_PI) * r;
			glBegin(GL_LINES);
			glVertex3f(x1, y, z1);
			glVertex3f(x2, y, z2);
			glEnd();
		}
	}
	glEnable(GL_LIGHTING);

	glPopMatrix();
}