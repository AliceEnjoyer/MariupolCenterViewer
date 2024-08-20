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

    table = new TableModel(0, 3);
    tableView->setModel(table);

    tableMeetings = new TableModel2(0, 4);
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


    mTableMeetings->setStyleSheet("QMenu{background: rgb(65, 105, 225); color: white;} QMenu::item:selected  {background-color: rgb(255, 216, 0);color: black;}");
    mDb->setStyleSheet("QMenu{background: rgb(65, 105, 225); color: white;} QMenu::item:selected  {background-color: rgb(255, 216, 0);color: black;}");
    mPerson->setStyleSheet("QMenu{background: rgb(65, 105, 225); color: white;} QMenu::item:selected  {background-color: rgb(255, 216, 0);color: black;}");

    m = new QMenuBar(this);
    m->addMenu(mDb);
    m->addMenu(mPerson);
    m->addMenu(mTableMeetings);
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

    //dioResults->setGeometry(dioResults->x(), dioResults->y(), meetingsResultView->width()+40, 300);



    dioAddNewUser = new QDialog(this);
    lineFull_name = new QLineEdit();
    lineAge = new QLineEdit();
    lineRegistration_adress = new QLineEdit();
    lineActual_adress = new QLineEdit();
    linePhone_number = new QLineEdit();
    lineCenter = new QLineEdit();
    lineMeetings_visited = new QLineEdit();
    QPushButton* bAddNewUser = new QPushButton("Add");
    QVBoxLayout* vblAddNewUser = new QVBoxLayout;
    vblAddNewUser->addWidget(new QLabel("Full name: "));
    vblAddNewUser->addWidget(lineFull_name);
    vblAddNewUser->addWidget(new QLabel("Age: "));
    vblAddNewUser->addWidget(lineAge);
    vblAddNewUser->addWidget(new QLabel("Registration address: "));
    vblAddNewUser->addWidget(lineRegistration_adress);
    vblAddNewUser->addWidget(new QLabel("Actual address: "));
    vblAddNewUser->addWidget(lineActual_adress);
    vblAddNewUser->addWidget(new QLabel("Phone number: "));
    vblAddNewUser->addWidget(linePhone_number);
    vblAddNewUser->addWidget(new QLabel("Center: "));
    vblAddNewUser->addWidget(lineCenter);
    vblAddNewUser->addWidget(new QLabel("Meetings visited: "));
    vblAddNewUser->addWidget(lineMeetings_visited);
    vblAddNewUser->addWidget(bAddNewUser);
    dioAddNewUser->setLayout(vblAddNewUser);
    //dioAddNewUser->setGeometry(dioAddNewUser->x(), dioAddNewUser->y(),dioAddNewUser->width(), 100);




    dioAddNewMeeting = new QDialog(this);
    lineNumberOfMeeting = new QLineEdit();
    lineNameOfMeeting = new QLineEdit();
    lineTopics = new QLineEdit();
    lineParticipants = new QLineEdit();
    lineEssence = new QTextEdit();
    lineAuthor = new QLineEdit();
    lineHowToUse = new QTextEdit();
    QPushButton* bAddNewMeeting = new QPushButton("Add");
    QVBoxLayout* vblAddNewMeeting = new QVBoxLayout;
    vblAddNewMeeting->addWidget(new QLabel("Number of meeting: "));
    vblAddNewMeeting->addWidget(lineNumberOfMeeting);
    vblAddNewMeeting->addWidget(new QLabel("Name of meeting: "));
    vblAddNewMeeting->addWidget(lineNameOfMeeting);
    vblAddNewMeeting->addWidget(new QLabel("Topics: "));
    vblAddNewMeeting->addWidget(lineTopics);
    vblAddNewMeeting->addWidget(new QLabel("Participants: "));
    vblAddNewMeeting->addWidget(lineParticipants);
    vblAddNewMeeting->addWidget(new QLabel("Essence: "));
    vblAddNewMeeting->addWidget(lineEssence);
    vblAddNewMeeting->addWidget(new QLabel("Author: "));
    vblAddNewMeeting->addWidget(lineAuthor);
    vblAddNewMeeting->addWidget(new QLabel("How to use: "));
    vblAddNewMeeting->addWidget(lineHowToUse);
    vblAddNewMeeting->addWidget(bAddNewMeeting);
    dioAddNewMeeting->setLayout(vblAddNewMeeting);




    connect(m, &QMenuBar::triggered, this, &window::slotMenuTriggered);
    connect(tableView, &QTableView::doubleClicked, this, &window::slotTableDoubleClicked);
    connect(tableMeetingsView, &QTableView::doubleClicked, this, &window::slotMeetingsViewDoubleClicked);   
    connect(bAddNewUser, &QPushButton::clicked, this, &window::slotAddNewUserClicked);
    connect(bAddNewMeeting, &QPushButton::clicked, this, &window::slotAddNewMeetindClicked);
    connect(bConnectDb, &QPushButton::clicked, this, &window::slotConnectDbClicked);
}

