// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include <csignal>

#include "SignalHandler.h"
#include "WalletLogger/WalletLogger.h"

namespace WalletGui {

SignalHandler& SignalHandler::instance() {
  static SignalHandler inst;
  return inst;
}

SignalHandler::SignalHandler() : QObject() {
}

SignalHandler::~SignalHandler() {
}

void SignalHandler::init() {
  std::signal(SIGINT, SignalHandler::sigHandler);
  std::signal(SIGTERM, SignalHandler::sigHandler);
#ifndef Q_OS_WIN
  std::signal(SIGPIPE, SIG_IGN);
#endif
}

void SignalHandler::sigHandler(int _signal) {
  WalletLogger::warning(tr("[SignalHandler] Signal received: %1").arg(_signal));
  Q_EMIT SignalHandler::instance().quitSignal();
}

}
