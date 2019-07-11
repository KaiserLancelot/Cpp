//
// Created by kaiser on 19-7-11.
//

#ifndef CPP_STUDY_LIBRARY_NEW_QT_CUSTOM_MAIN_WINDOW_TITLE_BAR_H_
#define CPP_STUDY_LIBRARY_NEW_QT_CUSTOM_MAIN_WINDOW_TITLE_BAR_H_

#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QToolButton>
#include <QWidget>

class TitleBar : public QWidget {
  Q_OBJECT
 public:
  explicit TitleBar(QWidget *parent = nullptr);
  void SetIcon(const QString &file_name);

 protected:
  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void mouseDoubleClickEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;

 private:
  QPoint position_;
  bool pressed_{false};

  QLabel *icon_label_;

  QToolButton *minimize_button_;
  QToolButton *maximize_button_;
  QToolButton *close_button_;

  QWidget *parent_;

 private slots:
  void OnClickedMaximizeButton();
  void OnClickedCloseButton();
};

#endif  // CPP_STUDY_LIBRARY_NEW_QT_CUSTOM_MAIN_WINDOW_TITLE_BAR_H_
