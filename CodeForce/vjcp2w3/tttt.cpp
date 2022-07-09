#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct mTerm {
	int row, col;
	double value;
};

int compare(int M, int N, int P, int Q);

class sMatrix {
	public:
		sMatrix(){};
		sMatrix(int row, int col, int terms);
		void AddTerm(vector<mTerm> T);
		sMatrix FtMatrix()const;
		sMatrix Mult(const sMatrix& b);
		int getRow();
		int getCol();
		void StoreSum(const double sum, const int r, const int c);
		void PrintMatrix();
		void ChangeSize1D(const int newSize);
		sMatrix operator =(const sMatrix& S);
	private:
		int Row, Col, Terms, capacity;
		mTerm *smArray;
		
};

int main() {
	ifstream input;
	ofstream output;
	input.open("test.txt");
	output.open("test_output.txt", ios::app);
	string temp;
	int tempR, tempC;
	vector<mTerm> tempM;
	mTerm t;
	
	getline(input, temp);
	tempC = 1;
	tempR = 1;
	
	do {
		input >> temp;
		if (temp == "0") {
			tempC++;
		}
		else if (temp == ";") {
			tempR++;
		}
		else {
			t.col = tempC;
			t.row = tempR;
			t.value = atof(temp.c_str());
			tempM.push_back(t);
			tempC++;
		}
	} while (temp != "B");
	tempR--;
	sMatrix A(tempR, tempC, tempM.size());
	A.AddTerm(tempM);
	
	input >> temp;
	tempC = 1;
	tempR = 1;
	tempM.clear();
	
	do {
		input >> temp;
		if (temp == "0") {
			tempC++;
		}
		else if (temp == ";") {
			tempR++;
		}
		else {
			t.col = tempC;
			t.row = tempR;
			t.value = atof(temp.c_str());
			tempM.push_back(t);
			tempC++;
		}
	} while (!input.eof());
	tempR--;
	sMatrix B(tempR, tempC, tempM.size());
	B.AddTerm(tempM);
	
	int m, n, p, q;
	m = A.getRow();
	n = A.getCol();
	p = B.getRow();
	q = B.getCol();
	
	int cases = compare(m, n, p, q);
	switch (cases) {
		case 1:
			break;
		case 2:
			A = A.FtMatrix();
			break;
		case 3:
			B = B.FtMatrix();
			break;
		case 4:
			A = A.FtMatrix();
			B = B.FtMatrix();
			break;
	}
	
	sMatrix ANS = A.Mult(B);
	ANS.PrintMatrix();
	input.close();
	output.close();
	return 0;
}

sMatrix::sMatrix(int row, int col, int terms) {
	Row = row;
	Col = col;
	Terms = terms;
}

void sMatrix::AddTerm(vector<mTerm> T) {
	for (int i = 0; i < Terms; i++) {
		smArray[i] = T[i];
	}
}

int sMatrix::getCol() {
	return Col;
}

int sMatrix::getRow() {
	return Row;
}

sMatrix sMatrix::FtMatrix() const{
	int *RowSize = new int[Col];
	int *RowStart = new int[Col];
	sMatrix b(Col, Row, Terms);
	if (Terms > 0) {
		for (int i = 0; i < Col; i++) {
			RowSize[i] = 0;
		}
		for (int i = 0; i < Terms; i++) {
			RowSize[smArray[i].col]++;
		}
		RowStart[0] = 0;
		for (int i = 1; i < Col; i++) {
			RowStart[i] = RowStart[i - 1] + RowSize[i - 1];
		}
		for (int i = 0; i <Terms; i++) {
			int j = RowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			RowStart[smArray[i].col]++;
		}
	}
	delete [] RowSize;
	delete [] RowStart;
	return b;
}

void sMatrix::StoreSum(const double sum, const int r, const int c) {
	if (sum != 0) {
		if (Terms == capacity) {
			ChangeSize1D(2 * capacity);
		}
		smArray[Terms].row = r;
		smArray[Terms].col = c;
		smArray[Terms++].value = sum;
	}
}

sMatrix sMatrix::Mult(const sMatrix& b) {
	if (Col != b.Row) {
		throw "Incompatible Matrices";
	}
	sMatrix bXpose = b.FtMatrix();
	sMatrix d(Row, b.Col, 0);
	int currRowIndex = 0;
	int currRowBegin = 0;
	int currRowA = smArray[0].row;
	if (Terms == capacity) {
		ChangeSize1D(Terms + 1);
	}
	bXpose.ChangeSize1D(bXpose.Terms + 1);
	smArray[Terms].row = Row;
	bXpose.smArray[b.Terms].row = b.Col;
	bXpose.smArray[b.Terms].col = -1;
	int sum = 0;
	while (currRowIndex < Terms) {
		int currColB = bXpose.smArray[0].row;
		int currColIndex = 0;
		while (currColIndex <= b.Terms) {
			if (smArray[currRowIndex].row != currRowA) {
				d.StoreSum(sum, currRowA, currColB);
				sum = 0;
				currRowIndex = currRowBegin;
				while (bXpose.smArray[currColIndex].row == currColB) {
					currColIndex++;
				}
				currColB = bXpose.smArray[currColIndex].row;
			}
			else if (bXpose.smArray[currColIndex].row != currColB) {
				d.StoreSum(sum, currRowA, currColB);
				sum = 0;
				currRowIndex = currRowBegin;
				currColB = bXpose.smArray[currColIndex].row;
			}
			else {
				if (smArray[currRowIndex].col < bXpose.smArray[currColIndex].col) {
					currRowIndex++;
				}
				else if (smArray[currColIndex].col == bXpose.smArray[currColIndex].col) {
					sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
					currRowIndex++;
					currColIndex++;
				}
				else {
					currColIndex++;
				}
			}
		}
		while (smArray[currRowIndex].row == currRowA) {
			currRowIndex++;
			currRowBegin = currRowIndex;
			currRowA = smArray[currRowIndex].row;
		}
	}
	return d;
}

sMatrix sMatrix::operator=(const sMatrix& S) {
	sMatrix ans;
	ans.Col = S.Col;
	ans.Row = S.Row;
	ans.Terms = S.Terms;
	for (int i = 0; i < Terms; i++) {
		ans.smArray[i] = S.smArray[i];
	}
	return ans;
}

void sMatrix::PrintMatrix() {
	int i, j, k;
	for (i = 1; i <= Col; i++) {
		for (j = 1; j <= Row; j++) {
			for (k = 0; k < Terms; k++) {
				if (smArray[k].col == i && smArray[k].row == j) {
					cout << smArray[k].value << " ";
				}
				else {
					cout << "0 ";
				}
			}
		}
		cout << ";" << endl;
	}
}

void sMatrix::ChangeSize1D (const int newSize) {
	if (newSize < Terms) {
		throw "New size must be >= number of Terms";
	}
	mTerm *temp = new mTerm[newSize];
	copy(smArray, smArray + Terms, temp);
	delete [] smArray;
	smArray = temp;
	capacity = newSize;
}

int compare(int M, int N, int P, int Q) {
	if (N == P) {
		return 1;
	}
	else if (M == P) {
		return 2;
	}
	else if (N == Q) {
		return 3;
	}
	else if (M == Q) {
		return 4;
	}
}