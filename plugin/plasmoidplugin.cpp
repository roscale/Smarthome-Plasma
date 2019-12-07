//
// Created by roscale on 11/28/19.
//

#include "plasmoidplugin.hpp"

#include <QtQml>
#include <QtConcurrent>
#include <QDebug>
#include <iostream>

enum class DeviceState {
   ON,
   OFF
};

class Networking : public QObject {
Q_OBJECT

private:
    QTcpSocket socket;
	QString wantedState = "on";

public:
   Networking() : QObject() {
	   connect(&socket, &QAbstractSocket::stateChanged, this, &Networking::socketStateChanged);
   };

   void socketStateChanged(QAbstractSocket::SocketState state) {
   	if (state == QAbstractSocket::SocketState::ConnectedState) {
	    std::clog << "Connected ! yay\n";

	    socket.write(wantedState == "on" ? "on" : "off");
	    socket.flush();
	    socket.close();
    }
   }

   Q_INVOKABLE
   void changeState(QString state) {
		socket.abort();
        std::clog << "Connecting\n";

        wantedState = state;
        socket.connectToHost(QHostAddress("192.168.0.57"), 8088, QIODevice::WriteOnly);
   }
};

void PlasmoidPlugin::registerTypes(const char *uri) {
	Q_ASSERT(uri == QLatin1String("org.kde.private.smarthome"));
	qmlRegisterType<Networking>(uri, 1, 0, "Networking");
}

#include "plasmoidplugin.moc"
