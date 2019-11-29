//
// Created by roscale on 11/28/19.
//

#include "plasmoidplugin.hpp"

#include <QtQml>
#include <QDebug>
#include <iostream>

class Bar : public QObject {
Q_OBJECT
   Q_PROPERTY(QString baz
		            READ
		            baz
		            WRITE
		            setBaz
		            NOTIFY
		            bazChanged)

public:
   Bar() = default;

   QString baz() const { return mBaz; }

   void setBaz(const QString &baz) {
	   if (baz == mBaz)
		   return;

	   mBaz = baz;
	   emit bazChanged();
   }

   Q_INVOKABLE void hello() {
        std::clog << "Hello world!\n";
   }

   Q_INVOKABLE void say(QString str) {
   	    std::clog << str.toStdString();
   }

   Q_INVOKABLE void turn(bool on) {
	   QTcpSocket socket;
	   socket.connectToHost(QHostAddress("192.168.0.57"), 8088, QIODevice::WriteOnly);
	   if (socket.waitForConnected()) {
	   	    std::clog << "Connected !\n";
	   }

	   socket.write(on ? "on" : "off");
	   socket.flush();
	   socket.close();
   }

signals:
   void bazChanged();

private:
   QString mBaz;
};

void PlasmoidPlugin::registerTypes(const char *uri) {
	Q_ASSERT(uri == QLatin1String("org.kde.private.smarthome"));
	qmlRegisterType<Bar>(uri, 1, 0, "Bar");
}

#include "plasmoidplugin.moc"
