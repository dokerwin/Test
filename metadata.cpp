#include "metadata.h"
#include <QCoreApplication>

bool done =false;

MetaData::MetaData(QObject *parent)
{

    player = new QMediaPlayer(this);
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(onMediaStatusChanged(QMediaPlayer::MediaStatus)));

}

MetaData *MetaData::getMetaData()
{
    if(metaData==nullptr){
        metaData = new MetaData();
    }
    return metaData;
}

qint64 MetaData::getDuration(QString track)
{


    done = false;
    player->setMedia(QUrl::fromLocalFile(track));
    return duration;

}

int MetaData::GetMetaData(QMediaPlayer *player)
{
    QStringList metadatalist = player->availableMetaData();

    QString metadata_key = "Duration";
    QVariant var_data;
    var_data = player->metaData(metadata_key);
    duration = var_data.toInt();

    return var_data.toInt();

}

struct A{

};

void MetaData::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{


    if (status == QMediaPlayer::LoadingMedia)
        while (status !=QMediaPlayer::LoadedMedia ) //wait till the duration is read
          {
               QCoreApplication::processEvents();
          } //this way you can loop through files
   if (status == QMediaPlayer::LoadedMedia)
        GetMetaData(player);


}



QMediaPlayer *MetaData:: player= nullptr;
qint64 MetaData::duration=0;
bool MetaData::done=0;
MetaData * MetaData:: metaData = nullptr;
