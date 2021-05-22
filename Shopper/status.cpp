#include "status.h"

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
