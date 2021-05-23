#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QString>
#include <QObject>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status=new Status(this);

    connect(ui->actionMenuAdd, &QAction::triggered, [&](){
        QString name = QInputDialog::getText(this,tr("Shopper"),tr("输入名称"));
        int money = QInputDialog::getInt(this,tr("Shopper"),tr("输入价格"));
        status->AddCommodity(name,money);
    });

    connect(ui->actionMenuBuy, &QAction::triggered,   [&](){
        int id=ui->listWidget->currentRow();
        status->BuyCommodity(id);
    });

    connect(ui->actionMenuDelete, &QAction::triggered, [&](){
        int id=ui->listWidget->currentRow();
        status->DeleteCommodity(id);
    });

    connect(ui->actionMenuMake, &QAction::triggered, [&](){
        int money = QInputDialog::getInt(this,tr("Shopper"),tr("输入本次工资"));
        status->MakeMoney(money);
    });

    connect( ui->btnAdd, &QPushButton::clicked,ui->actionMenuAdd, &QAction::triggered);
    connect( ui->btnBuy, &QPushButton::clicked,ui->actionMenuBuy, &QAction::triggered);
    connect( ui->btnDelete, &QPushButton::clicked,ui->actionMenuDelete, &QAction::triggered);
    connect( ui->btnMake, &QPushButton::clicked,ui->actionMenuMake, &QAction::triggered);

    connect(status, &Status::dataChanged, [&](){
        ui->listWidget->clear();
        for(auto item:status->GetCommodityList())
        {
            ui->listWidget->addItem(item.first + " ~" + QString::asprintf("%d",item.second));
        }
        ui->label->setText(QString::asprintf("余额：%d",status->GetMoney()));
        status->Write();
    });

    // Init


    status->Read();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
}
