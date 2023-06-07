#pragma once

#include <QWidget>
#include <QLabel>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QToolButton>
class titlebar : public QWidget
{
	Q_OBJECT

public:
	titlebar(QWidget* parent = Q_NULLPTR);
	~titlebar();
	void createLayout();
	void createTileUi();


public:
	QHBoxLayout* titleHboxLayout;
	QLabel* iconLabel;
	QLabel* titleLabel;
	QSpacerItem* spacer;
	QToolButton* tbtnAddServer;
	QToolButton* tbtnUps;
	QToolButton* tbtnLanguage;
	QToolButton* tbtnOption;
	QToolButton* tbtnRescan;
	QToolButton* tbtnStatus;
	QToolButton* tbtnClose;
	QToolButton* tbtnMax;
	QToolButton* tbtnMin;
	QMenu* menuStatus;
	QMenu* menulanguage;
protected:
	//move the window
	virtual void mousePressEvent(QMouseEvent* event) override;
	//zoomin the window
	virtual void mouseDoubleClickEvent(QMouseEvent* event) override;

private slots:
	void OntristateBtnControl();
	void OnMenuStatusClick(QAction* action);
	void OnLanguageMenuClick(QAction* action);
signals:
	void sg_Option_btn_clk();
	void sg_Rescan_btn_clk();
	void sg_AddServer_btn_clk();
	void sg_Ups_btn_clk();
	void sg_MenuStatus_Plc_clk();
	void sg_MenuStatus_ServerStatus_clk();
	void sg_MenuStatus_Ups_clk();


private:
	void createActionAndMenu();
};
