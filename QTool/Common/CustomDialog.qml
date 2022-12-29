import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.12
import QtQuick.Extras 1.4

Item {
    property var portNumberArray: serialMain.serialPortInfo
    property var baudrateArray: [1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200]
    property var dataBitsArray: [5, 6, 7, 8, 9]
    property var stopBitsArray: [0, 1]
    property var parityBitsArray: ["None", "Odd", "Even"]

    property var tempArray: []

    property string portNumberText: "Port Number"
    property string baudrateText: "Baudrate"
    property string dataBitsText: "Data Bits"
    property string stopBitsText: "Stop Bits"
    property string parityBitsText: "Parity Bits"

    property int textLeftMargin: 10
    property int colSpacing: 10
    property int rowSpacing: 30
    property int comboBoxWidth: 200

    Dialog {
        id: settingDialog
        visible: true
        width: 320
        height: 330

        standardButtons: StandardButton.Ok | StandardButton.Cancel

        onButtonClicked: {
            if (clickedButton === StandardButton.Ok) {
                console.log("Accepted " + baudrateComboBoxId.currentIndex)

                connetButtonClick(baudrateComboBoxId.currentIndex, dataBitsComboBoxId.currentIndex, stopBitsComboBoxId.currentIndex, parityBitsComboBoxId.currentIndex)
            }
            else {
                console.log("Rejected" + clickedButton)
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
        }
    }

    function connetButtonClick(info1, info2, info3, info4)
    {
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

