//Imani Cage
//array.cpp
/* Created two-dimensional array of integers according to the user’s request.  
Asks the user for the number of rows and columns for the array, and all the elements of the array.  
Print the array contents along with the sum of each row, and the sum of each column. */

#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
   int colmCount, rowCount;
   int sum = 0;

    //Requests users for amount of rows and columns
   cout << endl << endl;
   cout << "Input rows" << endl;
   cin >> rowCount;
   cout << "Input columns" << endl;
   cin >> colmCount;

    //dynamically allocates rows as a 2d array

   int * * a = new int*[rowCount];

    for(int i = 0; i < rowCount; i++){
        a[i] = new int[colmCount];
    }

    //Requests user for values within the rows and columns
    for(int i = 0; i < rowCount; i++){
        for(int j = 0; j < colmCount; j++){
            cout << endl << endl;
            cout << "Please input a number for row " << i + 1 << " column " << j + 1;
            cin >> a[i][j];
        }
    } // Creates chart of input numbers
    cout << endl;
    for(int i = 0; i < rowCount; i++){
        for(int j = 0; j < colmCount; j++){
            cout <<  a[i][j] << " ";
        }
        cout << endl;
    }

    //Calculates sum of the specific rows

    for(int i = 0; i < rowCount; i++){
        for(int j = 0; j < colmCount; j++){
            sum = sum + a[i][j];
        }
        cout << endl;
        cout << "The sum of row " << i + 1 << " is " << sum;
        sum = 0;
    }

    //Calculates sum of the specific column

    for(int i = 0; i < colmCount; i++){
        for(int j = 0; j < rowCount; j++){
            sum = sum + a[j][i];
        }
        cout << endl;
        cout << "The sum of column " << i + 1 << " is " << sum;
        sum = 0;
    }
    cout << endl << endl;

    for(int i = 0; i < rowCount; i++){
        delete[] a[i];
    }
    delete[] a;
    return 0;
}