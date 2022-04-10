// Если флаг подключения заголовочного файла не установлен
#ifndef F_MAIN_H
// Установить флаг подключения заголовочного файла
#define F_MAIN_H

/*
    Обязательные к подключению модули
*/

// Подключить модуль QMainWindow
#include <QMainWindow>
// Подключить Ui формы
#include "ui_F_Main.h"
// Подключить модуль QFile
#include <QFile>
// Подключить модуль F_Ingredient_DB
#include "F_Ingredient_DB.h"
// Подключить модуль F_Ingredient
#include "F_Ingredient.h"
// Подключить модуль F_Cocktail
#include "F_Cocktail.h"
// Подключить модуль QDir
#include <QDir>

// Пространоство имен ui формы
namespace Ui
{
    // Класс формы
    class F_Main;
}

/*
    Структуры
*/

/*!
    @struct  Ingredients_Data_Struct
    @brief   Структура данных об ингредиентах
*/
typedef struct Ingredients_Data_Struct
{
    QList<Ingredient_DB_Struct> Data;   //!< Данные об ингредиентах
    QList<F_Ingredient_DB *>    Forms;  //!< Указатели на формы ингредиентов
    QVBoxLayout                *Layout; //!< Указатель на Layout, где располагаются формы игредиентов
}Ingredients_Data_Struct;

/*!
    @struct  Ingredients_Data
    @brief   Структура данных о коктейлях
*/
typedef struct Cocktails_Data_Struct
{
    QList<Cocktail_Data_Struct> Data;  //!< Данные о коктейлях
    QList<F_Cocktail *>         Forms; //!< Указатели на формы коктейлей
    QVBoxLayout                *Layout; //!< Указатель на Layout, где располагаются формы игредиентов
}Cocktails_Data_Struct;

/*!
    @class   F_Main
    @brief   Класс главной формы
    @details
*/
class F_Main : public QMainWindow
{

/*
    Подключить механизм слотов и сигналов
*/
Q_OBJECT

/*
    Публичные объявления
*/
public:

    /*!
        @fn      F_Main(QWidget *Parent)
        @brief   Базовый конструктор класса
    */
    F_Main(QWidget *Parent = nullptr);

    /*!
        @fn     ~F_Main()
        @brief   Деструктор класса
    */
    ~F_Main();

    /*!
        @var     QFile *File_Cocktails
        @brief   Файл со списком коктейлей
    */
    QFile *File_Cocktails;

    /*!
        @var     Ingredients_Data_Struct Ingredients_Data
        @brief   Данные об ингридиентах
    */
    Ingredients_Data_Struct Ingredients_Data =
    {
        QList<Ingredient_DB_Struct>(),
        QList<F_Ingredient_DB *>(),
        0
    };

    /*!
        @var     Cocktails_Data_Struct Cocktails_Data
        @brief   Данные о коктейлях
    */
    Cocktails_Data_Struct Cocktails_Data =
    {
        QList<Cocktail_Data_Struct>(),
        QList<F_Cocktail *>(),
        0
    };

    /*!
        @var     QStringList Ingredients_List_Inner
        @brief   Внутренний список ингредиентов
    */
    QStringList Ingredients_List_Inner;

/*
    Приватные объявления
*/
private:

    /*!
        @var     Ui::F_Main *Form
        @brief   Ui формы
    */
    Ui::F_Main *Form;

    /*!
        @fn      void Ingredients_DB_Show()
        @brief   Метод вывода данных об ингредиентах из файла на форму
        @details Данный метод выполняет чтение данных об ингредиентах из файла и вывод их на форму
        @return  None
    */
    void Ingredients_DB_Show();

    /*!
        @fn      void Cocktails_DB_Show()
        @brief   Метод вывода данных о коктейлях из файла на форму
        @details Данный метод выполняет чтение данных о коктейлях из файла и вывод их на форму
        @return  None
    */
    void Cocktails_DB_Show();

    /*!
        @fn      int Get_Ingredient_Number(QString Ingredient_Name)
        @brief   Метод поиска номера ингредиента
        @details Данный метод выполняет поиск номера ингредиента
        @param   Ingredient_Name [IN] Название ингредиента
        @return  Возвращает номер ингредиента в случае успешного выполнения операции. В противном случае, возвращает -1
    */
    int Get_Ingredient_Number(QString Ingredient_Name);

    /*!
        @fn      void Update_Cocktails_Data()
        @brief   Метод обновления данных о коктейлях
        @details Данный метод выполняет перерасчет стоимости коктейлей, их объема и крепости и вывод результата на форму
        @return  None
    */
    void Update_Cocktails_Data();

    /*!
        @fn      bool Is_Exist(QString Ingredient_Name)
        @brief   Метод проверки ингредиента на существование в списке ингредиентов
        @details Данный метод выполняет проверку ингредиента на существование в списке ингредиентов
        @param   Ingredient_Name [IN] Название ингредиента
        @return  Возвращает флаг существования ингредиента в списке ингредиентов
    */
    bool Is_Exist(QString Ingredient_Name);

    /*!
        @fn      void Write_Cocktails_To_File()
        @brief   Метод записи данных о коктейлях в файл
        @details Данный метод выполняет запись данных о коктейлях в файл
        @return  None
    */
    void Write_Cocktails_To_File();

    /*!
        @fn      void Write_Ingredients_To_File()
        @brief   Метод записи данных об ингредиентах в файл
        @details Данный метод выполняет запись данных об ингредиентах в файл
        @return  None
    */
    void Write_Ingredients_To_File();

/*
    Приватные объявления слотов
*/
private slots:

    /*!
        @fn      void Add_Cocktail_Button_Clicked()
        @brief   Метод обработки нажатия на кнопку добавления коктейля
        @details Данный метод выполняет обработку нажатия на кнопку добавления коктейля и перезапись коклейтей в файл
        @return  None
    */
    void Add_Cocktail_Button_Clicked();

    /*!
        @fn      void Add_Ingredient_Button_Clicked()
        @brief   Метод обработки нажатия на кнопку добавления ингредиента
        @details Данный метод выполняет обработку нажатия на кнопку добавления ингредиента и перезапись ингредиентов в файл
        @return  None
    */
    void Add_Ingredient_Button_Clicked();

    /*!
        @fn      void Cocktail_Edited(QString Cocktail_Name)
        @brief   Метод обработки изменения данных о коктейле
        @details Данный метод выполняет обработку изменения данных о коктейле и перезапись данных о коктейлях в файл
        @param   Cocktail_Name [OUT] Название коктейля
        @return  None
    */
    void Cocktail_Edited(QString Cocktail_Name);

    /*!
        @fn      void Ingredient_Edited(QString Ingredient_Name)
        @brief   Метод обработки изменения данных об ингредиенте
        @details Данный метод выполняет обработку изменения данных об ингредиенте и перезапись данных об ингредиентах в файл
        @param   Ingredient_Name [OUT] Название ингредиента
        @return  None
    */
    void Ingredient_Edited(QString Ingredient_Name);

    /*!
        @fn      void Cocktail_Deteled(QString Cocktail_Name)
        @brief   Метод обработки удаления коктейля
        @details Данный метод выполняет обработку удаления коктейля
        @return  None
    */
    void Cocktail_Deteled(QString Cocktail_Name);

    /*!
        @fn      void Ingredient_Deteled(QString Ingredient_Name)
        @brief   Метод обработки удаления ингредиента
        @details Данный метод выполняет обработку удаления ингредиента
        @return  None
    */
    void Ingredient_Deteled(QString Ingredient_Name);
};

// Конец блока
#endif
