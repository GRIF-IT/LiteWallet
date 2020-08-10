// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "MnemonicDialog.h"
#include "Mnemonics/electrum-words.h"

#include "ui_MnemonicDialog.h"

namespace WalletGui {

MnemonicDialog::MnemonicDialog(const AccountKeys& _keys, QWidget* _parent) : QDialog(_parent, static_cast<Qt::WindowFlags>(Qt::WindowCloseButtonHint)),
  m_ui(new Ui::MnemonicDialog) {
  m_ui->setupUi(this);
  m_keys = _keys;
  setWindowTitle(tr("Mnemonic seed"));
  m_ui->m_descriptionLabel->setText(tr("This is the mnemonic seed of your wallet. Write it down carefully! "
                                       "You can restore your wallet from these words."));
  initLanguages();
  m_ui->m_languageCombo->setCurrentIndex(m_ui->m_languageCombo->findData("English", Qt::DisplayRole));
  QString lang = "English";
  getMnemonic(lang);
}

MnemonicDialog::~MnemonicDialog() {
}

void MnemonicDialog::initLanguages() {
  std::vector<std::string> languages;
  Crypto::ElectrumWords::get_language_list(languages);
  for (size_t i = 0; i < languages.size(); ++i)
  {
    m_ui->m_languageCombo->addItem(QString::fromStdString(languages[i]));
  }
}

void MnemonicDialog::languageChanged() {
   getMnemonic(m_ui->m_languageCombo->currentText());
}

void MnemonicDialog::getMnemonic(QString _lang) {
  std::string seed_language = _lang.toUtf8().constData();
  std::string electrum_words;
  Crypto::ElectrumWords::bytes_to_words(m_keys.spendKeys.secretKey, electrum_words, seed_language);
  QString seed = QString::fromStdString(electrum_words);
  m_ui->m_textLabel->setText(seed);
}

}
