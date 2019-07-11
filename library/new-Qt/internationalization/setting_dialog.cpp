//
// Created by kaiser on 19-7-11.
//

#include "setting_dialog.h"

#include <QVariant>
#include <QtGlobal>

SettingDialog::SettingDialog(QWidget* parent)
    : QDialog{parent},
      label_{new QLabel{this}},
      language_label_{new QLabel{this}},
      language_combo_box_{new QComboBox{this}} {
  language_combo_box_->addItem(tr("chinese"),
                               QVariant::fromValue(Language::kChinese));
  language_combo_box_->addItem(tr("english"),
                               QVariant::fromValue(Language::kEnglish));
}

void SettingDialog::TranslateUi() {
  setWindowTitle(tr("Setting Dialog"));
  label_->setText(tr("Hello World"));
  language_label_->setText(tr("Language"));

  language_combo_box_->setItemText(0, tr("chinese"));
  language_combo_box_->setItemText(1, tr("english"));

  connect(language_combo_box_,
          QOverload<int>::of(&QComboBox::currentIndexChanged), this,
          &SettingDialog::OnIndexChanged);
}

void SettingDialog::OnIndexChanged() {
  auto language{language_combo_box_->currentData().value<Language>()};
  emit SwitchLanguage(language);
}

void SettingDialog::changeEvent(QEvent* event) {
  switch (event->type()) {
    // The application translation changed.
    case QEvent::LanguageChange:
      TranslateUi();
      break;
    default:
      QDialog::changeEvent(event);
  }
}
