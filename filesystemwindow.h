#ifndef FILESYSTEMWINDOW_H
#define FILESYSTEMWINDOW_H

#include <QTreeView>
#include <QFileSystemModel>
#include <QMainWindow>
#include <QDir>
#include <QString>
#include <QSortFilterProxyModel>
#include "myfiltermodel.h"

class FileSystemWindow : public QMainWindow
{
    Q_OBJECT
public:
    FileSystemWindow(QDir::Filters filters, QString rootPath, QWidget* parent = 0);
    QSortFilterProxyModel * filteredModel;
    MyFilterModel * myFilteredModel;
    QFileSystemModel * model;
    QTreeView * tree;
    QLineEdit * lineEdit;
    QString path;
public slots:
    void update(QString text);
};

#endif // FILESYSTEMWINDOW_H
