#include "folderwatcher.h"


 /*
  *Watcher Initialisation
  *
  *
  */
FolderWatcher::FolderWatcher()
{
    // Create list file
    listFiles = new QStringList();
    this->ActualiseList();


    const QString CONTENT_PATH = "content/";
    //create watcher
    watcher = new QFileSystemWatcher();
    // add path to watch
    watcher->addPath(CONTENT_PATH);
    // Connect watcher
    QObject::connect(watcher,SIGNAL(directoryChanged(QString)),this, SLOT(onFileDetected()));

}

void FolderWatcher::onFileDetected(){
    qDebug()<<"changement dans le dossier détecté";
    QStringList *oldList = new QStringList(*listFiles);
    QString new_file;

    this->ActualiseList();
    new_file =this->findNewFile(oldList);


    if (new_file!=""){
        qDebug()<<"le nouveau fichier s'appele :"+new_file;
//        emit pictureDetected(new_file);
        if(new_file.split(".").at(1)=="jpg" || new_file.split(".").at(1)=="png" ){

            qDebug()<<"LLLLL"<<new_file;
            emit pictureDetected(new_file);
        }
    }

}



/*
  save current name files in the list
*/

void FolderWatcher::ActualiseList(){
    DIR *dir;
    struct dirent *ent;
    listFiles->clear();
    if ((dir = opendir ("/root/content")) != NULL) {

      while ((ent = readdir (dir)) != NULL) {
          if(strcmp(ent->d_name,".") != 0 && strcmp(ent->d_name,"..") != 0){
            *listFiles << ent->d_name;
          }
      }
      closedir (dir);
    } else {
        qDebug()<<"could not open directory";
    }
}

QString FolderWatcher::findNewFile(QStringList *oldList){
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
