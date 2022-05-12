#include "mydatabase.h"
#include <QDebug>
#include <QSqlError>
#include <QString>

MyDatabase::MyDatabase()
{ 
     db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("mesures.db");
     db.open();

     if (db.open())
     {
         qDebug() << "DB opened";
     }
}

Measure MyDatabase::GetMeasure(int id)
{
    Measure measure;

    if (db.open())
    {
        statement = "SELECT * FROM mesures WHERE Id = " + QString::number(id) + ";";

        query = db.exec(statement);

        query.executedQuery();

        rec = query.record();

            while (query.next())
            {
                int id = query.value(rec.indexOf("id")).toFloat();

                measure.x = query.value(rec.indexOf("long")).toFloat();

                measure.y = query.value(rec.indexOf("height")).toFloat();

                measure.z = query.value(rec.indexOf("width")).toFloat();

                measure.w = query.value(rec.indexOf("weight")).toFloat();

                measure.Barcode = query.value(rec.indexOf("barcode")).toString();

                qDebug() << id << " " << measure.x << " " << measure.y << " " << measure.z << " " << measure.w << " " << measure.Barcode;

            }

    }

    //db.close();

    return measure;
}

QVector<Measure> MyDatabase::GetAll()
{
    Measure measure;

    QVector<Measure> measures;

    if (db.open())
    {
        statement = "SELECT * FROM mesures";

        query = db.exec(statement);

        query.executedQuery();

        rec = query.record();

            while (query.next())
            {
                int id = query.value(rec.indexOf("id")).toFloat();

                measure.x = query.value(rec.indexOf("long")).toFloat();

                measure.y = query.value(rec.indexOf("height")).toFloat();

                measure.z = query.value(rec.indexOf("widht")).toFloat();

                measure.w = query.value(rec.indexOf("weight")).toFloat();

                measure.Barcode = query.value(rec.indexOf("barcode")).toString();

                qDebug() << id << " " << measure.x << " " << measure.y << " " << measure.z << " " << measure.w << " " << measure.Barcode;

                measures.push_back(measure);
            }

    }

    return measures;

    //db.close();
}

Measure MyDatabase::GetLastMeasure()
{
    Measure measure;

    if (db.open())
    {
        statement = "SELECT * FROM mesures order by Id desc LIMIT 1;";

        query = db.exec(statement);

        rec = query.record();

            while (query.next())
            {
                int id = query.value(rec.indexOf("id")).toFloat();

                measure.x = query.value(rec.indexOf("long")).toFloat();

                measure.y = query.value(rec.indexOf("height")).toFloat();

                measure.z = query.value(rec.indexOf("width")).toFloat();

                measure.w = query.value(rec.indexOf("weight")).toFloat();

                measure.Barcode = query.value(rec.indexOf("barcode")).toString();

                qDebug() << id << " " << measure.x << " " << measure.y << " " << measure.z << " " << measure.w << " " << measure.Barcode;

            }
    }

    return measure;

    //db.close();
}

void MyDatabase::DeleteMeasure(int id)
{
       statement = "DELETE FROM mesures WHERE id = 88;";

        query = db.exec(statement);

        if (!query.exec())
        {
            qDebug() << "error delete row ";
            qDebug() << query.lastError().text();
        }
        else
        {
            qDebug() << "OK";
        }

       // db.close();
}

void MyDatabase::CreateMeasure(Measure measure, QString photoPath)
{
    statement = "INSERT INTO mesures (id, barcode, mesure_time, weight, long, height, widht, photo) VALUES (?, ?, ?, ?, ?, ?, ?, ?);";

    query = db.exec(statement);

    query.addBindValue(88);
    query.addBindValue(measure.Barcode);
    query.addBindValue(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
    query.addBindValue(measure.w);
    query.addBindValue(measure.x);
    query.addBindValue(measure.y);
    query.addBindValue(measure.z);
    query.addBindValue(photoPath);

    if (!query.exec())
    {
        qDebug() << "error insert row ";
        qDebug() << query.lastError().text();
    }
    else
    {
        qDebug() << "Unable to do insert opeation";
    }

    //db.close();
}

