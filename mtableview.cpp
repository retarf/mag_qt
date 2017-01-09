#include <QDebug>

#include "mtableview.h"

MTableView::MTableView()
{

}

void MTableView::edit(const QModelIndex &index)
{

    qDebug() << "Signal" << " Kolumna: " << index.column() << " ";
}
