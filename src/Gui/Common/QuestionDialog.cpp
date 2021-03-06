// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "QuestionDialog.h"

#include "ui_QuestionDialog.h"

namespace WalletGui {

QuestionDialog::QuestionDialog(const QString& _title, const QString& _text, QWidget* _parent) : QDialog(_parent, static_cast<Qt::WindowFlags>(Qt::WindowCloseButtonHint)),
  m_ui(new Ui::QuestionDialog) {
  m_ui->setupUi(this);
  setWindowTitle(_title);
  m_ui->m_questionLabel->setText(_text);
}

QuestionDialog::~QuestionDialog() {
}

}
