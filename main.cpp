#include <QScreen>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QTreeWidget>
#include <QLineEdit>
#include <QFileSystemModel>
#include <QDir>
#include <QApplication>
#include <QVBoxLayout>
#include <QLineEdit>
#include "filesystemwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FileSystemWindow * window = new FileSystemWindow(QDir::Hidden | QDir::AllDirs | QDir::Files, QDir::homePath());
    window->show();
    return app.exec();
}
