// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QPushButton>

namespace WalletGui {

class WalletBlueButton : public QPushButton {
  Q_OBJECT
  Q_DISABLE_COPY(WalletBlueButton)

public:
  explicit WalletBlueButton(QWidget* _parent);
  virtual ~WalletBlueButton();
};

class WalletNormalBlueButton : public WalletBlueButton {
  Q_OBJECT
  Q_DISABLE_COPY(WalletNormalBlueButton)

public:
  explicit WalletNormalBlueButton(QWidget* _parent);
  ~WalletNormalBlueButton();
};

class WalletLargeBlueButton : public WalletBlueButton {
  Q_OBJECT
  Q_DISABLE_COPY(WalletLargeBlueButton)

public:
  explicit WalletLargeBlueButton(QWidget* _parent);
  ~WalletLargeBlueButton();
};

}
