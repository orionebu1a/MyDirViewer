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

    model->setRootPath(rootPath);
    model->setFilter(filters);

    tree->setModel(model);
    model->setNameFilterDisables(false);

    if (!rootPath.isEmpty()) {
        const auto rootIndex = model->index(QDir::cleanPath(rootPath));
        if (rootIndex.isValid())
            tree->setRootIndex(rootIndex);
    }

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

    QObject::connect(lineEdit, &QLineEdit::textChanged,
          [&] (QString text) { model->setNameFilters({"*" + text + "*"}); });

    setCentralWidget(window);

}


