// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QDateTime>
#include <QSortFilterProxyModel>

namespace WalletGui {

class ICryptoNoteAdapter;

class FilteredBlockModel : public QSortFilterProxyModel {
  Q_OBJECT
  Q_DISABLE_COPY(FilteredBlockModel)

public:
  enum Filter {
    All = 0, LastHour, LastDay, LastWeek, LastMonth, LastYear, Custom
  };

  FilteredBlockModel(ICryptoNoteAdapter* _cryptoNoteAdapter, QAbstractItemModel* _blockChainModel, QObject* _parent);
  ~FilteredBlockModel();

  void setFilter(FilteredBlockModel::Filter _filter, bool _enable_period, const QDateTime &_begin, const QDateTime &_end,
                 const QString &_hash);
  void resetFilter();

protected:
  bool filterAcceptsRow(int _sourceRow, const QModelIndex &_sourceParent) const override;

private:
  ICryptoNoteAdapter* m_cryptoNoteAdapter;
  FilteredBlockModel::Filter m_filter;
  bool m_enablePeriod;
  QDateTime m_begin;
  QDateTime m_end;
  QString m_hash;
  quint32 m_beginHeight;
  quint32 m_endHeight;
};

}
