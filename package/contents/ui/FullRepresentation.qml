import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.1
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.plasma.extras 2.0 as PlasmaExtras
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.core 2.0 as PlasmaCore

Item {
    id: fullRepresentation

    Button {
        anchors.fill: parent
        flat: true
//        iconSource: Qt.resolvedUrl("images/lightbulb_on.png")

        Control {
            padding: 5
            anchors.centerIn: parent
            anchors.fill: parent

            contentItem: Image {
                id: bulb
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit

                source: "images/lightbulb_on.png"
                asynchronous: true
            }
        }

        onClicked: main.turn(!main.state)
    }

    Connections {
        target: main
        onStateChanged: {
            console.log(main.state);
            if (main.state) {
                bulb.source = "images/lightbulb_on.png";
                networking.changeState("on");
            } else {
                bulb.source = "images/lightbulb_off.png";
                networking.changeState("off");
            }
        }
    }
}
