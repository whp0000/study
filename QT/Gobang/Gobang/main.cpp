#include "includes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GobangWidget w;
    w.show();

    return a.exec();
}
