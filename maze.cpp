#include "maze.h"
#include <iostream>

using namespace std;

maze::maze() {
	row = 0;
	column = 0;
	hurdle = 0;
	map = NULL;
	head = NULL;
	tail = NULL;
}

node* maze:: Create(int a,int b) {
	node* newNode = new node();
	newNode->r = a;
	newNode->c = b;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

maze::maze(int a, int b, int c, int** arr1) {
	row = a;
	column = b;
	hurdle = c;
	map = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[column];
		for (int j=0; j < column; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < hurdle; i++) {
		map[arr1[i][0]][arr1[i][1]] = 1;
	}
	head = NULL;
	tail = NULL;
}

void maze::build( int** arr1) {
	map = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[column];
		for (int j = 0; j < column; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < hurdle; i++) {
		map[arr1[i][0]][arr1[i][1]] = 1;
	}
	map = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[column];
		for (int j=0; j < column; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < hurdle; i++) {
		map[arr1[i][0]][arr1[i][1]] = 1;
	}
}

bool maze::Isempty() {
	if (!head) return true;
	return false;
}

node* maze::top() {
	if (!head) cout << "Empty!" << endl; return head;
	return tail;
}

void maze::push(node* newNode) {
	if (head==NULL) {
		head = newNode;
		tail = newNode;
		return;
	}
	//node* curr = head;
	//while (curr->next) {
	//	curr = curr->next;
	//}
	//curr = newNode;
	////curr = newNode;
	//tail = newNode;

	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

void maze::pop() {
	/*if (Isempty()) {
		cout << "Empty\n";
		return;
	}

	node* curr = tail->prev;
	delete tail;
	tail = curr;*/
	if(Isempty()){
		cout << "Empty\n";
		return;
	}
	head = head->next;
	head->prev = NULL;
}

void maze::print_map() {
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++) {
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}

void maze::route() {
	int i = 0, j = 0;
	push(Create(i, j));
	while ((i != ((column - 1))) && (j != (row - 1))) {
	down:
		i++; push(Create(i, j));
		if (!down(i, j)) {
			i--; pop();
		right:
			j++; push(Create(i, j));
			if (!right(i, j)) {
				j--; pop();
				if (down(i + 1, j)) {
					goto down;
				}
			up:
				i--; push(Create(i, j));
				if (!up(i, j)) {
					i++; pop();
				left:
					j--; push(Create(i, j));
					if (!left(i, j)) {
						j++; pop();
						cout << "Stuck\n";
						if (i == row - 1 && j == column - 1) { break; }
					}
					else {
						cout << "LEFT!\n";
						//push(Create(i, j));
						if (i == row - 1 && j == column - 1) { break; }
						goto down;
					}
					//else if(top)
				}
				else {
					cout << "UP!\n";
					//push(Create(i, j));
					if (right(j + 1, j)) {
						if (i == row - 1 && j == column - 1) { break; }
						goto right;
					}
					else if (down(i + 2, j)) {
						if (i == row - 1 && j == column - 1) { break; }
						goto down;
					}
					else {
						goto up;
					}
				}
			}
			else {
				cout << "RIGHT!\n";
				//push(Create(i, j));
				if (i == row - 1 && j == column - 1) { break; }
				goto right;
			}
		}
		else {
			cout << "DOWN!\n";
			//push(Create(i, j));
			if (i == row - 1 && j == column - 1) { break; }
			goto down;
		}
	}
	push(Create(row - 1, column - 1));
}

void maze::print_route() {
	cout << "Route: \n";
	if (head == NULL) { cout << "No Route!\n"; return; }

	node* curr = tail;
	while (curr->prev) {
		cout << curr->r << "\t" << curr->c << endl;
		curr = curr->prev;
	}
}

bool maze::right(int i, int j) {
	if (j>(column-1)) {
		return false;
	}
	else if (map[i][j]==1) {
		return false;
	}
	else {
		return true;
	}
}

bool maze::down(int i, int j) {
	if (i > (row - 1)) {
		return false;
	}
	else if (map[i][j] == 1) {
		return false;
	}
	else {
		return true;
	}
}

bool maze::left(int i, int j) {
	if (j < 0) {
		return false;
	}
	else if (map[i][j] == 1) {
		return false;
	}
	else {
		return true;
	}
}

bool maze::up(int i, int j) {
	if (i < 0) {
		return false;
	}
	else if (map[i][j] == 1) {
		return false;
	}
	else {
		return true;
	}
}
