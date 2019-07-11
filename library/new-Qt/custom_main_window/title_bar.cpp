//
// Created by kaiser on 19-7-11.
//

#include "title_bar.h"

#include <QHBoxLayout>
#include <QIcon>
#include <QPainter>

TitleBar::TitleBar(QWidget* parent)
    : QWidget{parent},
      icon_label_{new QLabel{this}},
      minimize_button_{new QToolButton{this}},
      maximize_button_{new QToolButton{this}},
      close_button_{new QToolButton{this}} {
  parent_ = qobject_cast<QWidget*>(parent);

  setFixedHeight(100);

  icon_label_->setFixedSize(200, 60);
  icon_label_->setScaledContents(true);

  minimize_button_->setFixedSize(40, 40);
  maximize_button_->setFixedSize(40, 40);
  close_button_->setFixedSize(40, 40);

  minimize_button_->setToolTip("Minimize");
  maximize_button_->setToolTip("Maximize");
  close_button_->setToolTip("Close");

  minimize_button_->setIcon(QIcon{":minimize"});
  close_button_->setIcon(QIcon{":close"});

  auto layout{new QHBoxLayout{this}};
  layout->addWidget(icon_label_);
  layout->addSpacing(20);
  layout->addStretch();
  layout->addWidget(minimize_button_);
  layout->addWidget(maximize_button_);
  layout->addWidget(close_button_);

  connect(minimize_button_, &QToolButton::clicked, this,
          [this] { parent_->showMinimized(); });
  connect(maximize_button_, &QToolButton::clicked, this,
          &TitleBar::OnClickedMaximizeButton);
  connect(close_button_, &QToolButton::clicked, this,
          &TitleBar::OnClickedCloseButton);
}

void TitleBar::mouseMoveEvent(QMouseEvent* event) {
  if (pressed_) {
    parent_->move(parent_->pos() + (event->pos() - position_));
  }

  QWidget::mouseMoveEvent(event);
}

void TitleBar::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton) {
    pressed_ = true;
    position_ = event->pos();
  }

  QWidget::mousePressEvent(event);
}

void TitleBar::mouseReleaseEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton) {
    pressed_ = false;
  }

  QWidget::mouseReleaseEvent(event);
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent* event) {
  OnClickedMaximizeButton();
  QWidget::mouseDoubleClickEvent(event);
}

void TitleBar::SetIcon(const QString& file_name) {
  icon_label_->setPixmap(QIcon{file_name}.pixmap(icon_label_->size()));
}

void TitleBar::OnClickedCloseButton() { parent_->close(); }

// 设置背景颜色
void TitleBar::paintEvent(QPaintEvent* event) {
  QPainter p{this};
  p.setPen(Qt::NoPen);
  p.setBrush(Qt::darkGray);
  p.drawRect(rect());

  QWidget::paintEvent(event);
}

void TitleBar::OnClickedMaximizeButton() {
  if (parent_->isMaximized()) {
    parent_->showNormal();
  } else {
    parent_->showMaximized();
  }
}
