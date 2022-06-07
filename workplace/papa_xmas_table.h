#pragma once

#include "i_table.h"


class PapaXmasTable : public ITable {
  protected:
    Object** container;
    int count = 0;
    int max_count = 0;
  public:
    explicit PapaXmasTable(int max_count);

    ~PapaXmasTable() override;

    Object* take(int id = -1) override;

    bool put(Object* object) override;

    std::string* look() override;
};