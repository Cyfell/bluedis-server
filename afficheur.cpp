#include "afficheur.h"
#include "ui_afficheur.h"
#include <qdebug.h>
#include <unistd.h>
#include <dirent.h>
#include <string>


Afficheur::Afficheur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Afficheur)
{
    listFiles = new QStringList();
    this->actualiseListFiles();
    //qDebug()<<*listFiles;

    ui->setupUi(this);
    control=true;
}

void Afficheur::LoadFirstImg()
{
    QString imageDir="content/";
    qDebug()<<"Image affichée : "+imageDir+listFiles->at(0);
    image.load(imageDir+listFiles->at(0));
    scene = new QGraphicsScene(this);

    item = scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->mainImage->setScene(scene);

}

void Afficheur::InitiateDirectoryWatcher(QString watcher_path){
    //create watcher
    watcher = new QFileSystemWatcher();
    // add path to watch
    watcher->addPath(watcher_path);
    //initiate watcher
    connect(watcher,SIGNAL(directoryChanged(QString)),this, SLOT(actualiseImg()));
}

void Afficheur::actualiseListFiles(){
    DIR *dir;
    struct dirent *ent;
    listFiles->clear();
    if ((dir = opendir ("/root/content")) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
          if(strcmp(ent->d_name,".") != 0 && strcmp(ent->d_name,"..") != 0){
            *listFiles << ent->d_name;
          }
      }
      closedir (dir);
    } else {
      /* could not open directory */
        qDebug()<<"could not open directory";
    }
}

void Afficheur::actualiseImg(){
    qDebug()<<"nouvelle image detectee";
    QStringList *oldList = new QStringList(*listFiles);
    QString new_file;

    this->actualiseListFiles();
    new_file =this->findNewFile(oldList);
    qDebug()<<"le nouveau fichier s'appele :"+new_file;

    this->scene->removeItem(this->scene->items().first());
    this->image.load("content/"+new_file);
    this->scene->addPixmap(image);

}
QString Afficheur::findNewFile(QStringList *oldList){
    QString result = "";

    // Get new file
    foreach(QString file, *listFiles){
        if(!oldList->contains(file)) {
            qDebug()<<"New file found";
            result = file;
        }
    }

    // Delete unused files
    if(result != ""){
        foreach(QString file, *listFiles){
            if(result != file){
                QString file_to_remove = "content/"+file;
                qDebug()<<"je supprime le fichier :"+file_to_remove;
                remove(file_to_remove.toAscii());
            }
        }
    }

    return result;
}

void Afficheur::print(QString srt){
    qDebug()<<srt;

    // LE BON COMMENTAIRE QUAND TU ES PARTI SANS FERMER TA SESSION
}

Afficheur::~Afficheur()
{
    delete ui;
}
