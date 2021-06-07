#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QStandardItemModel"
#include "QSortFilterProxyModel"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_2_triggered();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_actionSave_triggered();

    void on_pushButton_3_clicked();

    void on_actionOpen_triggered();

    void on_actionClose_triggered();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QSortFilterProxyModel *proxyModel;
    QStringList list;

};
#endif // MAINWINDOW_H
