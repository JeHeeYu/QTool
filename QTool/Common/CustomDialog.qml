import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.12
import QtQuick.Extras 1.4

Item {

    property bool dialogOpenStatus: false

    property var portNumberArray: serialMain.serialPortInfo
    property var baudrateArray: [9600, 1200, 2400, 4800, 19200, 38400, 57600, 115200]
    property var dataBitsArray: [8, 5, 6, 7]
    property var stopBitsArray: [1, 2, 3]
    property var parityBitsArray: ["NoParity", "EvenParity", "OddParity", "SpaceParity", "MarkParity"]
    property var flowControlBitsArray: ["NoFlowControl", "HardwareControl", "SoftwareControl"]

    property var serialPortInfo: []

    property string portNumberText: "Port Number"
    property string baudrateText: "Baudrate"
    property string dataBitsText: "Data Bits"
    property string stopBitsText: "Stop Bits"
    property string parityBitsText: "Parity Bits"
    property string flowControlBitsText: "Parity Bits"

    property int textLeftMargin: 10
    property int colSpacing: 10
    property int rowSpacing: 30
    property int comboBoxWidth: 300

    Dialog {
        id: settingDialog
        visible: dialogOpenStatus
        width: 470
        height: 370

        standardButtons: StandardButton.Ok | StandardButton.Cancel

        onButtonClicked: {
            if (clickedButton === StandardButton.Ok) {
                serialPortInfo[0] = portNumberComboBoxId.currentText
                serialPortInfo[1] = baudrateComboBoxId.currentIndex
                serialPortInfo[2] = dataBitsComboBoxId.currentIndex
                serialPortInfo[3] = stopBitsComboBoxId.currentIndex
                serialPortInfo[4] = parityBitsComboBoxId.currentIndex
                serialPortInfo[5] = flowControlBitsComboBoxId.currentIndex

                serialMain.connectionSerial(serialPortInfo)
            }
            else {
                Qt.quit()
            }
        }

        ColumnLayout {
            width: parent.width
            spacing: colSpacing

            // Port Number Row Laoyut
            RowLayout {
                spacing: rowSpacing
                Text {
                    text: portNumberText
                    Layout.leftMargin: textLeftMargin
                }

                ComboBox {
                    id: portNumberComboBoxId
                    width: comboBoxWidth
                    Layout.rightMargin: 10
                    model: portNumberArray
                }
            }

            // Baudrate Row Layout
            RowLayout {
                spacing: rowSpacing + 25
                Text {
                    text: baudrateText
                    Layout.leftMargin: textLeftMargin
                }

                ComboBox {
                    id: baudrateComboBoxId
                    width: comboBoxWidth
                    model: baudrateArray
                    Layout.alignment: Qt.AlignRight
                }
            }

            // Data Bits Row Layout
            RowLayout {
                spacing: rowSpacing + 25
                Text {
                    text: dataBitsText
                    Layout.leftMargin: textLeftMargin
                }

                ComboBox {
                    id: dataBitsComboBoxId
                    width: comboBoxWidth
                    model: dataBitsArray
                }
            }

            // Stop Bits Row Layout
            RowLayout {
                spacing: rowSpacing + 25
                Text {
                    text: stopBitsText
                    Layout.leftMargin: textLeftMargin
                }

                ComboBox {
                    id: stopBitsComboBoxId
                    width: comboBoxWidth
                    model: stopBitsArray
                }
            }

            // Parity Bits Row Layout
            RowLayout {
                spacing: rowSpacing + 20
                Text {
                    text: parityBitsText
                    Layout.leftMargin: textLeftMargin
                }

                ComboBox {
                    id: parityBitsComboBoxId
                    width: comboBoxWidth
                    model: parityBitsArray
                }
            }

            // Flow Control Bits Row Layout
            RowLayout {
                spacing: rowSpacing + 20
                Text {
                    text: flowControlBitsText
                    Layout.leftMargin: textLeftMargin
                }

                ComboBox {
                    id: flowControlBitsComboBoxId
                    width: comboBoxWidth
                    model: flowControlBitsArray
                }
            }
        }
    }

    function dialogOpen()
    {
        settingDialog.open()
    }
}

//    Dialog {
//        id: customDialog
//        title: "Custom Dialog in QML/Qt 5.3"
//        standardButtons: StandardButton.Ok | StandardButton.Cancel

//        Column {
//            anchors.fill: parent
//            Text {
//                text: "Here goes all your custom elements..."
//            }
//            TextInput {
//                id: edtInput
//                text: "Input text"
//            }
//        }

//        onButtonClicked: {
//            if (clickedButton === StandardButton.Ok) {
//                console.log("Accepted " + clickedButton)
//                lblResults.text += edtInput.text
//            } else {
//                console.log("Rejected" + clickedButton)
//            }
//        }
//    }
//    Column {
//        anchors.fill: parent

//        Button {
//            text: qsTr("Call Custom dialog")
//            onClicked: customDialog.open()
//        }

//        Text {
//            id: lblResults
//            text: qsTr("Results: ")
//        }
//    }

