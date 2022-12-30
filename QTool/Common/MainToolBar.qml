import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.12


ToolBar {
    id: root


    property int toolButtonWidth: 60
    property int toolButtonHeight: 80

    property int iconMargin: 5
    property int iconBottomMargin: 25
    property int textMargin: 5

    property string newIconSource: "file:///home/workstation/QTool_Save/images/new_icon.png"
    property string newIconText: "New"

    property string settingIconSource: "file:///home/workstation/QTool_Save/images/setting_icon.png"
    property string settingIconText: "Setting"

    property string exitIconSource: "file:///home/workstation/QTool_Save/images/exit_icon.png"
    property string exitIconText: "Exit"

    // ToolBar Button Click Event
    signal newButtonClickSignal()
    signal settingButtonClickSignal()
    signal exitButtonClickSignal()

    Row {
        // New ToolBar Button
        ToolButton {
            id: newButton
            width: toolButtonWidth
            height: toolButtonHeight
            Image {
                source: newIconSource
                fillMode: Image.PreserveAspectFit
                anchors.fill: parent
                width: parent.width
                height: parent.width
                anchors.margins: iconMargin
                anchors.bottomMargin: iconBottomMargin
            }

            Text {
                id: newText
                text: newIconText
                anchors.bottom: parent.bottom
                anchors.margins: textMargin
                anchors.horizontalCenter: parent.horizontalCenter
                renderType: Text.NativeRendering
            }

            onClicked: {
                newButtonClickSignal()
            }
        }

        // Setting ToolBar Button
        ToolButton {
            id: settingButton
            width: toolButtonWidth
            height: toolButtonHeight
            Image {
                source: settingIconSource
                fillMode: Image.PreserveAspectFit
                anchors.fill: parent
                width: parent.width
                height: parent.width
                anchors.margins: iconMargin
                anchors.bottomMargin: iconBottomMargin
            }

            Text {
                id: settingText
                text: settingIconText
                anchors.bottom: parent.bottom
                anchors.margins: textMargin
                anchors.horizontalCenter: parent.horizontalCenter
                renderType: Text.NativeRendering
            }

            onClicked: {
                settingButtonClickSignal()
            }
        }

        // Exit ToolBar Button
        ToolButton {
            id: exitButton
            width: toolButtonWidth
            height: toolButtonHeight
            Image {
                source: exitIconSource
                fillMode: Image.PreserveAspectFit
                anchors.fill: parent
                width: parent.width
                height: parent.width
                anchors.margins: iconMargin
                anchors.bottomMargin: iconBottomMargin
            }

            Text {
                id: exitText
                text: exitIconText
                anchors.bottom: parent.bottom
                anchors.margins: textMargin
                anchors.horizontalCenter: parent.horizontalCenter
                renderType: Text.NativeRendering
            }

            onClicked: {
                exitButtonClickSignal()
            }
        }
    }
}


//Image {
//    source: parent.iconSource
//    fillMode: Image.PreserveAspectFit // For not stretching image (optional)
//    anchors.fill: parent
//    anchors.margins: 2 // Leaving space between image and borders (optional)
//    anchors.bottomMargin:10 // Leaving space for text in bottom
//}
//Text {
//    text: parent.text

//    anchors.bottom: parent.bottom // Placing text in bottom
//    anchors.margins: 2 // Leaving space between text and borders  (optional)
//    anchors.horizontalCenter: parent.horizontalCenter // Centering text
//    renderType: Text.NativeRendering // Rendering type (optional)
//}


//Rectangle {
//        id: toolbar
//        color: "green"
//        anchors.left: parent.left
//        anchors.right: parent.right
//        anchors.bottom: parent.bottom
//        height: 50

//        Row
//        {
//            anchors.fill: parent
//            anchors.horizontalCenter: parent.horizontalCenter
//            spacing: 60

//            ToolButton {
//                height: parent.height
//                Image {
//                    anchors.verticalCenter: parent.verticalCenter
//                    source: "file:///home/workstation/QTool_Save/images/exit_icon.png"
//                    anchors.fill: parent
//                }
//            }

//            ToolButton {
//                height: parent.height
//                Image {
//                    anchors.verticalCenter: parent.verticalCenter
//                    source: "../images/image.png"
//                }
//            }
//        }
// }
