#include "myfiltermodel.h"
#include <QSortFilterProxyModel>

MyFilterModel::MyFilterModel(QObject * parent) : QSortFilterProxyModel(parent)
{

}

bool MyFilterModel::filterAcceptsRow(int sourceRow,const QModelIndex &sourceParent) const{
    if(sourceRow == 0){
        return true;
    }
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
    auto var = sourceModel()->data(index).toString().toLower().trimmed();
    auto filter = filterRegExp();
    if(sourceModel()->data(index).toString().toLower().trimmed().contains(filterRegExp())){
       return true;
    }
    return false;
}
