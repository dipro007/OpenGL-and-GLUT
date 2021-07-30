#include <GL/gl.h>
#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#define PI 3.14                       //Ordering the value of PI as 3.14.
float angleMoon=0.0,
      angleEarth=0.0,
      angleAstroid=0.0,               //Taking initial float values for different planets as variables.
      angleMars=0.0,
      angleMercury=0.0,
      angleVenus=0.0,
      angleJupiter=0.0,
      angleSaturn=0.0,
      angleUranus=30.0,
      angleNeptune=60.0;

GLfloat sx=0.2,sy=0.2,sz=0.2;
int planet1;                          //Taking initial int values for planets.
GLfloat black[]={0.0f,0.0f,0.0f,1.0f};
GLfloat white[]={1.0f,1.0f,1.0f,1.0f};
GLfloat blue[]={0.0f,0.0f,0.9f,1.0f};
GLfloat er[]={0.0f,5.0f,0.9f,1.0f};
GLfloat yellow[]={0.7f,0.2f,0.0f,1.0f};
GLfloat qAmb[]={0.1,0.1,0.1,1.0};
GLfloat qDif[]={1.0,1.0,1.0,1.0};
GLfloat qSpec[]={.50,.50,.50,.10};
GLfloat qPos[]={0,0,0,0.1};
GLfloat sc[8]={0.295 , 0.40,0.50, 0.60,0.80,1.0,1.05,1.13};
double ang=2*PI/300;                 //Taking double variables for PI values.
double angular=2*PI/50;


void initLighting()                 //I have created a shadow look for day and night view of the SUN.
{

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT7);

    glLightfv(GL_LIGHT7,GL_AMBIENT,qAmb);
    glLightfv(GL_LIGHT7,GL_DIFFUSE,qDif);
    glLightfv(GL_LIGHT7,GL_SPECULAR,qSpec);

}
void myinit()
{
   glClearColor(0.0,0.0,0.0,0.0); //background color is just like space color.

   glPointSize(1.0);
   glLineWidth(2.0);

}

void background()                // background architecture.
{
    glBegin(GL_QUADS);
      glColor3f(0.0,0.00,0.00);
      glVertex3f(-01.00,01.00,1);
      glColor3f(.20,0.0,0.70);
      glVertex3f(01.00,1.00,1);
      glColor3f(0,0.0,0.0);
      glVertex3f(1.00,-1.00,1);
      glColor3f(.70,.10,.20);
      glVertex3f(-1.00,-1.00,1);
    glEnd();
}

void orbit()                  //The orbits of the solar system.
{
glColor3f(0.5,0.5,0.5);


int i=0;
for(i=0;i<8;i++){
glPushMatrix();
if(i==5)
{glRotatef(45,1.0,0.0,0.0);} //Rotation of the planets.
else
{glRotatef(63,1.0,0.0,0.0);}
glScalef(sc[i],sc[i],sc[i]);
glBegin(GL_POINTS);
double ang1=0.0;            //Moving angles with cos and sin.
  int i=0;
  for(i=0;i<300;i++)
  {glVertex2d(cos(ang1),sin(ang1));
   ang1+=ang;  }
glEnd();
glPopMatrix();
}
}

