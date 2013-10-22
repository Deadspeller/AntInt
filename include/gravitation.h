/* Gravitation-Header File */

#include "Timer.h"
#include <iostream>
using namespace std;


extern bool gravi_enable ;
extern float velocity;
extern float ypos;
extern float camheight;
extern float hp;
Timer t;

void gravi()
{
float g = 9.81;
float difTime = 0;

t.stop();
difTime = t.getElapsedTimeInSec();
t.start();

  if(gravi_enable == 1)
  {
	if(difTime < 0.2)
	velocity = velocity - (g*difTime); // new speed
	ypos = ypos + (velocity * difTime);// new position

  if(ypos <= camheight) //ground
	{	
	if(ypos<0) hp = 100;
	ypos = camheight;
	if(velocity < -5 && velocity > -100) //falling damage
	{ 
	cout<<difTime<<endl;
		if(velocity < -5 && velocity > -8)	hp += velocity/2;
		if(velocity < -8 && velocity > -12)	hp += velocity*1.5;
		if(velocity < -12 && velocity > -15)	hp += velocity*4;
		if(velocity < -15)	hp = 0;
	}	
	velocity = 0;
	}
  }	
}


