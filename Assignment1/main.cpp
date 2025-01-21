#include <GLFW/glfw3.h>
#include <cmath> 


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void drawOctagon(float radius) {
    const int sides = 8;
    const float angleStep = 2.0f * M_PI / sides; 
    const float offset = M_PI / 8.0f;

    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; i++) {
        float angle = i * angleStep - offset; 
        float x = radius * cos(angle);
        float y = radius * sin(angle) + 0.55;
        glVertex2f(x, y);
    }
    glEnd();
}

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Sol Andrei William Taboga", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Set the viewport to match the window size */
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    /* Adjust projection to normalized device coordinates */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        
        drawOctagon(0.5f);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
