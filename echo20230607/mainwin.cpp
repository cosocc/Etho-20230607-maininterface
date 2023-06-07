#include "mainwin.h"
#include <QDebug>
#include <QResizeEvent>
#include<QFrame>
mainwin::mainwin(QWidget* parent)
	: QMainWindow(parent)
{
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	loadBackground();
	createQssOBJ();
	loadQss();
	setCentralWidget(edgeQframe);
	resize(950, 650);

}

mainwin::~mainwin()
{}

void mainwin::loadBackground()
{

	QImage img;
	m_background = new QLabel(this);
	if (img.load(".\\img\\background.jpg"))
	{

		m_background->setPixmap(QPixmap::fromImage(img));
		m_background->setScaledContents(true);
	}
	else
	{
		qDebug() << "mainDlg: Failed to load background image!";
	}
	QIcon icon(".\\img\\SG.ico");
	this->setWindowIcon(icon);
}

void mainwin::resizeEvent(QResizeEvent* event)
{
	Q_UNUSED(event);
	m_background->move(1, 1);
	m_background->resize(size() - QSize(1, 1));
	contentdlg->move(1, 1);
	contentdlg->resize(event->size() - QSize(3, 3));
}

void mainwin::loadQss()
{
	QFile* qssfile = new QFile(".\\img\\center.qss");
	qssfile->open(QFile::ReadOnly);
	QByteArray qssStrArray = qssfile->readAll();
	QString qssStr = QString::fromUtf8(qssStrArray);
	qDebug() << qssStr;
	qssfile->close();
	this->setStyleSheet(qssStr);

}

void mainwin::createQssOBJ()
{
	edgeQframe = new QFrame(this);
	contentdlg = new content(edgeQframe);
	contentdlg->m_btngroup->echoremoteDesktop_btnFrame->setObjectName("remoteDesktop_btnFrame_obj");
	contentdlg->m_btngroup->echoOpertion_btnFrame->setObjectName("echoOpertion_btnFrame_obj");
	contentdlg->m_btngroup->echocentralControlCommand_btnFrame->setObjectName("centralControlCommand_btnFrame_obj");
	contentdlg->m_btngroup->echoMaterialManageMent_btnFrame->setObjectName("MaterialManageMent_btnFrame_obj");
	contentdlg->m_btngroup->echonullbtnFrame_btnFrame->setObjectName("nullbtnFrame_btnFrame_obj");
	edgeQframe->setObjectName("edgeQframe_obj");
	contentdlg->titlebargroup->setObjectName("titlebar_obj");
}
