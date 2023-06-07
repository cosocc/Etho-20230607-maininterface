#pragma once

#include <QWidget>
#include "titlebar.h"
#include "btngroup.h"
#include <QPainter>
#include<QStatusBar>
#include <QProcess>
class content : public QWidget
{
	Q_OBJECT

public:
	content(QWidget* parent = Q_NULLPTR);
	~content();
	void createUi();
	void LayoutUi();
	//void setWindowCernter(int w, int h);
	btngroup* m_btngroup;
	titlebar* titlebargroup;
private slots:
	void openRemoteServer();
protected:
	virtual void paintEvent(QPaintEvent* event) override;
private:
	QGridLayout* contentGridLayout;
	QStatusBar* statusBar;
};
