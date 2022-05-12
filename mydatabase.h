#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QSqlRecord>
#include <QTime>


struct Measure{
    float x;
    float y;
    float z;
    float w;
    QString Barcode;
};


class MyDatabase : public QObject
        {
Q_OBJECT

public:

    MyDatabase();

    Measure GetMeasure(int id);

    QVector<Measure> GetAll();

    Measure GetLastMeasure();

    void DeleteMeasure(int id);

    void CreateMeasure(Measure measure, QString photoPath);

private:

    QSqlDatabase db;
    QSqlQuery query;
    QString statement;
    QSqlRecord rec;
};

#endif // MYDATABASE_H

#include <main.moc>
