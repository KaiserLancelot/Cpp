//
// Created by kaiser on 19-3-30.
//

#include "main_window.h"

#include <QTimer>

#include "consts.h"

MainWindow::MainWindow()
    : scene_{new QGraphicsScene(this)},
      view_{new QGraphicsView(scene_, this)},
      controller_{new GameController(scene_, this)} {
  setCentralWidget(view_);
  resize(800, 800);

  InitScene();

  // 在第一个参数指定的毫秒后调用槽函数
  // 需要在视图绘制完毕后才去改变大小, 在一下次事件循环开始时立即调用槽函数
  QTimer::singleShot(0, this, &MainWindow::AdjustViewSize);
}

void MainWindow::InitScene() {
  scene_->setSceneRect(-100, -100, 200, 200);
  QPixmap bg{TILE_SIZE, TILE_SIZE};
  QPainter p{&bg};
  p.setBrush(Qt::gray);
  p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

  view_->setBackgroundBrush(bg);
}

void MainWindow::AdjustViewSize() {
  view_->fitInView(scene_->sceneRect(), Qt::KeepAspectRatioByExpanding);
}
