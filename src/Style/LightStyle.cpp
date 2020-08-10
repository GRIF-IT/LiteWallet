// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "LightStyle.h"

namespace WalletGui {

LightStyle::LightStyle() : Style("light", "Light") {

}

QString LightStyle::statusBarBackgroundColor() const {
  return "#734d26";
}

QString LightStyle::statusBarFontColor() const {
  return "#ffffff";
}

QString LightStyle::headerBackgroundColor() const {
  return "#734d26";
}

QString LightStyle::headerBorderColor() const {
  return "#734d26";
}

QString LightStyle::addressFontColor() const {
  return "#ffffff";
}

QString LightStyle::balanceFontColor() const {
  return "#ffffff";
}

QString LightStyle::toolButtonBackgroundColorNormal() const {
  return "#CCA66C";
}

QString LightStyle::toolButtonBackgroundColorHover() const {
  return "#39332d";
}

QString LightStyle::toolButtonBackgroundColorPressed() const {
  return "#39332d";
}

QString LightStyle::toolButtonFontColorNormal() const {
  return "#ffffff";
}

QString LightStyle::toolButtonFontColorDisabled() const {
  return "#b2ffffff";
}

QString LightStyle::toolBarBorderColor() const {
  return "#2e4558";
}

QString LightStyle::getWalletSyncGifFile() const {
  return QString(":icons/light/wallet-sync");
}

QPixmap LightStyle::getLogoPixmap() const {
  return QPixmap(QString(":icons/light/logo"));
}

QPixmap LightStyle::getBalanceIcon() const {
  return QPixmap(QString(":icons/total_balance"));
}

QPixmap LightStyle::getConnectedIcon() const {
  return QPixmap(QString(":icons/light/connected"));
}

QPixmap LightStyle::getDisconnectedIcon() const {
  return QPixmap(QString(":icons/light/disconnected"));
}

QPixmap LightStyle::getEncryptedIcon() const {
  return QPixmap(QString(":icons/light/encrypted"));
}

QPixmap LightStyle::getNotEncryptedIcon() const {
  return QPixmap(QString(":icons/light/decrypted"));
}

QPixmap LightStyle::getSyncedIcon() const {
  return QPixmap(QString(":icons/light/synced"));
}

}
