#include "processdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    processdialog w;
    w.show();

    return a.exec();
}
