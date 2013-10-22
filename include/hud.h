#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <GL/glew.h> // Include the GLEW header file  

extern sf::Window DSWindow;

void DrawHUD()
{
int ammoleft = 0, i=0, a=0;
char cammoleft[10] = "default";
char chp[10] = "default";





//DSWindow.Draw(Test2);

//ammo left
/*		for(int i=0; i<bullets; i++)
		{
			if(bulletarray[i].bulletflying == 0)
			{
			ammoleft += 1;
			}			
		}
sprintf(cammoleft,"Ammo: %d", ammoleft);

sprintf(chp,"HP: %d", hp);
*/






   glMatrixMode( GL_PROJECTION );
   glPushMatrix();
   glLoadIdentity();
   glOrtho( -100.0f, 100.0f, -100.0f, 100.0f, -0.01f, 1.0f );
   glMatrixMode( GL_MODELVIEW );

   		glPushMatrix(); 	//map
   		glLoadIdentity();
            	glColor3f( 1.0f, 1.0f, 0.0f );
            	glBegin( GL_LINE_LOOP);
             	glVertex2f( -95.0f, 95.0f );
             	glVertex2f( -95.0f, 50.0f );
             	glVertex2f( -50.0f, 50.0f );
              	glVertex2f( -50.0f, 95.0f );
           	glEnd();

		
	
	//aim
		glColor3f( 0.0f, 1.0f, 0.0f );
            	glBegin(GL_LINE_LOOP);
		glVertex2f( -4.0f, 0.1f );
		glVertex2f( -0.1f, 0.1f );
		glVertex2f( -0.1f, 4.0f );
		glVertex2f( 0.1f, 4.0f );
		glVertex2f( 0.1f, 0.1f );
		glVertex2f( 4.0f, 0.1f );
		glVertex2f( 4.0f, -0.1f );
		glVertex2f( 0.1f, -0.1f );
		glVertex2f( 0.1f, -4.0f );
		glVertex2f( -0.1f, -4.0f );
		glVertex2f( -0.1f, -0.1f );
		glVertex2f( -4.0f, -0.1f );
	        glVertex2f( -4.0f, -0.1f );
           	glEnd();

/*		glPushMatrix(); 	//Ammo
   		glLoadIdentity();
		glColor3f( 1.0f, 1.0f, 0.0f ); 
		glTranslatef( 40.0f, -90.0f, 0.0f );
            	glScalef( 0.08f, 0.08f, 0.08f);
            	while( cammoleft[i] != '\0' )
    		{
            	glutStrokeCharacter( GLUT_STROKE_ROMAN, cammoleft[i]);
		i++;
 		}
	
		glPushMatrix(); 	//HP
   		glLoadIdentity();
		glColor3f( 1.0f, 1.0f, 0.0f );	
		glTranslatef( -90.0f, -90.0f, 0.0f );
            	glScalef( 0.08f, 0.08f, 0.08f);
            	while( chp[a] != '\0' )
    		{
            	glutStrokeCharacter( GLUT_STROKE_ROMAN, chp[a]);
		a++;
 		}
*/
   	glMatrixMode( GL_PROJECTION );					
   	glPopMatrix();	
				
  glMatrixMode( GL_MODELVIEW );		
  glPopMatrix();
}
