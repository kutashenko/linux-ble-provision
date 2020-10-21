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
//   05 August 2020
//   Lead Maintainer: Roman Kutashenko <kutashenko@gmail.com>

import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "../../theme"
import "../../components"

Page {
    id: settingsPage

    background: Rectangle {
        color: "transparent"
    }

    header: Header {
        title: qsTr("Global Settings")
        showBackButton: false
        showMenuButton: true
        showSettingsButton: true
    }

    ListView {
        id: list
        anchors.fill: parent

        spacing: 1

        model: ListModel {
            ListElement {
                name: qsTr("WiFi credentials")
                image: "Key"
                property var action: function() {
                    showWiFiSettings()
                }
            }

            ListElement {
                name: qsTr("Event triggers")
                image: "Lock"
                property var action: function() {
                    showEventsSettings()
                }
            }
        }

        delegate: Rectangle {
            id: base
            width: parent.width
            height: 45
            color: "transparent"

            RowLayout {
                id: listDelegate
                anchors.fill: parent
                clip: true

                Image {
                    id: icon
                    source: "qrc:/qml/resources/icons/%1.png".arg(image)
                    Layout.maximumHeight: listDelegate.height * 0.7
                    Layout.maximumWidth: Layout.maximumHeight
                    fillMode: Image.PreserveAspectFit
                    Layout.alignment: Qt.AlignLeft
                    Layout.leftMargin: 10
                }

                Text {
                    id: nameText
                    text: name
                    color: Theme.primaryTextColor
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: UiHelper.fixFontSz(14)

                    Layout.alignment: Qt.AlignLeft
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                RowLayout {
                    id: actionsBlock
                    Layout.rightMargin: 10

                    Image {
                        id: iconAction
                        source: "qrc:/qml/resources/icons/Arrow-Right.png"
                        Layout.maximumHeight: listDelegate.height * 0.7
                        Layout.maximumWidth: Layout.maximumHeight
                        fillMode: Image.PreserveAspectFit
                        Layout.alignment: Qt.AlignRight
                        Layout.rightMargin: 10
                    }
                }
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    action()
                }

                onEntered: {
                    base.color = Theme.contactsBackgroundColor
                }

                onExited: {
                    base.color = "transparent"
                }
            }
        }
    }
}
