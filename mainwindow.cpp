#include "mainwindow.h"
#include "openglwidget.h"

MainWindow::MainWindow(QWidget* parent)
	:QMainWindow(parent) {
	setWindowTitle("Qt OpenGL");      // qt == glfw + glad
	setCentralWidget(new OpenGLWidget(this));
	resize(800, 600);
}
