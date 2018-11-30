/* A straight copy from the tutorial
 * Changed nothing, this is Section 8 Lecture 43
 */

#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template<class T>
class ring {
private:
	int m_pos;
	int m_size;
	T *m_values;
public:
	class iterator;
public:
	ring(int size): m_pos(0),m_size(size),m_values(0){
		m_values = new T[size];
	}

	~ring(){
		delete [] m_values;
	}

	int size(){
		return m_size;
	}

	iterator begin(){
		return iterator(0, *this);
	}

	iterator end(){
		return iterator(m_size, *this);
	}

	void add(T value){
		m_values[m_pos] = value;
		m_pos++;
		if(m_pos == m_size){
			m_pos = 0;
		}
	}

	T &get(int pos){
		return m_values[pos];
	}
};

template<class T>
class ring<T>::iterator{
private:
	int m_pos;
	ring &m_ring;
public:
	iterator(int pos, ring &myRing):m_pos(pos),m_ring(myRing){
	
	}

	//This is the postfix operator ++ becuase it has the unused
	//int param
	iterator &operator++(int){
		m_pos++;
		return *this;
	}

	//The prefix operator ++ without the int param
	iterator &operator++(){
		m_pos++;
		return *this;
	}

	//We must override the dereference(*) operator to return
	//the item we actually care about at any given point of
	//iteration
	T &operator*(){
		return m_ring.get(m_pos);
	}

	//The != comparison is used in standard iteration so
	//it must be implemented for this iterator to be useful
	bool operator!=(const iterator &other) const {
		return m_pos != other.m_pos;
	}
};

#endif
