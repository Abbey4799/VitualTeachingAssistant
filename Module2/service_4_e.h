#ifndef SERVICE_4_E_H
#define SERVICE_4_E_H

#include <QWidget>
#include <QtWidgets/QDialog>
#include "speech_recognizer.h"

namespace Ui {
	class service_4_E;
}

class service_4_E : public QWidget
{
	Q_OBJECT

public:
	service_4_E(QWidget *parent = nullptr);
	~service_4_E();
	char* print_material();
	void quitS4_E();
	static void on_result(const char* result, char is_last);
	static void on_speech_begin();
	static void on_speech_end(int reason);
	int Tmin(int a, int b, int c);
	double compare_result(char* string, char* material);

protected:
	void keyPressEvent(QKeyEvent* e);

private slots:
	void back_func();

private:
	Ui::service_4_E *ui;
	int _iErrcode;
	struct speech_rec _iat;
	static service_4_E* static_Self;
};

#endif // SERVICE_4_E_H