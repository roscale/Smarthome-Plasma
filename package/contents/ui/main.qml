import QtQuick 2.13
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.private.smarthome 1.0

Item {
    id: main
    PlasmaCore.IconItem {
            source: "images/lightbulb_off.png"
    		width: parent.width
            height: parent.width
    }

    Plasmoid.compactRepresentation: CompactRepresentation {}
    Plasmoid.fullRepresentation: FullRepresentation {}
    Plasmoid.preferredRepresentation: Plasmoid.fullRepresentation

    property bool state: true

    function turn(state) {
        main.state = state;
        console.log("Turned " + state);
    }

    Networking {
        id: networking
    }
} // end Item
