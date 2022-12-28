import QtQuick 2.0
import QtQuick.Controls 2.5

MenuBar{
    property var fileDialog: null
    Menu{
        id: file
        title: qsTr("File")

        Action {
            text: qsTr("&New...")
        }
        Action {
            text: qsTr("&Open...")
            shortcut: "Ctrl+N"
            onTriggered: { fileDialog.open() }
        }
        Action {
            text: qsTr("&Save")
        }
        Action {
            text: qsTr("Save &As...")
        }
        MenuSeparator { }
        Action {
            text: qsTr("E&xit...")
            onTriggered: Qt.quit()
        }
    }

    Menu{
        id: edit
        title: qsTr("Edit")
        Action {
            text: qsTr("&Copy...")
        }
        Action {
            text: qsTr("&Paste...")
        }
        Action {
            text: qsTr("&Delete...")
        }
    }

    Menu{
        id: help
        title: qsTr("Help")
        Action {
            text: qsTr("&About...")
        }
    }
}
