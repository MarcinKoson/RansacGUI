#include "mainwindow.h"

#include <QApplication>
/*!
 * \brief main
 * \param argc
 * \param argv
 * \return
 *
 * Main function of program
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
