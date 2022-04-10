// Если флаг подключения заголовочного файла не установлен
#ifndef F_INGREDIENT_DB_H
// Установить флаг подключения заголовочного файла
#define F_INGREDIENT_DB_H

/*
    Обязательные к подключению модули
*/

// Подключить модуль QWidget
#include <QWidget>
// Подключить Ui формы
#include "ui_F_Ingredient_DB.h"
// Подключить модуль QFile
#include <QFile.h>

/*
    Директивы препроцессору
*/

/*!
    @def     F_INGREDIENT_DB_STYLESHEET_TBOX_OK
    @brief   stylesheet для полей ввода без ошибок
*/
#define F_INGREDIENT_DB_STYLESHEET_TBOX_OK "color:black;\nbackground-color:white;\nfont-size:12pt"

/*!
    @def     F_INGREDIENT_DB_STYLESHEET_TBOX_ERROR
    @brief   stylesheet для полей ввода с ошибкой
*/
#define F_INGREDIENT_DB_STYLESHEET_TBOX_ERROR "color:white;\nbackground-color:red;\nfont-size:12pt"

/*
    Структуры
*/

/*!
    @struct  Ingredient_DB_Struct
    @brief   Структура ингредиента из базы данных
*/
typedef struct Ingredient_DB_Struct
{
    QString Name;     //!< Название ингредиента
    int     Volume;   //!< Объем
    int     Price;    //!< Цена
    int     Alcohol;  //!< Процент алкоголя
}Ingredient_DB_Struct;

// Пространоство имен ui формы
namespace Ui
{
    // Класс формы
    class F_Ingredient_DB;
}

/*!
    @class   F_Ingredient_DB
    @brief   Класс формы создания ингредиент
    @details
*/
class F_Ingredient_DB : public QWidget
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
    explicit F_Ingredient_DB(QWidget *Parent = nullptr);

    /*!
        @fn     ~F_Ingredient_DB()
        @brief   Деструктор класса
    */
    ~F_Ingredient_DB();

    /*!
        @fn      void Set_Data(Ingredient_DB_Struct *Data_Ptr_New, QStringList *Ingredients_List_Ptr_New)
        @brief   Метод установки данных ингредиента
        @details Данный метод выполняет запись новых указателей на данные ингредиента и список ингредиентов,
                 а также вывод данных ингредиента на форму
        @param   Data_Ptr_New             [IN] Новый указатель на данные ингредиента
        @param   Ingredients_List_Ptr_New [IN] Новый указатель на список ингредиентов
        @return  None
    */
    void Set_Data(Ingredient_DB_Struct *Data_Ptr_New, QStringList *Ingredients_List_Ptr_New);

    /*!
        @fn      bool Validate_Data_Current()
        @brief   Метод валидации текущих данных
        @details Данный метод выполняет валидацию текущих данных и подсветку полей с некорректными данными
        @return  Возвращает true в случае, если текущие данные ингредиента корректны. В противном случае, возвращает false
    */
    bool Validate_Data_Current();

    /*!
        @fn      bool Validate_Data()
        @brief   Метод валидации данных ингредиента
        @details Данный метод выполняет валидацию данных ингредиента
        @return  Возвращает true в случае, если данные ингредиента корректны. В противном случае, возвращает false
    */
    bool Validate_Data();

    /*!
        @fn      bool Is_Exist(QString Ingredient_Name)
        @brief   Метод проверки ингредиента на существование в списке ингредиентов
        @details Данный метод выполняет проверку ингредиента на существование в списке ингредиентов
        @param   Ingredient_Name [IN] Название ингредиента
        @return  Возвращает флаг существования ингредиента в списке ингредиентов
    */
    bool Is_Exist(QString Ingredient_Name);

    /*!
        @fn       static QList<Ingredients_DB_Struct> Read_Ingredients_From_File(QString File_Path)
        @brief    Статический метод чтения данных об ингредиентах из файла
        @details  Данный метод выполняет чтение данных об ингредиентах из указанного файла и их валидацию.<br>
                  Данные должны быть в следующем виде: имя ингредиента,объем,цена,процент алкоголя.<br>
                  Разделителем между ингредиентами является \r\n
        @param    File_Path [IN] Полный путь к файлу
        @return   Возвращает массив считанных данных об ингредиентах
    */
    static QList<Ingredient_DB_Struct> Read_Ingredients_From_File(QString File_Path);

/*
    Приватные объявления
*/
private:

    /*!
        @var     Ui::F_Ingredient_DB *Form
        @brief   Ui формы
    */
    Ui::F_Ingredient_DB *Form;

    /*!
        @var     bool Is_Changed
        @brief   Флаг изменения данных об ингредиенте
    */
    bool Is_Changed = false;

    /*!
        @var     Ingredient_DB_Struct Data_Current
        @brief   Текущие данные ингредиента
    */
    Ingredient_DB_Struct Data_Current;

    /*!
        @var     Ingredient_DB_Struct *Data_Ptr
        @brief   Указатель на данные ингредиента
    */
    Ingredient_DB_Struct *Data_Ptr;

    /*!
        @var     QStringList *Ingredients_List_Ptr_Inner
        @brief   Указатель на список ингредиентов
    */
    QStringList *Ingredients_List_Ptr;

    /*!
        @fn      void Update_Data_Current()
        @brief   Метод обновления текущих данных ингредиента
        @details Данный метод выполняет получение данных ингредиента с формы и записывает их в текущие данные ингредиента
        @return  None
    */
    void Update_Data_Current();

    /*!
        @fn      void Change_Is_Changed(bool New_State)
        @brief   Метод изменения флага изменения данных ингредиента
        @details Данный метод выполняет изменения флага изменения данных ингредиента и первод формы в состояние, соответствующее New_State
        @param   New_State [IN] Новое состояние флага изменения данных ингредиента
        @return  None
    */
    void Change_Is_Changed(bool New_State);

/*
    Приватные объявления слотов
*/
private slots:

    /*!
        @fn       void Accept_Button_Clicked()
        @brief    Метод обработки нажатия на кнопку принятия изменений
        @details  Данный метод выполняет обработку нажатия на кнопку принятия изменений
        @return   None
    */
    void Accept_Button_Clicked();

    /*!
        @fn       void Delete_Button_Clicked()
        @brief    Метод обработки нажатия на кнопку удаления ингредиента
        @details  Данный метод выполняет обработку нажатия на кнопку удаления ингредиента
        @return   None
    */
    void Delete_Button_Clicked();

    /*!
        @fn       void TBox_Changed(const QString &New_Text)
        @brief    Метод обработки изменения поля ввода
        @details  Данный метод выполняет обработку изменения поля ввода и установку флага изменения данных об ингредиенте
        @param    New_Text [IN] Новый текст поля ввода
        @return   None
    */
    void TBox_Changed(const QString &New_Text);

/*
    Объявления сигналов
*/
signals:

    /*!
        @fn      void Edited_Signal(QString Ingredient_Name)
        @brief   Сигнал изменения ингредиента в списке ингредиентов
        @details Данный сигнал генерируется, когда данные ингредиента в списке ингредиентов изменяются
        @param   Ingredient_Name [OUT] Название ингредиента
        @return  None
    */
    void Edited_Signal(QString Ingredient_Name);

    /*!
        @fn      void Delete_Signal(QString Ingredient_Name)
        @brief   Сигнал удаления ингредиента
        @details Данный сигнал генерируется, когда необходимо удалить ингредиент
        @param   Ingredient_Name [OUT] Название ингредиента
        @return  None
    */
    void Delete_Signal(QString Ingredient_Name);
};

// Конец блока
#endif
