#include <QtGui/QApplication>
#include "afficheur.h"

#include <stdio.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Afficheur afficheur;
    afficheur.actualiseListFiles();

    afficheur.LoadFirstImg();
    afficheur.InitiateDirectoryWatcher("content/");
    afficheur.showFullScreen();



    return a.exec();
}

