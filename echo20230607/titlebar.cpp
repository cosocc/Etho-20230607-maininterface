#include "titlebar.h"
#include <Windows.h>
#include <QIcon>
#include <QMenu>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

titlebar::titlebar(QWidget* parent)
	: QWidget(parent)
{

	createTileUi();
	createLayout();
	createActionAndMenu();


	connect(tbtnMax, &QToolButton::clicked, this, &titlebar::OntristateBtnControl);
	connect(tbtnMin, &QToolButton::clicked, this, &titlebar::OntristateBtnControl);
	connect(tbtnClose, &QToolButton::clicked, this, &titlebar::OntristateBtnControl);


	//本类的状态按钮triggered消息 被翻译成了三态按钮信号  也就是对外提供了下面三个信号
	//void StatusBtnClicked_signal();
	//void PlcStatusbtnClicked_signal();
	//void UPSStatusbtnClicked_signal();
	connect(menuStatus, SIGNAL(triggered(QAction*)), this, SLOT(OnMenuStatusClick(QAction*)));

	connect(menulanguage, SIGNAL(triggered(QAction*)), this, SLOT(OnLanguageMenuClick(QAction*)));
	connect(tbtnUps, &QToolButton::clicked, this, &titlebar::sg_Ups_btn_clk);
	connect(tbtnOption, &QToolButton::clicked, this, &titlebar::sg_Option_btn_clk);
	connect(tbtnRescan, &QToolButton::clicked, this, &titlebar::sg_Rescan_btn_clk);
	connect(tbtnAddServer, &QToolButton::clicked, this, &titlebar::sg_AddServer_btn_clk);



}

titlebar::~titlebar()
{


}

void titlebar::createLayout()
{
	titleHboxLayout = new QHBoxLayout(this);
	titleHboxLayout->setContentsMargins(0, 0, 0, 0);
	titleHboxLayout->setSpacing(0);
	titleHboxLayout->addWidget(iconLabel);
	titleHboxLayout->addWidget(titleLabel);
	titleHboxLayout->addSpacerItem(spacer);
	titleHboxLayout->addWidget(tbtnAddServer);
	titleHboxLayout->addWidget(tbtnUps);
	titleHboxLayout->addWidget(tbtnRescan);
	titleHboxLayout->addWidget(tbtnStatus);
	titleHboxLayout->addWidget(tbtnOption);
	titleHboxLayout->addWidget(tbtnLanguage);
	titleHboxLayout->addWidget(tbtnMin);
	titleHboxLayout->addWidget(tbtnMax);
	titleHboxLayout->addWidget(tbtnClose);
}

void titlebar::createTileUi()
{
	QIcon icon(".\\img\\sg.ico");
	iconLabel = new QLabel(this);
	iconLabel->setPixmap(icon.pixmap(QSize(32, 32)));
	titleLabel = new QLabel(tr("Master Control"));
	spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
	tbtnAddServer = new QToolButton(this);
	tbtnAddServer->setText(QString::fromLocal8Bit("Add Server"));
	tbtnUps = new QToolButton(this);
	tbtnUps->setText(QString::fromLocal8Bit("UPS"));
	tbtnRescan = new QToolButton(this);
	tbtnRescan->setText(QString::fromLocal8Bit("Rescan"));
	tbtnStatus = new QToolButton(this);
	tbtnStatus->setText(QString::fromLocal8Bit("Status"));
	tbtnOption = new QToolButton(this);
	tbtnOption->setText(QString::fromLocal8Bit("Option"));
	tbtnLanguage = new QToolButton(this);
	tbtnLanguage->setText(QString::fromLocal8Bit("Language"));
	tbtnMin = new QToolButton(this);
	QIcon iconMin(".\\img\\min.png");
	tbtnMin->setIcon(iconMin);
	tbtnMax = new QToolButton(this);
	QIcon iconMax(".\\img\\max.png");
	tbtnMax->setIcon(iconMax);
	tbtnClose = new QToolButton(this);
	QIcon iconClose(".\\img\\close.png");
	tbtnClose->setIcon(iconClose);
}

void titlebar::mousePressEvent(QMouseEvent* event)
{
	if (ReleaseCapture())
	{
		QWidget* pWindow = this->window();
		if (pWindow->isTopLevel())
		{
			//When the mouse hovers over the title and the left mouse button is clicked, it can be dragged / moved
			::SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
	}
	event->ignore();
}


void titlebar::mouseDoubleClickEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	emit tbtnMax->clicked();
}



void titlebar::OntristateBtnControl()
{

	QToolButton* pButton = qobject_cast<QToolButton*>(sender());
	QWidget* pWindow = this->window();
	if (pWindow->isTopLevel())
	{
		if (pButton == tbtnMin)
		{
			pWindow->showMinimized();
		}
		else if (pButton == tbtnMax)
		{
			pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
		}
		else if (pButton == tbtnClose)
		{
			pWindow->close();
		}
	}

}


void titlebar::createActionAndMenu()
{
	menulanguage = new QMenu(this);
	QAction* zh = new QAction(tr("Chinese"), menulanguage);
	QAction* en = new QAction(tr("English"), menulanguage);
	en->setData("EN");
	zh->setData("ZH");
	menulanguage->addAction(zh);
	menulanguage->addAction(en);
	tbtnLanguage->setPopupMode(QToolButton::InstantPopup);
	tbtnLanguage->setMenu(menulanguage);

	menuStatus = new QMenu(this);
	QAction* PLC = new QAction(tr("PLC"), menuStatus);
	QAction* Server = new QAction(tr("serverState"), menuStatus);
	QAction* UPS = new QAction(tr("UPS"), menuStatus);
	PLC->setData("PLC");
	Server->setData("serverState");
	UPS->setData("UPS");
	menuStatus->addAction(PLC);
	menuStatus->addAction(Server);
	menuStatus->addAction(UPS);
	tbtnStatus->setPopupMode(QToolButton::InstantPopup);
	tbtnStatus->setMenu(menuStatus);
}



void titlebar::OnLanguageMenuClick(QAction* action)
{
	QString tag = action->data().toString();
	//CLinguist* lin = CLinguist::GetLinguistInstance();
	if (tag == "EN") {
		//lin->ChangeLanguage(Language::en_us);

	}
	else if (tag == "ZH") {
		//lin->ChangeLanguage(Language::zh_cn);
	}

}

void titlebar::OnMenuStatusClick(QAction* action)
{
	QString tag = action->data().toString();
	if (tag == "PLC") {
		emit sg_MenuStatus_Plc_clk();
	}
	else if (tag == "serverState") {
		emit sg_MenuStatus_ServerStatus_clk();
	}
	else if (tag == "UPS") {
		emit sg_MenuStatus_Ups_clk();
	}
}