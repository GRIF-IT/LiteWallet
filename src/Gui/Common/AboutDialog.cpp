// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include <QDateTime>

#include "AboutDialog.h"
#include "Settings/Settings.h"
#include "version.h"
#include "CryptoNoteWalletConfig.h"

#include "ui_AboutDialog.h"

namespace WalletGui {

AboutDialog::AboutDialog(QWidget* _parent) : QDialog(_parent, static_cast<Qt::WindowFlags>(Qt::WindowCloseButtonHint)), m_ui(new Ui::AboutDialog) {
  m_ui->setupUi(this);

  QString aboutText = m_ui->m_aboutLabel->text();
  m_ui->m_aboutLabel->setText(aboutText.arg(WALLET_VERSION " (" GIT_REVISION ")")
                                       .arg(PROJECT_VERSION_LONG)
                                       .arg(QDateTime::currentDateTime().date().year()));
}

AboutDialog::~AboutDialog() {
}

}
