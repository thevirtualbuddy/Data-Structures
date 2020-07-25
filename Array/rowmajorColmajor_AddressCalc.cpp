#include <iostream>
using namespace std;

int rowMajor(int, int, int, int); //Function to calculation address for row Major scenario
int colMajor(int, int, int, int); //Function to calculation address for column Major scenario

//Driver function
int main(){
    cout << "-------------ROW MAJOR & COLUMN MAJOR-------------\n";

    int base, row, col;
    cout << "Enter the size of row and column of the array: ";
    cin >> row >> col;
    cout << "Enter the base address: ";
    cin >> base;
    cout << endl;
    cout << "Following are the cell number of each elements in the array:\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << i << j << "\t";
        }
        cout << endl;
    }

    int cell, rowAdd, colAdd;
    cout << endl << "Enter the cell number for which you want to find the address: ";
    cin >> cell;

    cout << "Assuming the word size of integer to be 4 bytes\n\n";
    rowAdd = rowMajor(row, col, base, cell);
    cout << "Address of the given cell for row major is: " << rowAdd << endl << endl;

    colAdd = colMajor(row, col, base, cell);
    cout << "Address of the given cell for column major is: " << colAdd << endl << endl;

    return 0;
}

int rowMajor(int row, int col, int base, int cell){
    int r, c;
    c = cell%10;
    r = cell/10;
    cout << "The elements in memory location are stored as follows in the row major fashion: \n";
    for(int i=0;i<row;i++){
        cout << "| ";
        for(int j=0;j<col;j++)
            cout << i << j << " |";
    }
    cout << endl << endl;
    int add;
    cout << "Address can be calculated as: ((rowNumber * columnSize) + columnNumber ) * WordSize + BaseAddress\n";
    add = ((r * col) + c )*4 + base;
    return add;

}

int colMajor(int row, int col, int base, int cell){
    int r, c;
    c = cell%10;
    r = cell/10;

    cout << "The elements in memory location are stored as follows in the column major fashion: \n";
    for(int i=0;i<col;i++){
        cout << "| ";
        for(int j=0;j<row;j++)
            cout << i << j << " |";
    }
    cout << endl << endl;
    int add;
    cout << "Address can be calculated as: ((columnNumber * rowSize) + rowNumber ) * WordSize + BaseAddress\n";
    add = ((c * row)+ r) *4 + base;
    return add;

}
