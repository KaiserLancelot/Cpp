//
// Created by kaiser on 19-7-11.
//

#include "main_widget.h"

#include <QMessageBox>
#include <QString>
#include <QVBoxLayout>

MainWidget::MainWidget()
    : normal_{new QLineEdit{this}},
      custom_{new PasswordLineEdit{this}},
      search_{new SearchLineEdit{this}} {
  setMinimumSize(1000, 800);

  auto layout{new QVBoxLayout{this}};
  layout->addWidget(normal_);
  layout->addWidget(custom_);
  layout->addWidget(search_);

  normal_->setEchoMode(QLineEdit::Password);

  connect(search_, &SearchLineEdit::OnButtonClicked,
          [this](const QString &text) {
            if (!text.isEmpty()) {
              QMessageBox::information(this, tr("Search"),
                                       tr("Search content is %1").arg(text));
            }
          });
}
