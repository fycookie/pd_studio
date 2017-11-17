#include "pd_studio.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	pd_studio w;
	w.show();
	return a.exec();
}
