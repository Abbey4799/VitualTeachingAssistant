#ifndef SERVICE_2_H
#define SERVICE_2_H

#include <QWidget>

namespace Ui {
class Service_2;
}

class Service_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Service_2(QWidget *parent = nullptr);
    ~Service_2();

private slots:
    void on_input_OK_clicked();
	void back_func();

private:
    Ui::Service_2 *ui;
};

#endif // SERVICE_2_H
