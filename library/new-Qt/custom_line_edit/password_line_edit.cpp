//
// Created by kaiser on 19-7-11.
//

#include "password_line_edit.h"

PasswordLineEdit::PasswordLineEdit(QWidget *parent) : QLineEdit(parent) {
  // 无右键菜单
  setContextMenuPolicy(Qt::NoContextMenu);
  // 无输入时提示信息
  setPlaceholderText(tr("Please enter your password"));
  // 密码效果模式
  // QLineEdit::Normal 输入时, 正常显示字符, 默认值
  // QLineEdit::NoEcho 不显示任何信息, 密码长度, 信息需要保密时比较适用
  // QLineEdit::Password 显示平台相关的密码掩码字符, 而非实际的字符输入
  // QLineEdit::PasswordEchoOnEdit 编辑时候显示字符, 编辑结束后和
  // QLineEdit::Password 效果一样
  setEchoMode(QLineEdit::Password);
  // 最大输入长度16位
  setMaxLength(16);
}
