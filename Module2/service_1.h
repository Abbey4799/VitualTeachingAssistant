#ifndef SERVICE_1_H
#define SERVICE_1_H

#include <QWidget>

namespace Ui {
class Service_1;
}

class Service_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Service_1(QWidget *parent = nullptr);
    ~Service_1();
private slots:
    void chooseChinese_func();
    void chooseEnglish_func();
	void back_func();
private:
    Ui::Service_1 *ui;
};

#endif // SERVICE_1_H
