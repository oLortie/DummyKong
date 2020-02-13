/*
*   myVector est une implémentation personelle de la classe vecteur
*
*
*
*   @Author: Charles Lévesque-Matte
*   @Date: 2020-02-06
*   @Revision: 1
*   @Id:
*
*   Copyright 2020 Charles Lévesque-Matte
*/

#pragma once

#include <stdint.h>
#include <ostream>
#include <iostream>

#include <string>
#include <errno.h>

template <typename T >
class myVector
{
private:
	T *m_vector;
	int capacity; 
	int size; 
	bool empty;
	int position;
public:
	/* Constructor that initilize member variables */
	myVector();
	myVector(const myVector& copySource);
	virtual ~myVector();
	
	/* Function declaration */
	/**************************************************************************/
	myVector<T> getObj(); /* return the object vector created on the heap*/
	int getCapacity();
	int getSize();
	int getPosition();
	bool clear();
	bool insert(T member, int index);   /* Define as a template*/
	bool push_back(T element);
	bool pop_back();
	bool resize();
	T& operator[](int index);
	T& operator++();
	T& operator--();
	bool operator+=(T m_vector);
	bool operator-=(T m_vector);


};
#include "myVector.cpp"
