#include "afficheur.h"
#include "ui_afficheur.h"
#include "newfile.h"
#include <qdebug.h>
#include <unistd.h>
#include <dirent.h>
#include <string>



Afficheur::Afficheur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Afficheur)
{
    ui->setupUi(this);

    image.load("chien.png");
    scene = new QGraphicsScene(this);
    item = scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->mainImage->setScene(scene);

    dir_watcher = new FolderWatcher();

    connect(dir_watcher,SIGNAL(pictureDetected(QString)), this, SLOT(displayImg(QString)));


}

void Afficheur::displayImg(QString img_name){
    this->scene->removeItem(this->scene->items().first());
    this->image.load("content/"+img_name);
    this->scene->addPixmap(image);
}


Afficheur::~Afficheur()
{
    delete ui;
}
