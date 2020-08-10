// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QDialog>

namespace Ui {
class QRCodeDialog;
}

namespace WalletGui {

class QRCodeDialog : public QDialog {
  Q_OBJECT
  Q_DISABLE_COPY(QRCodeDialog)

public:
  QRCodeDialog(const QString& _title, const QString& _text, QWidget* _parent);
  ~QRCodeDialog();

private:
  QScopedPointer<Ui::QRCodeDialog> m_ui;
};

}
