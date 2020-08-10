// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include <QDebug>
#include <QMessageBox>
#include "WalletLogger/WalletLogger.h"
#include "CryptoNoteWrapper/DeterministicWalletAdapter.h"
#include "crypto/crypto.h"
extern "C"
{
#include "crypto/keccak.h"
#include "crypto/crypto-ops.h"
}

namespace WalletGui {

DeterministicWalletAdapter::DeterministicWalletAdapter(QObject *parent) :
    QObject(parent)
{
}

DeterministicWalletAdapter::~DeterministicWalletAdapter() {
}

AccountKeys DeterministicWalletAdapter::generateDeterministicKeys() {
  AccountKeys keys;
  Crypto::SecretKey second;
  WalletLogger::info(tr("[Deterministic Wallet Adapter] Generating deterministic keys..."));
  try {
    Crypto::generate_keys(keys.spendKeys.publicKey, keys.spendKeys.secretKey);
    keccak((uint8_t *)&keys.spendKeys.secretKey, sizeof(Crypto::SecretKey), (uint8_t *)&second, sizeof(Crypto::SecretKey));
    Crypto::generate_deterministic_keys(keys.viewKeys.publicKey, keys.viewKeys.secretKey, second);
  } catch (std::system_error&) {

  }
  return keys;
}

bool DeterministicWalletAdapter::isDeterministic(AccountKeys& _keys) const {
  Crypto::SecretKey second;
  keccak((uint8_t *)&_keys.spendKeys.secretKey, sizeof(Crypto::SecretKey), (uint8_t *)&second, sizeof(Crypto::SecretKey));
  sc_reduce32((uint8_t *)&second);
  bool keys_deterministic = memcmp(second.data,_keys.viewKeys.secretKey.data, sizeof(Crypto::SecretKey)) == 0;
  return keys_deterministic;
}

}
