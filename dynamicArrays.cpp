#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){

    int size;

    float *myArr = new float[size];

    cout << "Enter the number:\n";
    cin >> size;
    cout << endl;

    for(int i = 0; i<size; i++){
        cout << "Enter the number:\n";
        cin >> myArr[i];
    }

    cout << endl;

    for(int i = 0; i<size; i++){
        cout << myArr[i] << "\n";
    }

    cout << endl;

    for(int i = 0; i<size; i++){
        cout << *(myArr+i) << "\n";
    }

    delete[]myArr;
    myArr = NULL;
    
    return 0;


}