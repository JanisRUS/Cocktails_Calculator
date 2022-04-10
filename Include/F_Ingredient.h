// Если флаг подключения заголовочного файла не установлен
#ifndef F_INGREDIENT_H
// Установить флаг подключения заголовочного файла
#define F_INGREDIENT_H

/*
    Обязательные к подключению модули
*/

// Подключить модуль QWidget
#include <QWidget>
// Подключить Ui формы
#include "ui_F_Ingredient.h"
// Подключить модуль QFile
#include <QFile>
// Подключить модуль F_Ingredient_DB
#include "F_Ingredient_DB.h"

/*
    Структуры
*/

/*!
    @struct  Ingredient_Data_Struct
    @brief   Структура данных об ингредиенте
*/
typedef struct Ingredient_Data_Struct
{
    QString Name;   //!< Название ингредиента
    int     Volume; //!< Объем ингредиента
}Ingredient_Data_Struct;

// Пространоство имен ui формы
namespace Ui
{
    // Класс формы
    class F_Ingredient;
}

/*!
    @class   F_Ingredient
    @brief   Класс формы выбора ингредиент
    @details
*/
class F_Ingredient : public QWidget
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
        @fn      F_Ingredient(QWidget *Parent)
        @brief   Базовый конструктор класса
    */
    explicit F_Ingredient(QWidget *Parent = nullptr);

    /*!
        @fn     ~F_Ingredient()
        @brief   Деструктор класса
    */
    ~F_Ingredient();

    /*!
        @fn      void Set_Data(Ingredient_Data_Struct *Data_Ptr_New, QStringList *Ingredients_List_Ptr_New, QStringList *Cocktail_Ingredients_List_Ptr_New)
        @brief   Метод установки данных ингредиента
        @details Данный метод выполняет запись новых указателей на данные ингредиента и список ингредиентов,
                 а также вывод данных ингредиента на форму
        @param   Data_Ptr_New                      [IN] Новый указатель на данные ингредиента
        @param   Ingredients_List_Ptr_New          [IN] Новый указатель на список ингредиентов
        @param   Cocktail_Ingredients_List_Ptr_New [IN] Новый указатель на ингредиенты коктейля
        @return  None
    */
    void Set_Data(Ingredient_Data_Struct *Data_Ptr_New, QStringList *Ingredients_List_Ptr_New, QStringList *Cocktail_Ingredients_List_Ptr_New);

    /*!
        @fn      bool Validate_Data()
        @brief   Метод валидации данных ингредиента
        @details Данный метод выполняет валидацию данных ингредиента
        @return  Возвращает true в случае, если данные ингредиента корректны. В противном случае, возвращает false
    */
    bool Validate_Data();

    /*!
        @fn      void Set_Name(QString New_Name)
        @brief   Метод установки нового названия ингредиента
        @details Данный метод выполняет установку нового названия ингредиента и выводит его на форму
        @param   New_Name [IN] Новое название ингредиента
        @return  None
    */
    void Set_Name(QString New_Name);

    /*!
        @fn      bool Validate_Data_Current()
        @brief   Метод валидации текущих данных
        @details Данный метод выполняет валидацию текущих данных и подсветку полей с некорректными данными
        @return  Возвращает true в случае, если текущие данные ингредиента корректны. В противном случае, возвращает false
    */
    bool Validate_Data_Current();

    /*!
        @fn      void Accept_Changes()
        @brief   Метод принятия изменений
        @details Данный метод выполняет запись текущих данных ингредиента в данные ингредиента
        @return  None
    */
    void Accept_Changes();

/*
    Приватные объявления
*/
private:

    /*!
        @var     Ui::F_Ingredient *Form
        @brief   Ui формы
    */
    Ui::F_Ingredient *Form;

    /*!
        @var     bool Is_Changed
        @brief   Флаг изменения данных об ингредиенте
    */
    bool Is_Changed = false;

    /*!
        @var     Ingredient_Data_Struct Data_Current
        @brief   Текущие данные ингредиента
    */
    Ingredient_Data_Struct Data_Current;

    /*!
        @var     Ingredient_Data_Struct *Data_Ptr
        @brief   Указатель на данные ингредиента
    */
    Ingredient_Data_Struct *Data_Ptr;

    /*!
        @var     QStringList *Ingredients_List_Ptr_Inner
        @brief   Указатель на список ингредиентов
    */
    QStringList *Ingredients_List_Ptr;

    /*!
        @var     QStringList *Cocktail_Ingredients_List_Ptr
        @brief   Указатель на список ингредиентов коктейля
    */
    QStringList *Cocktail_Ingredients_List_Ptr;

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
        @fn      void Delete_Button_Clicked()
        @brief   Метод обработки нажатия на кнопку удаления ингредиента
        @details Данный метод выполняет обработку нажатия на кнопку удаления ингредиента
        @return  None
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

    /*!
        @fn      void Ingredient_Data_Edit_Finished()
        @brief   Метод обработки завершения редактирования данных об ингредиенте
        @details Данный метод выполняет обработку завершения редактирования данных об ингредиенте
        @return  None
    */
    void Ingredient_Data_Edit_Finished();

/*
    Объявления сигналов
*/
signals:

    /*!
        @fn      void Edited_Signal()
        @brief   Сигнал изменения ингредиента
        @details Данный сигнал генерируется, когда данные об ингредиенте изменяются
        @return  None
    */
    void Edited_Signal();

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
