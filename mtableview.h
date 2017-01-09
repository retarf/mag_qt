#ifndef MTABLEVIEW_H
#define MTABLEVIEW_H

#include <QTableView>

class MTableView :public QTableView
{
public:
    MTableView();

public slots:

    void edit(const QModelIndex &index);
};

#endif // MTABLEVIEW_H
