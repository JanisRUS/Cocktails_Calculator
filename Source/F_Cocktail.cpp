// Подключить заголовочный файл
#include "F_Cocktail.h"

// Базовый конструктор класса
F_Cocktail::F_Cocktail(QWidget *Parent) : QWidget(Parent), Form(new Ui::F_Cocktail)
{
    // Настроить Ui формы
    Form->setupUi(this);
    // Назначить обработчик завершения редактирования названия коктейля
    connect(Form->Name_TBox,              &QLineEdit::editingFinished, this, &F_Cocktail::Name_Edit_Finished);
    // Назначить обработчик нажатия на кнопку удаления коктейля
    connect(Form->Delete_Button,          &QPushButton::clicked,       this, &F_Cocktail::Delete_Button_Clicked);
    // Назначить обработчик нажатия на кнопку добавления ингредиента
    connect(Form->Add_Ingredient_Button,  &QPushButton::clicked,       this, &F_Cocktail::Add_Ingredient_Button_Clicked);
    // Назначить обработчик нажатия на кнопку принятия изменений
    connect(Form->Accept_Button,          &QPushButton::clicked,       this, &F_Cocktail::Accept_Button_Clicked);
}

// Деструктор класса
F_Cocktail::~F_Cocktail()
{
    // Удалить Ui формы
    delete Form;
}

// Метод установки данных коктейля
void F_Cocktail::Set_Data(Cocktail_Data_Struct *Data_Ptr_New, QStringList *Ingredients_List_Ptr_New)
{
    // Записать указатель на данные коктейля
    Data_Ptr = Data_Ptr_New;
    // Записать указатель на список ингредиентов
    Ingredients_List_Ptr = Ingredients_List_Ptr_New;

    // Вывести имя коктейля
    Form->Name_TBox->setText(Data_Ptr_New->Name);

    // Для всех ингредиентов
    for (int i = 0; i < Data_Ptr->Ingredients_Count; i++)
    {
        // Создать форму ингредиента
        Data_Ptr->Forms.append(new F_Ingredient());
        // Задать данные ингредиента
        Data_Ptr->Forms[i]->Set_Data(&Data_Ptr->Ingredients_Data[i], Ingredients_List_Ptr, &Cocktail_Ingredients_List);
        // Выровнять ингредиент по левому верхнему краю
        Form->Ingredients_Layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        // Добавить форму ингредиента на Layout
        Form->Ingredients_Layout->addWidget(Data_Ptr->Forms[i]);
        // Назначить обработчик удаления ингредиента
        connect(Data_Ptr->Forms[i], &F_Ingredient::Delete_Signal, this, &F_Cocktail::Ingredient_Deteled);
        // Назначить обработчик изменения ингредиента
        connect(Data_Ptr->Forms[i], &F_Ingredient::Edited_Signal, this, &F_Cocktail::Ingredient_Edited);
    }
    // Очистить список ингредиентов коктейля
    Cocktail_Ingredients_List.clear();
    // Для всех ингредиентов коктейля
    for (int i = 0; i < Data_Ptr->Forms.length(); i++)
    {
        // Добавить ингредиент в список
        Cocktail_Ingredients_List.append(Data_Ptr->Ingredients_Data[i].Name);
    }

    // Обновить текущие данные коктейля
    Update_Data_Current();
    // Выполнить валидацию текущих данных
    Validate_Data_Current();
    // Сбросить флаг изменения данных коктейля
    Change_Is_Changed(false);
}

// Метод вывода рассчитанных данных коктейля
void F_Cocktail::Show_Calculated_Data(int Price, int Volume, int Alcohol)
{
    // Вывести цену коктейля
    Form->Price_TBox->setText(QString::number(Price));
    // Вывести объем коктейля
    Form->Volume_TBox->setText(QString::number(Volume));
    // Вывести процент алкоголя в коктейле
    Form->Alcohol_TBox->setText(QString::number(Alcohol));
}

