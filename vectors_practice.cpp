#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){

    vector<float> items;
    int n;
    float j;

    cout << "Enter the size of Vector:\n";
    cin >> n;
    cout << endl;

    for(int i = 0; i < n; i++){
        cout << "Enter the number:\n";
        cin >> j;
        items.push_back(j);
    }

    cout << endl;

     for(int i = 0; i < n; i++)
        cout << items[i] << endl;

    cout << items.size();

    return 0;
    
}