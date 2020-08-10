// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QString>

namespace WalletGui {

class INotificationMonitorObserver {
public:
  virtual ~INotificationMonitorObserver() {}
  virtual void notify(const QString& _notification) = 0;
};

}
