#pragma once
#include "content.h"
#include <QMainWindow>

class mainwin : public QMainWindow
{
	Q_OBJECT

public:
	mainwin(QWidget* parent = Q_NULLPTR);
	~mainwin();
	void loadBackground();
private:
	QLabel* m_background;
	content* contentdlg;
	QFrame* edgeQframe;
	void loadQss();
	void createQssOBJ();

protected:
	virtual void resizeEvent(QResizeEvent* event) override;
};

