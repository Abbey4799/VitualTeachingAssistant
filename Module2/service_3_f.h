#ifndef SERVICE_3_F_H
#define SERVICE_3_F_H

#include <QWidget>

namespace Ui {
class service_3_F;
}

class service_3_F : public QWidget
{
    Q_OBJECT

public:
    explicit service_3_F(QWidget *parent = nullptr);
    ~service_3_F();
	void quitS3_F();

private slots:
    void on_input_OK_clicked();
	void back_func();

private:
    Ui::service_3_F *ui;
};

#endif // SERVICE_3_F_H
