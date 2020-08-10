// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QDialog>
#include "IWalletAdapter.h"

namespace Ui {
class MnemonicDialog;
}

namespace WalletGui {

class MnemonicDialog : public QDialog {
  Q_OBJECT
  Q_DISABLE_COPY(MnemonicDialog)

public:
  MnemonicDialog(const AccountKeys& _keys, QWidget* _parent);
  ~MnemonicDialog();

private:
  QScopedPointer<Ui::MnemonicDialog> m_ui;
  AccountKeys m_keys;

  void initLanguages();
  void getMnemonic(QString _lang);

  Q_SLOT void languageChanged();

};

}
