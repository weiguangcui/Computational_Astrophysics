//
// Created by weiguang on 10/04/24.
//
/*In this code, we first allocate memory for x number of 2D arrays. Then for each 2D array, we allocate memory for y
 * number of 1D arrays. Finally, for each 1D array, we allocate memory for z number of integers.
 *
 * When deallocating, we must deallocate in the reverse order of allocation. First, we deallocate each 1D array, then
 * each 2D array, and finally the 3D array itself.*/
#include <iostream>

//
int main() {
    // Dimensions of the 3D array
    int x = 10;
    int y = 20;
    int z = 30;

    // Allocate memory
    int*** array = new int**[x];
    for(int i = 0; i < x; ++i) {
        array[i] = new int*[y];
        for(int j = 0; j < y; ++j) {
            array[i][j] = new int[z];
        }
    }

    // Use the array
    array[0][0][0]=1;
    array[1][2][3]=2;
    std::cout << ***array << std::endl; // Outputs: 1
    std::cout  << "array[1][2][3] =" << *(*(*(array+1)+2)+3)<< std::endl; // Outputs: 2
    // std::cout  << "array[1][2][3] =" << ***(array+1*y*z+2*z+3)<< std::endl; // This won't work because the whole memory is not saved in one block!!

    // Deallocate memory
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j) {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;


    // to have the above problematic line (32) work, we need to allocate memory for the whole 3D array in one block.
    int* data     = new int[x * y * z];        // contiguous block
    int** rows    = new int*[x * y];            // row pointers
    array  = new int**[x];              // slice pointers

    for (int i = 0; i < x; ++i) {
        array[i] = rows + i * y;
        for (int j = 0; j < y; ++j) {
            array[i][j] = data + (i * y + j) * z;
        }
    }
    array[1][2][3]=20;
    std::cout << "array[1][2][3] =" << *(*(*(array+1)+2)+3)<< std::endl; // Outputs: 20
    std::cout << "array[1][2][3] =" << *(data+1*y*z+2*z+3)<< std::endl; // now this should work!!

    // Deallocate memory
    delete[] data;
    delete[] rows;
    delete[] array;

    return 0;
}