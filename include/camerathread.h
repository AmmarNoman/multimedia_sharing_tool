#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

#include <QThread>
#include <configurations.h>
#include <serverstreamthread.h>
#include <cudadetectionthread.h>
#include <feedaudiopipethread.h>
#include <feedvideopipethread.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <semaphore.h>
#include <sys/ioctl.h> // Allows to check if a pipe is ready to be read
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

class CameraThread : public QThread
{
    Q_OBJECT
public:
    CameraThread();
    ~CameraThread();
    void run();

private:
    ServerStreamThread *server_stream_thread;
    CudaDetectionThread *cuda_detection_thread;
    FeedAudioPipeThread *audio_pipe_thread;
    FeedVideoPipeThread *video_pipe_thread;
    sem_t sem_audio, sem_video, sem_screen, sem_detection_done;
    bool thread_active = true;
    bool tik_tok = true; // Used to prevent audio and frames to be subscribed in subsequent iterations
    int mst_audio_pipe, mst_video_pipe, ffmpeg_audio_pipe, ffmpeg_video_pipe;
    std::string path, mstaudio_pipe_path, mstvideo_pipe_path, ffaudio_pipe_path, ffvideo_pipe_path;
    std::string file_name, strvideo_length, command, rtsp_url, timing;
    long video_length, begin_chunk, end_chunk;
    int begin_h, begin_m, begin_s, end_h, end_m, end_s;

    void captureFromFile();
    std::string execCmd(const char* cmd);
    long strToPositiveDigit(std::string s);
    void beginCameraWork();
    void ffmpegJob();
    void defineChunk();
    void createChunk();
    void captureFromScreen();

public slots:
    void notifyAudioToMstCondVar();
    void notifyVideoToMstCondVar();
    void continueSendingScreenFrame();
    void detectionDone();

signals:
    void writeText(QString);
    void stopStream();
    void setStreamingEnded();
    void takeAScreenPicture(std::string save_path);
    void runIntrusionDetection(bool single_frame);
};

#endif // CAMERATHREAD_H
