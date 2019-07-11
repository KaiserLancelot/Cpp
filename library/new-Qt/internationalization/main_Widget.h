//
// Created by kaiser on 19-7-11.
//

#ifndef CPP_STUDY_LIBRARY_NEW_QT_INTERNATIONALIZATION_MAIN_WIDGET_H_
#define CPP_STUDY_LIBRARY_NEW_QT_INTERNATIONALIZATION_MAIN_WIDGET_H_

#include <QLabel>
#include <QPushButton>
#include <QWidget>

class MainWidget : public QWidget {
  Q_OBJECT
 public:
  MainWidget();

 private:
  void TranslateUi();

  QLabel *label_;
  QPushButton *setting_;
  QPushButton *determine_;
  QPushButton *cancel_;
};

#endif  // CPP_STUDY_LIBRARY_NEW_QT_INTERNATIONALIZATION_MAIN_WIDGET_H_
