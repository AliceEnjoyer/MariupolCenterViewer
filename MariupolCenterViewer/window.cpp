#include "window.h"

window::window(QWidget *parent)
    : QMainWindow(parent)
{
    QTableView* tableView = new QTableView;
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setMaximumWidth(500);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QTableView* tableMeetingsView = new QTableView;
    tableMeetingsView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    table = new TableModel(3, 3);
    tableView->setModel(table);

    tableMeetings = new TableModel2(4, 4);
    tableMeetingsView->setModel(tableMeetings);
    tableMeetingsView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    mDb = new QMenu("database");
    mDb->addAction("connect...");
    mDb->addAction("refresh");

    QMenu* mPerson = new QMenu("participants table");
    mPerson->addAction("add person...");
    mPerson->addAction("change person...");
    mPerson->addSeparator();
    mPerson->addAction("delete person...");

    QMenu* mTableMeetings = new QMenu("meetings table");
    mTableMeetings->addAction("add meeting...");
    mTableMeetings->addAction("change meeting...");
    mTableMeetings->addSeparator();
    mTableMeetings->addAction("delete meeting...");

    QMenu* mTableMeetingsInfo = new QMenu("meetings info table");
    mTableMeetingsInfo->addAction("add meeting info...");
    mTableMeetingsInfo->addAction("change meeting info...");
    mTableMeetingsInfo->addSeparator();
    mTableMeetingsInfo->addAction("delete meeting info...");


    mDb->setStyleSheet("QMenu{background: rgb(65, 105, 225); color: white;} QMenu::item:selected  {background-color: rgb(255, 216, 0);color: black;}");
    mPerson->setStyleSheet("QMenu{background: rgb(65, 105, 225); color: white;} QMenu::item:selected  {background-color: rgb(255, 216, 0);color: black;}");
    mTableMeetingsInfo->setStyleSheet("QMenu{background: rgb(65, 105, 225); color: white;} QMenu::item:selected  {background-color: rgb(255, 216, 0);color: black;}");

    m = new QMenuBar(this);
    m->addMenu(mDb);
    m->addMenu(mPerson);
    m->addMenu(mTableMeetingsInfo);
    m->addAction("About...");

    setMenuBar(m);

    QWidget* centralWidget = new QWidget;
    QHBoxLayout* hbl = new QHBoxLayout;
    hbl->addWidget(tableMeetingsView);
    hbl->addWidget(tableView);
    centralWidget->setLayout(hbl);

    setCentralWidget(centralWidget);




    setMinimumWidth(1120);
    setMinimumHeight(200);



    dioConnectDb = new QDialog(this);
    tlHostname = new QLineEdit();
    tlPort = new QLineEdit();
    tlPort->setMaxLength(5);
    tlPort->setValidator(new QIntValidator());
    tlUsername = new QLineEdit();
    tlPassword = new QLineEdit();
    tlPassword->setEchoMode(QLineEdit::Password);

    tlDbName = new QLineEdit();
    QPushButton* bConnectDb = new QPushButton("Connect");

    QVBoxLayout *vblDioConnectDb = new QVBoxLayout;
    vblDioConnectDb->addWidget(new QLabel("host name: "));
    vblDioConnectDb->addWidget(tlHostname);
    vblDioConnectDb->addWidget(new QLabel("port: "));
    vblDioConnectDb->addWidget(tlPort);
    vblDioConnectDb->addWidget(new QLabel("Username: "));
    vblDioConnectDb->addWidget(tlUsername);
    vblDioConnectDb->addWidget(new QLabel("Password: "));
    vblDioConnectDb->addWidget(tlPassword);
    vblDioConnectDb->addWidget(new QLabel("Database name: "));
    vblDioConnectDb->addWidget(tlDbName);
    vblDioConnectDb->addSpacing(20);
    vblDioConnectDb->addWidget(bConnectDb);

    dioConnectDb->setLayout(vblDioConnectDb);
    dioConnectDb->setGeometry(dioConnectDb->x(), dioConnectDb->y(), 350, 380);
    dioConnectDb->setWindowTitle("Connection to database");
    dioConnectDb->setFixedSize(350, dioConnectDb->height());



    dioResults = new QDialog(this);
    QTableView* meetingsResultView = new QTableView;
    meetingsResultView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    meetingsResultView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableMeetingsResults = new TableModel3(5, 5);
    meetingsResultView->setModel(tableMeetingsResults);

    QVBoxLayout* vblDioMettingsResults = new QVBoxLayout();
    vblDioMettingsResults->addWidget(meetingsResultView);

    dioResults->setLayout(vblDioMettingsResults);
    dioResults->setGeometry(dioResults->x(), dioResults->y(), meetingsResultView->width()+40, 300);


    connect(m, &QMenuBar::triggered, this, &window::slotMenuTriggered);
    connect(tableView, &QTableView::doubleClicked, this, &window::slotTableDoubleClicked);
    connect(tableMeetingsView, &QTableView::doubleClicked, this, &window::slotMeetingsViewDoubleClicked);
    connect(meetingsResultView, &QTableView::doubleClicked, this, &window::slotMeetingsResultViewDoubleClicked);
}

