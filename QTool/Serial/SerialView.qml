import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.12

Item {
    width: 1280
    height: 840

    property string sendMessageEditHint: "Send message here"
    property string receiveData: serialMain.readData


    onReceiveDataChanged: {
        receiveListModel.append(({message: receiveData}))
    }

    // Send message Area
    ColumnLayout {
        id: sendMessage
        x: 20
        y: 20
        width: 300
        height: 89
        spacing: 5

        Text {
            text: qsTr("Message")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            width: parent.width
            height: 40
            border.width: 1
            border.color: "#ACACAC"
            Layout.fillWidth: true
            color: "#ffffff"
            radius: 5

            TextEdit {
                id: sendTextEdit
                width: parent.width
                height: parent.height
                focus: true
                textMargin: 10

                Text {
                    x: 10
                    y: 10
                    width: parent.width
                    height: parent.height
                    text: sendMessageEditHint
                    color: "#ACACAC"
                    visible: !sendTextEdit.text
                }
            }
        }

        Button {
            id: button
            text: qsTr("Send Message")
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 30
            enabled: sendTextEdit.text

            onClicked: {
                sendListModel.append({message: sendTextEdit.text})
                sendTextEdit.text = ""
            }
        }
    }

    // Send Message List View Area
    Column {
        id: sendMessageHistory
        x: 20
        y: 135
        width: 300
        height: 485
        spacing: 10

        Text {
            id: element1
            text: qsTr("Sent Message")
            anchors.bottomMargin: 30
        }

        Rectangle {
            width: parent.width
            height: 400
            color: "#ffffff"
            border.color: "#ACACAC"
            radius: 5

            ListView {
                id: sendListView
                anchors.fill: parent
                focus: true
                model: sendListModel//선언된 데이터들을 리스트뷰에 넣는다.
                delegate: sendDelegate//delegate란 리스트 한개의 틀(틀을 하나 만들어서 그것들을 여러개 붙여놓은것이 리스트 뷰이다.)
                highlight: Rectangle {
                    width: delegateItem.width
                    height: delegateItem.height
                    color: "lightsteelblue"
                    radius: 5
                }
            }
        }

        Button {
            text: qsTr("Message Clear")
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 30
            enabled: sendListModel.count

            onClicked: {
                sendMessageClear()
            }
        }

        ListModel {
            id: sendListModel
        }

        Component {
           id: sendDelegate
           Item {
               id: delegateItem
               width: 100; height: 20
               Column {
                   Text { text:  message }
               }
           }
        }
    }

    Column {
        id: receiveMessage
        x: sendMessage.width + 70
        y: sendMessage.y
        width: 400
        height: 580
        spacing: 10

        Text {
            text: qsTr("Receive Message")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            width: parent.width
            height: parent.height - 65
            color: "#FFFFFF"
            border.color: "#ACACAC"
            radius: 5

            ListView {
                id: receiveListView
                width: parent.width
                height: 300
                model: receiveListModel
                delegate: receiveDelegate
                highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                focus: true
                ScrollBar.vertical: ScrollBar{
                    width:15
                    policy:ScrollBar.AlwaysOn
                }
            }
        }

        Button {
            text: qsTr("Message Clear")
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 30
            enabled: receiveListModel.count

            onClicked: {
                receiveListModel.clear()
            }
        }

        ListModel {//리스트뷰에 담은 데이터들을 선언한다.
            id: receiveListModel
        }

        Component {
           id: receiveDelegate
           Item {
               id: delegateItem
               width: 100; height: 20
               Column {
                   Text { text:  message }
               }
           }
        }
    }

    function sendMessageClear()
    {
        sendListModel.clear()
    }
}

