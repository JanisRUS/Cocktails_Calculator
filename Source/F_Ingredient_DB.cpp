// Подключить заголовочный файл
#include "F_Ingredient_DB.h"

// Базовый конструктор класса
F_Ingredient_DB::F_Ingredient_DB(QWidget *Parent) : QWidget(Parent), Form(new Ui::F_Ingredient_DB)
{
    // Настроить Ui формы
    Form->setupUi(this);
    // Назначить обработчик нажатия на кнопку принятия изменений
    connect(Form->Accept_Button, &QPushButton::clicked,   this, &F_Ingredient_DB::Accept_Button_Clicked);
    // Назначить обработчик нажатия на кнопку удаления ингредиента
    connect(Form->Delete_Button, &QPushButton::clicked,   this, &F_Ingredient_DB::Delete_Button_Clicked);
    // Назначить обработчик изменения текста в поле ввода названия ингредиента
    connect(Form->Name_TBox,     &QLineEdit::textChanged, this, &F_Ingredient_DB::TBox_Changed);
    // Назначить обработчик изменения текста в поле ввода объема ингредиента
    connect(Form->Volume_TBox,   &QLineEdit::textChanged, this, &F_Ingredient_DB::TBox_Changed);
    // Назначить обработчик изменения текста в поле ввода цены ингредиента
    connect(Form->Price_TBox,    &QLineEdit::textChanged, this, &F_Ingredient_DB::TBox_Changed);
    // Назначить обработчик изменения текста в поле ввода процента алкоголя ингредиента
    connect(Form->Alcohol_TBox,  &QLineEdit::textChanged, this, &F_Ingredient_DB::TBox_Changed);
}

// Деструктор класса
F_Ingredient_DB::~F_Ingredient_DB()
{
    // Удалить Ui формы
    delete Form;
}

// Метод установки данных ингредиента
void F_Ingredient_DB::Set_Data(Ingredient_DB_Struct *Data_Ptr_New, QStringList *Ingredients_List_Ptr_New)
{
    // Записать указатель на данные ингредиента
    Data_Ptr = Data_Ptr_New;
    // Записать указатель на список ингредиентов
    Ingredients_List_Ptr = Ingredients_List_Ptr_New;

    // Вывести имя ингредиента
    Form->Name_TBox->setText(Data_Ptr->Name);
    // Вывести объем
    Form->Volume_TBox->setText(QString::number(Data_Ptr->Volume));
    // Вывести цену
    Form->Price_TBox->setText(QString::number(Data_Ptr->Price));
    // Вывести процент алкоголя
    Form->Alcohol_TBox->setText(QString::number(Data_Ptr->Alcohol));

    // Обновить текущие данные ингредиента
    Update_Data_Current();
    // Выполнить валидацию текущих данных
    Validate_Data_Current();
    // Сбросить флаг изменения данных ингредиента
    Change_Is_Changed(false);
}

// Метод валидации текущих данных ингредиента
bool F_Ingredient_DB::Validate_Data_Current()
{
    // Флаг валидности данных
    bool Is_Valid = true;
    // Количество нахождений ингредиента
    int Ingredient_Found_Count = 0;

    // Для всего списка ингредиентов
    for (int i = 0; i < Ingredients_List_Ptr->length(); i++)
    {
        // Если название ингредиента совпадает с названием из списка
        if (Data_Current.Name == Ingredients_List_Ptr->at(i))
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

    // Если цена ингредиента некорректна
    if (Data_Current.Price < 0)
    {
        // Изменить цвет поля ввода и текста
        Form->Price_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_ERROR);
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }
    // Если цена ингредиента корректна
    else
    {
        // Изменить цвет поля ввода и текста
        Form->Price_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_OK);
    }

    // Если процент алкоголя в ингредиенте некорректен
    if (Data_Current.Alcohol < 0)
    {
        // Изменить цвет поля ввода и текста
        Form->Alcohol_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_ERROR);
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }
    // Если процент алкоголя в ингредиенте корректен
    else
    {
        // Изменить цвет поля ввода и текста
        Form->Alcohol_TBox->setStyleSheet(F_INGREDIENT_DB_STYLESHEET_TBOX_OK);
    }

    // Вернуть флаг валидности данных
    return Is_Valid;
}

