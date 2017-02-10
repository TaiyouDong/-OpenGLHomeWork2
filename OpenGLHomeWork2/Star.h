#ifndef STAR_H
#define STAR_H
#include<string>
#include<glut.h>
#include<iostream>

#define NUMBER		14
#define SUN			0
#define MERCURY		1
#define VENUS		2
#define EARTH		3
#define MARS		4
#define JUPITER		5
#define STATURN		6
#define URANUS		7
#define NEPTUNE		8
#define MOON		9
#define LO			10
#define EUROPA		11
#define GANYMEDA	12
#define CALLISO		13


class Star {
private:
	int ID;
	double radius;				//�뾶
	double rotation_period;		
	double rotation_angle;
	double revolution_radius;	
	double revolution_period;
	double revolution_angle;
	double angle = 0;
	double rotationAngle = 0;

public:
	GLfloat rotaVector[NUMBER][3];
public:
	//���ƣ��뾶����ת���ڣ���ת�Ƕȣ���ת�뾶����ת���ڣ���ת�Ƕ�
	Star(int, double, double, double, double, double, double,double);
	Star();
	//�������ǵĲ���
	void Mertial(GLfloat*, GLfloat*, GLfloat*, GLfloat*, GLfloat);

	void DrawStar(bool run);						//��������
	void DrawStaellite(Star& Planet,bool run);		//��������
	void DrawOrbit();								//���ƹ��
	void DrawSatelliteOrbit(Star& Planet);			//�������ǹ��
	void SetValue(GLfloat* , GLfloat , GLfloat , GLfloat );

	void DrawRing(GLfloat R,GLfloat Width);			//�������ǻ�
};

#endif // !STAR_H
