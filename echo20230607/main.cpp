#include <QApplication>
#include "titlebar.h"
#include "btnframe.h"
#include "content.h"
#include "mainwin.h"
#include "btngroup.h"
int main(int argc, char** argv)
{
	QApplication a(argc, argv);
	mainwin dlg;
	dlg.show();
	return a.exec();
}