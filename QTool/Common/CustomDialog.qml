import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.12
import QtQuick.Extras 1.4

Item {
    Dialog {
        id: settingDialog
        visible: true
        width: 320
        height: 400

        standardButtons: StandardButton.Ok | StandardButton.Cancel

        onButtonClicked: {
            if (clickedButton === StandardButton.Ok) {
                console.log("Accepted " + clickedButton)
            }
            else {
                console.log("Rejected" + clickedButton)
            }
        }

        ColumnLayout {

            Row {
                Text {
                    text:qsTr("Jehee1")
                }

                ComboBox {
                    width: 200
                    model: [ "Banana", "Apple", "Coconut" ]
                }
            }

            Row {
                Text {
                    text:qsTr("Jehee1")
                }

                ComboBox {
                    editable: false
                    model: ListModel {
                        id: model
                        ListElement { text: "Banana"; color: "Yellow" }
                        ListElement { text: "Apple"; color: "Green" }
                        ListElement { text: "Coconut"; color: "Brown" }
                    }

                    onAccepted: {
                        if (find(currentText) === -1) {
                            model.append({text: editText})
                            currentIndex = find(editText)
                        }
                    }
                }
            }
        }
    }

    ListModel {

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
}
