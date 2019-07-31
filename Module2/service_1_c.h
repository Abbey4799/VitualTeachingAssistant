#ifndef SERVICE_1_C_H
#define SERVICE_1_C_H

#include <QWidget>

namespace Ui {
class service_1_C;
}

class service_1_C : public QWidget
{
    Q_OBJECT

public:
    explicit service_1_C(QWidget *parent = nullptr);
    ~service_1_C();
    void quitS1_C();

private slots:
    void on_input_OK_clicked();
	void back_func();

private:
    Ui::service_1_C *ui;
};

#endif // SERVICE_1_C_H
