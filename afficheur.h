#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <qfilesystemwatcher.h>


namespace Ui {
class Afficheur;
}

class Afficheur : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Afficheur(QWidget *parent = 0);
    void LoadFirstImg();
    void actualiseListFiles();
    void InitiateDirectoryWatcher(QString watcher_path);


    void watch_dir();
    ~Afficheur();
    
public slots :
      void print(QString str);
      void actualiseImg();

signals:
      void file_found();

private:

    QString findNewFile(QStringList *newList);

    QStringList *listFiles;
    Ui::Afficheur *ui;
    QGraphicsScene *scene;
    QPixmap image;
    QGraphicsPixmapItem *item;
    QFileSystemWatcher *watcher;
    bool control;
    //Folder_watcher *folder_watcher;
};

#endif // AFFICHEUR_H