// Метод обновления текущих данных коктейля
void F_Cocktail::Update_Data_Current()
{
    // Новые данные коктейля
    Cocktail_Data_Struct Data_New;

    // Записать новое название коктейля
    Data_New.Name = Form->Name_TBox->text();

    // Если новое название коктейля отличается от названия коктейля
    if (Data_New.Name != Data_Ptr->Name)
    {
        // Изменить флаг изменения данных коктейля
        Change_Is_Changed(true);
    }
    // Если новые данные ингредиента не отличаются от данных ингредиента
    else
    {
        // Изменить флаг изменения данных коктейля
        Change_Is_Changed(false);
    }

    // Для всех ингредиентов коктейля
    for (int i = 0; i < Data_Ptr->Ingredients_Data.length(); i++)
    {
        // Если позиция в списке ингредиент коктейля отсутствует
        if (i >= Cocktail_Ingredients_List.length())
        {
            // Прервать выполнение цикла
            break;
        }
        // Если ингредиент отличается
        if (Data_Ptr->Ingredients_Data[i].Name != Cocktail_Ingredients_List[i])
        {
            // Изменить флаг изменения данных коктейля
            Change_Is_Changed(true);
        }
    }
    // Очистить список ингредиентов коктейля
    Cocktail_Ingredients_List.clear();
    // Для всех ингредиентов коктейля
    for (int i = 0; i < Data_Ptr->Forms.length(); i++)
    {
        // Добавить ингредиент в список
        Cocktail_Ingredients_List.append(Data_Ptr->Ingredients_Data[i].Name);
    }

    // Перезаписать название коктейля
    Data_Current.Name = Data_New.Name;
}

// Метод изменения флага изменения данных о коктейле
void F_Cocktail::Change_Is_Changed(bool New_State)
{
    // Если новое состояние- true
    if (New_State)
    {
        // Установить флаг изменения данных о коктейле
        Is_Changed = true;
        // Изменить доступность кнопки
        Form->Accept_Button->setEnabled(true);
    }
    // Еслит новое состояние- false
    else
    {
        // Сбросить флаг изменения данных о коктейле
        Is_Changed = false;
        // Изменить доступность кнопки
        Form->Accept_Button->setEnabled(false);
    }
}

// Метод обработки нажатия на кнопку принятия изменений
void F_Cocktail::Accept_Button_Clicked()
{
    // Если коктейль не был изменен
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
    // Перезаписать название коктейля
    Data_Ptr->Name = Data_Current.Name;
    // Для всех ингредиентов коктейля
    for (int i = 0; i < Data_Ptr->Forms.length(); i++)
    {
        // Принять изменения
        Data_Ptr->Forms[i]->Accept_Changes();
    }

    // Изменить флаг изменения данных коктейля
    Change_Is_Changed(false);

    // Создать сигнал
    emit Edited_Signal(Data_Ptr->Name);
}

// Метод валидации текущих данных коктейля
bool F_Cocktail::Validate_Data_Current()
{
    // Флаг валидности данных
    bool Is_Valid  = true;

    // Если название коктейля некорректно
    if (Data_Current.Name.length() == 0)
    {
        // Изменить цвет поля ввода и текста
        Form->Name_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_ERROR);
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }
    // Если название коктейля корректно
    else
    {
        // Изменить цвет поля ввода и текста
        Form->Name_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_OK);
    }

    // Для всех ингредиентов коктейля
    for (int i = 0; i < Data_Ptr->Forms.length(); i++)
    {
        // Если выполнить обновление текущих данных ингредиента не удалось
        if (!Data_Ptr->Forms[i]->Validate_Data_Current())
        {
            // Сбросить флаг валидности данных
            Is_Valid = false;
        }
    }

    // Вернуть флаг валидности данных
    return Is_Valid;
}

