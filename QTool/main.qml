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

    //property var jehee: serialPortInfo

    Component.onCompleted: {
        console.log("jehee : ", serialMain.serialPortInfo);
        //console.log("zz")
    }

    menuBar: MainMenuBar { id: mainMenu }
    header: MainToolBar { id: mainTool }

    SerialMainWindow {
        id: serialMainWindow
        visible: true
    }

    Button {
        width: 100
        height: 100
        onClicked: {
            //serialMain.visible = true
            serialMain.jeheetest(1)
            console.log("jehee : ", serialMain.serialPortInfo);
        }
    }

}
