/********************************************************************************
** Form generated from reading UI file 'F_Main.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MAIN_H
#define UI_F_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_F_Main
{
public:
    QWidget *Main_Widget;
    QGridLayout *Main_Layout;
    QHBoxLayout *Add_Ingredient_Layout;
    QPushButton *Add_Ingredient_Button;
    QHBoxLayout *Cocktails_Layout;
    QLabel *Cocktails_Label;
    QHBoxLayout *Add_Cocktail_Layout;
    QPushButton *Add_Cocktail_Button;
    QHBoxLayout *Ingredients_Layout;
    QLabel *Ingredients_Label;
    QScrollArea *Ingredients_Scroll_Area;
    QWidget *Ingredients_Scroll_Area_Content;
    QScrollArea *Cocktails_Scroll_Area;
    QWidget *Cocktails_Scroll_Area_Content;

    void setupUi(QMainWindow *F_Main)
    {
        if (F_Main->objectName().isEmpty())
            F_Main->setObjectName(QString::fromUtf8("F_Main"));
        F_Main->resize(1000, 600);
        F_Main->setMinimumSize(QSize(1000, 600));
        QFont font;
        font.setPointSize(12);
        F_Main->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Icons/Cocktail_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        F_Main->setWindowIcon(icon);
        Main_Widget = new QWidget(F_Main);
        Main_Widget->setObjectName(QString::fromUtf8("Main_Widget"));
        Main_Layout = new QGridLayout(Main_Widget);
        Main_Layout->setObjectName(QString::fromUtf8("Main_Layout"));
        Add_Ingredient_Layout = new QHBoxLayout();
        Add_Ingredient_Layout->setObjectName(QString::fromUtf8("Add_Ingredient_Layout"));
        Add_Ingredient_Button = new QPushButton(Main_Widget);
        Add_Ingredient_Button->setObjectName(QString::fromUtf8("Add_Ingredient_Button"));
        Add_Ingredient_Button->setMinimumSize(QSize(50, 50));
        Add_Ingredient_Button->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/Icons/Add_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Add_Ingredient_Button->setIcon(icon1);
        Add_Ingredient_Button->setIconSize(QSize(50, 50));
        Add_Ingredient_Button->setFlat(true);

        Add_Ingredient_Layout->addWidget(Add_Ingredient_Button);


        Main_Layout->addLayout(Add_Ingredient_Layout, 3, 1, 1, 1);

        Cocktails_Layout = new QHBoxLayout();
        Cocktails_Layout->setObjectName(QString::fromUtf8("Cocktails_Layout"));
        Cocktails_Label = new QLabel(Main_Widget);
        Cocktails_Label->setObjectName(QString::fromUtf8("Cocktails_Label"));
        Cocktails_Label->setMinimumSize(QSize(200, 30));
        Cocktails_Label->setMaximumSize(QSize(200, 30));
        Cocktails_Label->setAlignment(Qt::AlignCenter);

        Cocktails_Layout->addWidget(Cocktails_Label);


        Main_Layout->addLayout(Cocktails_Layout, 0, 0, 1, 1);

        Add_Cocktail_Layout = new QHBoxLayout();
        Add_Cocktail_Layout->setObjectName(QString::fromUtf8("Add_Cocktail_Layout"));
        Add_Cocktail_Button = new QPushButton(Main_Widget);
        Add_Cocktail_Button->setObjectName(QString::fromUtf8("Add_Cocktail_Button"));
        Add_Cocktail_Button->setMinimumSize(QSize(50, 50));
        Add_Cocktail_Button->setMaximumSize(QSize(50, 50));
        Add_Cocktail_Button->setIcon(icon1);
        Add_Cocktail_Button->setIconSize(QSize(50, 50));
        Add_Cocktail_Button->setFlat(true);

        Add_Cocktail_Layout->addWidget(Add_Cocktail_Button);


        Main_Layout->addLayout(Add_Cocktail_Layout, 3, 0, 1, 1);

        Ingredients_Layout = new QHBoxLayout();
        Ingredients_Layout->setObjectName(QString::fromUtf8("Ingredients_Layout"));
        Ingredients_Label = new QLabel(Main_Widget);
        Ingredients_Label->setObjectName(QString::fromUtf8("Ingredients_Label"));
        Ingredients_Label->setMinimumSize(QSize(200, 30));
        Ingredients_Label->setMaximumSize(QSize(200, 30));
        Ingredients_Label->setAlignment(Qt::AlignCenter);

        Ingredients_Layout->addWidget(Ingredients_Label);


        Main_Layout->addLayout(Ingredients_Layout, 0, 1, 1, 1);

        Ingredients_Scroll_Area = new QScrollArea(Main_Widget);
        Ingredients_Scroll_Area->setObjectName(QString::fromUtf8("Ingredients_Scroll_Area"));
        Ingredients_Scroll_Area->setMinimumSize(QSize(333, 0));
        Ingredients_Scroll_Area->setMaximumSize(QSize(333, 16777215));
        Ingredients_Scroll_Area->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        Ingredients_Scroll_Area->setWidgetResizable(true);
        Ingredients_Scroll_Area->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Ingredients_Scroll_Area_Content = new QWidget();
        Ingredients_Scroll_Area_Content->setObjectName(QString::fromUtf8("Ingredients_Scroll_Area_Content"));
        Ingredients_Scroll_Area_Content->setGeometry(QRect(0, 0, 331, 484));
        Ingredients_Scroll_Area->setWidget(Ingredients_Scroll_Area_Content);

        Main_Layout->addWidget(Ingredients_Scroll_Area, 2, 1, 1, 1);

        Cocktails_Scroll_Area = new QScrollArea(Main_Widget);
        Cocktails_Scroll_Area->setObjectName(QString::fromUtf8("Cocktails_Scroll_Area"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cocktails_Scroll_Area->sizePolicy().hasHeightForWidth());
        Cocktails_Scroll_Area->setSizePolicy(sizePolicy);
        Cocktails_Scroll_Area->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        Cocktails_Scroll_Area->setWidgetResizable(true);
        Cocktails_Scroll_Area->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Cocktails_Scroll_Area_Content = new QWidget();
        Cocktails_Scroll_Area_Content->setObjectName(QString::fromUtf8("Cocktails_Scroll_Area_Content"));
        Cocktails_Scroll_Area_Content->setGeometry(QRect(0, 0, 641, 484));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Cocktails_Scroll_Area_Content->sizePolicy().hasHeightForWidth());
        Cocktails_Scroll_Area_Content->setSizePolicy(sizePolicy1);
        Cocktails_Scroll_Area->setWidget(Cocktails_Scroll_Area_Content);

        Main_Layout->addWidget(Cocktails_Scroll_Area, 2, 0, 1, 1);

        F_Main->setCentralWidget(Main_Widget);

        retranslateUi(F_Main);

        QMetaObject::connectSlotsByName(F_Main);
    } // setupUi

    void retranslateUi(QMainWindow *F_Main)
    {
        F_Main->setWindowTitle(QCoreApplication::translate("F_Main", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200 \320\272\320\276\320\272\321\202\320\265\320\271\320\273\320\265\320\271", nullptr));
        Add_Ingredient_Button->setText(QString());
        Cocktails_Label->setText(QCoreApplication::translate("F_Main", "\320\232\320\276\320\272\321\202\320\265\320\271\320\273\320\270", nullptr));
        Add_Cocktail_Button->setText(QString());
        Ingredients_Label->setText(QCoreApplication::translate("F_Main", "\320\230\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_Main: public Ui_F_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MAIN_H
