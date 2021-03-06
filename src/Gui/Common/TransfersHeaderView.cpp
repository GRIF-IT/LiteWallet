// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "TransfersHeaderView.h"
#include "Models/TransfersModel.h"

namespace WalletGui {

TransfersHeaderView::TransfersHeaderView(QWidget* _parent) : QHeaderView(Qt::Horizontal, _parent) {
}

TransfersHeaderView::~TransfersHeaderView() {
}

void TransfersHeaderView::paintSection(QPainter* _painter, const QRect& _rect, int _logicalIndex) const {
  QRect rect(_rect);
  switch (_logicalIndex) {
  case TransfersModel::COLUMN_AMOUNT:
    rect.setRight(_rect.right() - 24);
    break;
  case TransfersModel::COLUMN_ADDRESS:
    rect.setRight(_rect.right() - 20);
    break;
  }


  QHeaderView::paintSection(_painter, rect, _logicalIndex);
}

QSize TransfersHeaderView::sectionSizeFromContents(int _logicalIndex) const {
  QSize res = QHeaderView::sectionSizeFromContents(_logicalIndex);
  if (_logicalIndex == TransfersModel::COLUMN_AMOUNT) {
    res.setWidth(res.width() + 20);
  }

  return res;
}

}
