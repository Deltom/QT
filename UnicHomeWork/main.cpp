#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QCheckBox>
#include <QDebug>
#include <QLineEdit>
#include <iostream>
#include <QLabel>
#include <string>

double convertRubInto(double count, bool rub, bool efr, bool dol, bool ten, bool fun)   //Функция конвертации из рубля
{
    if(rub == 1){
        return count;
    }
    if(efr == 1){
        return count * 0.0116;
    }
    if(dol == 1){
        return count * 0.0125;
    }
    if(ten == 1){
        return count * 5.6185;
    }
    if(fun == 1){
        return count * 0.01;
    }
    return 0;
}

double convertEfroInto(double count, bool rub, bool efr, bool dol, bool ten, bool fun)  //Функция конвертации из Евро
{
    if(rub == 1){
        return count * 86.4964;
    }
    if(efr == 1){
        return count;
    }
    if(dol == 1){
        return count * 1.0807;
    }
    if(ten == 1){
        return count * 485.9842;
    }
    if(fun == 1){
        return count * 0.9369;
    }
    return 0;
}

double convertDolInto(double count, bool rub, bool efr, bool dol, bool ten, bool fun)   //Функция конвертации из Долара
{
    if(rub == 1){
        return count * 80.0366;
    }
    if(efr == 1){
        return count * 0.9253;
    }
    if(dol == 1){
        return count;
    }
    if(ten == 1){
        return count * 449.6888;
    }
    if(fun == 1){
        return count * 0.8022;
    }
    return 0;
}

double convertTenInto(double count, bool rub, bool efr, bool dol, bool ten, bool fun)   //Функция конвертации из Тенге
{
    if(rub == 1){
        return count * 0.178;
    }
    if(efr == 1){
        return count * 0.0021;
    }
    if(dol == 1){
        return count * 0.0022;
    }
    if(ten == 1){
        return count;
    }
    if(fun == 1){
        return count * 0.0018;
    }
    return 0;
}

