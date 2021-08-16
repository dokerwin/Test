#ifndef APPCORE_H
#define APPCORE_H
#include<QVector>
#include <QObject>
#include <QtMultimedia/QMediaPlayer>
#include<QMediaMetaData>
#include <QTimer>
#include "playlist.h"
class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = nullptr);

    void priviously();
    void setVolume();


    Playlist &getPlaylist();
    void set_curr_track();
    void start_playing();

signals:
    void durationChanged(int duration);
    void setDurationSignal(int duration_);
    void controlLevelChanged(int volume);
    void sendLabelToQml(QString track);
    void allTracksToQml(unsigned int  allTracks);

public slots:
    void test(int dur);//for test setting duration
    void setDirectory(QString directory);
    int  getControlLevel() const;
    void setControlLevel(int _controlLevel);
    void setDuration(int duration);
    void nextTrack();
    void prevTrack();
    void randomTrack();
    void play_track(QString track);

    void play();
    void pause();
    void stop();




private slots:
    void setDuration1();//set duration for timer


private:

    Playlist  playlist;
    size_t curr_track;
    QMediaPlayer *player;
    int controlLevel;
    static int duration__;
    static int status;
    static size_t  temp;
    QTimer *timer;

};
#endif // APPCORE_H
