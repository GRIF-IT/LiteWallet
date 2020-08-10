// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QFrame>
#include "Application/IWalletUiItem.h"
#include "ICryptoNoteAdapter.h"

class QAbstractItemModel;

namespace Ui {
class ReceiveFrame;
}

namespace WalletGui {

class ReceiveFrame : public QFrame, public IWalletUiItem, public ICryptoNoteAdapterObserver {
  Q_OBJECT
  Q_DISABLE_COPY(ReceiveFrame)

public:
  explicit ReceiveFrame(QWidget* _parent);
  ~ReceiveFrame();

  // IWalletUiItem
  virtual void setCryptoNoteAdapter(ICryptoNoteAdapter* _cryptoNoteAdapter) override;
  virtual void setMainWindow(QWidget* _mainWindow) override;

  // ICryptoNoteAdapterObserver
  Q_SLOT virtual void cryptoNoteAdapterInitCompleted(int _status) override;
  Q_SLOT virtual void cryptoNoteAdapterDeinitCompleted() override;

  Q_SLOT void walletOpened(QString _address);
  Q_SLOT void walletClosed();

  QString m_address;
  QString m_request;

private:
  QScopedPointer<Ui::ReceiveFrame> m_ui;
  ICryptoNoteAdapter* m_cryptoNoteAdapter;
  QWidget* m_mainWindow;

  Q_SLOT void generatePaymentIdClicked();
  Q_SLOT void generateRequest();
  Q_SLOT void copyRequest();
  Q_SLOT void saveRequest();
  Q_SLOT void saveQrCode();
};

}