// Метод проверки данных о коктейле
bool F_Cocktail::Check_Data()
{
    // Если название коктейля некорректно
    if (Data_Ptr->Name.length() == 0)
    {
        // Вернуть ошибку
        return false;
    }

    // Для всего списка ингредиентов
    for (int i = 0; i < Data_Ptr->Ingredients_Data.length(); i++)
    {
        // Если данные ингредиента некорректны
        if (!Data_Ptr->Forms[i]->Validate_Data())
        {
            // Вернуть ошибку
            return false;
        }
    }

    // Вернуть подтверждение
    return true;
}

// Метод обработки нажатия на кнопку удаления коктейля
void F_Cocktail::Delete_Button_Clicked()
{
    // Создать сигнал
    emit Delete_Signal(Data_Ptr->Name);
}

// Метод обработки удаления ингредиента
void F_Cocktail::Ingredient_Deteled(QString Ingredient_Name)
{
    // Для всех ингредиентов коктейля
    for (int i = 0; i < Data_Ptr->Ingredients_Data.length(); i++)
    {
        // Если найден ингредиент, который необходимо удалить
        if (Data_Ptr->Ingredients_Data[i].Name == Ingredient_Name)
        {
            // Сбросить обработчик удаления ингредиента
            disconnect(Data_Ptr->Forms.last(), &F_Ingredient::Delete_Signal, this, &F_Cocktail::Ingredient_Deteled);
            // Сбросить обработчик изменения ингредиента
            disconnect(Data_Ptr->Forms.last(), &F_Ingredient::Edited_Signal, this, &F_Cocktail::Ingredient_Edited);
            // Удалить форму ингредиента
            delete Data_Ptr->Forms[i];
            // Удалить форму ингредиента
            Data_Ptr->Forms.removeAt(i);
            // Удалить данные ингредиента
            Data_Ptr->Ingredients_Data.removeAt(i);
            // Уменьшить количество ингредиентов
            Data_Ptr->Ingredients_Count--;
            // Обновить текущие данные коктейля
            Update_Data_Current();
        }
    }

    // Изменить флаг изменения данных коктейля
    Change_Is_Changed(true);
}

// Метод обработки нажатия на кнопку добавления ингредиента
void F_Cocktail::Add_Ingredient_Button_Clicked()
{
    // Увеличить количество ингредиентов
    Data_Ptr->Ingredients_Count++;
    // Создать данные ингредиента
    Data_Ptr->Ingredients_Data.append({"", 0});
    // Создать форму ингредиента
    Data_Ptr->Forms.append(new F_Ingredient());
    // Задать данные ингредиента
    Data_Ptr->Forms.last()->Set_Data(&Data_Ptr->Ingredients_Data.last(), Ingredients_List_Ptr, &Cocktail_Ingredients_List);
    // Добавить форму ингредиента на Layout
    Form->Ingredients_Layout->addWidget(Data_Ptr->Forms.last());
    // Назначить обработчик удаления ингредиента
    connect(Data_Ptr->Forms.last(), &F_Ingredient::Delete_Signal, this, &F_Cocktail::Ingredient_Deteled);
    // Назначить обработчик изменения ингредиента
    connect(Data_Ptr->Forms.last(), &F_Ingredient::Edited_Signal, this, &F_Cocktail::Ingredient_Edited);
    // Установить флаг изменения данных коктейля
    Change_Is_Changed(true);
}

// Метод обработки завершения редактирования названия коктейля
void F_Cocktail::Name_Edit_Finished()
{
    // Обновить текущие данные коктейля
    Update_Data_Current();
    // Выполнить валидацию текущих данных
    Validate_Data_Current();
}

// Метод обработки изменения данных об ингредиенте
void F_Cocktail::Ingredient_Edited()
{
    // Изменить флаг изменения данных о коктейле
    Change_Is_Changed(true);
}

