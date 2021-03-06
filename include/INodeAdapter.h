// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QObject>

#include "INode.h"

namespace WalletGui {

enum class ConnectionMethod : int {
  AUTO, EMBEDDED, LOCAL, REMOTE
};

enum class NodeType {
  UNKNOWN, IN_PROCESS, RPC
};

class IBlockChainExplorerAdapter;
class IWalletAdapter;

class INodeAdapterObserver {
public:
  virtual ~INodeAdapterObserver() {}
  virtual void initCompleted(int _status) = 0;
  virtual void deinitCompleted() = 0;
  virtual void peerCountUpdated(quintptr _count) = 0;
  virtual void localBlockchainUpdated(CryptoNote::BlockHeaderInfo _lastBlockInfo) = 0;
  virtual void lastKnownBlockHeightUpdated(quint32 _height) = 0;
  virtual void connectionStatusUpdated(bool _connected) = 0;
};

class INodeAdapter {
public:
  enum InitStatus {
    INIT_SUCCESS = 0, INIT_TIMEOUT, INIT_DB_FAILED, INIT_DB_IN_USAGE, INIT_CORE_FAILED, INIT_NET_NODE_FAILED, INIT_P2P_BIND_FAILED, INIT_NODE_FAILED
  };

  virtual ~INodeAdapter() {}

  virtual void init() = 0;
  virtual void deinit() = 0;
  virtual NodeType getNodeType() const = 0;
  virtual QString getNodeVersion() const = 0;
  virtual quintptr getPeerCount() const = 0;
  virtual quint32 getKnownBlockCount() const = 0;
  virtual quint32 getLocalBlockCount() const = 0;
  virtual QString getNodeHost() const = 0;
  virtual quint16 getNodePort() const = 0;
  virtual QString getNodeFeeAddress() const = 0;
  virtual quint64 getNodeFee() const = 0;
  virtual quint64 getMinimalFee() const = 0;
  virtual CryptoNote::BlockHeaderInfo getLastLocalBlockInfo() const = 0;
  virtual void addObserver(INodeAdapterObserver* _observer) = 0;
  virtual void removeObserver(INodeAdapterObserver* _observer) = 0;
  virtual IBlockChainExplorerAdapter* getBlockChainExplorerAdapter() = 0;
  virtual IWalletAdapter* getWalletAdapter() = 0;
};

}
