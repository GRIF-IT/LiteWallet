// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QDialog>
#include <QPersistentModelIndex>

namespace Ui {
  class TransactionDetailsDialog;
}

namespace WalletGui {

class ICryptoNoteAdapter;

class TransactionDetailsDialog : public QDialog {
  Q_OBJECT
  Q_DISABLE_COPY(TransactionDetailsDialog)

public:
  TransactionDetailsDialog(ICryptoNoteAdapter*_cryptoNoteAdapter, QAbstractItemModel* _transactionsModel, const QModelIndex& _index, QWidget* _parent);
  ~TransactionDetailsDialog();

  virtual bool eventFilter(QObject* _object, QEvent* _event) override;

protected:
  virtual void showEvent(QShowEvent* _event) override;

private:
  QScopedPointer<Ui::TransactionDetailsDialog> m_ui;
  ICryptoNoteAdapter* m_cryptoNoteAdapter;
  QPersistentModelIndex m_index;

  void copyableItemClicked(const QModelIndex& _index);
  QString getTxProof(const QModelIndex& _index) const;
};

}
