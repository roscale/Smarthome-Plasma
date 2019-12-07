import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.1
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.core 2.0 as PlasmaCore

Item {
    Button {
        id: compactRepresentation
        anchors.fill: parent
        flat: true

        onClicked: main.turn(!main.state)
    }
}
