#include <check_gl.hpp>

void render() {}

int main() {
  if (!glfwInit()) {
    throw std::runtime_error("failed to initialize GLFW");
  }

  GLFWwindow *window = glfwCreateWindow(1080, 720, "window", NULL, NULL);
  if (!window) {
    glfwTerminate();
    throw std::runtime_error("GLFW failed to create window");
  }
  glfwMakeContextCurrent(window);
  if (!gladLoadGL()) {
    glfwTerminate();
    throw std::runtime_error("GLAD failed to load GL functions");
  }
  while (!glfwWindowShouldClose(window)) {
    CHECK_GL(glClear(GL_COLOR_BUFFER_BIT));
    render();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  return 0;
}
