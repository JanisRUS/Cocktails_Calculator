// Подключить заголовочный файл
#include "F_Main.h"

// Базовый конструктор класса
F_Main::F_Main(QWidget *Parent) : QMainWindow(Parent), Form(new Ui::F_Main)
{
    // Настроить Ui формы
    Form->setupUi(this);

    // Назначить метод обработки нажатия на кнопку добавления коктейля
    connect(Form->Add_Cocktail_Button,   &QPushButton::clicked, this, &F_Main::Add_Cocktail_Button_Clicked);
    // Назначить метод обработки нажатия на кнопку добавления ингредиента
    connect(Form->Add_Ingredient_Button, &QPushButton::clicked, this, &F_Main::Add_Ingredient_Button_Clicked);

    // Вывести данные об ингредиентах из файла на форму
    Ingredients_DB_Show();
    // Вывести данные о коктейлях из файла на форму
    Cocktails_DB_Show();

    // Для всего списка коктейлей
    for (int i = 0; i < Cocktails_Data.Data.length(); i++)
    {
        // Назначить обработчик изменения данных о коктейле
        connect(Cocktails_Data.Forms[i], &F_Cocktail::Edited_Signal, this, &F_Main::Cocktail_Edited);
    }

    // Для всего списка ингредиентов
    for (int i = 0; i < Ingredients_Data.Data.length(); i++)
    {
        // Метод обработки изменения данных об ингредиенте
        connect(Ingredients_Data.Forms[i], &F_Ingredient_DB::Edited_Signal, this, &F_Main::Ingredient_Edited);
    }
}

// Деструктор класса
F_Main::~F_Main()
{
    // Удалить Ui формы
    delete Form;
}

// Метод вывода ингредиентов из файла
void F_Main::Ingredients_DB_Show()
{
    // Если Layout создан
    if (Ingredients_Data.Layout)
    {
        // Удалить Layout
        delete Ingredients_Data.Layout;
    }
    // Для всех указателей на формы игредиентов
    for (int i = 0; i < Ingredients_Data.Forms.length(); i++)
    {
        // Удалить форму
        delete Ingredients_Data.Forms[i];
    }
    // Создать Layout
    Ingredients_Data.Layout = new QVBoxLayout(Form->Ingredients_Scroll_Area_Content);
    // Очистить данные об ингредиентах
    Ingredients_Data.Data.clear();
    // Очистить указатели на формы ингредиентов
    Ingredients_Data.Forms.clear();
    // Очистить названия ингредиентов
    Ingredients_List_Inner.clear();
    // Считать данные об ингредиентах из файла
    Ingredients_Data.Data = F_Ingredient_DB::Read_Ingredients_From_File(QDir::currentPath() + "/Data/Ingredients.txt");
    // Для всех данных, считанных из файла ингредиентов
    for (int i = 0; i < Ingredients_Data.Data.length(); i++)
    {
        // Создать форму ингредиента
        Ingredients_Data.Forms.append(new F_Ingredient_DB());
        // Вывести на форму данные об ингредиенте
        Ingredients_Data.Forms[i]->Set_Data(&Ingredients_Data.Data[i], &Ingredients_List_Inner);
        // Добавить форму ингредиента
        Ingredients_Data.Layout->addWidget(Ingredients_Data.Forms[i]);
        // Записать название ингредиента
        Ingredients_List_Inner.append(Ingredients_Data.Data[i].Name);
    }
}

// Метод вывода коктейлей из файла
void F_Main::Cocktails_DB_Show()
{
    // Если Layout создан
    if (Cocktails_Data.Layout)
    {
        // Удалить Layout
        delete Cocktails_Data.Layout;
    }
    // Для всех указателей на формы игредиентов
    for (int i = 0; i < Cocktails_Data.Forms.length(); i++)
    {
        // Удалить форму
        delete Cocktails_Data.Forms[i];
    }
    // Создать Layout
    Cocktails_Data.Layout = new QVBoxLayout(Form->Cocktails_Scroll_Area_Content);
    // Очистить данные о коктейлях
    Cocktails_Data.Data.clear();
    // Очистить указатели на формы коктейлей
    Cocktails_Data.Forms.clear();
    // Считать данные о коктейлях из файла
    Cocktails_Data.Data = F_Cocktail::Read_Cocktails_From_File(QDir::currentPath() + "/Data/Cocktails.txt");
    // Для всех данных, считанных из файла коктейлей
    for (int i = 0; i < Cocktails_Data.Data.length(); i++)
    {
        // Создать форму коктейля
        Cocktails_Data.Forms.append(new F_Cocktail());
        // Вывести на форму данные о коктейле
        Cocktails_Data.Forms[i]->Set_Data(&Cocktails_Data.Data[i], &Ingredients_List_Inner);
        // Добавить форму ингредиента
        Cocktails_Data.Layout->addWidget(Cocktails_Data.Forms[i]);
    }
    // Обновить данные о коктейлях
    Update_Cocktails_Data();
}

