import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

import "../Common"

ApplicationWindow {
    visible: true
    width: 1280
    height: 840
    color: "#EFEFEF"
    title: qsTr("Serial Main Window")

    property int indicatorX: 1280 - 115
    property bool connectionStatus: serialMain.connectionStatus

    menuBar: MainMenuBar {
        id: mainMenu
    }
    header: MainToolBar {
        id: mainTool

        onSettingButtonClickSignal: {
            customDialog.dialogOpen()
        }
    }

    onConnectionStatusChanged: {
        statusIndicator.indicatorActive(connectionStatus)
    }

    CustomDialog {
        id: customDialog
        dialogOpenStatus: false
    }

    Indicator {
        id: statusIndicator
        visible: true
        x: indicatorX


    }

    SerialView {

    }


}
