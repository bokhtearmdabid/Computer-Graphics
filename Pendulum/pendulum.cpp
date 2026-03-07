#include <GL/glut.h>   // OpenGL Utility Toolkit for graphics window and drawing
#include <math.h>      // Used for sin() and cos() functions

// Fixed point (pivot) position of the pendulum
int centerX = 250;
int centerY = 400;

// Length of the pendulum string
int length = 200;

// Initial angle of the pendulum (starting from left side)
float angle = -45;

// Direction of motion (1 = right, -1 = left)
int direction = 1;


// Function to draw a circle using Midpoint Circle Algorithm
void drawCircle(int cx,int cy,int r)
{
    int x = 0;
    int y = r;

    // Decision parameter
    int p = 1 - r;

    glBegin(GL_POINTS);

    // Loop until x crosses y
    while(x<=y)
    {
        // Plot 8 symmetric points of the circle
        glVertex2i(cx+x,cy+y);
        glVertex2i(cx-x,cy+y);
        glVertex2i(cx+x,cy-y);
        glVertex2i(cx-x,cy-y);

        glVertex2i(cx+y,cy+x);
        glVertex2i(cx-y,cy+x);
        glVertex2i(cx+y,cy-x);
        glVertex2i(cx-y,cy-x);

        x++;

        // Update decision parameter
        if(p<0)
            p = p + 2*x + 1;
        else
        {
            y--;
            p = p + 2*(x-y) + 1;
        }
    }

    glEnd();
}


// Function to draw a line using Bresenham Line Algorithm
void drawLine(int x1,int y1,int x2,int y2)
{
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);

    // Step direction
    int sx = (x1<x2)?1:-1;
    int sy = (y1<y2)?1:-1;

    int err = dx-dy;

    while(true)
    {
        // Plot current pixel
        glBegin(GL_POINTS);
        glVertex2i(x1,y1);
        glEnd();

        // Stop when the end point is reached
        if(x1==x2 && y1==y2) break;

        int e2 = 2*err;

        if(e2>-dy)
        {
            err -= dy;
            x1 += sx;
        }

        if(e2<dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}


// Function to display text on screen
void drawText(float x, float y, const char *text)
{
    glRasterPos2f(x, y);

    // Print characters one by one
    while (*text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}


// Display function (draws pendulum every frame)
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear screen

    // Convert angle from degree to radian
    float rad = angle * 3.1416 / 180;

    // Calculate bob position using trigonometry
    int bobX = centerX + length*sin(rad);
    int bobY = centerY - length*cos(rad);

    // Draw top support bar (fixed support)
    drawLine(centerX-120, centerY, centerX+120, centerY);

    // Draw pivot point (small circle)
    drawCircle(centerX,centerY,5);

    // Label A above pivot point
    drawText(centerX-5, centerY+20, "A");

    // Draw string of pendulum
    drawLine(centerX,centerY,bobX,bobY);

    // Draw moving bob
    drawCircle(bobX,bobY,15);

    // Calculate left extreme position of pendulum
    float radL = -45 * 3.1416 / 180;
    int Lx = centerX + length*sin(radL);
    int Ly = centerY - length*cos(radL);

    // Label B at left extreme
    drawText(Lx-15, Ly, "B");

    // Calculate right extreme position
    float radR = 45 * 3.1416 / 180;
    int Rx = centerX + length*sin(radR);
    int Ry = centerY - length*cos(radR);

    // Label B at right extreme
    drawText(Rx+10, Ry, "B'");

    glFlush();  // Execute drawing
}


// Timer function to create rhythmic pendulum motion
void timer(int)
{
    // Change angle continuously
    angle += direction;

    // Reverse direction when reaching extreme positions
    if(angle>45 || angle<-45)
        direction = -direction;

    glutPostRedisplay();  // Request screen redraw

    // Call timer again after 30 milliseconds
    glutTimerFunc(30,timer,0);
}


// Initialization function for OpenGL settings
void init()
{
    // Set background color to white
    glClearColor(1,1,1,1);

    // Set drawing color to black
    glColor3f(0,0,0);

    // Size of points
    glPointSize(3);

    // Set projection mode
    glMatrixMode(GL_PROJECTION);

    // Define 2D coordinate system
    gluOrtho2D(0,500,0,500);
}


// Main function
int main(int argc,char** argv)
{
    glutInit(&argc,argv);  // Initialize GLUT

    // Use single buffer and RGB color
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    // Window size
    glutInitWindowSize(500,500);

    // Create window with title
    glutCreateWindow("Pendulum Motion");

    init();  // Call initialization

    // Register display function
    glutDisplayFunc(display);

    // Start timer for animation
    glutTimerFunc(30,timer,0);

    // Start main loop
    glutMainLoop();
}
