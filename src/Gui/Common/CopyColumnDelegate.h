// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QStyledItemDelegate>

namespace WalletGui {

class CopyColumnDelegate : public QStyledItemDelegate {
  Q_OBJECT
  Q_DISABLE_COPY(CopyColumnDelegate)

public:
  explicit CopyColumnDelegate(QObject* _parent);
  virtual ~CopyColumnDelegate();

  virtual void paint(QPainter* _painter, const QStyleOptionViewItem& _option, const QModelIndex& _index) const override;
  virtual QWidget* createEditor(QWidget* _parent, const QStyleOptionViewItem& _option, const QModelIndex& _index) const override;
  virtual void updateEditorGeometry(QWidget* _editor, const QStyleOptionViewItem& _option, const QModelIndex& _index) const override;
};

}
