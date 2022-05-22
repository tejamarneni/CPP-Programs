#include<iostream>
using std::cout;
using std::cin;

int main(){

    int size;
    cout << "Enter the size of the array:\n";
    cin >> size;

    float *myArray = new float[size];

    for(int i = 0; i<size; i++){
        cout << "Enter " << i << " Element:\n";
        cin >> myArray[i];
    }

     for(int i = 0; i<size; i++){
        cout << myArray[i] << "\n";
    }

    delete[]myArray;
    myArray = NULL;
    return 0;
}