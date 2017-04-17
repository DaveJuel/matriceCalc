/*
 * THIS IS THE C APPLICATION TO HELP CONDUCT SOME MATRICE CALCULATIONS
 */

/* 
 * File:   main.c
 * Author: david
 *
 * Created on March 29, 2017, 11:48 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int row;
    int column;
    int inner;
    int outer;
    int det;
    int getCofactor(int refRow, int row, int column, int table[row][column]);
    int laplaceMeth(int row, int column, int table[row][column]);
    int sarrusMeth(int row, int column, int table[row][column]);
    int twodem(int row, int column, int table[row][column]);
    void displayMatrix(int row, int column, int table[row][column]);
    void transpose(int row, int column, int table[row][column]);
    printf("Define the size of the matrix\n");
    printf("number of rows:\n");
    scanf("%d", &row);
    printf("number of columns:\n");
    scanf("%d", &column);
    int matrix[row][column];
    //read matrix values

    for (outer = 0; outer < row; outer++) {
        for (inner = 0; inner < column; inner++) {
            printf("Enter value on row(%d),column(%d)\n", outer + 1, inner + 1);
            scanf("%d", &matrix[outer][inner]);
        }
    }
    //display the matrix
    printf("Your matrix is:\n");
    displayMatrix(row, column, matrix);
    //end display
    if (row == column) {
        //calculate determinant
        if (row == 2) {
            det = twodem(row, column, matrix);
        } else if (row == 3) {
            det = sarrusMeth(row, column, matrix);
        } else {
            
            //det = laplaceMeth(row, column, matrix);
        }
        printf("The determinant is: %d\n", det);
        //end determinant
    } else {
        printf("Determinant can not be calculated. rows != columns\n");
    }
    transpose(row, column, matrix);
    //end read
    return (EXIT_SUCCESS);
}

void displayMatrix(int row, int column, int table[row][column]) {
    int outer;
    int inner;    
    for (outer = 0; outer < row; outer++) {
        printf("|");
        for (inner = 0; inner < column; inner++) {
            printf(" %d ", table[outer][inner]);
        }
        printf("|\n");
    }
    printf("And it has (%d)rows and (%d) columns\n", row, column);
}
//CALCULATING THE DETERMINANT OF A TWO DIMENSIONAL MATRIX

int twodem(int row, int column, int table[row][column]) {
    int det;
    int a = table[0][0];
    int b = table[1][1];
    int c = table[0][1];
    int d = table[1][0];
    det = (a * b)-(c * d);
    return det;
}
//SARRUS METHOD OF CALCULATING THE DETERMINANT

int sarrusMeth(int row, int column, int table[row][column]) {
    int even;
    int odd;
    int det;
    even = table[0][0] * table[1][1] * table[2][2] + table[0][1] * table[1][2] * table[2][0] + table[0][2] * table[1][0] * table[2][1];
    odd = table[0][2] * table[1][1] * table[2][0] + table[0][1] * table[1][0] * table[2][2] + table[0][0] * table[1][2] * table[2][1];
    det = even - odd;
    return det;
}

//finding minors

int getCofactor(int refRow, int row, int column, int table[row][column]) {
  
    return 0;
}
//CALCULATE THE DETERMINANT USING LAPLACE METHOD 

int laplaceMeth(int row, int column, int table[row][column]) {
    int refRow;
    int inner;
    int outer;
    int determinant = 0;
    int expRow[row];
    int minor[row-1][column-1];
    printf("The application calculates the determinant via the cofactor\n");
    printf("Choose the row to expand on:\n");
    scanf("%d", &refRow);
    if (refRow <= row) {
     
    } else {
        printf("Reference error: The row you specified does not match!\n");
    }
    return determinant;
}
//CALCULATE THE TRANSPOSE OF A MATRIX

void transpose(int row, int column, int table[row][column]) {
    int outer;
    int inner;
    int transposeMat[column][row];
    for (outer = 0; outer < column; outer++) {
        for (inner = 0; inner < row; inner++) {
            transposeMat[outer][inner]=table[inner][outer];
        }
    }
    printf("The transpose is:\n");
    displayMatrix(column, row, transposeMat);   
}


