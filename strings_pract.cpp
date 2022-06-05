#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;

int main(){

    string name;
    cout << "Enter the name:\n";
    getline(cin, name);

    cout << " My name is " << name << "\n";

    return 0;
}