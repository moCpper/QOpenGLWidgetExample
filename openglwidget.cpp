#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent)
	:QOpenGLWidget(parent){}

void OpenGLWidget::initializeGL() {
	initializeOpenGLFunctions();

	// …Ë÷√«Â∆¡—’…´
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	vao.create();
	vbo.create();

	const float vertices[] = {
		-1,-1,0,
		1,-1,0,
		0,1,0
	};

	vao.bind();
	vbo.bind();
	vbo.allocate(vertices, sizeof(vertices));

	program.addShaderFromSourceFile(QOpenGLShader::Vertex, "orange.vert");
	program.addShaderFromSourceFile(QOpenGLShader::Fragment, "orange.frag");
	program.link();

	program.enableAttributeArray("position");
	program.setAttributeBuffer("position", GL_FLOAT, 0, 3, 0);

	vao.release();
	vbo.release();
}

void OpenGLWidget::resizeGL(int w, int h) {
	glViewport(0, 0, w, h);
}

void OpenGLWidget::paintGL() {
	vao.bind();
	program.bind();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	program.release();
	vao.release();
}