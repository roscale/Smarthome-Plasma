cmake_minimum_required(VERSION 3.14)

find_package(ECM REQUIRED NO_MODULE)
# Needed by find_package(KF5Plasma) below.
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

# Locate plasma_install_package macro.
find_package(Qt5 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Quick)
find_package(Qt5 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Concurrent)
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS Plasma)
add_subdirectory(plugin)

plasma_install_package(package org.kde.smarthome)
