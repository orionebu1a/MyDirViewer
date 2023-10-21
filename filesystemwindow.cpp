#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QScreen>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QTreeWidget>
#include <QLineEdit>
#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QString>
#include <QSortFilterProxyModel>
#include "filesystemwindow.h"

FileSystemWindow::FileSystemWindow(QDir::Filters filters, QString rootPath, QWidget* parent) : QMainWindow(parent){

    model = new QFileSystemModel;
    tree = new QTreeView;
    model->setFilter(filters);
    model->setRootPath(rootPath);

    tree->setAnimated(false);
    tree->setIndentation(20);
    tree->setSortingEnabled(true);
    tree->setColumnWidth(0, tree->width() / 3);
    tree->setWindowTitle(QObject::tr("Dir View"));


    QVBoxLayout * verticalLayout = new QVBoxLayout();
    lineEdit = new QLineEdit;
    verticalLayout->addWidget(lineEdit);
    verticalLayout->addWidget(tree);
    QWidget * window = new QWidget();
    window->setLayout(verticalLayout);

    filteredModel = new QSortFilterProxyModel;
    filteredModel->setSourceModel(model);

    path = rootPath;

    QObject::connect(lineEdit, &QLineEdit::textChanged,
     [&] (QString text) {

        filteredModel->setFilterWildcard(text);

        model->setRootPath(path);

        if (!path.isEmpty()) {
            auto rootIndex = model->index(path);
            auto proxyIndex = filteredModel->mapFromSource(rootIndex);
            if (proxyIndex.isValid())
                tree->setRootIndex(proxyIndex);
        }
        tree->setModel(filteredModel);
        });

    tree->setModel(filteredModel);

    if (!path.isEmpty()) {
        auto rootIndex = model->index(path);
        auto proxyIndex = filteredModel->mapFromSource(rootIndex);
        if (proxyIndex.isValid())
            tree->setRootIndex(proxyIndex);
    }
    setCentralWidget(window);

}



