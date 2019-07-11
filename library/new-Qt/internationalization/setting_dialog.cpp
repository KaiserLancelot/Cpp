//
// Created by kaiser on 19-7-11.
//

#include "setting_dialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QVariant>
#include <QtGlobal>

SettingDialog::SettingDialog(QWidget* parent)
    : QDialog{parent},
      label_{new QLabel{this}},
      language_label_{new QLabel{this}},
      language_combo_box_{new QComboBox{this}} {
  setMinimumSize(500, 300);

  language_combo_box_->addItem(tr("chinese"),
                               QVariant::fromValue(Language::kChinese));
  language_combo_box_->addItem(tr("english"),
                               QVariant::fromValue(Language::kEnglish));
  language_combo_box_->setFixedWidth(100);

  auto layout{new QHBoxLayout};
  layout->addStretch(1);
  layout->addWidget(language_label_);
  layout->addSpacing(10);
  layout->addWidget(language_combo_box_);
  layout->addStretch(1);

  auto main_layout{new QVBoxLayout{this}};
  main_layout->addWidget(label_, 0, Qt::AlignCenter);
  main_layout->addLayout(layout);

  TranslateUi();

  // 如果要在 Qt 信号槽中使用自定义类型传递参数, 需要注意使用
  // qRegisterMetaType 对自定义类型进行注册
  // 引用类型需要单独注册 qRegisterMetaType<Language>("Language&");
  qRegisterMetaType<Language>("Language");

  connect(language_combo_box_,
          QOverload<int>::of(&QComboBox::currentIndexChanged), this,
          &SettingDialog::OnIndexChanged);
}

void SettingDialog::TranslateUi() {
  setWindowTitle(tr("Setting Dialog"));
  label_->setText(tr("Hello World"));
  language_label_->setText(tr("Language"));

  language_combo_box_->setItemText(0, tr("chinese"));
  language_combo_box_->setItemText(1, tr("english"));
}

void SettingDialog::OnIndexChanged() {
  auto language{language_combo_box_->currentData().value<Language>()};
  emit SwitchLanguage(language);
}

void SettingDialog::changeEvent(QEvent* event) {
  if (event->type() == QEvent::LanguageChange) {
    TranslateUi();
  } else {
    QWidget::changeEvent(event);
  }
}