// Метод валидации данных ингредиента
bool F_Ingredient_DB::Validate_Data()
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

    // Если цена ингредиента некорректна
    if (Data_Ptr->Price < 0)
    {
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }

    // Если процент алкоголя в ингредиенте некорректен
    if (Data_Ptr->Alcohol < 0)
    {
        // Сбросить флаг валидности данных
        Is_Valid = false;
    }

    // Вернуть флаг валидности данных
    return Is_Valid;
}

// Метод изменения флага изменения данных об ингредиенте
void F_Ingredient_DB::Change_Is_Changed(bool New_State)
{
    // Если новое состояние- true
    if (New_State)
    {
        // Установить флаг изменения данных об ингредиенте
        Is_Changed = true;
        // Изменить доступность кнопки
        Form->Accept_Button->setEnabled(true);
    }
    // Еслит новое состояние- false
    else
    {
        // Сбросить флаг изменения данных об ингредиенте
        Is_Changed = false;
        // Изменить доступность кнопки
        Form->Accept_Button->setEnabled(false);
    }
}

// Метод обновления текущих данных ингредиента
void F_Ingredient_DB::Update_Data_Current()
{
    // Новые данные об ингредиенте
    Ingredient_DB_Struct Data_New;
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

    // Получить цену ингредиента
    Data_New.Price = Form->Price_TBox->text().toInt(&Is_Ok);
    // Если получить цену не удалось
    if (!Is_Ok)
    {
        // Записать невалидную цену ингредиента
        Data_New.Price = -1;
    }

    // Получить процент алкоголя ингредиента
    Data_New.Alcohol = Form->Alcohol_TBox->text().toInt(&Is_Ok);
    // Если получить процент алкоголя не удалось
    if (!Is_Ok)
    {
        // Записать невалидный процент алкоголя ингредиента
        Data_New.Alcohol = -1;
    }

    // Перезаписать текущие данные ингредиента
    Data_Current = Data_New;
}

// Метод обработки нажатия на кнопку принятия изменений
void F_Ingredient_DB::Accept_Button_Clicked()
{
    // Старое название ингредиента
    QString Name_Old = Data_Ptr->Name;

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
    // Перезаписать данные ингредиента
    *Data_Ptr = Data_Current;

    // Изменить флаг изменения данных об ингредиенте
    Change_Is_Changed(false);

    // Создать сигнал
    emit Edited_Signal(Name_Old + "->" + Data_Current.Name);
}

// Метод обработки нажатия на кнопку удаления ингредиента
void F_Ingredient_DB::Delete_Button_Clicked()
{
    // Создать сигнал
    emit Delete_Signal(Data_Ptr->Name);
}

// Метод обработки изменения поля ввода
void F_Ingredient_DB::TBox_Changed(const QString &New_Text)
{
    // Флаг совпадения
    bool Is_Equal = true;

    // Сделать преременную неиспользуемой
    Q_UNUSED(New_Text);

    // Обновить текущие данные ингредиента
    Update_Data_Current();
    // Выполнить валидацию текущих данных
    Validate_Data_Current();

    // Если название ингредиента отличается
    if (Data_Ptr->Name != Data_Current.Name)
    {
        // Сбросить флаг совпадения
        Is_Equal = false;
    }
    // Если название ингредиента отличается
    else if (Data_Ptr->Volume != Data_Current.Volume)
    {
        // Сбросить флаг совпадения
        Is_Equal = false;
    }
    // Если название ингредиента отличается
    else if (Data_Ptr->Price != Data_Current.Price)
    {
        // Сбросить флаг совпадения
        Is_Equal = false;
    }
    // Если название ингредиента отличается
    else if (Data_Ptr->Alcohol != Data_Current.Alcohol)
    {
        // Сбросить флаг совпадения
        Is_Equal = false;
    }

    // Изменить флаг изменения данных ингредиента
    Change_Is_Changed(!Is_Equal);
}

