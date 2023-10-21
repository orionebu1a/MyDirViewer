#ifndef FILESYSTEMWINDOW_H
#define FILESYSTEMWINDOW_H

#include <QTreeView>
#include <QFileSystemModel>
#include <QMainWindow>
#include <QDir>
#include <QString>
#include <QSortFilterProxyModel>

class FileSystemWindow : public QMainWindow
{
    Q_OBJECT
public:
    FileSystemWindow(QDir::Filters filters, QString rootPath, QWidget* parent = 0);
    QSortFilterProxyModel * filteredModel;
    QFileSystemModel * model;
    QTreeView * tree;
    QLineEdit * lineEdit;
    QString path;
};

#endif // FILESYSTEMWINDOW_H