// Метод поиска номера ингредиента
int F_Main::Get_Ingredient_Number(QString Ingredient_Name)
{
    // Для всех ингредиентов
    for (int i = 0; i < Ingredients_List_Inner.length(); i++)
    {
        // Если название ингредиента найдено
        if (Ingredient_Name == Ingredients_List_Inner[i])
        {
            // Вернуть номер ингредиента
            return i;
        }
    }
    // Вернуть ошибку
    return -1;
}

// Метод обновления данных о коктейлях
void F_Main::Update_Cocktails_Data()
{
    // Для всех коктейлей
    for (int i = 0; i < Cocktails_Data.Data.length(); i++)
    {
        // Цена коктейля
        int Price = 0;
        // Объем коктейля
        int Volume = 0;
        // Процент алкоголя
        int Alcohol = 0;

        // Для всех ингредиентов коктейля
        for (int j = 0; j < Cocktails_Data.Data[i].Ingredients_Count; j++)
        {
            // Найти номер ингредиента
            int Ingredient_Number = Get_Ingredient_Number(Cocktails_Data.Data[i].Ingredients_Data[j].Name);
            // Стоимость 1 мл ингредиента
            double Price_ML = 0;
            // Если найти номер ингредиента не удалось
            if (Ingredient_Number == -1)
            {
                // Продолжить выполнение цикла
                continue;
            }
            // Рассчитать стоимость 1 мл ингредиента
            Price_ML = (double)Ingredients_Data.Data[Ingredient_Number].Price / (double)Ingredients_Data.Data[Ingredient_Number].Volume;
            // Дописать цену коктейля
            Price += Price_ML * Cocktails_Data.Data[i].Ingredients_Data[j].Volume;
            // Дописать объем коктейля
            Volume += Cocktails_Data.Data[i].Ingredients_Data[j].Volume;
            // Дописать процент алкоголя
            Alcohol += Cocktails_Data.Data[i].Ingredients_Data[j].Volume * Ingredients_Data.Data[Ingredient_Number].Alcohol / 100;
        }
        // Выполнить рассчет процента алкоголя
        Alcohol = 100 * (double)Alcohol / (double)Volume;

        // Округлить цену до 10
        Price = ((Price / 10) + 1) * 10;

        // Вывести рассчитанные данные коктейля
        Cocktails_Data.Forms[i]->Show_Calculated_Data(Price, Volume, Alcohol);
    }
}

// Метод проверки ингредиента на существование в списке ингредиентов
bool F_Main::Is_Exist(QString Ingredient_Name)
{
    // Для всего списка ингредиентов
    for (int i = 0; i < Ingredients_List_Inner.length(); i++)
    {
        // Если ингредиент найден
        if (Ingredient_Name == Ingredients_List_Inner[i])
        {
            // Вернуть подтверждение
            return true;
        }
    }
    // Вернуть ошибку
    return false;
}


// Метод записи данных о коктейлях в файл
void F_Main::Write_Cocktails_To_File()
{
    // Файл для записи
    QFile *File = new QFile(QDir::currentPath() + "/Data/Cocktails.txt");
    // Открыть файл
    File->open(QFile::WriteOnly);
    // Для всех коктейлей
    for (int i = 0; i < Cocktails_Data.Data.length(); i++)
    {
        // Строка для записи
        QString String_To_Write = "";

        // Если данные о коктейле некорректны
        if (!Cocktails_Data.Forms[i]->Check_Data())
        {
            // Продолжить выполнение цикла
            continue;
        }

        // Записать название коктейля
        String_To_Write += Cocktails_Data.Data[i].Name + ",";
        // Записать количество ингредиентов
        String_To_Write += QString("%1,").arg(Cocktails_Data.Data[i].Ingredients_Data.length());
        // Для всех ингредиентов
        for (int j = 0; j < Cocktails_Data.Data[i].Ingredients_Data.length(); j++)
        {
            // Записать название ингредиента
            String_To_Write += QString(Cocktails_Data.Data[i].Ingredients_Data[j].Name + ",");
            // Записать объем ингредиента
            String_To_Write += QString("%1,").arg(Cocktails_Data.Data[i].Ingredients_Data[j].Volume);
        }
        // Стереть последнюю запятую
        String_To_Write.remove(String_To_Write.length() - 1, 1);
        // Если коктейль не является последним
        if (i != Cocktails_Data.Data.length() - 1)
        {
            // Записать перенос строки
            String_To_Write += "\r\n";
        }
        // Записать строку в файл
        File->write(String_To_Write.toUtf8());
    }
    // Закрыть файл
    File->close();
}

