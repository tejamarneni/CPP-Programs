#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[],int n){
    
    for(int i = 0; i< n-1; i++){
        for(int j = 0; j < n-i-1;j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }

    for(int i = 0; i< n;i++)
        cout << arr[i] << "\t";
    
}
int main()
{
    
    int a[] ={6,2,9,10,21,32,5,1};

    int n = sizeof(a)/sizeof(a[0]);

    for(int i = 0; i< sizeof(a)/sizeof(a[0]);i++)
        cout << a[i] << "\t";

    cout << "\n";
    bubbleSort(a,n);    

    
    return 0;
}