#pragma once
#include <QWidget>
#include "btnframe.h"
class btngroup : public QWidget
{
	Q_OBJECT

public:
	btngroup(QWidget* parent = nullptr);
	~btngroup();
	void createUi();
	void LayoutUi();
	btnframe* echoremoteDesktop_btnFrame;
	btnframe* echoOpertion_btnFrame;
	btnframe* echocentralControlCommand_btnFrame;
	btnframe* echoMaterialManageMent_btnFrame;
	btnframe* echonullbtnFrame_btnFrame;
private:
	QGridLayout* contentGridLayout;

	QLabel* m_background;
};
