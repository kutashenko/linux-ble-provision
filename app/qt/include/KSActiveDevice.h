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
//   04 August 2020
//   Lead Maintainer: Roman Kutashenko <kutashenko@gmail.com>

#ifndef PROVISION_QT_ACTIVE_DEVICE_H
#define PROVISION_QT_ACTIVE_DEVICE_H

#include <QtCore>

struct KSActiveDeviceInfo {
    QDateTime lastUpdate;
    QString image;

    KSActiveDeviceInfo(QString img = "") {
        lastUpdate = QDateTime::currentDateTime();
        image = img;
    }
};

typedef QMap<QString, KSActiveDeviceInfo> KSQActiveDevices;


#endif // PROVISION_QT_ACTIVE_DEVICE_H
