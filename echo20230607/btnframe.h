#pragma once

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
class btnframe : public QFrame
{
	Q_OBJECT

public:
	btnframe(QWidget* parent = Q_NULLPTR);
	~btnframe();
	void SetTitle(QString title);
	void SetDetail(QString detail);
signals:
	void mouseLPressSignal();
protected:
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void enterEvent(QEvent* event) override;
	virtual void leaveEvent(QEvent* event) override;
	virtual void paintEvent(QPaintEvent* event)override;
public:
	QLabel* m_titleLabel;
	QLabel* m_detailLabel;
private:
	void createUI();
	QVBoxLayout* btnFrameVlayout;
	bool m_bEnter;
};
