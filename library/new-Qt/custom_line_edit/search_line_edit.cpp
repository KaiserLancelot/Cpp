//
// Created by kaiser on 19-7-11.
//

#include "search_line_edit.h"

#include <QIcon>

SearchLineEdit::SearchLineEdit(QWidget* parent)
    : QLineEdit(parent), search_{new QAction{this}} {
  QIcon icon;
  icon.addFile(":search_normal", QSize{}, QIcon::Normal);
  icon.addFile(":search_press", QSize{}, QIcon::Active);
  search_->setIcon(icon);

  search_->setToolTip(tr("search"));
  addAction(search_, TrailingPosition);
  setClearButtonEnabled(true);

  connect(search_, &QAction::triggered,
          [this] { emit OnButtonClicked(text()); });
}

void SearchLineEdit::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Enter) {
    emit OnButtonClicked(text());
  } else {
    QLineEdit::keyPressEvent(event);
  }
}
