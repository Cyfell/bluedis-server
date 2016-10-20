#ifndef FOLDERWATCHER_H
#define FOLDERWATCHER_H
#include <qstring.h>
#include <qdebug.h>
#include <unistd.h>
#include <dirent.h>
#include <string>
#include <qfilesystemwatcher.h>
#include <qstringlist.h>




class FolderWatcher : public QObject
{
Q_OBJECT
public:
    FolderWatcher();

public slots :
    void onFileDetected();

signals :
    QString pictureDetected(QString new_file);

private:
    void ActualiseList();
    QString findNewFile(QStringList *oldList);
    QStringList *listFiles;
    const QString CONTENT_PATH;
    QFileSystemWatcher *watcher;

};

#endif // FOLDERWATCHER_H
