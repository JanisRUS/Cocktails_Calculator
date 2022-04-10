// Если флаг подключения заголовочного файла не установлен
#ifndef F_COCKTAIL_H
// Установить флаг подключения заголовочного файла
#define F_COCKTAIL_H

/*
    Обязательные к подключению модули
*/

// Подключить модуль QWidget
#include <QWidget>
// Подключить Ui формы
#include "ui_F_Cocktail.h"
// Подключить модуль QFile
#include <QFile>
// Подключить модуль F_Ingredient
#include "F_Ingredient.h"
// Подключить модуль QMessageBox
#include <QMessageBox>

/*
    Структуры
*/

/*!
    @struct  Cocktail_Data_Struct
    @brief   Структура данных о коктейле
*/
typedef struct Cocktail_Data_Struct
{
    QString                       Name;              //!< Название коктейля
    int                           Ingredients_Count; //!< Количество ингредиентов
    QList<Ingredient_Data_Struct> Ingredients_Data;  //!< Данные об ингредиентах
    QList<F_Ingredient *>         Forms;             //!< Указатели на формы ингредиентов
}Cocktail_Data_Struct;

// Пространоство имен ui формы
namespace Ui
{
    // Класс формы
    class F_Cocktail;
}

/*!
    @class   F_Cocktail
    @brief   Класс формы создания коктейлей
    @details
*/
class F_Cocktail : public QWidget
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
        @fn      F_Cocktail(QWidget *Parent)
        @brief   Базовый конструктор класса
    */
    explicit F_Cocktail(QWidget *Parent = nullptr);

    /*!
        @fn     ~F_Cocktail()
        @brief   Деструктор класса
    */
    ~F_Cocktail();

    /*!
        @fn      void Set_Data(Cocktail_Data_Struct *Data_Ptr_New, QStringList *Ingredients_List_Ptr_New)
        @brief   Метод установки данных коктейля
        @details Данный метод выполняет запись новых указателей на данные коктейля и список ингредиентов,
                 а также вывод данных коктейля на форму
        @param   Data_Ptr_New             [IN] Новый указатель на данные коктейля
        @param   Ingredients_List_Ptr_New [IN] Новый указатель на список ингредиентов
        @return  None
    */
    void Set_Data(Cocktail_Data_Struct *Data_Ptr_New, QStringList *Ingredients_List_Ptr_New);

    /*!
        @fn      void Show_Calculated_Data(int Price, int Volume, int Alcohol)
        @brief   Метод вывода рассчитанных данных коктейля
        @details Данный метод выполняет вывод данных о стоимости, объеме и проценте алкоголя коктейля
        @param   Price   [IN] Цена коктейля
        @param   Volume  [IN] Объем коктейля
        @param   Alcohol [IN] Процент алкоголя в коктейле
    */
    void Show_Calculated_Data(int Price, int Volume, int Alcohol);

    /*!
        @fn      bool Check_Data()
        @brief   Метод проверки данных о коктейле
        @details Данный метод выполняет проверку данных о коктейле
        @return  Возвращает true в случае, если данные о коктейле корректны. В противном случае, возвращает false
    */
    bool Check_Data();

    /*!
        @fn      bool Validate_Data_Current()
        @brief   Метод валидации текущих данных коктейля
        @details Данный метод выполняет валидацию текущих данных коктейля и подсветку полей с некорректными данными
        @return  Возвращает true в случае, если текущие данные коктейля корректны. В противном случае, возвращает false
    */
    bool Validate_Data_Current();

    /*!
        @fn       static QList<Cocktail_Info_Struct> Read_Cocktails_From_File(QString File_Path)
        @brief    Статический метод чтения данных о коктейлях из файла
        @details  Данный метод выполняет чтение данных о коктейлях из указанного файла и их валидацию.<br>
                  Данные должны быть в следующем виде: имя коктейля, количество ингредиентов, имя ингредиента, объем.
                  Количество имен ингредиентов и их объемов должны соответствовать количеству ингредиентов<br>
                  Разделителем между ингредиентами является \r\n
        @param    File_Path [IN] Полный путь к файлу
        @return   Возвращает массив считанных данных о коктейлях
    */
    static QList<Cocktail_Data_Struct> Read_Cocktails_From_File(QString File_Path);

