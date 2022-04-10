/********************************************************************************
** Form generated from reading UI file 'F_Ingredient.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_INGREDIENT_H
#define UI_F_INGREDIENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_F_Ingredient
{
public:
    QVBoxLayout *F_Ingredient_Layout;
    QFrame *Ingredient_Frame;
    QVBoxLayout *Ingredient_Layout;
    QHBoxLayout *Name_Layout;
    QLabel *Name_Label;
    QLineEdit *Name_TBox;
    QHBoxLayout *Volume_Layout;
    QLabel *Volume_Label;
    QLineEdit *Volume_TBox;
    QHBoxLayout *Delete_Layout;
    QPushButton *Delete_Button;

    void setupUi(QWidget *F_Ingredient)
    {
        if (F_Ingredient->objectName().isEmpty())
            F_Ingredient->setObjectName(QString::fromUtf8("F_Ingredient"));
        F_Ingredient->resize(296, 168);
        F_Ingredient->setMinimumSize(QSize(296, 168));
        F_Ingredient->setMaximumSize(QSize(296, 168));
        QFont font;
        font.setPointSize(12);
        F_Ingredient->setFont(font);
        F_Ingredient_Layout = new QVBoxLayout(F_Ingredient);
        F_Ingredient_Layout->setSpacing(9);
        F_Ingredient_Layout->setObjectName(QString::fromUtf8("F_Ingredient_Layout"));
        F_Ingredient_Layout->setContentsMargins(9, 9, 9, 9);
        Ingredient_Frame = new QFrame(F_Ingredient);
        Ingredient_Frame->setObjectName(QString::fromUtf8("Ingredient_Frame"));
        Ingredient_Frame->setMinimumSize(QSize(278, 150));
        Ingredient_Frame->setMaximumSize(QSize(278, 150));
        Ingredient_Frame->setFrameShape(QFrame::StyledPanel);
        Ingredient_Frame->setFrameShadow(QFrame::Sunken);
        Ingredient_Layout = new QVBoxLayout(Ingredient_Frame);
        Ingredient_Layout->setSpacing(6);
        Ingredient_Layout->setObjectName(QString::fromUtf8("Ingredient_Layout"));
        Ingredient_Layout->setContentsMargins(0, 0, 0, 0);
        Name_Layout = new QHBoxLayout();
        Name_Layout->setObjectName(QString::fromUtf8("Name_Layout"));
        Name_Label = new QLabel(Ingredient_Frame);
        Name_Label->setObjectName(QString::fromUtf8("Name_Label"));
        Name_Label->setMinimumSize(QSize(100, 30));
        Name_Label->setMaximumSize(QSize(100, 30));

        Name_Layout->addWidget(Name_Label);

        Name_TBox = new QLineEdit(Ingredient_Frame);
        Name_TBox->setObjectName(QString::fromUtf8("Name_TBox"));
        Name_TBox->setMinimumSize(QSize(150, 30));
        Name_TBox->setMaximumSize(QSize(150, 30));
        Name_TBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Name_Layout->addWidget(Name_TBox);


        Ingredient_Layout->addLayout(Name_Layout);

        Volume_Layout = new QHBoxLayout();
        Volume_Layout->setObjectName(QString::fromUtf8("Volume_Layout"));
        Volume_Label = new QLabel(Ingredient_Frame);
        Volume_Label->setObjectName(QString::fromUtf8("Volume_Label"));
        Volume_Label->setMinimumSize(QSize(100, 30));
        Volume_Label->setMaximumSize(QSize(100, 30));

        Volume_Layout->addWidget(Volume_Label);

        Volume_TBox = new QLineEdit(Ingredient_Frame);
        Volume_TBox->setObjectName(QString::fromUtf8("Volume_TBox"));
        Volume_TBox->setMinimumSize(QSize(150, 30));
        Volume_TBox->setMaximumSize(QSize(150, 30));
        Volume_TBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Volume_Layout->addWidget(Volume_TBox);


        Ingredient_Layout->addLayout(Volume_Layout);

        Delete_Layout = new QHBoxLayout();
        Delete_Layout->setObjectName(QString::fromUtf8("Delete_Layout"));
        Delete_Button = new QPushButton(Ingredient_Frame);
        Delete_Button->setObjectName(QString::fromUtf8("Delete_Button"));
        Delete_Button->setMinimumSize(QSize(50, 50));
        Delete_Button->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Icons/Delete_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Delete_Button->setIcon(icon);
        Delete_Button->setIconSize(QSize(50, 50));
        Delete_Button->setFlat(true);

        Delete_Layout->addWidget(Delete_Button);


        Ingredient_Layout->addLayout(Delete_Layout);


        F_Ingredient_Layout->addWidget(Ingredient_Frame, 0, Qt::AlignLeft|Qt::AlignTop);


        retranslateUi(F_Ingredient);

        QMetaObject::connectSlotsByName(F_Ingredient);
    } // setupUi

    void retranslateUi(QWidget *F_Ingredient)
    {
        F_Ingredient->setWindowTitle(QCoreApplication::translate("F_Ingredient", "Form", nullptr));
        Name_Label->setText(QCoreApplication::translate("F_Ingredient", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        Volume_Label->setText(QCoreApplication::translate("F_Ingredient", "\320\236\320\261\321\212\320\265\320\274 (\320\274\320\273)", nullptr));
        Delete_Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class F_Ingredient: public Ui_F_Ingredient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_INGREDIENT_H
