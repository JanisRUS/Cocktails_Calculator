// Подключить заголовочный файл
#include "F_Ingredient.h"

// Базовый конструктор класса
F_Ingredient::F_Ingredient(QWidget *Parent) : QWidget(Parent), Form(new Ui::F_Ingredient)
{
    // Настроить Ui формы
    Form->setupUi(this);
    // Назначить обработчик редактирования названия ингредиента
    connect(Form->Name_TBox,     &QLineEdit::textChanged,     this, &F_Ingredient::TBox_Changed);
    // Назначить обработчик редактирования объема ингредиента
    connect(Form->Volume_TBox,   &QLineEdit::textChanged,     this, &F_Ingredient::TBox_Changed);
    // Назначить обработчик нажатия на кнопку удаления ингредиента
    connect(Form->Delete_Button, &QPushButton::clicked,       this, &F_Ingredient::Delete_Button_Clicked);
    // Назначить обработчик завершения редактирования данных об ингредиенте
    connect(Form->Name_TBox,     &QLineEdit::editingFinished, this, &F_Ingredient::Ingredient_Data_Edit_Finished);
    // Назначить обработчик завершения редактирования данных об ингредиенте
    connect(Form->Volume_TBox,   &QLineEdit::editingFinished, this, &F_Ingredient::Ingredient_Data_Edit_Finished);
}

// Деструктор класса
F_Ingredient::~F_Ingredient()
{
    // Удалить Ui формы
    delete Form;
}

// Метод установки данных ингредиента
void F_Ingredient::Set_Data(Ingredient_Data_Struct *Data_Ptr_New, QStringList *Ingredients_List_Ptr_New, QStringList *Cocktail_Ingredients_List_Ptr_New)
{
    // Записать указатель на данные ингредиента
    Data_Ptr = Data_Ptr_New;
    // Записать указатель на список ингредиентов
    Ingredients_List_Ptr = Ingredients_List_Ptr_New;
    // Записать указатель на список ингредиентов коктейля
    Cocktail_Ingredients_List_Ptr = Cocktail_Ingredients_List_Ptr_New;

    // Вывести имя ингредиента
    Form->Name_TBox->setText(Data_Ptr->Name);
    // Вывести объем ингредиента
    Form->Volume_TBox->setText(QString::number(Data_Ptr->Volume));

    // Обновить текущие данные ингредиента
    Update_Data_Current();
    // Выполнить валидацию текущих данных
    Validate_Data_Current();
}

// Метод валидации данных ингредиента
bool F_Ingredient::Validate_Data()
{
    // Флаг валидности данных
    bool Is_Valid = true;

    // Если название ингредиента некорректно
    if (Data_Ptr->Name.length() == 0)
    {
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }

    // Если объем ингредиента некорректен
    if (Data_Ptr->Volume <= 0)
    {
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }

    // Вернуть флаг валидности данных
    return Is_Valid;
}

// Метод установки нового названия ингредиента
void F_Ingredient::Set_Name(QString New_Name)
{
    // Вывести название ингредиента
    Form->Name_TBox->setText(New_Name);
    // Обновить текущие данные ингредиента
    Update_Data_Current();
    // Выполнить валидацию текущих данных
    Validate_Data_Current();
    // Перезаписать данные ингредиента
    *Data_Ptr = Data_Current;
}

// Метод обработки изменения поля ввода
void F_Ingredient::TBox_Changed(const QString &New_Text)
{
    // Обновить текущие данные ингредиента
    Update_Data_Current();
    // Выполнить валидацию текущих данных
    Validate_Data_Current();

    // Если название ингредиента не изменяется
    if (!Form->Name_TBox->hasFocus())
    {
        // Прервать выполнение метода
        return;
    }
    // Если новый текст пустой
    if (New_Text.length() == 0)
    {
        // Прервать выполнение метода
        return;
    }
    // Для всего списка ингредиентов
    for (int i = 0; i < Ingredients_List_Ptr->length(); i++)
    {
        // Если подстрока совпадает с введенным текстом
        if (New_Text == Ingredients_List_Ptr->at(i).mid(0, New_Text.length()))
        {
            // Записать текст
            Form->Name_TBox->setText(Ingredients_List_Ptr->at(i));
            // Изменить положение курсора
            Form->Name_TBox->setCursorPosition(New_Text.length());
            // Изменить выделение текста
            Form->Name_TBox->setSelection(New_Text.length(), Ingredients_List_Ptr->at(i).length());
            // Прервать выполнение метода
            return;
        }
    }
}

// Метод обработки завершения редактирования данных об ингредиенте
void F_Ingredient::Ingredient_Data_Edit_Finished()
{
    // Если выполнить валидацию текущих данных не удалось
    if (!Validate_Data_Current())
    {
        // Прервать выполнение метода
        return;
    }

    // Создать сигнал
    emit Edited_Signal();
}

