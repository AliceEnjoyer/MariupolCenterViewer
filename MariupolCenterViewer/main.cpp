#include "window.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile f(QCoreApplication::applicationDirPath()+"/style.css");
    f.open(QIODevice::ReadOnly);

    window w;
    QString style = f.readAll();
    w.setStyleSheet(style);
    f.close();
    w.show();
    return a.exec();
}

//#include <QCoreApplication>
//#include <QtSql>
//#include <QDebug>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    // Создаем объект для подключения к базе данных
//    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

//    // Устанавливаем параметры подключения
//    db.setHostName("localhost");       // Хост базы данных (или IP адрес)
//    db.setPort(5432);                  // Порт, используемый PostgreSQL
//    db.setDatabaseName("mariupolcenter"); // Имя базы данных
//    db.setUserName("postgres");   // Имя пользователя
//    db.setPassword("4nEfYh323K");   // Пароль

//    // Пытаемся подключиться к базе данных
//    if (!db.open()) {
//        qDebug() << "Ошибка подключения к базе данных: " << db.lastError().text();
//        return -1; // Завершаем программу при ошибке
//    } else {
//        qDebug() << "Успешное подключение к базе данных!";
//    }

//    // Выполняем запрос
//    QSqlQuery query;
//    if (query.exec("SELECT * FROM your_table_name")) {
//        while (query.next()) {
//            QString column1 = query.value(0).toString();
//            QString column2 = query.value(1).toString();
//            qDebug() << "Результат:" << column1 << column2;
//        }
//    } else {
//        qDebug() << "Ошибка выполнения запроса: " << query.lastError().text();
//    }

//    // Закрытие соединения
//    db.close();

//    return a.exec();
//}
