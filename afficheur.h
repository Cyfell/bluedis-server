#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <folderwatcher.h>
#include "ui_afficheur.h"
#include <qdebug.h>
#include <unistd.h>
#include <dirent.h>
#include <string>
#include <QString>
#include <QtMultimedia>
//#include <QMediaPlayer>
#include <QSound>

#define DEFAULT_CONTENT_DIR  "/var/lib/bluedis/downloads/"

namespace Ui {
class Afficheur;
}

class Afficheur : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Afficheur(QWidget *parent = 0);

    ~Afficheur();
    
public slots :
        void displayImg(QString img_name);
        void playSound(QString music_file);
        void displayVideo();
        void commandVideo();

signals:
      void file_found();

private:

    Ui::Afficheur *ui;
    QGraphicsScene *scene;
    QPixmap image;
    QGraphicsPixmapItem *item;

    FolderWatcher *dir_watcher;
};

#endif // AFFICHEUR_H
