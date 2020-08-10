// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

class QAbstractItemModel;
class QWidget;

namespace WalletGui {

class ICryptoNoteAdapter;
class IAddressBookManager;
class IDonationManager;
class IOptimizationManager;
class IApplicationEventHandler;
class INewsReader;

class IWalletUiItem {
public:
  virtual ~IWalletUiItem() {}
  virtual void setCryptoNoteAdapter(ICryptoNoteAdapter* _cryptoNoteAdapter) {}
  virtual void setAddressBookManager(IAddressBookManager* _addressBookManager) {}
  virtual void setOptimizationManager(IOptimizationManager* _optimizationManager) {}
  virtual void setDonationManager(IDonationManager* _donationManager) {}
  virtual void setApplicationEventHandler(IApplicationEventHandler* _applicationEventHandler) {}
  virtual void setMainWindow(QWidget* _mainWindow) {}
  virtual void setTransactionsModel(QAbstractItemModel* _model) {}
  virtual void setSortedTransactionsModel(QAbstractItemModel* _model) {}
  virtual void setNodeStateModel(QAbstractItemModel* _model) {}
  virtual void setWalletStateModel(QAbstractItemModel* _model) {}
  virtual void setAddressBookModel(QAbstractItemModel* _model) {}
  virtual void setSortedAddressBookModel(QAbstractItemModel* _model) {}
  virtual void setBlockChainModel(QAbstractItemModel* _model) {}
  virtual void setTransactionPoolModel(QAbstractItemModel* _model) {}
  virtual void updateStyle() {}
};

}
