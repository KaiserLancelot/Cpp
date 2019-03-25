//
// Created by kaiser on 19-3-23.
//

// 事件是由系统或者 Qt 本身在不同的时刻发出的.
// 当用户按下鼠标, 敲下键盘, 或者是窗口需要重新绘制的时候
// 都会发出一个相应的事件.一些事件在对用户操作做出响应时发出,
// 如键盘事件等;另一些事件则是由系统自动发出,如计时器事件

// 总的来说, 如果我们使用组件, 我们关心的是信号槽;如果我们自定义组件,
// 我们关心的是事件.因为我们可以通过事件来改变组件的默认操作

#include <QApplication>
#include <QLabel>
#include <QMouseEvent>
#include <QString>

class EventLabel : public QLabel {
 protected:
  void mouseMoveEvent(QMouseEvent *event) override {
    this->setText(
        QString("<center><h1>Move: (%1, %2)</h1></center>")
            .arg(QString::number(event->x()), QString::number(event->y())));
  }

  void mousePressEvent(QMouseEvent *event) override {
    this->setText(
        QString("<center><h1>Press: (%1, %2)</h1></center>")
            .arg(QString::number(event->x()), QString::number(event->y())));
  }

  void mouseReleaseEvent(QMouseEvent *event) override {
    this->setText(
        QString("<center><h1>Release: (%1, %2)</h1></center>")
            .arg(QString::number(event->x()), QString::number(event->y())));
  }
};

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  EventLabel label;
  label.setWindowTitle("MouseEvent Demo");
  label.resize(600, 400);
  // 该属性用于设置是否追踪鼠标.只有鼠标被追踪时, mouseMoveEvent()
  // 等事件才会发出, 默认是 false , 所以至少一次鼠标点击之后, 才能够被追踪
  label.setMouseTracking(true);
  label.show();

  QApplication::exec();
}