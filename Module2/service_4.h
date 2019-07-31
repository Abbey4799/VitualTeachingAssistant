#ifndef SERVICE_4_H
#define SERVICE_4_H

#include <QWidget>

namespace Ui
{
class Service_4;
}

class Service_4 : public QWidget
{
    Q_OBJECT

public:
    explicit Service_4(QWidget *parent = nullptr);
    ~Service_4();

public slots:
    void poetry_func();
    void english_func();

private slots:
	void back_func();

private:
    Ui::Service_4 *ui;
};

#endif // SERVICE_4_H
