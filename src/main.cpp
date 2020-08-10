// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "Application/WalletApplication.h"

using namespace WalletGui;

int main(int argc, char* argv[]) {
  WalletApplication app(argc, argv);
  try {
    if (!app.init()) {
      return 0;
    }

    return app.exec();
  } catch (const std::exception& _error) {
    fprintf(stderr, "[Main] Unhandled exception: %s\n", _error.what());
    return 0;
  }
}
