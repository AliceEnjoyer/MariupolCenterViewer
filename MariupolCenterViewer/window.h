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

    QDialog* dioResults;
    TableModel3* tableMeetingsResults;

    // QWidget interface
protected:
    //virtual void resizeEvent(QResizeEvent *event) override;
    QString personInfoGetter(int row, int col);
};
#endif // WINDOW_H
