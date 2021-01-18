#include<iostream>
using namespace std;

void selectionSort(int arr[],int arr_size){
    int mark = 0, temp = 0;

    cout << "Before: ";
    for(int j = 0; j < arr_size; j++)
        cout << arr[j] << "\t";

    cout << endl;

    while(mark < arr_size){
        for(int i = mark; i < arr_size; i++){
            if(arr[i] < arr[mark]){
                temp = arr[i];
                arr[i] = arr[mark];
                arr[mark] = temp;
            }
        }
        mark += 1;
    }

    cout << "After: ";
    for(int j = 0; j < arr_size; j++)
        cout << arr[j] << "\t";

    cout << endl;    
    
}
int main(){

    int a[] = {3,19,5,1,-6,0,4,23};
    int n = sizeof(a)/sizeof(a[0]);

    selectionSort(a,n);

    return 0;
}