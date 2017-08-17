/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVTKWidget *vtkRenderer;
    QPushButton *btnOpenDCMFolder;
    QSlider *hSliderDCM;
    QPushButton *btnRotateFile;
    QVTKWidget *rotateRenderer;
    QPushButton *btnOpenImage;
    QPushButton *btnRotateDCM;
    QLabel *label;
    QTextEdit *num_slices_edit;
    QTextEdit *num_grados_edit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *num_total_slices;
    QPushButton *btnExportImage;
    QLabel *label_4;
    QPushButton *btnMoveFile;
    QPlainTextEdit *move_x;
    QPlainTextEdit *move_y;
    QPlainTextEdit *move_z;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1157, 559);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        vtkRenderer = new QVTKWidget(centralWidget);
        vtkRenderer->setObjectName(QStringLiteral("vtkRenderer"));
        vtkRenderer->setGeometry(QRect(0, 0, 511, 411));
        btnOpenDCMFolder = new QPushButton(centralWidget);
        btnOpenDCMFolder->setObjectName(QStringLiteral("btnOpenDCMFolder"));
        btnOpenDCMFolder->setGeometry(QRect(10, 460, 121, 24));
        hSliderDCM = new QSlider(centralWidget);
        hSliderDCM->setObjectName(QStringLiteral("hSliderDCM"));
        hSliderDCM->setGeometry(QRect(140, 460, 381, 23));
        hSliderDCM->setOrientation(Qt::Horizontal);
        btnRotateFile = new QPushButton(centralWidget);
        btnRotateFile->setObjectName(QStringLiteral("btnRotateFile"));
        btnRotateFile->setGeometry(QRect(890, 430, 121, 27));
        rotateRenderer = new QVTKWidget(centralWidget);
        rotateRenderer->setObjectName(QStringLiteral("rotateRenderer"));
        rotateRenderer->setGeometry(QRect(590, 0, 531, 411));
        btnOpenImage = new QPushButton(centralWidget);
        btnOpenImage->setObjectName(QStringLiteral("btnOpenImage"));
        btnOpenImage->setGeometry(QRect(10, 420, 121, 27));
        btnRotateDCM = new QPushButton(centralWidget);
        btnRotateDCM->setObjectName(QStringLiteral("btnRotateDCM"));
        btnRotateDCM->setGeometry(QRect(890, 460, 121, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 490, 141, 17));
        num_slices_edit = new QTextEdit(centralWidget);
        num_slices_edit->setObjectName(QStringLiteral("num_slices_edit"));
        num_slices_edit->setGeometry(QRect(320, 490, 61, 21));
        num_grados_edit = new QTextEdit(centralWidget);
        num_grados_edit->setObjectName(QStringLiteral("num_grados_edit"));
        num_grados_edit->setGeometry(QRect(710, 430, 61, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 430, 101, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(780, 430, 55, 17));
        num_total_slices = new QLabel(centralWidget);
        num_total_slices->setObjectName(QStringLiteral("num_total_slices"));
        num_total_slices->setGeometry(QRect(390, 490, 51, 17));
        btnExportImage = new QPushButton(centralWidget);
        btnExportImage->setObjectName(QStringLiteral("btnExportImage"));
        btnExportImage->setGeometry(QRect(1030, 430, 111, 27));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(600, 530, 121, 17));
        btnMoveFile = new QPushButton(centralWidget);
        btnMoveFile->setObjectName(QStringLiteral("btnMoveFile"));
        btnMoveFile->setGeometry(QRect(890, 520, 121, 27));
        move_x = new QPlainTextEdit(centralWidget);
        move_x->setObjectName(QStringLiteral("move_x"));
        move_x->setGeometry(QRect(710, 520, 41, 21));
        move_y = new QPlainTextEdit(centralWidget);
        move_y->setObjectName(QStringLiteral("move_y"));
        move_y->setGeometry(QRect(760, 520, 41, 21));
        move_z = new QPlainTextEdit(centralWidget);
        move_z->setObjectName(QStringLiteral("move_z"));
        move_z->setGeometry(QRect(810, 520, 41, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(720, 540, 16, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(770, 540, 16, 17));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(820, 540, 16, 17));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnOpenDCMFolder->setText(QApplication::translate("MainWindow", "Importar DCM ", 0));
        btnRotateFile->setText(QApplication::translate("MainWindow", "Rotar Imagen", 0));
        btnOpenImage->setText(QApplication::translate("MainWindow", "Importar Imagen", 0));
        btnRotateDCM->setText(QApplication::translate("MainWindow", "Rotar DCM", 0));
        label->setText(QApplication::translate("MainWindow", "Numero de Slice Actual:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Rotar la imagen", 0));
        label_3->setText(QApplication::translate("MainWindow", "grados", 0));
        num_total_slices->setText(QString());
        btnExportImage->setText(QApplication::translate("MainWindow", "Exportar Imagen", 0));
        label_4->setText(QApplication::translate("MainWindow", "Mover Imagen:", 0));
        btnMoveFile->setText(QApplication::translate("MainWindow", "Move File", 0));
        label_5->setText(QApplication::translate("MainWindow", "X", 0));
        label_6->setText(QApplication::translate("MainWindow", "Y", 0));
        label_7->setText(QApplication::translate("MainWindow", "Z", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
