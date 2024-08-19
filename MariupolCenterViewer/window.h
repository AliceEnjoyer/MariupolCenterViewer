#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets>
#include <QSqlDatabase>
#include "tablemodel.h"
#include "tablemodel2.h"
#include "tablemodel3.h"

class window : public QMainWindow
{
    Q_OBJECT

public:
    window(QWidget *parent = nullptr);

protected slots:
    void slotMenuTriggered(QAction*);
    void slotTableDoubleClicked(const QModelIndex&);
    void slotMeetingsViewDoubleClicked(const QModelIndex&);
    void slotMeetingsResultViewDoubleClicked(const QModelIndex&);
    void slotAddNewUserClicked();
    void slotAddNewMeetindClicked();
    void slotConnectDbClicked();

private:
    QMenuBar * m;
    QMenu* mDb;

    TableModel* table;
    TableModel2* tableMeetings;

    QDialog* dioConnectDb;
    QLineEdit* tlHostname;
    QLineEdit* tlPort;
    QLineEdit* tlUsername;
    QLineEdit* tlPassword;
    QLineEdit* tlDbName;

    QMainWindow* dioResults;
    TableModel3* tableMeetingsResults;

    QDialog* dioAddNewUser;
    QLineEdit* lineFull_name;
    QLineEdit* lineAge;
    QLineEdit* lineRegistration_adress;
    QLineEdit* lineActual_adress;
    QLineEdit* linePhone_number;
    QLineEdit* lineCenter;
    QLineEdit* lineMeetings_visited;

    QDialog* dioAddNewMeeting;
    QLineEdit* lineNumberOfMeeting;
    QLineEdit* lineNameOfMeeting;
    QLineEdit* lineTopics;
    QLineEdit* lineParticipants;


    // QWidget interface
protected:
    //virtual void resizeEvent(QResizeEvent *event) override;
    QString personInfoGetter(int row, int col);
};
#endif // WINDOW_H
