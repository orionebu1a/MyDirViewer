#ifndef MYFILTERMODEL_H
#define MYFILTERMODEL_H
#include <QModelIndex>
#include <QSortFilterProxyModel>
#include <QObject>


class MyFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    MyFilterModel(QObject *parent = nullptr);
    bool filterAcceptsRow(int sourceRow,const QModelIndex &sourceParent) const;
};

#endif // MYFILTERMODEL_H
