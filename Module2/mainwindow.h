#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void service1_func();
    void service2_func();
    void service3_func();
    void service4_func();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