/*
    Приватные объявления
*/
private:

    /*!
        @var     Ui::F_Cocktail *Form
        @brief   Ui формы
    */
    Ui::F_Cocktail *Form;

    /*!
        @var     bool Is_Changed
        @brief   Флаг изменения данных коктейля
    */
    bool Is_Changed = false;

    /*!
        @var     Cocktail_Data_Struct Data_Current
        @brief   Текущие данные коктейля
    */
    Cocktail_Data_Struct Data_Current;

    /*!
        @var     Cocktail_Data_Struct *Data_Ptr
        @brief   Указатель на данные коктейля
    */
    Cocktail_Data_Struct *Data_Ptr;

    /*!
        @var     QStringList *Ingredients_List_Ptr
        @brief   Указатель на список ингредиентов
    */
    QStringList *Ingredients_List_Ptr;

    /*!
        @var     QStringList Cocktail_Ingredients_List
        @brief   Список ингредиентов коктейля
    */
    QStringList Cocktail_Ingredients_List;

    /*!
        @fn      bool Update_Cocktail_Data()
        @brief   Метод обновления данных о коктейле
        @details Данный метод выполняет валидацию данных о коктейле, находящихся на форме и их перезапись
        @return  Возвращает результат обновления данных о коктейле
    */
    bool Update_Cocktail_Data();

    /*!
        @fn      void Update_Data_Current()
        @brief   Метод обновления текущих данных коктейля
        @details Данный метод выполняет получение данных коктелейля с формы и записывает их в текущие данные коктейля
        @return  None
    */
    void Update_Data_Current();

    /*!
        @fn      void Change_Is_Changed(bool New_State)
        @brief   Метод изменения флага изменения данных о коктейле
        @details Данный метод выполняет изменения флага изменения данных о коктейле и первод формы в состояние, соответствующее New_State
        @param   New_State [IN] Новое состояние флага изменения данных о коктейле
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
        @brief    Метод обработки нажатия на кнопку удаления коктейля
        @details  Данный метод выполняет обработку нажатия на кнопку удаления коктейля
        @return   None
    */
    void Delete_Button_Clicked();

    /*!
        @fn       void Add_Ingredient_Button_Clicked()
        @brief    Метод обработки нажатия на кнопку добавления ингредиента
        @details  Данный метод выполняет обработку нажатия на кнопку добавления ингредиента
        @return   None
    */
    void Add_Ingredient_Button_Clicked();

    /*!
        @fn      void Name_Edit_Finished()
        @brief   Метод обработки завершения редактирования названия коктейля
        @details Данный метод выполняет обработку завершения редактирования названия коктейля
        @return  None
    */
    void Name_Edit_Finished();

    /*!
        @fn      void Ingredient_Edited()
        @brief   Метод обработки изменения данных об ингредиенте
        @details Данный метод выполняет обработку изменения данных о ингредиенте
        @return  None
    */
    void Ingredient_Edited();

    /*!
        @fn      void Ingredient_Deteled(QString Ingredient_Name)
        @brief   Метод обработки удаления ингредиента
        @details Данный метод выполняет обработку удаления ингредиента
        @return  None
    */
    void Ingredient_Deteled(QString Ingredient_Name);

/*
    Объявления сигналов
*/
signals:

    /*!
        @fn      void Edited_Signal(QString Cocktail_Name)
        @brief   Сигнал изменения коктейля
        @details Данный сигнал генерируется, когда данные о коктейле изменяются
        @param   Cocktail_Name [OUT] Название коктейля
        @return  None
    */
    void Edited_Signal(QString Cocktail_Name);

    /*!
        @fn      void Delete_Signal(QString Cocktail_Name)
        @brief   Сигнал удаления коктейля
        @details Данный сигнал генерируется, когда необходимо удалить коктейль
        @param   Cocktail_Name [OUT] Название коктейля
        @return  None
    */
    void Delete_Signal(QString Cocktail_Name);

};

// Конец блока
#endif
