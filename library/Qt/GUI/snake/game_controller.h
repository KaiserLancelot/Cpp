//
// Created by kaiser on 19-3-30.
//

#ifndef CPP_STUDY_LIBRARY_QT_GUI_SNAKE_GAME_CONTROLLER_H_
#define CPP_STUDY_LIBRARY_QT_GUI_SNAKE_GAME_CONTROLLER_H_

#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>

#include "food.h"

class Snake;

// 初始化场景中的游戏对象, 开始游戏循环
class GameController : public QObject {
  Q_OBJECT
 public:
  explicit GameController(QGraphicsScene *scene, QObject *parent = nullptr);

  void SnakeAteFood(Food *food);

 protected:
  bool eventFilter(QObject *object, QEvent *event) override;

 private:
  void HandleKeyPressed(QKeyEvent *event);
  void AddNewFood();

  QTimer timer_;
  QGraphicsScene *scene_;
  Snake *snake_;
  bool is_pause_{false};

 public slots:
  void Pause();
  void Resume();
  void GameOver();
};

#endif  // CPP_STUDY_LIBRARY_QT_GUI_SNAKE_GAME_CONTROLLER_H_
