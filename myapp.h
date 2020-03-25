#ifndef MYAPP_H
#define MYAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_myapp.h"
#include "stack.h"

class MyApp : public QMainWindow
{
	Q_OBJECT

public:
	MyApp(QWidget *parent = 0);
	~MyApp();

private:
	Ui::MyAppClass ui;
	Stack m_stack;
	bool getOperands(int* _n1, int* _n2);
	void displayStack();

public slots:
	void inputDigit();
	void selectOp();
	void enterNumber();
};

#endif // MYAPP_H
