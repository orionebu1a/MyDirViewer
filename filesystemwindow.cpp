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
#include <QThread>
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
    myFilteredModel = new MyFilterModel;
    myFilteredModel->setSourceModel(model);

    path = rootPath;

    QObject::connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(update(QString)));

    tree->setModel(myFilteredModel);

    if (!path.isEmpty()) {
        auto rootIndex = model->index(path);
        auto proxyIndex = myFilteredModel->mapFromSource(rootIndex);
        if (proxyIndex.isValid())
            tree->setRootIndex(proxyIndex);
    }

    setCentralWidget(window);
}

void FileSystemWindow::update(QString text){
    model->setRootPath(path);

    if (!path.isEmpty()) {
        auto rootIndex = model->index(path);
        auto proxyIndex = myFilteredModel->mapFromSource(rootIndex);
        if (proxyIndex.isValid())
            tree->setRootIndex(proxyIndex);
        else{
            myFilteredModel->setFilterRegExp("");
            proxyIndex = myFilteredModel->mapFromSource(rootIndex);
            tree->setRootIndex(proxyIndex);
        }
    }

    myFilteredModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    myFilteredModel->setFilterRegExp(text);
}




