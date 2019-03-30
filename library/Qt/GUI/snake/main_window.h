//
// Created by kaiser on 19-3-30.
//

#ifndef CPP_STUDY_LIBRARY_QT_GUI_SNAKE_MAIN_WINDOW_H_
#define CPP_STUDY_LIBRARY_QT_GUI_SNAKE_MAIN_WINDOW_H_

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>

#include "game_controller.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();

 private:
  void InitScene();

  QGraphicsScene *scene_;
  QGraphicsView *view_;
  GameController *controller_;

 private slots:
  void AdjustViewSize();
};

#endif  // CPP_STUDY_LIBRARY_QT_GUI_SNAKE_MAIN_WINDOW_H_
