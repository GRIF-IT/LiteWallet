// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <QScrollArea>

namespace WalletGui {

class ResizableScrollArea : public QScrollArea {
  Q_OBJECT
  Q_DISABLE_COPY(ResizableScrollArea)

public:
  explicit ResizableScrollArea(QWidget* _parent);
  virtual ~ResizableScrollArea();

  virtual QSize sizeHint() const override;
};

}
