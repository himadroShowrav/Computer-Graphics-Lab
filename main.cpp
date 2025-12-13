// File Name: dda_forward_user_input.cpp
#include <GL/glut.h>
#include <cmath>
#include <iostream>

float X0, Y0, X1, Y1;

void DDA(float x0, float y0, float x1, float y1) {
    float dx = x1 - x0;
    float dy = y1 - y0;

    // float steps = std::abs(dx) > std::abs(dy) ? std::abs(dx) : std::abs(dy);
    float steps;
        if (std::abs(dx) > std::abs(dy))
            steps = std::abs(dx);
        else
            steps = std::abs(dy);


    float Xinc = dx / steps;
    float Yinc = dy / steps;

    float x = x0;
    float y = y0;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2f(x, y);
        x += Xinc;
        y += Yinc;
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red color
    DDA(X0, Y0, X1, Y1);      // Draw line using user input
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background
    glColor3f(1.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);       // Set coordinate system
}

int main(int argc, char** argv) {
    std::cout << "Enter first point (X0 Y0): ";
    std::cin >> X0 >> Y0;
    std::cout << "Enter second point (X1 Y1): ";
    std::cin >> X1 >> Y1;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing - User Input");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
