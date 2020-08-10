// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QObject>

class QFile;
class QFileSystemWatcher;

namespace WalletGui {

class LogFileWatcher : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(LogFileWatcher)

public:
  LogFileWatcher(const QString& _filePath, QObject* _parent);
  ~LogFileWatcher();

protected:
  void timerEvent(QTimerEvent* _event) override;

private:
  int m_fileCheckTimer;
  QFile* m_logFile;

  void fileChanged();

Q_SIGNALS:
  void newLogStringSignal(const QString& _string);
};

}
