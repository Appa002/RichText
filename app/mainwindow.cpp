#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    richAction = new QAction(this);
    richAction->setShortcut(QKeySequence(tr("Ctrl+Return")));
    connect(richAction, &QAction::triggered, this, &MainWindow::createGraph);
    this->addAction(richAction);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete richAction;
}

void MainWindow::createGraph()
{
    this->ui->textEdit->render();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
}
