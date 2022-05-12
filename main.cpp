//http://qt-doc.ru/soedinenie-s-bazoj-dannyh-qt.html
//https://qt.developpez.com/doc/4.7/qsqldatabase/#driver

#include <QCoreApplication>
#include "myserver.h"
#include "mydatabase.h"



int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    MyDatabase db;

    Measure measure{100, 200, 300, 50, "8007808005055"};

   // db.DeleteMeasure(88);

   // db.CreateMeasure(measure, QString("C:\\Users\\Meresse\\Desktop"));

    return app.exec();
}

