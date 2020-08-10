// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QObject>

namespace WalletGui {

class IDonationManagerObserver {
public:
  virtual ~IDonationManagerObserver() {}
  virtual void donationManagerOpened() = 0;
  virtual void donationManagerClosed() = 0;
  virtual void donationChangeEnabled(bool _on) = 0;
  virtual void donationChangeAddressChanged(const QString& _address) = 0;
  virtual void donationChangeAmountChanged(int _amount) = 0;
};

class IDonationManager {
public:
  virtual ~IDonationManager() {}
  virtual bool isDonationChangeEnabled() const = 0;
  virtual QString getDonationChangeAddress() const = 0;
  virtual int getDonationChangeAmount() const = 0;

  virtual void setDonationChangeEnabled(bool _on) = 0;
  virtual void setDonationChangeAddress(const QString& _address) = 0;
  virtual void setDonationChangeAmount(int _amount) = 0;

  virtual void addObserver(IDonationManagerObserver* _observer) = 0;
  virtual void removeObserver(IDonationManagerObserver* _observer) = 0;
};

}
