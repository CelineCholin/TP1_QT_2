#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnSauvegarder_clicked()
{
    // Récupérer le texte du widget Code
    QString texte = ui->Code->text();
    if (ui->Code->text().isEmpty())
    {
        QMessageBox::warning(this,
                             "Saisi du code",
                    "Vous devez saisir un code !!");
        return; // on arrête la fonction
    }

    // Copier ce texte dans le widget DernierCodeSaisi
    ui->DernierCodeSaisi->setText(texte);
}
