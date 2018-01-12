//Programme qui génére la Fractale de Newton-Raphson
//Programmé par Jarod1980 - 02/08/2005
// f(z) = z^3-1=0
// où z = x+iy. La méthode de Newton-Raphson: xn = xn-1 - f(xn-1)/f'(xn-1)
// f'(z)=3z²
//z = z -f(z)/f'(z) = (2/3)*z + 1/3z² or z = x+iy => z = (2/3)*(x+yi) + 1/3*(x+yi)2
// donc : z = (2/3)*(x+yi) + ((x2 - y2) - 2*x*yi)/3*((x2 - y2)2 + 4*x2*y2)
// posons:
// d = 3*((x2 - y2)2 + 4*x2*y2)
//finalement: z = [(2/3)*x + (x2 - y2)/d] + [(2/3)*y - 2*x*y/d]i

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

typedef unsigned char uchar;

void disp(void);
void reshape(int x,int y);
void mouse(int button,int state, int x, int y);
void keyb(uchar key,int x,int y);
void CrearPaleta(void);

static int winx;
static int winy;
static double xbegin = -2.0;
static double xend=2.0;
static double ybegin = -2.0;
static double yend=2.0;

int R,G,B;
int ColorRGB[256][3];
int color;

int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Fractale Newton-Raphson");
	glutInitWindowSize(600,600);

	CreerPalette();
	glClearColor(1.0,1.0,1.0,0.0);
	glutDisplayFunc(disp);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyb);
	glutMainLoop();
}

void disp(void){
	float i,j;
	double deltax, deltay;
	double x, y, tmp, xx, yy, d;
	int color, row, col, count;
	int maxiter = 2048; //nombre d'itérations

	deltax = (xend - xbegin)/winx;
	deltay = (yend - ybegin)/winy;

	glClear(GL_COLOR_BUFFER_BIT);

	// debut définition
	glBegin(GL_POINTS);

	// pour chaque pixel à l'écran
	for(i=0;i<winx;i++)
	{

		for( j=0;j<winy;j++)
		{
			x = xbegin + i * deltax;
			y = ybegin + j * deltay;
			count=0;
			while (count<maxiter)
			{
				xx = x * x;
				yy = y * y;
				d = 3.0*( (xx - yy) * (xx - yy) + 4.0 * xx * yy);
				if (d == 0.0)
					d = 0.000001;
				tmp=x;
				x = (2.0 / 3.0) * x + (xx - yy) / d;
				y = (2.0 / 3.0) * y - 2.0 * tmp * y / d;
				count+=1;
			}
			if (x > 0.0)
				color = count % 64;
			else
			{
				if ( (x<-0.3) && (y>0.0) )
					color = (count%64) + 64;
				else
					color = (count%64) + 128;
			}
			R=ColorRGB[color][0];
			G=ColorRGB[color][1];
			B=ColorRGB[color][2];
			glColor3f (R,G,B);
			glVertex2f(i,j); //on trace
		}
	}
	glEnd();

	glutSwapBuffers();
}

void keyb(uchar key, int x, int y){
	if(key=='Q'||key=='q'){
		exit(0);
	}else if(key=='r'){
		xbegin = -1.8;
		xend=1.1;
		ybegin = -1.2;
		yend=1.2;
		reshape(winx,winy);
	}

}
//fonction permettant de zoomer avec la souris
//click droit pour zoom ( + ), gauche pour zoom( - )
void mouse(int button,int state,int x,int y){

	if(state == GLUT_DOWN){

		y = winy - y;
		double dx = (xend-xbegin);
		double dy = (yend-ybegin);
		if(dx != 0 && dy != 0){
			if(button == GLUT_LEFT){
				xend = x * dx/winx +xbegin  + dx/10;
				xbegin = x * dx/winx +xbegin  - dx/10;

				yend = y * dy/winy +ybegin  + dy/10;
				ybegin = y * dy/winy +ybegin  - dy/10;
			}else{
				xend = x * dx/winx +xbegin  + 5*dx;
				xbegin = x * dx/winx +xbegin  - 5*dx;

				yend = y * dy/winy +ybegin  + 5*dy;
				ybegin = y * dy/winy +ybegin  - 5*dy;

			}
			glutPostRedisplay();
		}else{

			printf("appuyer sur 'r' pour reset");
		}
	}
}

void reshape(int x,int y){
	winx =x;
	winy =y;
	glViewport(0,0,x,y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,x,0,y);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void CreerPalette(void)
{
	int i;

	for (i=0; i<256; i++)
	{
		if (i<64)
		{
			ColorRGB[i][0] = 192 + i;
			ColorRGB[i][1] = 0;
			ColorRGB[i][2] = 0;
		}
		else if ((i>63) && (i<128))
		{
			ColorRGB[i][0] = 0;
			ColorRGB[i][1] = (192 + i)-64;
			ColorRGB[i][2] = 0;
		}
		else if ((i>127)&&(i<192))
		{
			ColorRGB[i][0] = 0;
			ColorRGB[i][1] = 0;
			ColorRGB[i][2] = (192 + i)-128;
		}
	}
