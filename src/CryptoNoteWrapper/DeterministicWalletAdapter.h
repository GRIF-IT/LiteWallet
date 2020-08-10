// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include "ICryptoNoteAdapter.h"
#include "IWalletAdapter.h"

namespace Logging {
  class ILogger;
}

namespace WalletGui {

class DeterministicWalletAdapter : public QObject
{
    Q_OBJECT

public:
  explicit DeterministicWalletAdapter(QObject *parent = 0);

  virtual ~DeterministicWalletAdapter();

  AccountKeys generateDeterministicKeys();
  bool isDeterministic(AccountKeys& _keys) const;
};

}
