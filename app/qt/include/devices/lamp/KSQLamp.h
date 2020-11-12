//
//                                  _____   _______
//                                 |_   _| |__   __|
//                                   | |  ___ | |
//                                   | | / _ \| |
//                                  _| || (_) | |
//                                 |_____\___/|_|
//
//    _  ________ ______ _____    _____ _______    _____ _____ __  __ _____  _      ______
//   | |/ /  ____|  ____|  __ \  |_   _|__   __|  / ____|_   _|  \/  |  __ \| |    |  ____|
//   | ' /| |__  | |__  | |__) |   | |    | |    | (___   | | | \  / | |__) | |    | |__
//   |  < |  __| |  __| |  ___/    | |    | |     \___ \  | | | |\/| |  ___/| |    |  __|
//   | . \| |____| |____| |       _| |_   | |     ____) |_| |_| |  | | |    | |____| |____
//   |_|\_\______|______|_|      |_____|  |_|    |_____/|_____|_|  |_|_|    |______|______|
//
//
//
//   01 August 2020
//   Lead Maintainer: Roman Kutashenko <kutashenko@gmail.com>

#ifndef YIOT_LAMP_H
#define YIOT_LAMP_H


#include <QtCore>
#include <virgil/iot/protocols/snap/lamp/lamp-structs.h>

#include <devices/KSQDeviceBase.h>

class KSQLamp : public KSQDeviceBase {
    Q_OBJECT
    Q_PROPERTY(QString state READ state WRITE setState NOTIFY fireStateChanged)
public:
    KSQLamp() : KSQDeviceBase() { }
    KSQLamp(VSQMac mac, QString name, QString img = "");
    KSQLamp(const KSQLamp& l);
    virtual ~KSQLamp() = default;

    Q_INVOKABLE QString
    state() const;

    virtual QString
    _deviceType() const final { return "lampMono"; }

    static const QString kStateUnknown;
    static const QString kStateOn;
    static const QString kStateOff;
    static const QStringList kStates;

signals:
    void fireStateChanged(QString);
    void fireSetDeviceParams(const KSQLamp &lamp);

public slots:
    Q_INVOKABLE void
    setState(QString state);

private:
    QString m_state;
};

Q_DECLARE_METATYPE(KSQLamp)
Q_DECLARE_METATYPE(KSQLamp*)

#endif // YIOT_LAMP_H
