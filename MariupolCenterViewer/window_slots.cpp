#include "window.h"
#include <vector>
#include <string>

void window::slotMenuTriggered(QAction* a) {
    QString triggeredMenuText = a->text();
    if (triggeredMenuText == "connect...") {
        dioConnectDb->show();


//        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
//        db.setHostName("localhost");
//        db.setPort(5432);
//        db.setUserName("postgres");
//        db.setPassword("4nEfYh323K");
//        db.setDatabaseName("mariupolcenter");

//        if(db.open()) {
//            qDebug() << "yeeees\n";
//        } else {
//            qDebug() << "nooo((((\n";
//        }
    } else if (triggeredMenuText == "About...") {
        QMessageBox::about(this, "About", "<h1>MariupolCenterViewer</h1>\n<h3>The program was created to keep track of the participants of dialogue meetings within the scope of the work of humanitarian centers of the \"I am Mariupol\" Charitable Foundation by Valeriia Siechko, student of Computer science department of V. N. Karazin Kharkiv National University<h3>");
    }
}

QString window::personInfoGetter(int row, int col) {
    QString txt = table->data(row, col).toString();
    return txt.isEmpty() ? "UNKNOWN" : txt;
}

void window::slotTableDoubleClicked(const QModelIndex &i)
{
    int row = i.row();
    QString personInfo =
    "Name: " + personInfoGetter(row, 0) + "\n" +
    "city: " + personInfoGetter(row, 1) + "\n" +
    "meetings visited: " + personInfoGetter(row, 2) + "\n" +
    "\"bd\" info coming soon\n";

    QMessageBox::about(this, "Person info", personInfo);
}

void window::slotMeetingsViewDoubleClicked(const QModelIndex &i)
{
    QString temp = tableMeetings->data(i.row(), 0).toString();
    dioResults->setWindowTitle(temp == "" ? "Number of meeting: UNKNOWN" : "Number of meeting: " + temp);
    dioResults->show();
}

void window::slotMeetingsResultViewDoubleClicked(const QModelIndex &)
{

}

std::vector<std::string> split(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));  // Извлекаем подстроку
        start = end + 1;  // Начинаем после разделителя
        end = str.find(delimiter, start);  // Ищем следующий разделитель
    }

    // Добавляем последний токен (после последнего разделителя)
    tokens.push_back(str.substr(start));

    return tokens;
}



