import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

import "../Common"

ApplicationWindow {
    visible: true
    width: 1280
    height: 840
    title: qsTr("Serial Main Window")

    property int indicatorX: 1280 - 115

    menuBar: MainMenuBar {
        id: mainMenu
    }
    header: MainToolBar { id: mainTool }
    Indicator {
        id: statusIndicator
        visible: true
        x: indicatorX
    }

}
