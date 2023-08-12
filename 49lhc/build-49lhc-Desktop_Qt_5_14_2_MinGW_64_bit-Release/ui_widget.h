/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTextBrowser *his;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *buy;
    QLabel *label;
    QLineEdit *code;
    QLabel *label_2;
    QLineEdit *money;
    QPushButton *puchase;
    QPushButton *rand;
    QLineEdit *lineEdit_a;
    QLineEdit *lineEdit_b;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QTextBrowser *show;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QTextBrowser *income;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *dead;
    QLabel *label_4;
    QSpinBox *killline;
    QPushButton *killcomfirm;
    QLabel *label_8;
    QLabel *label_10;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *commend;
    QLabel *label_9;
    QTextBrowser *recommendnumber;
    QLabel *label_5;
    QTextBrowser *killb;
    QTextBrowser *redetail;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1128, 530);
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(320, 10, 171, 511));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        his = new QTextBrowser(verticalLayoutWidget);
        his->setObjectName(QString::fromUtf8("his"));

        verticalLayout_3->addWidget(his);

        horizontalLayoutWidget_2 = new QWidget(Widget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 311, 91));
        buy = new QHBoxLayout(horizontalLayoutWidget_2);
        buy->setObjectName(QString::fromUtf8("buy"));
        buy->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        buy->addWidget(label);

        code = new QLineEdit(horizontalLayoutWidget_2);
        code->setObjectName(QString::fromUtf8("code"));

        buy->addWidget(code);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        buy->addWidget(label_2);

        money = new QLineEdit(horizontalLayoutWidget_2);
        money->setObjectName(QString::fromUtf8("money"));

        buy->addWidget(money);

        puchase = new QPushButton(horizontalLayoutWidget_2);
        puchase->setObjectName(QString::fromUtf8("puchase"));

        buy->addWidget(puchase);

        rand = new QPushButton(Widget);
        rand->setObjectName(QString::fromUtf8("rand"));
        rand->setGeometry(QRect(30, 250, 75, 23));
        lineEdit_a = new QLineEdit(Widget);
        lineEdit_a->setObjectName(QString::fromUtf8("lineEdit_a"));
        lineEdit_a->setGeometry(QRect(120, 250, 41, 21));
        lineEdit_b = new QLineEdit(Widget);
        lineEdit_b->setObjectName(QString::fromUtf8("lineEdit_b"));
        lineEdit_b->setGeometry(QRect(190, 250, 51, 21));
        verticalLayoutWidget_2 = new QWidget(Widget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(500, 10, 161, 511));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        show = new QTextBrowser(verticalLayoutWidget_2);
        show->setObjectName(QString::fromUtf8("show"));

        verticalLayout->addWidget(show);

        verticalLayoutWidget_3 = new QWidget(Widget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(670, 10, 451, 511));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        income = new QTextBrowser(verticalLayoutWidget_3);
        income->setObjectName(QString::fromUtf8("income"));

        verticalLayout_2->addWidget(income);

        verticalLayoutWidget_4 = new QWidget(Widget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 110, 308, 121));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        dead = new QHBoxLayout();
        dead->setObjectName(QString::fromUtf8("dead"));
        label_4 = new QLabel(verticalLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        dead->addWidget(label_4);

        killline = new QSpinBox(verticalLayoutWidget_4);
        killline->setObjectName(QString::fromUtf8("killline"));
        killline->setMaximum(1000000);

        dead->addWidget(killline);

        killcomfirm = new QPushButton(verticalLayoutWidget_4);
        killcomfirm->setObjectName(QString::fromUtf8("killcomfirm"));

        dead->addWidget(killcomfirm);


        verticalLayout_4->addLayout(dead);

        label_8 = new QLabel(verticalLayoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_10 = new QLabel(verticalLayoutWidget_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);

        verticalLayoutWidget_5 = new QWidget(Widget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(20, 290, 290, 152));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        commend = new QHBoxLayout();
        commend->setObjectName(QString::fromUtf8("commend"));
        label_9 = new QLabel(verticalLayoutWidget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        commend->addWidget(label_9);

        recommendnumber = new QTextBrowser(verticalLayoutWidget_5);
        recommendnumber->setObjectName(QString::fromUtf8("recommendnumber"));

        commend->addWidget(recommendnumber);

        label_5 = new QLabel(verticalLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        commend->addWidget(label_5);

        killb = new QTextBrowser(verticalLayoutWidget_5);
        killb->setObjectName(QString::fromUtf8("killb"));

        commend->addWidget(killb);


        verticalLayout_5->addLayout(commend);

        redetail = new QTextBrowser(verticalLayoutWidget_5);
        redetail->setObjectName(QString::fromUtf8("redetail"));

        verticalLayout_5->addWidget(redetail);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\272\244\346\230\223\345\216\206\345\217\262", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\217\267\347\240\201\357\274\232", nullptr));
        code->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\351\207\221\351\242\235\357\274\232", nullptr));
        money->setText(QCoreApplication::translate("Widget", "0", nullptr));
        puchase->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244\350\264\255\344\271\260", nullptr));
        rand->setText(QCoreApplication::translate("Widget", "\351\232\217\346\234\272\346\250\241\346\213\237", nullptr));
        lineEdit_a->setText(QCoreApplication::translate("Widget", "1", nullptr));
        lineEdit_b->setText(QCoreApplication::translate("Widget", "999", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\345\261\225\347\244\272", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\346\224\266\347\233\212\347\273\237\350\256\241", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\346\226\251\346\235\200\347\272\277\357\274\232", nullptr));
        killcomfirm->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\347\202\271\345\207\273\347\241\256\350\256\244\345\220\216\344\275\216\344\272\216\346\226\251\346\235\200\347\272\277\347\232\204\346\225\260\346\215\256\345\260\206\345\234\250\345\261\225\347\244\272\345\222\214\345\233\276\346\240\207\344\270\255\346\230\276\347\244\2720", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "\344\275\206\346\230\257\347\234\237\345\256\236\346\225\260\346\215\256\344\270\215\346\224\271\345\217\230", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\346\216\250\350\215\220\344\270\255\345\245\226\344\272\272:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\345\257\271\345\272\224\351\207\221\351\242\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
