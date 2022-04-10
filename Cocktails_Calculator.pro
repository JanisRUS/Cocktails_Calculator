QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Записать файлы с исходным кодом
SOURCES += \
    Source/F_Cocktail.cpp \
    Source/F_Ingredient.cpp \
    Source/F_Ingredient_DB.cpp \
    Source/F_Main.cpp \
    Source/main.cpp

# Записать заголовочные файлы
HEADERS += \
    Include/F_Cocktail.h \
    Include/F_Ingredient.h \
    Include/F_Ingredient_DB.h \
    Include/F_Main.h

# Записать файлы форм
FORMS += \
    Forms/F_Cocktail.ui \
    Forms/F_Ingredient.ui \
    Forms/F_Ingredient_DB.ui \
    Forms/F_Main.ui

# Записать пути подключаемых файлов
INCLUDEPATH += \
    Include\

# Записать файлы ресурсов
RESOURCES += \
    Recources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


