#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "app/ExpressionDisplayWidget.h"

#include <QDebug>
#include <QResizeEvent>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->hide();

    richAction = new QAction(this);
    richAction->setShortcut(QKeySequence(tr("Ctrl+Return")));
    connect(richAction, &QAction::triggered, this, &MainWindow::createGraph);
    this->addAction(richAction);

    ui->frame->setup(ui->expressionAdderEdit, ui->sugestionsList);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete richAction;
}


void MainWindow::createGraph()
{
    this->adderOpen = !this->adderOpen;

    this->adderOpen ? (ui->frame->show()) : (ui->frame->hide());
    this->adderOpen ? (ui->expressionAdderEdit->setFocus()) : (ui->textEdit->setFocus());
    this->ui->textEdit->render();

    // 420 + 15 * #lables
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    this->ui->textEdit->resize(event->size().width(), event->size().height());
    this->ui->textEdit->move(0, 0);

    double frameRelativeWidth = 0.8;
    double frameWidth = event->size().width() * frameRelativeWidth;
    double frameYPos = (event->size().width() - frameWidth) / 2;

    this->ui->frame->resize(static_cast<int>(frameWidth), this->ui->frame->size().height());
    this->ui->frame->move(static_cast<int>(frameYPos), 0);
}
