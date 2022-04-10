// Подключить модуль F_Main
#include "F_Main.h"
// Подключить модуль QApplication
#include <QApplication>

// Точка входа в программу
int main(int argc, char *argv[])
{
    // Создать приложение
    QApplication Application(argc, argv);
    // Создать форму
    F_Main Form;
    // Показать форму
    Form.show();
    // Вернуть результат работы приложения
    return Application.exec();
}
