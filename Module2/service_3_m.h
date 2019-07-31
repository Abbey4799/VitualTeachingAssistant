#ifndef SERVICE_3_M_H
#define SERVICE_3_M_H

#include <QWidget>
#include <QtWidgets/QDialog>
#include "speech_recognizer.h"

namespace Ui {
class service_3_M;
}

class service_3_M : public QWidget
{
    Q_OBJECT

public:
    explicit service_3_M(QWidget *parent = nullptr);
    ~service_3_M();
	void quitS3_M();
	void output();
	void clear();
	static void on_result(const char* result, char is_last);
	static void on_speech_begin();
	static void on_speech_end(int reason);

private slots:
	void back_func();

protected:
	void keyPressEvent(QKeyEvent* e);

private:
    Ui::service_3_M *ui;
	int _iErrcode;
	struct speech_rec _iat;
	static service_3_M* static_Self;
};

#endif // SERVICE_3_M_H
