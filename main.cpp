#include "maze.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include <tchar.h>
#include <iostream>

using namespace std;



int main() {
	fstream input;
	string data;
	maze m;

	int** array1 = new int* [m.getHurdle()];
	

	int row=0, column=0, hurdle = 0;
	input.open("Maze.txt", ios::in);

	if (input.is_open()) {
		getline(input, data);
		int i,j=0;
		for ( i = 0;data[i]!=','; i++) {
			if (data[i] >= 48 && data[i] <= 57) {
				while (data[i] >= 48 && data[i] <= 57) {
					//m.setRow((int)data[i]-48);
					m.setRow(m.getRow() + ((int)data[i]-48)*pow(10,j));
					j++; i++;
				}
				j = 0;
			}
		}
		for (; i < data.length(); i++) {
			if (data[i] >= 48 && data[i] <= 57) {
				while (data[i] >= 48 && data[i] <= 57) {
					//m.setColumn(int(data[i])-48);
					m.setColumn(m.getColumn() + ((int)data[i]-48) * pow(10, j));
					j++; i++;
				}
				j = 0;
			}
		}
		getline(input, data);
		for (i=0; i < data.size(); i++) {
			if (data[i] >= 48 && data[i] <= 57) {
				while (data[i] >= 48 && data[i] <= 57) {
					m.setHurdle(m.getHurdle() + ((int)data[i]-48)* pow(10, j));
					j++; i++;
				}
				j = 0;
			}
		}
		int k = 0, l = 0, n = m.getHurdle(), o = 0;
		for (int z = 0; z < m.getHurdle(); z++) {
			array1[z] = new int[2];
			array1[z][0] = 0;
			array1[z][1] = 0;
		}

		j = 0;
		while (getline(input, data)) {
			
			for (i = 0; i < data.length(); i++) {
				if (data[i] >= 48 && data[i] <= 57) {
					while (data[i] >= 48 && data[i] <= 57) {
						if (((int)data[i] - 48) == 0) {
							array1[l][o] *= 10;
						}
						else {
							array1[l][o] += ((int)data[i] - 48);
						}
						j++; i++;
					}
					o++;
					j = 0;
				}
			}
			o = 0;
			l++;
		}
	}

	/*for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 2; j++) {
			cout<< array1[i][j] << endl;
		}
	}*/

	/*cout << m.getRow() << endl;
	cout << m.getColumn() << endl;
	cout << m.getHurdle() << endl;*/


	m.build(array1);

	m.print_map();
	cout << endl;
	m.route();

	m.print_route();

	//readfile();
	

}