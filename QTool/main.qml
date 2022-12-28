import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

import "./Common"
import "./Serial"

ApplicationWindow {
    id:root
    visible: true
    width: 1280
    height: 840
    title: qsTr("Hello World")

    //menuBar: MainMenuBar { id: mainMenu }
    //header: MainToolBar { id: mainTool }

    SerialMain {
        id: serialMain
        visible: false
    }

//    Button {
//        width: 100
//        height: 100
//        onClicked: {
//            serialMain.visible = true
//        }
//    }

    CustomDialog {

    }
}
