#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    Stack();
    ~Stack();
    void push(int _n);
    int pop();
    bool isEmpty();
	void show();
	int getSize();
    int getNumber(int _pos);

private:
    int m_top;
    int *m_elems;
};

#endif