// Статический метод чтения данных об ингредиентах из файла
QList<Ingredient_DB_Struct> F_Ingredient_DB::Read_Ingredients_From_File(QString File_Path)
{
    // Ответ
    QList<Ingredient_DB_Struct> Answer;
    // Записать имя файла
    QFile *File_Ingredients = new QFile(File_Path);
    // Открыть файл
    File_Ingredients->open(QFile::ReadWrite);
    // Считать все данные из файла
    QStringList Ingredients_String_Data = QString(File_Ingredients->readAll()).split("\r\n");
    // Вывести сообщение
    qDebug() << QString("%1 strings were read!").arg(Ingredients_String_Data.length());
    // Для всех считанных данных
    for (int i = 0; i < Ingredients_String_Data.length(); i++)
    {
        // Данные ингредиента
        Ingredient_DB_Struct Ingredient_Data;
        // Флаг успешного выполнения операции
        bool Is_Ok = false;
        // Разбить строку на строковые данные
        QStringList Ingredient_String_Data = Ingredients_String_Data[i].split(",");
        // Если количество данных некоректно
        if (Ingredient_String_Data.length() != 4)
        {
            // Вывести сообщение
            qDebug() << QString("Error at string #%1! Number of elements is not equeal to 4!").arg(i);
            // Продолжить выполнение цикла
            continue;
        }
        // Записать имя ингредиента
        Ingredient_Data.Name = Ingredient_String_Data[0];
        // Если имя ингредиента некорректно
        if (Ingredient_String_Data[0].length() == 0)
        {
            // Вывести сообщение
            qDebug() << QString("Error at string #%1! Name is empty!").arg(i);
            // Продолжить выполнение цикла
            continue;
        }
        // Считать объем ингредиента
        Ingredient_Data.Volume = Ingredient_String_Data[1].toInt(&Is_Ok);
        // Если объем ингредиента некорректен
        if (!Is_Ok)
        {
            // Вывести сообщение
            qDebug() << QString("Error at string #%1! Volume is incorrect!").arg(i);
            // Продолжить выполнение цикла
            continue;
        }
        // Считать цену ингредиента
        Ingredient_Data.Price = Ingredient_String_Data[2].toInt(&Is_Ok);
        // Если цена ингредиента некорректна
        if (!Is_Ok)
        {
            // Вывести сообщение
            qDebug() << QString("Error at string #%1! Price is incorrect!").arg(i);
            // Продолжить выполнение цикла
            continue;
        }
        // Считать процент алкоголя ингредиента
        Ingredient_Data.Alcohol = Ingredient_String_Data[3].toInt(&Is_Ok);
        // Если цена ингредиента некорректна
        if (!Is_Ok)
        {
            // Вывести сообщение
            qDebug() << QString("Error at string #%1! Alcohol is incorrect!").arg(i);
            // Продолжить выполнение цикла
            continue;
        }

        // Вывести сообщение
        qDebug() << QString
                    (
                        "Line #%1 has been read. "
                        "Name: %2. "
                        "Volume: %3. "
                        "Price: %4. "
                        "Alcohol: %5."
                    )
                    .arg(i)
                    .arg(Ingredient_Data.Name)
                    .arg(Ingredient_Data.Volume)
                    .arg(Ingredient_Data.Price)
                    .arg(Ingredient_Data.Alcohol);

        // Записать данные ингредиента
        Answer.append(Ingredient_Data);
    }
    // Закрыть файл
    File_Ingredients->close();
    // Вернуть ответ
    return Answer;
}
