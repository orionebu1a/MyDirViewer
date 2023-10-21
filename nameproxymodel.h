#ifndef NAMEPROXYMODEL_H
#define NAMEPROXYMODEL_H
#include <QSortFilterProxyModel>
#include <QString>


class NameProxyModel : public QSortFilterProxyModel
{
public:
    NameProxyModel(QObject *parent = nullptr);
    void filterFolderByName(const QString & str);
};

#endif // NAMEPROXYMODEL_H
