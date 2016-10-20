#include <QtGui/QApplication>
#include "afficheur.h"

#include <stdio.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Afficheur afficheur;
    afficheur.showFullScreen();



    return a.exec();
}

