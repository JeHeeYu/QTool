import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.12
import QtQuick.Extras 1.4

Rectangle {
    width: 115
    height: 50
    color: "#cccccc"

    property bool greenIndicatorActive: false
    property bool yellowIndicatorActive: false
    property bool redIndicatorActive: true

    RowLayout {
        anchors.fill: parent
        StatusIndicator {
            active: greenIndicatorActive
            color: "green"
        }

        StatusIndicator {
            active: yellowIndicatorActive
            color: "yellow"
        }

        StatusIndicator {
            active: redIndicatorActive
            color: "red"
        }
    }

    function indicatorActive(status)
    {
        if(status === true) {
            greenIndicatorActive = true
            redIndicatorActive = false
            yellowIndicatorActive = false
        }
        else {
            greenIndicatorActive = false
            yellowIndicatorActive = false
            redIndicatorActive = true
        }
    }
}

