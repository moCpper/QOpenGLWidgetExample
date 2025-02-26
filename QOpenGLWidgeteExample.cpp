#include "mainwindow.h"
#include <QApplication>
#include <QDir>

auto main(int argc,char* argv[]) -> int {
	QApplication app(argc,argv);
	QDir::setCurrent("..\\..\\..\\..\\");

	MainWindow mw;
	mw.show();

	return app.exec();
}
