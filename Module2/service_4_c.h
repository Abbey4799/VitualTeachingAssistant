#ifndef SERVICE_4_C_H
#define SERVICE_4_C_H

#include <QWidget>
#include <QtWidgets/QDialog>
#include "speech_recognizer.h"

namespace Ui {
	class service_4_C;
}

class service_4_C : public QWidget
{
	Q_OBJECT

public:
	service_4_C(QWidget *parent = nullptr);
	~service_4_C();
	char* print_material();
	void quitS4_C();
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
	Ui::service_4_C *ui;
	int _iErrcode;
	struct speech_rec _iat;
	static service_4_C* static_Self;
};

void StringReplace(std::string& strBase, std::string strSrc, std::string strDes);

#endif // SERVICE_4_C_H