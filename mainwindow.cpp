#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->DernierCodeSaisi->setText("Pas de code saisi !!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnSauvegarder_clicked()
{
    // On récupère le texte du widget Code
    QString code = ui->Code->text().trimmed();
    //Si la zone texte est vide
    if (code.isEmpty())
    {
        //on affiche le message d'erreur
        QMessageBox::warning(this,
                             "Saisi du code",
                    "Vous devez saisir un code !!");
        return; // on arrête la fonction
    }

    ui->ListeDesCodes->addItem(code);
    // On copie le texte récupéré dans le widget DernierCodeSaisi
    ui->DernierCodeSaisi->setText(code);
    //on vide la zone de saisie
    ui->Code->clear();
}


void MainWindow::on_pushButton_clicked()
{
    QListWidgetItem *item = ui->ListeDesCodes->currentItem();
    // Copie le code supprimé dans la zone de saisie
    ui->Code->setText(item->text());

    delete item;  // supprime le code
}

