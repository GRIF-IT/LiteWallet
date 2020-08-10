// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "QRCodeDialog.h"
#include "Gui/Common/QRLabel.h"
#include "Models/WalletStateModel.h"

#include "ui_QRCodeDialog.h"

namespace WalletGui {

QRCodeDialog::QRCodeDialog(const QString& _title, const QString& _text, QWidget* _parent) : QDialog(_parent, static_cast<Qt::WindowFlags>(Qt::WindowCloseButtonHint)),
  m_ui(new Ui::QRCodeDialog) {
  m_ui->setupUi(this);
  setWindowTitle(_title);
  m_ui->m_qrCodeLabel->showQRCode(_text);
}

QRCodeDialog::~QRCodeDialog() {
}

}
