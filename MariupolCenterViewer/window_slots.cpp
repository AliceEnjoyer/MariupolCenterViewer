#include "window.h"
#include "helpFunctions.h"
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
    } else if (triggeredMenuText == "add person...") {
        dioAddNewUser->show();
    } else if (triggeredMenuText == "add meeting...") {
        dioAddNewMeeting->show();
    } else if (triggeredMenuText == "refresh") {
        table->refreshTable();
        tableMeetings->refreshTable();
    }
}

QString window::personInfoGetter(int row, int col) {
    QString txt = table->data(row, col).toString();
    return txt.isEmpty() ? "UNKNOWN" : txt;
}

void window::slotTableDoubleClicked(const QModelIndex &index)
{
    QFile f(QCoreApplication::applicationDirPath() + "/db/participants.db");
    if (!f.open(QIODevice::ReadOnly)) {
        qDebug() << "Can not open file:" << f.errorString();
        return;
    }

    int row = index.row();
    int i = 0;
    while (!f.atEnd()) {
        if(i == row) break;
        f.readLine();
        ++i;

//        QList<QString> l = split(line.toStdString(), ';');
//        if (l.size() < 3) {
//            qDebug() << "Ошибка: недостаточно элементов в строке";
//            continue; // Пропуск некорректных строк
//        }
//        if(l[5])
    }
    QString buf = f.readLine().trimmed();
    QList<QString> l = split(buf.toStdString(), ';');

    f.close();


    QString personInfo =
    "Name: " + l[0] + "\n" +
    "city: " + l[1] + "\n" +
    "meetings visited: " + l[2] + "\n" +
    "Age: " + l[3] + "\n" +
    "Registration address: " + l[4] + "\n" +
    "Phone number: " + l[5] + "\n" +
    "Center: " + l[6] + "\n";

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

void window::slotAddNewUserClicked()
{
    QFile f(QCoreApplication::applicationDirPath() + "/db/participants.db");
    if (!f.open(QIODevice::Append)) {
        qDebug() << "Can not open file:" << f.errorString();
        return;
    }
    QString buf = lineFull_name->text()+";"+
            lineActual_adress->text()+";"+
            lineMeetings_visited->text()+";"+
            lineAge->text()+";"+
            lineRegistration_adress->text()+";"+
            linePhone_number->text()+";"+
            lineCenter->text()+"\n";

    f.write(buf.toUtf8());
    f.close();
    table->refreshTable();
}

void window::slotAddNewMeetindClicked()
{
    QFile f(QCoreApplication::applicationDirPath() + "/db/meetings.db");
    if (!f.open(QIODevice::Append)) {
        qDebug() << "Can not open file:" << f.errorString();
        return;
    }
    QString buf = lineNumberOfMeeting->text()+";"+
            lineNameOfMeeting->text()+";"+
            lineTopics->text()+";"+
            lineParticipants->text()+"\n";

    f.write(buf.toUtf8());
    f.close();
    tableMeetings->refreshTable();
}

void window::slotConnectDbClicked()
{
    table->refreshTable();
    tableMeetings->refreshTable();
    QMessageBox::about(this, "Info", "<h3>Database connected successfully!!<h3>");
}

