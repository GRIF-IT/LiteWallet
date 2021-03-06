// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QLineEdit>

namespace WalletGui {

class ClearableLineEdit : public QLineEdit {
  Q_OBJECT
  Q_DISABLE_COPY(ClearableLineEdit)

public:
  explicit ClearableLineEdit(QWidget* _parent = 0);
  ~ClearableLineEdit();
};

}
