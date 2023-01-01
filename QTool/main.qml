import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.12

import "./Common"
import "./Serial"

ApplicationWindow {
    id:root
    visible: true
    width: 1280
    height: 840
    title: qsTr("Hello World")

    Component.onCompleted: {
    }

    SerialMainWindow {
        id: serialMainWindow
        visible: false
    }

    RowLayout {
        x: 20
        y: 20
        Rectangle {
            id: serialArea
            width: 200
            height: 180

            Column {
                anchors.fill: parent
                Rectangle {
                    id: serialNormalArea
                    anchors.fill: parent
                    visible: true

                    Image {
                        anchors.fill: parent
                        anchors.margins: 20
                        anchors.bottomMargin: 40
                        source: "file:///D:/workstation/QTool/QTool/images/serial_image.png"
                    }

                    Text {
                        text: "Serial Communiation"
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                    }

                    Canvas {
                        anchors.fill: parent
                        Layout.alignment: bottom
                        onPaint: {
                            var ctx = getContext("2d")

                            ctx.strokeStyle = "gray"

                            ctx.beginPath()
                            ctx.moveTo(0,180)
                            ctx.lineTo(200,180)

                            ctx.stroke()
                        }
                    }
                }

                Rectangle {
                    id: serialThumbnail
                    anchors.fill: parent
                    visible: false
                    border.color: "gray"
                    border.width: 1

                    Text {
                        text: "Serial Communication"
                        y: 20
                        anchors.horizontalCenter: parent.horizontalCenter

                        Canvas {
                            width: 200
                            height: 200
                            onPaint: {
                                var ctx = getContext("2d")

                                ctx.strokeStyle = "gray"

                                ctx.beginPath()
                                ctx.moveTo(0,30)
                                ctx.lineTo(200,30)

                                ctx.stroke()
                            }
                        }
                    }
                }


            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    serialMainWindow.visible = true
                }

                onEntered: {
                    console.log("onEntered")
                    serialNormalArea.visible = false
                    serialThumbnail.visible = true
                }
                onExited: {
                    console.log("onExited")
                    serialNormalArea.visible = true
                    serialThumbnail.visible = false
                }
            }
        }
    }



}
