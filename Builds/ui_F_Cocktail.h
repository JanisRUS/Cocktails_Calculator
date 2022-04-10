/********************************************************************************
** Form generated from reading UI file 'F_Cocktail.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_COCKTAIL_H
#define UI_F_COCKTAIL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_F_Cocktail
{
public:
    QHBoxLayout *F_Cocktail_Layout;
    QFrame *Cocktail_Frame;
    QHBoxLayout *Cocktail_Layout;
    QWidget *Cocktail_Info_Widget;
    QVBoxLayout *Cocktail_Info_Layout;
    QHBoxLayout *Name_Layout;
    QLabel *Name_Label;
    QLineEdit *Name_TBox;
    QSpacerItem *Name_Spacer;
    QHBoxLayout *Volume_Layout;
    QLabel *Volume_Label;
    QLabel *Volume_TBox;
    QSpacerItem *Volume_Spacer;
    QHBoxLayout *Price_Layout;
    QLabel *Price_Label;
    QLabel *Price_TBox;
    QSpacerItem *Price_Spacer;
    QHBoxLayout *Alcohol_Layout;
    QLabel *Alcohol_Label;
    QLabel *Alcohol_TBox;
    QSpacerItem *Alcohol_Spacer;
    QHBoxLayout *Buttons_Layout;
    QPushButton *Accept_Button;
    QPushButton *Delete_Button;
    QPushButton *Add_Ingredient_Button;
    QSpacerItem *Buttons_Spacer;
    QHBoxLayout *Ingredients_Layout;

    void setupUi(QWidget *F_Cocktail)
    {
        if (F_Cocktail->objectName().isEmpty())
            F_Cocktail->setObjectName(QString::fromUtf8("F_Cocktail"));
        F_Cocktail->resize(330, 230);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(F_Cocktail->sizePolicy().hasHeightForWidth());
        F_Cocktail->setSizePolicy(sizePolicy);
        F_Cocktail->setMinimumSize(QSize(330, 230));
        F_Cocktail->setMaximumSize(QSize(16777215, 230));
        QFont font;
        font.setPointSize(12);
        F_Cocktail->setFont(font);
        F_Cocktail_Layout = new QHBoxLayout(F_Cocktail);
        F_Cocktail_Layout->setSpacing(0);
        F_Cocktail_Layout->setObjectName(QString::fromUtf8("F_Cocktail_Layout"));
        F_Cocktail_Layout->setContentsMargins(0, 0, 0, 0);
        Cocktail_Frame = new QFrame(F_Cocktail);
        Cocktail_Frame->setObjectName(QString::fromUtf8("Cocktail_Frame"));
        sizePolicy.setHeightForWidth(Cocktail_Frame->sizePolicy().hasHeightForWidth());
        Cocktail_Frame->setSizePolicy(sizePolicy);
        Cocktail_Frame->setMinimumSize(QSize(330, 230));
        Cocktail_Frame->setMaximumSize(QSize(16777215, 230));
        Cocktail_Frame->setFrameShape(QFrame::StyledPanel);
        Cocktail_Frame->setFrameShadow(QFrame::Sunken);
        Cocktail_Frame->setLineWidth(1);
        Cocktail_Layout = new QHBoxLayout(Cocktail_Frame);
        Cocktail_Layout->setSpacing(0);
        Cocktail_Layout->setObjectName(QString::fromUtf8("Cocktail_Layout"));
        Cocktail_Layout->setContentsMargins(0, 0, 0, 0);
        Cocktail_Info_Widget = new QWidget(Cocktail_Frame);
        Cocktail_Info_Widget->setObjectName(QString::fromUtf8("Cocktail_Info_Widget"));
        Cocktail_Info_Widget->setMinimumSize(QSize(320, 205));
        Cocktail_Info_Widget->setMaximumSize(QSize(320, 205));
        Cocktail_Info_Layout = new QVBoxLayout(Cocktail_Info_Widget);
        Cocktail_Info_Layout->setObjectName(QString::fromUtf8("Cocktail_Info_Layout"));
        Cocktail_Info_Layout->setSizeConstraint(QLayout::SetFixedSize);
        Cocktail_Info_Layout->setContentsMargins(0, 0, 0, 0);
        Name_Layout = new QHBoxLayout();
        Name_Layout->setSpacing(6);
        Name_Layout->setObjectName(QString::fromUtf8("Name_Layout"));
        Name_Layout->setSizeConstraint(QLayout::SetFixedSize);
        Name_Label = new QLabel(Cocktail_Info_Widget);
        Name_Label->setObjectName(QString::fromUtf8("Name_Label"));
        Name_Label->setMinimumSize(QSize(100, 30));
        Name_Label->setMaximumSize(QSize(100, 30));

        Name_Layout->addWidget(Name_Label);

        Name_TBox = new QLineEdit(Cocktail_Info_Widget);
        Name_TBox->setObjectName(QString::fromUtf8("Name_TBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Name_TBox->sizePolicy().hasHeightForWidth());
        Name_TBox->setSizePolicy(sizePolicy1);
        Name_TBox->setMinimumSize(QSize(200, 30));
        Name_TBox->setMaximumSize(QSize(200, 30));
        Name_TBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Name_Layout->addWidget(Name_TBox);

        Name_Spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Name_Layout->addItem(Name_Spacer);


        Cocktail_Info_Layout->addLayout(Name_Layout);

        Volume_Layout = new QHBoxLayout();
        Volume_Layout->setObjectName(QString::fromUtf8("Volume_Layout"));
        Volume_Layout->setSizeConstraint(QLayout::SetFixedSize);
        Volume_Label = new QLabel(Cocktail_Info_Widget);
        Volume_Label->setObjectName(QString::fromUtf8("Volume_Label"));
        Volume_Label->setMinimumSize(QSize(100, 30));
        Volume_Label->setMaximumSize(QSize(100, 30));

        Volume_Layout->addWidget(Volume_Label);

        Volume_TBox = new QLabel(Cocktail_Info_Widget);
        Volume_TBox->setObjectName(QString::fromUtf8("Volume_TBox"));
        Volume_TBox->setAlignment(Qt::AlignCenter);

        Volume_Layout->addWidget(Volume_TBox);

        Volume_Spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Volume_Layout->addItem(Volume_Spacer);


        Cocktail_Info_Layout->addLayout(Volume_Layout);

        Price_Layout = new QHBoxLayout();
        Price_Layout->setObjectName(QString::fromUtf8("Price_Layout"));
        Price_Layout->setSizeConstraint(QLayout::SetFixedSize);
        Price_Label = new QLabel(Cocktail_Info_Widget);
        Price_Label->setObjectName(QString::fromUtf8("Price_Label"));
        Price_Label->setMinimumSize(QSize(100, 30));
        Price_Label->setMaximumSize(QSize(100, 30));
        Price_Label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        Price_Layout->addWidget(Price_Label, 0, Qt::AlignLeft);

        Price_TBox = new QLabel(Cocktail_Info_Widget);
        Price_TBox->setObjectName(QString::fromUtf8("Price_TBox"));
        Price_TBox->setMinimumSize(QSize(0, 30));
        Price_TBox->setMaximumSize(QSize(16777215, 30));
        Price_TBox->setAlignment(Qt::AlignCenter);

        Price_Layout->addWidget(Price_TBox, 0, Qt::AlignLeft);

        Price_Spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Price_Layout->addItem(Price_Spacer);


        Cocktail_Info_Layout->addLayout(Price_Layout);

        Alcohol_Layout = new QHBoxLayout();
        Alcohol_Layout->setObjectName(QString::fromUtf8("Alcohol_Layout"));
        Alcohol_Layout->setSizeConstraint(QLayout::SetFixedSize);
        Alcohol_Label = new QLabel(Cocktail_Info_Widget);
        Alcohol_Label->setObjectName(QString::fromUtf8("Alcohol_Label"));
        Alcohol_Label->setMinimumSize(QSize(100, 30));
        Alcohol_Label->setMaximumSize(QSize(100, 30));

        Alcohol_Layout->addWidget(Alcohol_Label, 0, Qt::AlignLeft);

        Alcohol_TBox = new QLabel(Cocktail_Info_Widget);
        Alcohol_TBox->setObjectName(QString::fromUtf8("Alcohol_TBox"));
        Alcohol_TBox->setMinimumSize(QSize(0, 30));
        Alcohol_TBox->setMaximumSize(QSize(16777215, 30));
        Alcohol_TBox->setAlignment(Qt::AlignCenter);

        Alcohol_Layout->addWidget(Alcohol_TBox, 0, Qt::AlignLeft);

        Alcohol_Spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Alcohol_Layout->addItem(Alcohol_Spacer);


        Cocktail_Info_Layout->addLayout(Alcohol_Layout);

        Buttons_Layout = new QHBoxLayout();
        Buttons_Layout->setObjectName(QString::fromUtf8("Buttons_Layout"));
        Buttons_Layout->setSizeConstraint(QLayout::SetFixedSize);
        Accept_Button = new QPushButton(Cocktail_Info_Widget);
        Accept_Button->setObjectName(QString::fromUtf8("Accept_Button"));
        Accept_Button->setEnabled(false);
        Accept_Button->setMinimumSize(QSize(50, 50));
        Accept_Button->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Icons/Accept_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Accept_Button->setIcon(icon);
        Accept_Button->setIconSize(QSize(50, 50));
        Accept_Button->setFlat(true);

        Buttons_Layout->addWidget(Accept_Button);

        Delete_Button = new QPushButton(Cocktail_Info_Widget);
        Delete_Button->setObjectName(QString::fromUtf8("Delete_Button"));
        Delete_Button->setMinimumSize(QSize(50, 50));
        Delete_Button->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/Icons/Delete_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Delete_Button->setIcon(icon1);
        Delete_Button->setIconSize(QSize(50, 50));
        Delete_Button->setFlat(true);

        Buttons_Layout->addWidget(Delete_Button);

        Add_Ingredient_Button = new QPushButton(Cocktail_Info_Widget);
        Add_Ingredient_Button->setObjectName(QString::fromUtf8("Add_Ingredient_Button"));
        Add_Ingredient_Button->setMinimumSize(QSize(50, 50));
        Add_Ingredient_Button->setMaximumSize(QSize(50, 50));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/Icons/Add_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Add_Ingredient_Button->setIcon(icon2);
        Add_Ingredient_Button->setIconSize(QSize(50, 50));
        Add_Ingredient_Button->setFlat(true);

        Buttons_Layout->addWidget(Add_Ingredient_Button);

        Buttons_Spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Buttons_Layout->addItem(Buttons_Spacer);


        Cocktail_Info_Layout->addLayout(Buttons_Layout);


        Cocktail_Layout->addWidget(Cocktail_Info_Widget, 0, Qt::AlignLeft);

        Ingredients_Layout = new QHBoxLayout();
        Ingredients_Layout->setSpacing(0);
        Ingredients_Layout->setObjectName(QString::fromUtf8("Ingredients_Layout"));
        Ingredients_Layout->setSizeConstraint(QLayout::SetDefaultConstraint);

        Cocktail_Layout->addLayout(Ingredients_Layout);


        F_Cocktail_Layout->addWidget(Cocktail_Frame, 0, Qt::AlignLeft|Qt::AlignTop);


        retranslateUi(F_Cocktail);

        QMetaObject::connectSlotsByName(F_Cocktail);
    } // setupUi

    void retranslateUi(QWidget *F_Cocktail)
    {
        F_Cocktail->setWindowTitle(QCoreApplication::translate("F_Cocktail", "Form", nullptr));
        Name_Label->setText(QCoreApplication::translate("F_Cocktail", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        Name_TBox->setText(QString());
        Volume_Label->setText(QCoreApplication::translate("F_Cocktail", "\320\236\320\261\321\212\320\265\320\274:", nullptr));
        Volume_TBox->setText(QCoreApplication::translate("F_Cocktail", "0", nullptr));
        Price_Label->setText(QCoreApplication::translate("F_Cocktail", "\320\246\320\265\320\275\320\260:", nullptr));
        Price_TBox->setText(QCoreApplication::translate("F_Cocktail", "0", nullptr));
        Alcohol_Label->setText(QCoreApplication::translate("F_Cocktail", "\320\232\321\200\320\265\320\277\320\276\321\201\321\202\321\214 (%):", nullptr));
        Alcohol_TBox->setText(QCoreApplication::translate("F_Cocktail", "0", nullptr));
        Accept_Button->setText(QString());
        Delete_Button->setText(QString());
        Add_Ingredient_Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class F_Cocktail: public Ui_F_Cocktail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_COCKTAIL_H
