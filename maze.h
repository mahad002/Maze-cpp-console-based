#pragma once
#include <iostream>

using namespace std;

class node {
public:
	int r;
	int c;
	node* next;
	node* prev;
};

class maze {
	node* head;
	node* tail;
	int row;
	int column;
	int hurdle;
	int** map;
public:
	maze();
	maze(int,int,int,int**);
	void build(int**);
	bool Isempty();
	node* top();
	void push(node*);
	void pop();
	void print_map();
	node* Create(int, int);
	void route();
	void print_route();
	bool right(int, int);
	bool down(int, int);
	bool up(int, int);
	bool left(int, int);


	node* getHead() {
		return this->head;
	}
	void setHead(node* head) {
		this->head = head;
	}


	node* getTail() {
		return this->tail;
	}
	void setTail(node* tail) {
		this->tail = tail;
	}


	int getRow() {
		return this->row;
	}
	void setRow(int row) {
		this->row = row;
	}


	int getColumn() {
		return this->column;
	}
	void setColumn(int column) {
		this->column = column;
	}


	int getHurdle() {
		return this->hurdle;
	}
	void setHurdle(int hurdle) {
		this->hurdle = hurdle;
	}


	int** getMap() {
		return this->map;
	}
	void setMap(int** map) {
		this->map = map;
	}

};

