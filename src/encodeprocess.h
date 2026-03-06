#ifndef ENCODEPROCESS_H
#define ENCODEPROCESS_H

#include <QObject>
#include <QFile>
#include <QProcess>
#include <QString>
#include <QDebug>

class encodeProcess : public QObject
{
    Q_OBJECT
public:
    explicit encodeProcess(QObject *parent = 0);
    Q_PROPERTY(QString cmd READ cmd WRITE setCmd)
    QString cmd() { return mCmd; }
    Q_INVOKABLE bool setCmd(const QString &cmd);
    Q_PROPERTY(QString errorOutput READ errorOutput)
    QString errorOutput() { return mErrorOutput; }
    Q_INVOKABLE void runFFmpeg();
    Q_PROPERTY(QString currentState READ getCurrentState WRITE setCurrentState NOTIFY currentStateChanged)
    QString getCurrentState() { return mCurrentState; }
    Q_INVOKABLE void setCurrentState(const QString &currentState);

signals:
    void error();
    void success();
    void currentStateChanged();

public slots:
    void getffmpegOutput(int exitCode);

private:
    QString mCmd;
    QString mErrorOutput;
    QString mCurrentState = "Idle";
    QProcess ffmpegProc;
};

#endif // ENCODEPROCESS_H
