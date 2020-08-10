// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QDialog>
#include <QUrl>

namespace Ui {
class OpenUriDialog;
}

namespace WalletGui {

class OpenUriDialog : public QDialog {
  Q_OBJECT

public:
  OpenUriDialog(QWidget* _parent);
  ~OpenUriDialog();

  QUrl getURI() const;

private:
  QScopedPointer<Ui::OpenUriDialog> m_ui;
};

}
