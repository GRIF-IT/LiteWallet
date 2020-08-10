// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "OpenUriDialog.h"

#include "ui_OpenUriDialog.h"

namespace WalletGui {

OpenUriDialog::OpenUriDialog(QWidget* _parent) : QDialog(_parent), m_ui(new Ui::OpenUriDialog) {
  m_ui->setupUi(this);
  m_ui->m_uriEdit->setPlaceholderText("investcoin:");
}

OpenUriDialog::~OpenUriDialog() {
}

QUrl OpenUriDialog::getURI() const {
  return QUrl(m_ui->m_uriEdit->text().trimmed());
}

}
