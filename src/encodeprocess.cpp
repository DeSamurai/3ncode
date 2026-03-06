#include "encodeprocess.h"

encodeProcess::encodeProcess(QObject *parent) : QObject(parent)
{

}

bool encodeProcess::setCmd(const QString &cmd)
{
    mCmd = cmd;
    return true;
}

void encodeProcess::runFFmpeg()
{
    QString appPath("/usr/share/harbour-encode/");
    QString appName("ffmpeg_static");
    ffmpegProc.start(appPath+appName + " -y " + mCmd); // -y to always overwrite and not ask
    connect(&ffmpegProc, SIGNAL(finished(int)), this, SLOT(getffmpegOutput(int)));
    setCurrentState("Working...");
}

void encodeProcess::getffmpegOutput(int exitCode)
{
    if (exitCode == 0) {
        setCurrentState("Finished successfully");
        Q_EMIT success();
    }
    else {
        setCurrentState("Finished with errors");
        QByteArray errorOut = ffmpegProc.readAllStandardError();
        mErrorOutput = errorOut.simplified();
        Q_EMIT error();
    }
}

void encodeProcess::setCurrentState(const QString &currentState)
{
    mCurrentState = currentState;
    currentStateChanged();
}

