//
// Created by kaiser on 19-7-11.
//

#include "main_widget.h"

#include <QVBoxLayout>

MainWidget::MainWidget()
    : normal_{new QLineEdit{this}},
      custom_{new PasswordLineEdit{this}},
      search_{new SearchLineEdit{this}} {
  auto layout{new QVBoxLayout{this}};
  layout->addWidget(normal_);
  layout->addWidget(custom_);
  layout->addWidget(search_);

  normal_->setEchoMode(QLineEdit::Password);
}
