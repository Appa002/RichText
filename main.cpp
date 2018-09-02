#include "app/mainwindow.h"
#include <QApplication>
#include <fstream>

static std::ofstream logFile;
static long long counter = 0;

/*
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
*/

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    FILE* stream;
    QString formatString("[%0] [%1] \033[1m\033[95m%2\033[0m (%3:%4)\n\n");

    switch (type) {
    case QtDebugMsg:
        formatString = formatString.arg("DEBUG " + QString::number(counter))
                .arg(QString(context.function))
                .arg(msg)
                .arg(QString(context.file))
                .arg(QString::number(context.line));
        stream = stdout;
        counter++;
        break;

    case QtInfoMsg:
        formatString = formatString.arg("\033[94mINFO\033[0m")
                .arg(QString(context.function))
                .arg(msg)
                .arg(QString(context.file))
                .arg(QString::number(context.line));
        stream = stdout;
        break;

    case QtWarningMsg:
        formatString = formatString.arg("\033[93mWARNING\033[0m")
                .arg(QString(context.function))
                .arg(msg)
                .arg(QString(context.file))
                .arg(QString::number(context.line));
        stream = stdout;
        break;

    case QtCriticalMsg:
        formatString = formatString.arg("\033[91mCRITICAL\033[0m")
                .arg(QString(context.function))
                .arg(msg)
                .arg(QString(context.file))
                .arg(QString::number(context.line));
        stream = stderr;
        break;

    case QtFatalMsg:
        formatString = formatString.arg("\033[91mFATAL\033[0m")
                .arg(QString(context.function))
                .arg(msg)
                .arg(QString(context.file))
                .arg(QString::number(context.line));
        stream = stderr;    
        break;
    }

    if(logFile.is_open() && type != QtDebugMsg){
        logFile << formatString.toStdString();
        logFile.flush();
    }

    fprintf(stream, "%s", formatString.toStdString().c_str());
    fflush(stream);
}


int main(int argc, char *argv[])
{
    logFile.open("./log.txt", std::ios::out | std::ios::trunc);

    qInstallMessageHandler(myMessageOutput);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
