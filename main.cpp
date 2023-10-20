#include "mainwindow.h"

#include <QApplication>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QScreen>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);



    QFileSystemModel model;

    QString rootPath = QDir::homePath();

    model.setRootPath(rootPath);

    model.setFilter(QDir::Hidden | QDir::AllDirs | QDir::Files);

    QTreeView tree;
    tree.setModel(&model);
    if (!rootPath.isEmpty()) {
        const QModelIndex rootIndex = model.index(QDir::cleanPath(rootPath));
        if (rootIndex.isValid())
            tree.setRootIndex(rootIndex);
    }

    tree.setAnimated(false);
    tree.setIndentation(20);
    tree.setSortingEnabled(true);
    tree.setColumnWidth(0, tree.width() / 3);

    tree.setWindowTitle(QObject::tr("Dir View"));
    tree.show();

    return app.exec();
}
