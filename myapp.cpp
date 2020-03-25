#include "myapp.h"
#include <QMessageBox>

MyApp::MyApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

MyApp::~MyApp()
{
	
}


/* -------------------------------------------------
* Private methods:
*/
bool
MyApp::getOperands(int* _n1,
                   int* _n2)
{
/**** COMPLETE HERE: 09 ****/
	if (m_stack.isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText("Pilha Vazia!!!");
		msgBox.setWindowTitle("AVISO");
		msgBox.exec();
		return false;
	}
	*_n2 = m_stack.pop();
	if (m_stack.isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText("Necessita dois operandos!!!");
		msgBox.setWindowTitle("AVISO");
		msgBox.exec();
		m_stack.push(*_n2);
		return false;
	}
	*_n1 = m_stack.pop();
	return true;
/**** COMPLETE HERE: 09 ****/
}

void
MyApp::displayStack()
{
	QString text;
	text.clear();
	ui.stackViewer->clear();
/**** COMPLETE HERE: 10 ****/
	for (int i = 0; i < m_stack.getSize(); i++)
	{
		text.setNum(m_stack.getNumber(i));
		ui.stackViewer->insertPlainText(text + "\n");
		text.clear();
	}
	
/**** COMPLETE HERE: 10 ****/
	
	ui.stackViewer->moveCursor(QTextCursor::End);	
}

/* -------------------------------------------------
* Public slots:
*/
void
MyApp::inputDigit()
{	
	QObject *sender = const_cast<QObject *>(QObject::sender());
	QPushButton *button = static_cast<QPushButton *>(sender);
	QString digit = button->text();
	QString text = ui.inputViewer->text();
/**** COMPLETE HERE: 11 ****/
	ui.inputViewer->insert(digit);
	
/**** COMPLETE HERE: 11 ****/
}

void
MyApp::selectOp()
{
	QObject *sender = const_cast<QObject *>(QObject::sender());
	QPushButton *button = static_cast<QPushButton *>(sender);
	QString string = button->text();
	char op = string[0].toLatin1();
/**** COMPLETE HERE: 12 ****/
	int v1,v2,v3;

	switch (op)
	{
		case '+':
		{
			if (getOperands(&v1, &v2))
			{
				v3 = v1 + v2;
				m_stack.push(v3);
			}
		}
		break;
		case '-':
		{
			if (getOperands(&v1, &v2))
			{
				v3 = v2 - v1;
				m_stack.push(v3);
			}
		}
		break;
		case '/':
		{
			if (getOperands(&v1, &v2))
			{
				v3 = v2 / v1;
				m_stack.push(v3);
			}
		}
		break;
		case 'x':
		{
			if (getOperands(&v1, &v2))
			{
				v3 = v2 * v1;
				m_stack.push(v3);
			}
		}
		break;
	}
/**** COMPLETE HERE: 12 ****/
		displayStack();
		m_stack.show();
	
};

void
MyApp::enterNumber()
{
	QString text = ui.inputViewer->text();
	if (text.isEmpty()) return;
/**** COMPLETE HERE: 13 ****/
	int num = text.toInt();
	m_stack.push(num);

/**** COMPLETE HERE: 13 ****/
	displayStack();
	m_stack.show();
	ui.inputViewer->clear();
};
