#include "content.h"
#include <QPaintEvent>
#include <QMessageBox>
#include<QAction>
#include<QToolButton>


content::content(QWidget* parent)
	: QWidget(parent)
{
	createUi();
	LayoutUi();

	//If you want to replace these lambda expressions with slot functions to use these signals, you can do the following. 
	connect(titlebargroup, &titlebar::sg_MenuStatus_ServerStatus_clk, [this]() {QMessageBox::information(this, " serverstatus", "serverstatus "); });
	connect(titlebargroup, &titlebar::sg_MenuStatus_Plc_clk, [this]() {QMessageBox::information(this, " PLC", "PCL "); });
	connect(titlebargroup, &titlebar::sg_MenuStatus_Ups_clk, [this]() {QMessageBox::information(this, " UPS", "UPS "); });
	connect(titlebargroup->tbtnUps, &QToolButton::clicked, [this]() {QMessageBox::information(this, " tbtnUps", "tbtnUps "); });
	connect(titlebargroup->tbtnAddServer, &QToolButton::clicked, [this]() {QMessageBox::information(this, " tbtnAddServer", "tbtnAddServer "); });
	connect(titlebargroup->tbtnRescan, &QToolButton::clicked, [this]() {QMessageBox::information(this, " tbtnRescan", "tbtnRescan "); });
	connect(titlebargroup->tbtnOption, &QToolButton::clicked, [this]() {QMessageBox::information(this, " tbtnOption", "tbtnOption "); });

	connect(m_btngroup->echoremoteDesktop_btnFrame, &btnframe::mouseLPressSignal, this, &content::openRemoteServer);
	connect(m_btngroup->echocentralControlCommand_btnFrame, &btnframe::mouseLPressSignal, [this]() {QMessageBox::information(this, " echocentralControlCommand_btnFrame", "echocentralControlCommand_btnFrame "); });
	connect(m_btngroup->echoMaterialManageMent_btnFrame, &btnframe::mouseLPressSignal, [this]() {QMessageBox::information(this, " echoMaterialManageMent_btnFrame", "echoMaterialManageMent_btnFrame "); });
	connect(m_btngroup->echoOpertion_btnFrame, &btnframe::mouseLPressSignal, [this]() {QMessageBox::information(this, " echoOpertion_btnFrame", "echoOpertion_btnFrame "); });
	connect(m_btngroup->echonullbtnFrame_btnFrame, &btnframe::mouseLPressSignal, [this]() {QMessageBox::information(this, " echonullbtnFrame_btnFrame", "echonullbtnFrame_btnFrame "); });
}

content::~content()
{

}

void content::createUi()
{
	titlebargroup = new titlebar(this);
	m_btngroup = new btngroup(this);
	statusBar = new QStatusBar(this);
}

void content::LayoutUi()
{
	contentGridLayout = new QGridLayout(this);
	contentGridLayout->setContentsMargins(0, 0, 0, 0);
	contentGridLayout->setVerticalSpacing(0);
	contentGridLayout->addWidget(titlebargroup);
	titlebargroup->setFixedHeight(32);
	contentGridLayout->addWidget(m_btngroup);
	contentGridLayout->addWidget(statusBar);
	statusBar->setFixedHeight(32);
}

//#include <QGuiApplication>
//#include <QScreen>
//void content::setWindowCernter(int w, int h)
//{
//
//	QRect winRect = QGuiApplication::primaryScreen()->availableGeometry();
//	resize(w, h);
//	int screenWidth = winRect.width();
//	int screenHeight = winRect.height();
//	int x = (screenWidth - w) / 2;
//	int y = (screenHeight - h) / 2;
//	move(x, y);
//
//}




void content::paintEvent(QPaintEvent* event)
{

	QPainter painter(this);
	painter.fillRect(event->rect(), QColor(128, 128, 128, 128));

}


#include <QDebug>

void content::openRemoteServer()
{

	QProcess* pro = new QProcess();
	QString strPro = "00-testdemo.exe";
	pro->startDetached(strPro);

}