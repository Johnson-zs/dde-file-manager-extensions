// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef EVENTSHANDLER_H
#define EVENTSHANDLER_H

#include <QObject>
#include <QMap>

namespace dfmplugin_diskenc {
class EncryptProcessDialog;
class EventsHandler : public QObject
{
    Q_OBJECT
public:
    static EventsHandler *instance();
    void bindDaemonSignals();
    void hookEvents();

private Q_SLOTS:
    void onPreencryptResult(const QString &, const QString &, int);
    void onEncryptResult(const QString &, int);
    void onEncryptProgress(const QString &, double);
    void onDecryptResult(const QString &, const QString &, int);
    void onDecryptProgress(const QString &, double);
    void onChgPassphraseResult(const QString &, const QString &, int);
    bool onAcquireDevicePwd(const QString &dev, QString *pwd, bool *giveup);

    QString acquirePassphrase(const QString &dev, bool &cancelled);
    QString acquirePassphraseByPIN(const QString &dev, bool &cancelled);
    QString acquirePassphraseByTPM(const QString &dev, bool &cancelled);

private:
    explicit EventsHandler(QObject *parent = nullptr);

    QMap<QString, EncryptProcessDialog *> encryptDialogs;
    QMap<QString, EncryptProcessDialog *> decryptDialogs;
signals:
};
}
#endif   // EVENTSHANDLER_H
