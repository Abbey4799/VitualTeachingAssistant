#ifndef SERVICE_3_H
#define SERVICE_3_H

#include <QWidget>

namespace Ui {
class Service_3;
}

class Service_3 : public QWidget
{
    Q_OBJECT

public:
    explicit Service_3(QWidget *parent = nullptr);
    ~Service_3();

private slots:
    void fromFile_func();
    void fromMIC_func();
	void back_func();

private:
    Ui::Service_3 *ui;
};

#endif // SERVICE_3_H
