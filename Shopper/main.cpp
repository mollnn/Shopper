#include "mainwindow.h"

#include <QApplication>
#include <QString>
#include <QSystemTrayIcon>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMenu trayMenu;
    QAction actionShow(QIcon(), QString("显示"));
    QAction actionQuit(QIcon(), QString("退出"));
    trayMenu.addAction(&actionShow);
    trayMenu.addAction(&actionQuit);

    MainWindow w;

    QObject::connect(&actionShow, &QAction::triggered, [&](){
        w.hide();
        w.show();
    });

    QObject::connect(&actionQuit, &QAction::triggered, [&](){
        a.quit();
    });

    QSystemTrayIcon tray(QIcon(QString(":/Shopper.ico")));
    tray.setContextMenu(&trayMenu);
    tray.show();
    w.show();

    return a.exec();
}
