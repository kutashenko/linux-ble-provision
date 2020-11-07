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
//   09 October 2020
//   Lead Maintainer: Roman Kutashenko <kutashenko@gmail.com>

import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "../../../../theme"
import "../../../../components"

Page {
    id: p

    background: Rectangle {
        color: "transparent"
    }

    header: Header {
        title: qsTr("Lamp")
        backAction: function() { showDevices() }
    }

    Form {
        id: form
        stretched: true

        ColumnLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.topMargin: 40
            Layout.bottomMargin: 20

            spacing: 10

            Label {
                id: infoText
                Layout.alignment: Qt.AlignHCenter
                Layout.fillHeight: true
                Layout.fillWidth: true

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: Theme.mainFont
                font.pointSize: UiHelper.fixFontSz(24)
                color: Theme.brandColor
            }

            Image {
                property string img: ""
                id: stateImage

                Layout.fillHeight: true
                Layout.fillWidth: true

                fillMode: Image.PreserveAspectFit
                source: "qrc:/qml/resources/icons/dark/devices/lamp/mono/%1".arg(img)

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (monoLampController.state !== "on") {
                            monoLampController.state = "on"
                        } else {
                            monoLampController.state = "off"
                        }
                    }
                }
            }

            FormPrimaryButton {
                id: actionButton
                Layout.bottomMargin: 10
                text: qsTr("Close")
                onClicked: {
                    showDevices()
                }
            }
        }
    }

    states: [
        State {
            name: "unknown"
            PropertyChanges { target: infoText; text: qsTr("Unknown state") }
            PropertyChanges { target: stateImage; img: "unknown" }
        },
        State {
            name: "on"
            PropertyChanges { target: infoText; text: qsTr("On") }
            PropertyChanges { target: stateImage; img: "on" }
        },
        State {
            name: "off"
            PropertyChanges { target: infoText; text: qsTr("Off") }
            PropertyChanges { target: stateImage; img: "off" }
        }
    ]

    onVisibleChanged: {
        state = monoLampController.state
    }

    Connections {
        target: monoLampController

        onFireStateChanged: {
            state = monoLampController.state
        }
    }

}