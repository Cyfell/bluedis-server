#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <folderwatcher.h>


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

signals:
      void file_found();

private:

    Ui::Afficheur *ui;
    QGraphicsScene *scene;
    QPixmap image;
    QGraphicsPixmapItem *item;

    const QString DEFAULT_IMAGE_DIR="content/";
    FolderWatcher *dir_watcher;
};

#endif // AFFICHEUR_H
