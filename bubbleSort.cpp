#include<iostream>
using namespace std;

void swapEle(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int arr[], int n){
    bool swapped = true;

    while(swapped == true){
        swapped = false;
        for(int i = 0; i < n; i++){
            if(arr[i] > arr[i+1]){
                swapEle(&arr[i],&arr[i+1]);
                swapped = true;
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << arr[i] << "\t";

}
int main(){

    int a[] = {6,7,8,1,3,45,21,13,19,67,98};

    int n = sizeof(a)/sizeof(a[0]);

    
    for(int i = 0;i < n; i++)
        cout << a[i] << "\t";

    cout << endl;

    bubbleSort(a,n);

    return 0;

}