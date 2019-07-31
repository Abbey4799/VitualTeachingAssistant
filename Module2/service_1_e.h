#ifndef SERVICE_1_E_H
#define SERVICE_1_E_H

#include <QWidget>

namespace Ui {
class service_1_E;
}

class service_1_E : public QWidget
{
    Q_OBJECT

public:
    explicit service_1_E(QWidget *parent = nullptr);
    ~service_1_E();
    void quitS1_E();

private slots:
    void on_input_OK_clicked();
	void back_func();

private:
    Ui::service_1_E *ui;
};

#endif // SERVICE_1_E_H
