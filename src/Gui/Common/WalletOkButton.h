// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QPushButton>

namespace WalletGui {

class WalletOkButton : public QPushButton {
  Q_OBJECT
  Q_DISABLE_COPY(WalletOkButton)

public:
  explicit WalletOkButton(QWidget* _parent);
  ~WalletOkButton();
};

}
