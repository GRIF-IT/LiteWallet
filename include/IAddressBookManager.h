// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QObject>

namespace WalletGui {

const quintptr INVALID_ADDRESS_INDEX = std::numeric_limits<quintptr>::max();

struct AddressItem {
  QString label;
  QString address;
  QString paymentId;
  bool isDonationAddress;
};

class IAddressBookManagerObserver {
public:
  virtual ~IAddressBookManagerObserver() {}
  virtual void addressBookOpened() = 0;
  virtual void addressBookClosed() = 0;
  virtual void addressAdded(quintptr _addressIndex) = 0;
  virtual void addressEdited(quintptr _addressIndex) = 0;
  virtual void addressRemoved(quintptr _addressIndex) = 0;
};

class IAddressBookManager {
public:
  virtual ~IAddressBookManager() {}
  virtual quintptr getAddressCount() const = 0;
  virtual AddressItem getAddress(quintptr _addressIndex) const = 0;
  virtual quintptr findAddressByAddress(const QString& _address) const = 0;
  virtual quintptr findAddressByPaymentId(const QString& _paymentid) const = 0;
  virtual quintptr findAddressByLabel(const QString& _label) const = 0;
  virtual quintptr findAddress(const QString& _label, const QString& _address, const QString& _paymentid) const = 0;
  virtual quintptr findAddress(const QString& _label, const QString& _address, bool _isDonationAddress) const = 0;
  virtual void addAddress(const QString& _label, const QString& _address, const QString& _paymentid, bool _isDonationAddress) = 0;
  virtual void editAddress(quintptr _addressIndex, const QString& _label, const QString& _address, const QString& _paymentid, bool _isDonationAddress) = 0;
  virtual void removeAddress(quintptr _addressIndex) = 0;

  virtual void addObserver(IAddressBookManagerObserver* _observer) = 0;
  virtual void removeObserver(IAddressBookManagerObserver* _observer) = 0;
};

}
