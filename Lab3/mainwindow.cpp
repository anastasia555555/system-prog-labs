#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Position Manager");

    idLineEdit = new QLineEdit(this);
    idLineEdit->setPlaceholderText("ID");

    nameLineEdit = new QLineEdit(this);
    nameLineEdit->setPlaceholderText("Name");

    salaryLineEdit = new QLineEdit(this);
    salaryLineEdit->setPlaceholderText("Salary");

    responsibilitiesTextEdit = new QTextEdit(this);
    responsibilitiesTextEdit->setPlaceholderText("Responsibilities");

    requirementsTextEdit = new QTextEdit(this);
    requirementsTextEdit->setPlaceholderText("Requirements");

    filePathLineEdit = new QLineEdit(this);
    filePathLineEdit->setPlaceholderText("Enter file path...");

    saveButton = new QPushButton("Save to File", this);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveToFile);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(idLineEdit);
    layout->addWidget(nameLineEdit);
    layout->addWidget(salaryLineEdit);
    layout->addWidget(responsibilitiesTextEdit);
    layout->addWidget(requirementsTextEdit);
    layout->addWidget(filePathLineEdit);
    layout->addWidget(saveButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);
}

void MainWindow::saveToFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), "Text Files (*.txt);;All Files (*)");
    if (!filePath.isEmpty()) {
        int id = idLineEdit->text().toInt();
        QString name = nameLineEdit->text();
        double salary = salaryLineEdit->text().toDouble();
        QString responsibilities = responsibilitiesTextEdit->toPlainText();
        QString requirements = requirementsTextEdit->toPlainText();

        Records::Position newPosition(id, name.toStdString(), salary, responsibilities.toStdString(), requirements.toStdString());
        database.addPosition(newPosition);
        database.saveToFile(filePath.toStdString());
        filePathLineEdit->setText(filePath);
    }
}