void draw(void)             //Drawing the full fixture of the solar system model.
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    background();
    orbit();
    glLoadIdentity();
    glPushMatrix();        //Using push matrix to build the structure.
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
       glPushMatrix();
       glColor3f(0.7,0.5,0.0);
       glScalef(sx,sy,sz);
       glLightfv(GL_LIGHT7,GL_POSITION,qPos);
       glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,yellow);  //Giving a outlook of Back and Yellow.
       glutSolidSphere(1,50,50);
       glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);   //Giving a outlook of Back and Black.
       glPopMatrix();

       glScalef(0.2,0.2,0.2);
       glPushMatrix();
       glRotatef(angleMercury,0.0,1.0,-0.5);               //Angle of the planet Mercury.
       glTranslatef(1.5,0.0,0.0);
       glColor3f(1.0,0.9,0.0);
       glScalef(0.08,0.08,0.08);
       glutSolidSphere(1,50,50);
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleVenus,0.0,1.0,-0.5);               //Angle of the planet Venus.
         glTranslatef(2.0,0.0,0.0);
         glColor3f(0.9,0.1,0.0);
         glScalef(0.1,0.1,0.1);
         glutSolidSphere(1,50,50);
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleEarth,0.0,1.0,-0.5);               //Angle of the planet Earth.
         glTranslatef(2.5,0.0,0.0);
         glColor3f(0.0,0.1,0.7);
         glScalef(0.23,0.23,0.23);
         glutSolidSphere(1,50,50);
            glPushMatrix();
             glRotatef(angleMoon,0.0,0.1,0.05);            //Angle of the sub-planet Moon.
             glTranslatef(1.3,0.0,0.0);
             glColor3f(1.0,1.0,1.0);
             glScalef(0.5,0.5,0.5);
             glutSolidSphere(0.5,50,50);
           glPopMatrix();                                 //Moon made by these structure.
       glPopMatrix();                                     //Earth made by these structure.

       glPushMatrix();
         glRotatef(angleMars,0.0,1.0,-0.5);               //Angle of the planet Mars.
         glTranslatef(-3.0,0.0,0.0);
         glColor3f(0.05,0.05,0.01);
         glScalef(0.17,0.17,0.17);
         glutSolidSphere(1,50,50);
       glPopMatrix();

        glPushMatrix();
             glColor3f(3.30,3.30,3.30);                   //Color management.
             glRotatef(63,1.0,0.0,0.0);
             int j=0,i=0,div=90;float siz=2;              //Selected int and float
             float scl[4]={3.3,3.4,3.35,3.2};
             for(j=0;j<4;j++)
             {glPushMatrix();siz-=0.3;
             glPointSize(siz);
             glScalef(scl[j],scl[j],scl[j]);
             glBegin(GL_POINTS);
                double ang1=0.0 -angleAstroid,a=(2*PI)/div; //Simple value chnaging through the process.
                for(i=0;i<div;i++)
                  {glVertex2d(cos(ang1),sin(ang1));
                   ang1+=a;}
                   div+=10;
            glEnd();
            glPopMatrix();
             }
           glPopMatrix();                               //Astroid made by these structure.

       glPushMatrix();
         glRotatef(angleJupiter,0.0,1.0,-0.5);
         glTranslatef(-4.0,0.0,0.0);
         glColor3f(0.4,0.2,0.0);
         glScalef(0.5,0.5,0.5);
         glutSolidSphere(1,50,50);
         glPushMatrix();
             glRotatef(angleMoon,1.0,-0.5,0.0);         //Angle of the planet Moon.
             glTranslatef(0.0,0,1.1);
             glColor3f(1.0,1.0,1.0);
             glScalef(0.1,0.1,0.1);
             glutSolidSphere(0.5,50,50);
           glPopMatrix();                               //Moon made by these structure.
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleSaturn,0.0,1.0,-1.0);
         glTranslatef(-5.0,0.0,0.0);
         glColor3f(0.9,0.0,0.0);
         glScalef(0.4,0.4,0.4);
         glutSolidSphere(1,50,50);
         glPushMatrix();
             glRotatef(45,1.0,0.0,0.0);
             glPointSize(3);
             glColor3f(5.0,3.0,1.0);
             glScalef(1.2,1.2,1.2);
             glBegin(GL_POINTS);
                double ang1=0.0;
                i=0;
                for(i=0;i<50;i++)
                  {glVertex2d(cos(ang1),sin(ang1));
                   ang1+=angular;  }
            glEnd();

            glPointSize(2);
           glPopMatrix();                                //Ring made by this structure.
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleUranus,0.0,1.0,-0.5);
         glTranslatef(5.2,0.0,0.0);
         glColor3f(0.0,0.5,0.9);
         glScalef(0.23,0.23,0.23);
         glutSolidSphere(1,50,50);
       glPopMatrix();

       glPushMatrix();
         glRotatef(angleNeptune,0.0,1.0,-0.5);          //Angle of the planet Neptune.
         glTranslatef(-5.7,0.0,0.0);
         glColor3f(0.0,0.0,0.9);
         glScalef(0.2,0.2,0.2);
         glutSolidSphere(1,50,50);
       glPopMatrix();


     glPopMatrix();
     glFlush();
}


void update(int value){                                //The values for the rotation of each planet.

if((angleMoon>=0 && angleMoon<180) )
{sx-=0.0003;sy-=0.0003;sz-=0.0003;}
else{sx+=0.0003;sy+=0.0003;sz+=0.0003;}


angleMoon+=2;
if(angleMoon>360){
    angleMoon-=360;}             //360 Degree angels for Moon's rotation.

angleEarth+=0.7;
if(angleEarth>360){
    angleEarth-=360;}           //360 Degree angels for Earth's rotation.

angleMercury+=2;
if(angleMercury>360){
    angleMercury-=360;}         //360 Degree angels for Marcury's rotation.
                                                                                 //360 Degree angels for each platents roatation.
angleVenus+=0.9;
if(angleVenus>360){
    angleVenus-=360;}           //360 Degree angels for Venus's rotation.

angleMars+=0.5;
if(angleMars>360){
    angleMars-=360;}            //360 Degree angels for Mar's rotation.

angleJupiter+=0.2;
if(angleJupiter>360){
    angleJupiter-=360;}         //360 Degree angels for Jupiter's rotation.

angleSaturn+=0.1;
if(angleSaturn>360){
    angleSaturn-=360;}          //360 Degree angels for Saturn's rotation.


angleUranus+=0.05;
if(angleUranus>360){
    angleUranus-=360;}          //360 Degree angels for Uranus's rotation.


angleNeptune+=0.02;
if(angleNeptune>360){
    angleNeptune-=360;}         //360 Degree angels for Neptune's rotation.


angleAstroid+=0.002;
if(angleAstroid>360){
    angleAstroid-=360;}         //360 Degree angels for Astroid's rotation.


glutPostRedisplay();            //Displaying all the movement of these planets.
glutTimerFunc(20,update,0);
}

int main(int argc, char **argv) //OpenGL visibility of the Solar System.
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(700,700);
    glutCreateWindow("Muhtasim Shafi Kader  181-15-10809  G");
    initLighting();
    myinit();
    glutDisplayFunc(draw);
    glutTimerFunc(25,update,0);
    glutMainLoop();
    return 0;
}
