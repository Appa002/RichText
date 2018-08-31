#include "mainwindow.h"
#include <QApplication>
#include <fstream>

static std::ofstream logFile;

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
    QByteArray localMsg = msg.toLocal8Bit();
    char str[256] = {0};
    FILE* stream;

    switch (type) {
    case QtDebugMsg:
        sprintf(str, "[DEBUG] [%s] \033[1m\033[95m%s\033[0m (%s:%u)\n\n", context.function, localMsg.constData(), context.file, context.line);
        stream = stdout;
        break;
    case QtInfoMsg:
        sprintf(str, "[INFO] [%s] \033[1m\033[95m%s\033[0m (%s:%u)\n\n", context.function, localMsg.constData(), context.file, context.line);
        stream = stdout;
        break;
    case QtWarningMsg:
        sprintf(str, "[WARNING] [%s] \033[1m\033[95m%s\033[0m (%s:%u)\n\n", context.function, localMsg.constData(), context.file, context.line);
        stream = stdout;
        break;
    case QtCriticalMsg:
        sprintf(str, "[CRITICAL] [%s] \033[1m\033[95m%s\033[0m (%s:%u)\n\n", context.function, localMsg.constData(), context.file, context.line);
        stream = stderr;
        break;
    case QtFatalMsg:
        sprintf(str, "[FATAL] [%s] \033[1m\033[95m%s\033[0m (%s:%u)\n\n", context.function, localMsg.constData(), context.file, context.line);
        stream = stderr;
        break;
    }

    if(logFile.is_open()){
        logFile << str;
        logFile.flush();
    }

    fprintf(stream, "%s", str);
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
