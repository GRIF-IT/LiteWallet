// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include <QDialog>

#include "IWalletAdapter.h"
#include "ICryptoNoteAdapter.h"

class QAbstractItemModel;

namespace Ui {
class BalanceProofDialog;
}

namespace WalletGui {

namespace {

const char BALANCE_PROOF_DIALOG_STYLE_SHEET_TEMPLATE[] =
  "* {"
    "font-family: %fontFamily%;"
  "}"

  "WalletGui--BalanceProofDialog #m_keyEdit {"
    "font-size: %fontSizeNormal%;"
    "border-radius: 2px;"
    "border: 1px solid %borderColorDark%;"
  "}";
}

class IWalletAdapter;
class ICryptoNoteAdapter;

class BalanceProofDialog : public QDialog {
    Q_OBJECT

public:
    BalanceProofDialog(ICryptoNoteAdapter* _cryptoNoteAdapter, QWidget * _parent);
    void walletBalanceUpdated(quint64 _actualBalance, quint64 _pendingBalance);
    ~BalanceProofDialog();

private:
    quint64 m_amount;
    QString m_message;
    QString m_proof;

    Q_SLOT void genProof();
    Q_SLOT void copyProof();
    Q_SLOT void saveProof();
    Q_SLOT void balanceUpdated(quint64 _actualBalance, quint64 _pendingBalance);

    QScopedPointer<Ui::BalanceProofDialog> m_ui;
    ICryptoNoteAdapter* m_cryptoNoteAdapter;
    QAbstractItemModel* m_walletStateModel;
};

}
