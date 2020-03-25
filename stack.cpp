#include <stdio.h>
#include "stack.h"

Stack::Stack()
{
/**** COMPLETE HERE: 01 ****/
	m_elems = new int[50];
	m_top = 0;
/**** COMPLETE HERE: 01 ****/
}

Stack::~Stack()
{
/**** COMPLETE HERE: 02 ****/
	delete	m_elems;
	m_top = 0;
/**** COMPLETE HERE: 02 ****/
}

void
Stack::push( int _n )
{
/**** COMPLETE HERE: 03 ****/
	m_elems[m_top++] = _n;
/**** COMPLETE HERE: 03 ****/
}

int
Stack::pop()
{
/**** COMPLETE HERE: 04 ****/
	return m_elems[--m_top];
/**** COMPLETE HERE: 04 ****/
}

bool
Stack::isEmpty()
{
/**** COMPLETE HERE: 05 ****/
	return	m_top == 0;
/**** COMPLETE HERE: 05 ****/
}

void
Stack::show()
{
/**** COMPLETE HERE: 06 ****/	
	
/**** COMPLETE HERE: 06 ****/
}

int
Stack::getSize()
{
/**** COMPLETE HERE: 07 ****/
	return m_top;
/**** COMPLETE HERE: 07 ****/}

int
Stack::getNumber(int _pos)
{
/**** COMPLETE HERE: 08 ****/
	return m_elems[_pos];
/**** COMPLETE HERE: 08 ****/}
