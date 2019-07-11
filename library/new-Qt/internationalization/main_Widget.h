//
// Created by kaiser on 19-7-11.
//

#ifndef CPP_STUDY_LIBRARY_NEW_QT_INTERNATIONALIZATION_MAIN_WIDGET_H_
#define CPP_STUDY_LIBRARY_NEW_QT_INTERNATIONALIZATION_MAIN_WIDGET_H_

#include <QEvent>
#include <QLabel>
#include <QPushButton>
#include <QTranslator>
#include <QWidget>

#include "setting_dialog.h"

class MainWidget : public QWidget {
  Q_OBJECT
 public:
  MainWidget();
  void SetLanguage(Language curr_language);
  void SetTranslator(QTranslator *translator);
  void SetSysTranslator(QTranslator *translator);

 protected:
  void changeEvent(QEvent *event) override;

 private:
  void TranslateUi();

  QLabel *label_;
  QPushButton *setting_;
  QPushButton *determine_;
  QPushButton *cancel_;
  QPushButton *about_qt_;

  SettingDialog *setting_dialog_;
  Language curr_language_{Language::kChinese};
  QTranslator *translator_{};
  QTranslator *sys_translator_{};

 private slots:
  void ShowSetting();
  void SwitchLanguage(Language language);
};

#endif  // CPP_STUDY_LIBRARY_NEW_QT_INTERNATIONALIZATION_MAIN_WIDGET_H_