// Метод принятия изменений
void F_Ingredient::Accept_Changes()
{
    // Если ингредиент не был изменен
    if (!Is_Changed)
    {
        // Прервать выполнение метода
        return;
    }
    // Если данные невалидны
    if (!Validate_Data_Current())
    {
        // Прервать выполнение метода
        return;
    }
    // Перезаписать название ингредиента
    Data_Ptr->Name = Data_Current.Name;
    // Перезаписать объем ингредиента
    Data_Ptr->Volume = Data_Current.Volume;

    // Изменить флаг изменения данных об ингредиенте
    Change_Is_Changed(false);

    // Создать сигнал
    emit Edited_Signal();
}

// Метод обновления текущих данных ингредиента
void F_Ingredient::Update_Data_Current()
{
    // Новые данные ингредиента
    Ingredient_Data_Struct Data_New;
    // Флаг успешного выполнения операции
    bool Is_Ok = false;

    // Записать название ингредиента
    Data_New.Name = Form->Name_TBox->text();

    // Получить объем ингредиента
    Data_New.Volume = Form->Volume_TBox->text().toInt(&Is_Ok);
    // Если получить объем не удалось
    if (!Is_Ok)
    {
        // Записать невалидный объем ингредиента
        Data_New.Volume = -1;
    }

    // Если новые данные ингредиента отличаются от данных ингредиента
    if
    (
        Data_New.Name   != Data_Ptr->Name   ||
        Data_New.Volume != Data_Ptr->Volume
    )
    {
        // Изменить флаг изменения данных об ингредиенте
        Change_Is_Changed(true);
    }
    // Если новые данные ингредиента не отличаются от данных ингредиента
    else
    {
        // Изменить флаг изменения данных об ингредиенте
        Change_Is_Changed(false);
    }

    // Перезаписать текущие данные ингредиента
    Data_Current = Data_New;
}

// Метод валидации текущих данных ингредиента
bool F_Ingredient::Validate_Data_Current()
{
    // Флаг валидности данных
    bool Is_Valid  = true;
    // Флаг нахождения ингредиента
    bool Is_Found  = false;
    // Количество нахождений ингредиента
    int Ingredient_Found_Count = 0;

    // Для всего списка ингредиентов
    for (int i = 0; i < Ingredients_List_Ptr->length(); i++)
    {
        // Если название ингредиента совпадает с названием из списка
        if (Data_Current.Name == Ingredients_List_Ptr->at(i))
        {
            // Установить флаг нахождения ингредиента
            Is_Found = true;
            // Прервать выполнение цикла
            break;
        }
    }

    // Для всего списка ингредиентов коктейля
    for (int i = 0; i < Cocktail_Ingredients_List_Ptr->length(); i++)
    {
        // Если название ингредиента совпадает с названием из списка
        if (Data_Current.Name == Cocktail_Ingredients_List_Ptr->at(i))
        {
            // Увеличить количество нахождений ингредиента
            Ingredient_Found_Count++;
        }
    }

    // Если название ингредиента некорректно
    if (Data_Current.Name.length() == 0)
    {
        // Изменить цвет поля ввода и текста
        Form->Name_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_ERROR);
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }
    // Если ингредиент не найден
    else if (!Is_Found)
    {
        // Изменить цвет поля ввода и текста
        Form->Name_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_ERROR);
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }
    // Если количество нахождений ингредиента больше 1
    else if (Ingredient_Found_Count > 1)
    {
        // Изменить цвет поля ввода и текста
        Form->Name_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_ERROR);
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }
    // Если проблемы с названием ингредиента отсутствуют
    else
    {
        // Изменить цвет поля ввода и текста
        Form->Name_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_OK);
    }

    // Если объем ингредиента некорректен
    if (Data_Current.Volume <= 0)
    {
        // Изменить цвет поля ввода и текста
        Form->Volume_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_ERROR);
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }
    // Если объем ингредиента корректен
    else
    {
        // Изменить цвет поля ввода и текста
        Form->Volume_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_OK);
    }

    // Вернуть флаг валидности данных
    return Is_Valid;
}

// Метод изменения флага изменения данных ингредиента
void F_Ingredient::Change_Is_Changed(bool New_State)
{
    // Если новое состояние- true
    if (New_State)
    {
        // Установить флаг изменения данных ингредиента
        Is_Changed = true;
    }
    // Еслит новое состояние- false
    else
    {
        // Сбросить флаг изменения данных ингредиента
        Is_Changed = false;
    }
}

// Метод обработки нажатия на кнопку удаления ингредиента
void F_Ingredient::Delete_Button_Clicked()
{
    // Создать сигнал
    emit Delete_Signal(Data_Ptr->Name);
}
