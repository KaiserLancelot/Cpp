//
// Created by kaiser on 19-7-11.
//

#ifndef CPP_STUDY_LIBRARY_NEW_QT_CUSTOM_LINE_EDIT_SEARCH_LINE_EDIT_H_
#define CPP_STUDY_LIBRARY_NEW_QT_CUSTOM_LINE_EDIT_SEARCH_LINE_EDIT_H_

#include <QAction>
#include <QKeyEvent>
#include <QLineEdit>
#include <QString>
#include <QWidget>

class SearchLineEdit : public QLineEdit {
  Q_OBJECT
 public:
  explicit SearchLineEdit(QWidget *parent = nullptr);

 protected:
  void keyPressEvent(QKeyEvent *event) override;

 private:
  QAction *search_;

 signals:
  void OnButtonClicked(QString);
};

#endif  // CPP_STUDY_LIBRARY_NEW_QT_CUSTOM_LINE_EDIT_SEARCH_LINE_EDIT_H_
