#include "btngroup.h"
btngroup::btngroup(QWidget* parent)
	: QWidget(parent)
{

	createUi();
	LayoutUi();


}

btngroup::~btngroup()
{

}

void btngroup::createUi()
{

	echoremoteDesktop_btnFrame = new btnframe();
	echoremoteDesktop_btnFrame->m_titleLabel->setText(QString::fromLocal8Bit("Remote Desktop"));
	echoremoteDesktop_btnFrame->m_detailLabel->setText(QString::fromLocal8Bit("Remote operation server"));

	echoOpertion_btnFrame = new btnframe();
	echoOpertion_btnFrame->m_titleLabel->setText(QString::fromLocal8Bit("Echo Operation"));
	echoOpertion_btnFrame->m_detailLabel->setText(QString::fromLocal8Bit("Operation echo server out"));

	echocentralControlCommand_btnFrame = new btnframe();
	echocentralControlCommand_btnFrame->m_titleLabel->setText(QString::fromLocal8Bit("Central Control Command"));
	echocentralControlCommand_btnFrame->m_detailLabel->setText(QString::fromLocal8Bit("Setting and execution of central control command"));

	echoMaterialManageMent_btnFrame = new btnframe();
	echoMaterialManageMent_btnFrame->m_titleLabel->setText(QString::fromLocal8Bit("Material Management"));
	echoMaterialManageMent_btnFrame->m_detailLabel->setText(QString::fromLocal8Bit("Video file preview and upload"));

	echonullbtnFrame_btnFrame = new btnframe();
	echonullbtnFrame_btnFrame->m_titleLabel->setText(QString::fromLocal8Bit("NULL"));
	echonullbtnFrame_btnFrame->m_detailLabel->setText(QString::fromLocal8Bit("NULL"));
}

void btngroup::LayoutUi()
{
	contentGridLayout = new QGridLayout(this);
	contentGridLayout->setObjectName("contentGridLayout");
	contentGridLayout->setSpacing(0);
	contentGridLayout->setContentsMargins(0, 0, 0, 0);
	contentGridLayout->addWidget(echoremoteDesktop_btnFrame, 0, 0, 1, 1);
	contentGridLayout->addWidget(echoOpertion_btnFrame, 0, 1, 1, 1);
	contentGridLayout->addWidget(echocentralControlCommand_btnFrame, 0, 2, 1, 1);
	contentGridLayout->addWidget(echoMaterialManageMent_btnFrame, 1, 0, 1, 1);
	contentGridLayout->addWidget(echonullbtnFrame_btnFrame, 1, 1, 1, 2);
}
