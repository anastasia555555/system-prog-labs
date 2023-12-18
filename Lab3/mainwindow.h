#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include "Database.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void saveToFile();

private:
    QLineEdit *idLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *salaryLineEdit;
    QTextEdit *responsibilitiesTextEdit;
    QTextEdit *requirementsTextEdit;
    QLineEdit *filePathLineEdit;
    QPushButton *saveButton;
    Records::Database database;
};

#endif
