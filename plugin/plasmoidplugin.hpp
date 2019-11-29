//
// Created by roscale on 11/28/19.
//

#ifndef SMARTHOME_PLASMOID_PLASMOIDPLUGIN_HPP
#define SMARTHOME_PLASMOID_PLASMOIDPLUGIN_HPP

#include <QQmlExtensionPlugin>

class QQmlEngine;
class PlasmoidPlugin : public QQmlExtensionPlugin
{
   Q_OBJECT
   Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
   void registerTypes(const char *uri) override;
};

#endif //SMARTHOME_PLASMOID_PLASMOIDPLUGIN_HPP
