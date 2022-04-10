/********************************************************************************
** Form generated from reading UI file 'F_Ingredient_DB.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_INGREDIENT_DB_H
#define UI_F_INGREDIENT_DB_H

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

class Ui_F_Ingredient_DB
{
public:
    QVBoxLayout *F_Ingredient_DB_Layout;
    QFrame *Ingredient_Frame;
    QVBoxLayout *Ingredient_Layout;
    QHBoxLayout *Name_Layout;
    QLabel *Name_Label;
    QLineEdit *Name_TBox;
    QHBoxLayout *Volume_Layout;
    QLabel *Volume_Label;
    QLineEdit *Volume_TBox;
    QHBoxLayout *Price_Layout;
    QLabel *Price_Label;
    QLineEdit *Price_TBox;
    QHBoxLayout *Alcohol_Layout;
    QLabel *Alcohol_Label;
    QLineEdit *Alcohol_TBox;
    QHBoxLayout *Delete_Layout;
    QPushButton *Delete_Button;
    QPushButton *Accept_Button;

    void setupUi(QWidget *F_Ingredient_DB)
    {
        if (F_Ingredient_DB->objectName().isEmpty())
            F_Ingredient_DB->setObjectName(QString::fromUtf8("F_Ingredient_DB"));
        F_Ingredient_DB->resize(296, 243);
        F_Ingredient_DB->setMinimumSize(QSize(296, 243));
        F_Ingredient_DB->setMaximumSize(QSize(296, 243));
        QFont font;
        font.setPointSize(12);
        F_Ingredient_DB->setFont(font);
        F_Ingredient_DB->setAutoFillBackground(false);
        F_Ingredient_DB_Layout = new QVBoxLayout(F_Ingredient_DB);
        F_Ingredient_DB_Layout->setObjectName(QString::fromUtf8("F_Ingredient_DB_Layout"));
        Ingredient_Frame = new QFrame(F_Ingredient_DB);
        Ingredient_Frame->setObjectName(QString::fromUtf8("Ingredient_Frame"));
        Ingredient_Frame->setMinimumSize(QSize(278, 225));
        Ingredient_Frame->setMaximumSize(QSize(278, 225));
        Ingredient_Frame->setFrameShape(QFrame::StyledPanel);
        Ingredient_Frame->setFrameShadow(QFrame::Sunken);
        Ingredient_Frame->setLineWidth(1);
        Ingredient_Frame->setMidLineWidth(0);
        Ingredient_Layout = new QVBoxLayout(Ingredient_Frame);
        Ingredient_Layout->setObjectName(QString::fromUtf8("Ingredient_Layout"));
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
        Volume_TBox->setStyleSheet(QString::fromUtf8(""));
        Volume_TBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Volume_Layout->addWidget(Volume_TBox);


        Ingredient_Layout->addLayout(Volume_Layout);

        Price_Layout = new QHBoxLayout();
        Price_Layout->setObjectName(QString::fromUtf8("Price_Layout"));
        Price_Label = new QLabel(Ingredient_Frame);
        Price_Label->setObjectName(QString::fromUtf8("Price_Label"));
        Price_Label->setMinimumSize(QSize(100, 30));
        Price_Label->setMaximumSize(QSize(100, 30));

        Price_Layout->addWidget(Price_Label);

        Price_TBox = new QLineEdit(Ingredient_Frame);
        Price_TBox->setObjectName(QString::fromUtf8("Price_TBox"));
        Price_TBox->setMinimumSize(QSize(150, 30));
        Price_TBox->setMaximumSize(QSize(150, 30));
        Price_TBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Price_Layout->addWidget(Price_TBox);


        Ingredient_Layout->addLayout(Price_Layout);

        Alcohol_Layout = new QHBoxLayout();
        Alcohol_Layout->setObjectName(QString::fromUtf8("Alcohol_Layout"));
        Alcohol_Label = new QLabel(Ingredient_Frame);
        Alcohol_Label->setObjectName(QString::fromUtf8("Alcohol_Label"));
        Alcohol_Label->setMinimumSize(QSize(100, 30));
        Alcohol_Label->setMaximumSize(QSize(100, 30));

        Alcohol_Layout->addWidget(Alcohol_Label);

        Alcohol_TBox = new QLineEdit(Ingredient_Frame);
        Alcohol_TBox->setObjectName(QString::fromUtf8("Alcohol_TBox"));
        Alcohol_TBox->setMinimumSize(QSize(150, 30));
        Alcohol_TBox->setMaximumSize(QSize(150, 30));
        Alcohol_TBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Alcohol_Layout->addWidget(Alcohol_TBox);


        Ingredient_Layout->addLayout(Alcohol_Layout);

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

        Accept_Button = new QPushButton(Ingredient_Frame);
        Accept_Button->setObjectName(QString::fromUtf8("Accept_Button"));
        Accept_Button->setEnabled(false);
        Accept_Button->setMinimumSize(QSize(50, 50));
        Accept_Button->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/Icons/Accept_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Accept_Button->setIcon(icon1);
        Accept_Button->setIconSize(QSize(50, 50));
        Accept_Button->setFlat(true);

        Delete_Layout->addWidget(Accept_Button);


        Ingredient_Layout->addLayout(Delete_Layout);


        F_Ingredient_DB_Layout->addWidget(Ingredient_Frame, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        retranslateUi(F_Ingredient_DB);

        QMetaObject::connectSlotsByName(F_Ingredient_DB);
    } // setupUi

    void retranslateUi(QWidget *F_Ingredient_DB)
    {
        F_Ingredient_DB->setWindowTitle(QCoreApplication::translate("F_Ingredient_DB", "Form", nullptr));
        Name_Label->setText(QCoreApplication::translate("F_Ingredient_DB", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        Name_TBox->setText(QString());
        Volume_Label->setText(QCoreApplication::translate("F_Ingredient_DB", "\320\236\320\261\321\212\320\265\320\274 (\320\274\320\273)", nullptr));
        Volume_TBox->setText(QString());
        Price_Label->setText(QCoreApplication::translate("F_Ingredient_DB", "\320\246\320\265\320\275\320\260", nullptr));
        Alcohol_Label->setText(QCoreApplication::translate("F_Ingredient_DB", "\320\220\320\273\320\272\320\276\320\263\320\276\320\273\321\214 (%)", nullptr));
        Delete_Button->setText(QString());
        Accept_Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class F_Ingredient_DB: public Ui_F_Ingredient_DB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_INGREDIENT_DB_H
