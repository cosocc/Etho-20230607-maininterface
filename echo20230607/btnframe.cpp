#include "btnframe.h"
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>
#include <QPoint>
btnframe::btnframe(QWidget* parent)
	: QFrame(parent), m_bEnter(false)
{
	createUI();
}

btnframe::~btnframe()
{

}

void btnframe::SetTitle(QString title)
{
	m_titleLabel->setText(title);
}

void btnframe::SetDetail(QString detail)
{
	m_detailLabel->setText(detail);
}

void btnframe::mousePressEvent(QMouseEvent* event)
{
	if (event->buttons() & Qt::LeftButton) {
		emit mouseLPressSignal();
	}
	QFrame::mouseMoveEvent(event);

}

void btnframe::enterEvent(QEvent* event)
{
	m_bEnter = true;
	QCursor tempCursor;
	tempCursor = cursor();
	tempCursor.setShape(Qt::PointingHandCursor);
	setCursor(tempCursor);
	m_titleLabel->setStyleSheet("color:#000");
	m_detailLabel->setStyleSheet("color:#000");
	QWidget::enterEvent(event);
	update();
}

void btnframe::leaveEvent(QEvent* event)
{
	m_bEnter = false;
	QCursor tempCursor;
	tempCursor = cursor();
	tempCursor.setShape(Qt::ArrowCursor);
	setCursor(tempCursor);
	m_titleLabel->setStyleSheet("color:#FFF");
	m_detailLabel->setStyleSheet("color:#FFF");
	QWidget::enterEvent(event);
	update();
}

void btnframe::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	if (m_bEnter)
	{
		painter.fillRect(event->rect(), QColor(255, 255, 255, 128));
	}
	else
	{
		painter.fillRect(event->rect(), QColor(128, 128, 128, 0));
	}

}

void btnframe::createUI()
{
	resize(400, 300);
	m_titleLabel = new QLabel(QString::fromLocal8Bit("NULL"));
	QFont f_m_titleLabel;
	f_m_titleLabel.setPointSize(15);
	f_m_titleLabel.setBold(true);
	f_m_titleLabel.setWeight(75);
	m_titleLabel->setStyleSheet("color:#FFF");
	m_titleLabel->setFont(f_m_titleLabel);
	m_titleLabel->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
	m_detailLabel = new QLabel(QString::fromLocal8Bit("NULL"));
	QFont f_m_detailLabel;
	f_m_detailLabel.setWeight(50);
	m_detailLabel->setStyleSheet("color:#FFF");
	m_detailLabel->setFont(f_m_detailLabel);
	m_detailLabel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	m_detailLabel->setWordWrap(true);
	btnFrameVlayout = new QVBoxLayout(this);
	btnFrameVlayout->setContentsMargins(0, 0, 0, 0);
	btnFrameVlayout->addWidget(m_titleLabel);
	btnFrameVlayout->addWidget(m_detailLabel);
}