// Метод записи данных об ингредиентах в файл
void F_Main::Write_Ingredients_To_File()
{
    // Файл для записи
    QFile *File = new QFile(QDir::currentPath() + "/Data/Ingredients.txt");
    // Открыть файл
    File->open(QFile::WriteOnly);
    // Для всех ингредиентов
    for (int i = 0; i < Ingredients_Data.Data.length(); i++)
    {
        // Строка для записи
        QString String_To_Write = "";

        // Если данные ингредиента некорректны
        if (!Ingredients_Data.Forms[i]->Validate_Data())
        {
            // Продолжить выполнение цикла
            continue;
        }

        // Записать название ингредиента
        String_To_Write += Ingredients_Data.Data[i].Name + ",";
        // Записать объем ингредиента
        String_To_Write += QString("%1,").arg(Ingredients_Data.Data[i].Volume);
        // Записать цену ингредиента
        String_To_Write += QString("%1,").arg(Ingredients_Data.Data[i].Price);
        // Записать процент алкоголя в ингредиенте
        String_To_Write += QString("%1").arg(Ingredients_Data.Data[i].Alcohol);
        // Если ингредиент не является последним
        if (i != Ingredients_Data.Data.length() - 1)
        {
            // Записать перенос строки
            String_To_Write += "\r\n";
        }
        // Записать строку в файл
        File->write(String_To_Write.toUtf8());
    }
    // Закрыть файл
    File->close();
}

// Метод обработки нажатия на кнопку добавления коктейля
void F_Main::Add_Cocktail_Button_Clicked()
{
    // Создать форму коктейля
    Cocktails_Data.Forms.append(new F_Cocktail());
    // Создать данные коктейля
    Cocktails_Data.Data.append(QList<Cocktail_Data_Struct>());
    // Заполнить данные коктейля
    Cocktails_Data.Data.last() =
    {
        "",
        0,
        QList<Ingredient_Data_Struct>(),
        QList<F_Ingredient *>()
    };
    // Вывести на форму данные о коктейле
    Cocktails_Data.Forms.last()->Set_Data(&Cocktails_Data.Data.last(), &Ingredients_List_Inner);
    // Добавить форму ингредиента
    Cocktails_Data.Layout->addWidget(Cocktails_Data.Forms.last());
    // Назначить обработчик изменения данных о коктейле
    connect(Cocktails_Data.Forms.last(), &F_Cocktail::Edited_Signal, this, &F_Main::Cocktail_Edited);
}

// Метод обработки нажатия на кнопку добавления ингредиента
void F_Main::Add_Ingredient_Button_Clicked()
{
    // Создать форму ингредиента
    Ingredients_Data.Forms.append(new F_Ingredient_DB());
    // Создать данные ингредиента
    Ingredients_Data.Data.append({"", 0, 0, 0});
    // Вывести на форму данные об ингредиенте
    Ingredients_Data.Forms.last()->Set_Data(&Ingredients_Data.Data.last(), &Ingredients_List_Inner);
    // Добавить форму ингредиента
    Ingredients_Data.Layout->addWidget(Ingredients_Data.Forms.last());
    // Записать название ингредиента
    Ingredients_List_Inner.append(Ingredients_Data.Data.last().Name);
    // Метод обработки изменения данных об ингредиенте
    connect(Ingredients_Data.Forms.last(), &F_Ingredient_DB::Edited_Signal, this, &F_Main::Ingredient_Edited);
}

// Метод обработки изменения данных о коктейле
void F_Main::Cocktail_Edited(QString Cocktail_Name)
{
    // Сделать переменную неиспользуемой
    Q_UNUSED(Cocktail_Name);

    // Записать данные об ингредиентах в файл
    Write_Ingredients_To_File();
    // Записать данные о коктейлях в файл
    Write_Cocktails_To_File();
}

// Метод обработки изменения данных об ингредиенте
void F_Main::Ingredient_Edited(QString Ingredient_Name)
{
    // Старое название ингредиента
    QString Name_Old = Ingredient_Name.split("->")[0];
    // Текущее название ингредиента
    QString Name_Current = Ingredient_Name.split("->")[1];

    // Для всего списка ингредиентов
    for (int i = 0; i < Ingredients_List_Inner.length(); i++)
    {
        // Если ингредиент совпадает со старым названием ингредиента
        if (Ingredients_List_Inner[i] == Name_Old || Ingredients_List_Inner[i] == "")
        {
            // Задать новое название ингредиента
            Ingredients_List_Inner[i] = Name_Current;
        }
    }

    // Для всего списка коктейлей
    for (int i = 0; i < Cocktails_Data.Data.length(); i++)
    {
        // Для всего списка ингредиентов
        for (int j = 0; j < Cocktails_Data.Data[i].Ingredients_Data.length(); j++)
        {
            // Если ингредиент совпадает со старым названием ингредиента
            if (Cocktails_Data.Data[i].Ingredients_Data[j].Name == Name_Old)
            {
                // Задать новое название ингредиента
                Cocktails_Data.Data[i].Forms[j]->Set_Name(Name_Current);
            }
        }
    }

    // Обновить данные о коктейлях
    Update_Cocktails_Data();

    // Записать данные об ингредиентах в файл
    Write_Ingredients_To_File();
    // Записать данные о коктейлях в файл
    Write_Cocktails_To_File();
}

// Метод обработки удаления коктейля
void F_Main::Cocktail_Deteled(QString Cocktail_Name)
{

}

// Метод обработки удаления ингредиента
void F_Main::Ingredient_Deteled(QString Ingredient_Name)
{

}