// Статический метод чтения данных о коктейлях из файла
QList<Cocktail_Data_Struct> F_Cocktail::Read_Cocktails_From_File(QString File_Path)
{
    // Ответ
    QList<Cocktail_Data_Struct> Answer;
    // Записать имя файла
    QFile *File_Cocktails = new QFile(File_Path);
    // Открыть файл
    File_Cocktails->open(QFile::ReadWrite);
    // Считать все данные из файла
    QStringList Cocktails_String_Data = QString(File_Cocktails->readAll()).split("\r\n");
    // Вывести сообщение
    qDebug() << QString("%1 strings were read!").arg(Cocktails_String_Data.length());
    // Для всех считанных данных
    for (int i = 0; i < Cocktails_String_Data.length(); i++)
    {
        // Данные коктейля
        Cocktail_Data_Struct Cocktail_Data;
        // Данные ингредиента
        Ingredient_Data_Struct Ingredient_Data;
        // Флаг успешного выполнения операции
        bool Is_Ok = false;
        // Разбить строку на строковые данные
        QStringList Cocktail_String_Data = Cocktails_String_Data[i].split(",");
        // Текст сообщения
        QString Message_Text = "";

        // Если количество данных некоректно
        if (Cocktail_String_Data.length() < 2)
        {
            // Вывести сообщение
            qDebug() << QString("Error at string #%1! Number of elements is not equeal to 2!").arg(i);
            // Продолжить выполнение цикла
            continue;
        }

        // Получить имя коктейля
        Cocktail_Data.Name = Cocktail_String_Data[0];
        // Если имя коктейля некорректно
        if (Cocktail_Data.Name.length() == 0)
        {
            // Вывести сообщение
            qDebug() << QString("Error at string #%1! Name is empty!").arg(i);
            // Продолжить выполнение цикла
            continue;
        }

        // Получить количество ингредиентов
        Cocktail_Data.Ingredients_Count = Cocktail_String_Data[1].toInt(&Is_Ok);
        // Если получить количество ингредиентов не удалось
        if (!Is_Ok)
        {
            // Вывести сообщение
            qDebug() << QString("Error at string #%1! Ingredients count is incorrect!").arg(i);
            // Продолжить выполнение цикла
            continue;
        }

        // Если количество данных об ингредиентах некорректно
        if (Cocktail_Data.Ingredients_Count * 2 + 2 != Cocktail_String_Data.length())
        {
            // Вывести сообщение
            qDebug() << QString("Error at string #%1! Ingredients count is not equal to number of ingredients data!").arg(i);
            // Продолжить выполнение цикла
            continue;
        }

        // Дописать текст сообщения
        Message_Text += QString
                        (
                            "Line #%1 has been read. "
                            "Name: %2. "
                            "Ingredients Count: %3. "
                        )
                        .arg(i)
                        .arg(Cocktail_Data.Name)
                        .arg(Cocktail_Data.Ingredients_Count);

        // Для всех ингредиентов
        for (int j = 0; j < Cocktail_Data.Ingredients_Count; j++)
        {
            // Получить название ингредиента
            Ingredient_Data.Name   = Cocktail_String_Data[2 + j * 2];
            // Получить объем ингредиента
            Ingredient_Data.Volume = Cocktail_String_Data[2 + j * 2 + 1].toInt(&Is_Ok);
            // Если объем ингредиента некорректен
            if (!Is_Ok)
            {
                // Вывести сообщение
                qDebug() << QString("Error at string #%1 at ingredient #%2! Volume is incorrect!").arg(i).arg(j);
                // Прервать цикл
                break;
            }
            // Записать данные ингредиента
            Cocktail_Data.Ingredients_Data.append(Ingredient_Data);
            // Дописать текст сообщения
            Message_Text += QString
                            (
                                "Ingredient #%1. "
                                "Name: %2. "
                                "Volume: %3. "
                            )
                            .arg(j)
                            .arg(Ingredient_Data.Name)
                            .arg(Ingredient_Data.Volume);
        }

        // Вывести сообщение
        qDebug() << Message_Text;
        // Записать данные коктейля
        Answer.append(Cocktail_Data);
    }
    // Закрыть файл
    File_Cocktails->close();
    // Вернуть ответ
    return Answer;
}
