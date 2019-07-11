//
// Created by kaiser on 19-7-11.
//

#include "main_Widget.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include <QSettings>
#include <QString>
#include <QVBoxLayout>

MainWidget::MainWidget()
    : label_{new QLabel{this}},
      setting_{new QPushButton{this}},
      determine_{new QPushButton{this}},
      cancel_{new QPushButton{this}},
      about_qt_{new QPushButton{this}},
      setting_dialog_{new SettingDialog{this}} {
  setMinimumSize(1000, 600);

  auto button_layout{new QHBoxLayout};
  // 添加一个可伸缩空间, 如果只有一个为 0 的则占有全部剩余空间
  // 有多个为 0 的则平均分配, 有其他数字则忽略 0, 其他的按比例分配
  button_layout->addStretch();
  button_layout->addWidget(setting_);
  button_layout->addWidget(determine_);
  button_layout->addWidget(cancel_);
  button_layout->addWidget(about_qt_);
  // 设置 widget 的间距
  button_layout->setSpacing(10);

  auto main_layout{new QVBoxLayout{this}};
  // 第二个参数指示按比例分配给 widget 的空间, 0 为默认
  main_layout->addWidget(label_, 0, Qt::AlignCenter);
  main_layout->addLayout(button_layout);
  // 添加一个不可伸缩的空间
  main_layout->addSpacing(10);

  TranslateUi();

  connect(setting_dialog_, &SettingDialog::SwitchLanguage, this,
          &MainWidget::SwitchLanguage);
  connect(setting_, &QPushButton::clicked, this, [this] {
    setting_dialog_->SetLanguage(curr_language_);
    setting_dialog_->show();
  });
  connect(determine_, &QPushButton::clicked, this, &MainWidget::close);
  connect(cancel_, &QPushButton::clicked, this, &MainWidget::close);
  connect(about_qt_, &QPushButton::clicked, this,
          [this] { QMessageBox::aboutQt(this); });
}

void MainWidget::TranslateUi() {
  setWindowTitle(tr("Main Widget"));
  label_->setText(tr("Welcome to Qt"));
  setting_->setText(tr("Setting"));
  determine_->setText(tr("ok"));
  cancel_->setText(tr("cancel"));
  about_qt_->setText(tr("about"));
}

void MainWidget::SwitchLanguage(Language language) {
  if (curr_language_ != language) {
    curr_language_ = language;
    translator_->load(curr_language_ == Language::kChinese ? ":zh-CN"
                                                           : ":en-US");
    sys_translator_->load(curr_language_ == Language::kChinese ? ":qt_zh_CN"
                                                               : ":qt_en");
    QSettings settings;
    settings.beginGroup("General");
    settings.setValue("language", curr_language_ == Language::kChinese
                                      ? "chinese"
                                      : "english");
  }
}

void MainWidget::changeEvent(QEvent* event) {
  if (event->type() == QEvent::LanguageChange) {
    TranslateUi();
  } else {
    QWidget::changeEvent(event);
  }
}

void MainWidget::SetLanguage(Language curr_language) {
  curr_language_ = curr_language;
}

void MainWidget::SetTranslator(QTranslator* translator) {
  translator_ = translator;
}

void MainWidget::SetSysTranslator(QTranslator* translator) {
  sys_translator_ = translator;
}
