#include "afficheur.h"




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
    connect(dir_watcher,SIGNAL(musicDetected(QString)), this, SLOT(playSound(QString)));

}
/*
  Affiche une image dans la scène

  */
void Afficheur::displayImg(QString img_name){
    QString defaultContentDir(DEFAULT_CONTENT_DIR);
    QDebug waitPrint = qDebug();
    this->scene->removeItem(this->scene->items().first());
    qDebug()<<"affichage de l'image : "+defaultContentDir+img_name;
    for(int i = 0; i < 100000; i++){
        waitPrint << ".";
    }
    qDebug()<<"Done";
    this->image.load(DEFAULT_CONTENT_DIR+img_name);
    this->scene->addPixmap(image);
}
/*
  Play music

  */
void Afficheur::playSound(QString music_file){
    //TODO
    QSound sound(music_file);
    sound.play();
}

/*
  Affiche une vidéo dans la scène

  */
void Afficheur::displayVideo(){
    //TODO

}

/*
  commande la vidéo

  */
void Afficheur::commandVideo(){
    //TODO
}

Afficheur::~Afficheur()
{
    delete ui;
}