double convertFuntInto(double count, bool rub, bool efr, bool dol, bool ten, bool fun)  //Функция конвертации из Фунта
{
    if(rub == 1){
        return count * 99.7736;
    }
    if(efr == 1){
        return count * 1.1535;
    }
    if(dol == 1){
        return count * 1.2466;
    }
    if(ten == 1){
        return count * 560.5821;
    }
    if(fun == 1){
        return count;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget      wgt;

    wgt.setWindowTitle("Ногин М.О. ИВТ1-Б22 QT-GI-19");

    QPushButton closeButton("Exit", &wgt);
    QObject::connect(&closeButton, &QPushButton::clicked, &a, &QApplication::quit);     //Кнопка выхода

    QPushButton inputbutton("Input", &wgt);
    inputbutton.move(100, 0);

    QPushButton calkbutton("Calk", &wgt);
    calkbutton.move(540, 0);

    QLabel outPanel(&wgt);
    outPanel.move(205, 0);

    double number;
    bool isChecked1, isChecked2, isChecked3, isChecked4, isChecked5, isChecked6, isChecked7, isChecked8, isChecked9, isChecked10;

    QObject::connect(&inputbutton, &QPushButton::clicked, [&](){        //Обработка нажатия и открытие диалогового окна
        QDialog dialog(&wgt);
                dialog.setWindowTitle("Конвертатор");

                QGridLayout layout(&dialog);

                QCheckBox* checkBox1 = new QCheckBox("Руб", &dialog);       //Добавление флажков
                layout.addWidget(checkBox1, 0, 0);

                QCheckBox* checkBox2 = new QCheckBox("Евр", &dialog);
                layout.addWidget(checkBox2, 1, 0);

                QCheckBox* checkBox3 = new QCheckBox("Дол", &dialog);
                layout.addWidget(checkBox3, 2, 0);

                QCheckBox* checkBox4 = new QCheckBox("Тен", &dialog);
                layout.addWidget(checkBox4, 3, 0);

                QCheckBox* checkBox5 = new QCheckBox("Фун", &dialog);
                layout.addWidget(checkBox5, 4, 0);

                QCheckBox* checkBox6 = new QCheckBox("Руб", &dialog);
                layout.addWidget(checkBox6, 0,1);

                QCheckBox* checkBox7 = new QCheckBox("Евр", &dialog);
                layout.addWidget(checkBox7, 1,1);

                QCheckBox* checkBox8 = new QCheckBox("Дол", &dialog);
                layout.addWidget(checkBox8, 2, 1);

                QCheckBox* checkBox9 = new QCheckBox("Тен", &dialog);
                layout.addWidget(checkBox9, 3,1);

                QCheckBox* checkBox10 = new QCheckBox("Фун", &dialog);
                layout.addWidget(checkBox10, 4,1);

                QLineEdit* numberInput = new QLineEdit(&dialog);
                layout.addWidget(numberInput);

                // Создание и добавление кнопки "OK" в диалоговое окно
                QPushButton* okButton = new QPushButton("OK", &dialog);
                layout.addWidget(okButton);




                QObject::connect(okButton, &QPushButton::clicked, [&]() {       //Закрытие окна, обработка и вывод
                    QString numberText = numberInput->text();
                    number = numberText.toInt();

                    std::cout<< "Input number: " << number<<std::endl;

                    isChecked1 = checkBox1->isChecked();
                    isChecked2 = checkBox2->isChecked();
                    isChecked3 = checkBox3->isChecked();
                    isChecked4 = checkBox4->isChecked();
                    isChecked5 = checkBox5->isChecked();
                    isChecked6 = checkBox6->isChecked();
                    isChecked7 = checkBox7->isChecked();
                    isChecked8 = checkBox8->isChecked();
                    isChecked9 = checkBox9->isChecked();
                    isChecked10 = checkBox10->isChecked();

                    std::cout << "Checkbox 1: " << isChecked1<< std::endl;
                    std::cout << "Checkbox 2: " << isChecked2<< std::endl;
                    std::cout << "Checkbox 3: " << isChecked3<< std::endl;
                    std::cout << "Checkbox 4: " << isChecked4<< std::endl;
                    std::cout << "Checkbox 5: " << isChecked5<< std::endl;
                    std::cout << "Checkbox 6: " << isChecked6<< std::endl;
                    std::cout << "Checkbox 7: " << isChecked7<< std::endl;
                    std::cout << "Checkbox 8: " << isChecked8<< std::endl;
                    std::cout << "Checkbox 9: " << isChecked9<< std::endl;
                    std::cout << "Checkbox 10: " << isChecked10<< std::endl;

                    QString finalNumber;    //Переменная для вывода финального значения

                    if(isChecked1 == 1){    //Конвертация из рубля в ..

                        if(isChecked6 == 1){    //Рубль
                            finalNumber = QString::number(convertRubInto(number, 1, 0, 0, 0, 0));
                        }

                        if(isChecked7 == 1){    //Евро
                            finalNumber = QString::number(convertRubInto(number, 0, 1, 0, 0, 0));
                        }

                        if(isChecked8 == 1){    //Долар
                            finalNumber = QString::number(convertRubInto(number, 0, 0, 1, 0, 0));
                        }

                        if(isChecked9 == 1){    //Тенге
                            finalNumber = QString::number(convertRubInto(number, 0, 0, 0, 1, 0));
                        }

                        if(isChecked10 == 1){   //Фунт
                            finalNumber = QString::number(convertRubInto(number, 0, 0, 0, 0, 1));
                        }
                    }

                    if(isChecked2 == 1){    //Конвертация из евро в ..

                        if(isChecked6 == 1){    //Рубль
                            finalNumber = QString::number(convertEfroInto(number, 1, 0, 0, 0, 0));
                        }

                        if(isChecked7 == 1){    //Евро
                            finalNumber = QString::number(convertEfroInto(number, 0, 1, 0, 0, 0));
                        }

                        if(isChecked8 == 1){    //Долар
                            finalNumber = QString::number(convertEfroInto(number, 0, 0, 1, 0, 0));
                        }

                        if(isChecked9 == 1){    //Тенге
                            finalNumber = QString::number(convertEfroInto(number, 0, 0, 0, 1, 0));
                        }

                        if(isChecked10 == 1){   //Фунт
                            finalNumber = QString::number(convertEfroInto(number, 0, 0, 0, 0, 1));
                        }
                    }

                    if(isChecked3 == 1){    //Конвертация из долара в ..

                        if(isChecked6 == 1){    //Рубль
                            finalNumber = QString::number(convertDolInto(number, 1, 0, 0, 0, 0));
                        }

                        if(isChecked7 == 1){    //Евро
                            finalNumber = QString::number(convertDolInto(number, 0, 1, 0, 0, 0));
                        }

                        if(isChecked8 == 1){    //Долар
                            finalNumber = QString::number(convertDolInto(number, 0, 0, 1, 0, 0));
                        }

                        if(isChecked9 == 1){    //Тенге
                            finalNumber = QString::number(convertDolInto(number, 0, 0, 0, 1, 0));
                        }

                        if(isChecked10 == 1){   //Фунт
                            finalNumber = QString::number(convertDolInto(number, 0, 0, 0, 0, 1));
                        }
                    }

                    if(isChecked4 == 1){    //Конвертация из тенге в ..

                        if(isChecked6 == 1){    //Рубль
                            finalNumber = QString::number(convertTenInto(number, 1, 0, 0, 0, 0));
                        }

                        if(isChecked7 == 1){    //Евро
                            finalNumber = QString::number(convertTenInto(number, 0, 1, 0, 0, 0));
                        }

                        if(isChecked8 == 1){    //Долар
                            finalNumber = QString::number(convertTenInto(number, 0, 0, 1, 0, 0));
                        }

                        if(isChecked9 == 1){    //Тенге
                            finalNumber = QString::number(convertTenInto(number, 0, 0, 0, 1, 0));
                        }

                        if(isChecked10 == 1){   //Фунт
                            finalNumber = QString::number(convertTenInto(number, 0, 0, 0, 0, 1));
                        }
                    }

                    if(isChecked5 == 1){    //Конвертация из фунта в ..

                        if(isChecked6 == 1){    //Рубль
                            finalNumber = QString::number(convertFuntInto(number, 1, 0, 0, 0, 0));
                        }

                        if(isChecked7 == 1){    //Евро
                            finalNumber = QString::number(convertFuntInto(number, 0, 1, 0, 0, 0));
                        }

                        if(isChecked8 == 1){    //Долар
                            finalNumber = QString::number(convertFuntInto(number, 0, 0, 1, 0, 0));
                        }

                        if(isChecked9 == 1){    //Тенге
                            finalNumber = QString::number(convertFuntInto(number, 0, 0, 0, 1, 0));
                        }

                        if(isChecked10 == 1){   //Фунт
                            finalNumber = QString::number(convertFuntInto(number, 0, 0, 0, 0, 1));
                        }
                    }

                    outPanel.setText(finalNumber);  //Вывод
                    dialog.close();
                });

                dialog.setLayout(&layout);
                dialog.exec();
            });

    QVBoxLayout* pvbxLayout = new QVBoxLayout;

    wgt.setLayout(pvbxLayout);
    wgt.resize(640, 280);
    wgt.show();

    return a.exec();
}

