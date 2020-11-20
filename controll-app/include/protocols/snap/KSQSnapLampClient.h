//  ────────────────────────────────────────────────────────────
//                     ╔╗  ╔╗ ╔══╗      ╔════╗
//                     ║╚╗╔╝║ ╚╣╠╝      ║╔╗╔╗║
//                     ╚╗╚╝╔╝  ║║  ╔══╗ ╚╝║║╚╝
//                      ╚╗╔╝   ║║  ║╔╗║   ║║
//                       ║║   ╔╣╠╗ ║╚╝║   ║║
//                       ╚╝   ╚══╝ ╚══╝   ╚╝
//    ╔╗╔═╗                    ╔╗                     ╔╗
//    ║║║╔╝                   ╔╝╚╗                    ║║
//    ║╚╝╝  ╔══╗ ╔══╗ ╔══╗  ╔╗╚╗╔╝  ╔══╗ ╔╗ ╔╗╔╗ ╔══╗ ║║  ╔══╗
//    ║╔╗║  ║║═╣ ║║═╣ ║╔╗║  ╠╣ ║║   ║ ═╣ ╠╣ ║╚╝║ ║╔╗║ ║║  ║║═╣
//    ║║║╚╗ ║║═╣ ║║═╣ ║╚╝║  ║║ ║╚╗  ╠═ ║ ║║ ║║║║ ║╚╝║ ║╚╗ ║║═╣
//    ╚╝╚═╝ ╚══╝ ╚══╝ ║╔═╝  ╚╝ ╚═╝  ╚══╝ ╚╝ ╚╩╩╝ ║╔═╝ ╚═╝ ╚══╝
//                    ║║                         ║║
//                    ╚╝                         ╚╝
//
//    Lead Maintainer: Roman Kutashenko <kutashenko@gmail.com>
//  ────────────────────────────────────────────────────────────

#ifndef _YIOT_QT_SNAP_LAMP_CLIENT_SERVICE_H_
#define _YIOT_QT_SNAP_LAMP_CLIENT_SERVICE_H_

#include <QtCore>

#include <virgil/iot/protocols/snap/lamp/lamp-structs.h>
#include <virgil/iot/protocols/snap/lamp/lamp-client.h>
#include <virgil/iot/qt/helpers/VSQSingleton.h>
#include <virgil/iot/qt/protocols/snap/VSQSnapServiceBase.h>

using namespace VirgilIoTKit;

class VSQSnapLampClient final :
        public QObject,
        public VSQSingleton<VSQSnapLampClient>,
        public VSQSnapServiceBase {

    Q_OBJECT

    friend VSQSingleton<VSQSnapLampClient>;

public:

    /** Get service interface
     *
     * \return Service interface
     */
    const VirgilIoTKit::vs_snap_service_t *
    serviceInterface() override {
        return m_snapService;
    }

    /** Get service feature
     *
     * \return Service feature
     */
    VSQFeatures::EFeature
    serviceFeature() const override {
        return VSQFeatures::SNAP_LAMP_CLIENT;
    }

    /** Get service name
     *
     * \return Service name
     */
    const QString &
    serviceName() const override {
        static QString name{"LAMP Client"};
        return name;
    }

signals:
    void
    fireStateUpdate(const vs_mac_addr_t mac, const vs_snap_lamp_state_t state);

    void
    fireStateError(const vs_mac_addr_t mac);

public slots:
    void
    requestState(const vs_mac_addr_t &mac);

    void
    setState(const vs_mac_addr_t &mac, const vs_snap_lamp_state_t &state);


private:
    const VirgilIoTKit::vs_snap_service_t *m_snapService;

    VSQSnapLampClient();
    virtual ~VSQSnapLampClient() = default;

    static vs_status_e onUpdateState(vs_status_e res, const vs_mac_addr_t *mac, const vs_snap_lamp_state_t *data);

};

#endif // _YIOT_QT_SNAP_LAMP_CLIENT_SERVICE_H_