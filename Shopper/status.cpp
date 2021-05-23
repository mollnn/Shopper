#include "status.h"
#include <QDebug>

Status::Status(QWidget *parent)
{
    money=0;
}

const QVector<QPair<QString,int>> & Status::GetCommodityList()
{
    return list;
}

void Status::AddCommodity(const QString& name, int price)
{
    list.push_back(qMakePair(name,price));
    emit dataChanged();
}

void Status::BuyCommodity(int id)
{
    if(id<0 || id>=list.size()) return;
    if(list[id].second>money) return;
    money -= list[id].second;
    list[id].first  = QString("已购买 ")+list[id].first;
    emit dataChanged();
}

void Status::DeleteCommodity(int id)
{
    if(id<0 || id>=list.size()) return;
    list.erase(list.begin()+id);
    emit dataChanged();
}

void Status::MakeMoney(int delta)
{
    money+=delta;
    emit dataChanged();
}

int Status::GetMoney()
{
    return money;
}

void Status::Read()
{
    QFile file(tr("./status.data"));
    int flag = file.open(QIODevice::ReadOnly);
    if(!flag)
    {
        qDebug()<<"fail to open file";
        return;
    }
    QDataStream ds(&file);
    ds>>money>>list;
    file.close();
    emit dataChanged();
}

void Status::Write()
{
    QFile file(tr("./status.data"));

    int flag = file.open(QIODevice::WriteOnly);
    if(!flag)
    {
        qDebug()<<"fail to open file";
        return;
    }
    QDataStream ds(&file);
    ds<<money<<list;
    file.close();
}
