#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLVertexArrayObject>		// VAO
#include <QOpenGLBuffer>				// VBO
#include <QOPenGLShader>		
#include <QOpenGLShaderProgram>			

class OpenGLWidget : public QOpenGLWidget , private QOpenGLFunctions_3_3_Core{
	Q_OBJECT

	QOpenGLVertexArrayObject vao;
	QOpenGLBuffer vbo;
	QOpenGLShaderProgram program;
public:
	explicit OpenGLWidget(QWidget* parent = nullptr);

	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;
};