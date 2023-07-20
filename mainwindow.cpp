#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpression> // Include the QRegularExpression header

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the textChanged signal of the textEdit widget to the countWords() slot
    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::countWords);

    // Initialize word count on startup
    countWords();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::countWords()
{
    QString text = ui->textEdit->toPlainText();

    // Use QRegularExpression instead of QRegExp
    QStringList words = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    // Get the number of words
    int wordCount = words.size();

    // Update the word count label
    ui->labelWordCount->setText("Word Count: " + QString::number(wordCount));
}
