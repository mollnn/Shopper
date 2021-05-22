#ifndef STATUS_H
#define STATUS_H

#include <QObject>

class Status: public QObject
{
    Q_OBJECT
public:
    Status(QWidget *parent = nullptr);

private:
    int money;
    QVector<QPair<QString,int>> list;

public:
    const QVector<QPair<QString,int>> & GetCommodityList();
    void AddCommodity(const QString& name, int price);
    void BuyCommodity(int id);
    void DeleteCommodity(int id);
    void MakeMoney(int delta);
    int GetMoney();

signals:
    void dataChanged();
};

#endif // STATUS_H
