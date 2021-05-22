#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QString>
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status=new Status(this);

    connect(ui->btnAdd, &QPushButton::clicked, [&](){
        QString name = QInputDialog::getText(this,tr("Shopper"),tr("输入名称"));
        int money = QInputDialog::getInt(this,tr("Shopper"),tr("输入价格"));
        status->AddCommodity(name,money);
    });

    connect(ui->btnBuy, &QPushButton::clicked,   [&](){
        int id=ui->listWidget->currentRow();
        status->BuyCommodity(id);
    });

    connect(ui->btnDelete, &QPushButton::clicked,  [&](){
        int id=ui->listWidget->currentRow();
        status->DeleteCommodity(id);
    });

    connect(ui->btnMake, &QPushButton::clicked,  [&](){
        int money = QInputDialog::getInt(this,tr("Shopper"),tr("输入本次工资"));
        status->MakeMoney(money);
    });

    connect(status, &Status::dataChanged, [&](){
        ui->listWidget->clear();
        for(auto item:status->GetCommodityList())
        {
            ui->listWidget->addItem(item.first + " ~" + QString::asprintf("%d",item.second));
        }
        ui->statusbar->showMessage(QString::asprintf("余额：%d",status->GetMoney()));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

