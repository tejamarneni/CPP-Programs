#include<iostream>
#include<list>
#include<math.h>
#include<cctype>
using namespace std;

int main()
{

    int choicenum;

    int amt = 0, adamt=0;

    char Y_N = 'y';

tryagain: /* Sends the loop back */
    cout << "1. Check Balance:" << endl;
    cout << "2. Deposite:" << endl;
    cout << "3. Withdraw:" << endl;

    cin >> choicenum;

    switch(choicenum){
        case 1:
            cout << "Your Balance is $" << amt << "\n";
            cout << "Do you want to try again? Press Y for yes, N for No" << "\n";
            cin >> Y_N;
            Y_N = tolower(Y_N); /* Changes the userchoice to lower case y or n */
            if (Y_N == 'y')
            {
                goto tryagain;
            }
            else if(Y_N == 'n')
            {
                cout << "Thank you for using the Service.\n";
                break;
            }

        case 2:
            cout << "Enter the amout to deposite:" << endl;
            cin >> adamt;
            amt += adamt;
            cout << "Your Total new balance is: $" << amt << endl;
            cout << "Do you want to try again? Press Y for yes, N for No" << "\n";
            cin >> Y_N;
            Y_N = tolower(Y_N);
            if (Y_N == 'y')
            {
                goto tryagain;
            }
            else if(Y_N == 'n')
            {
                cout << "Thank you for using the Service.\n";
                break;
            }
            
        case 3:
            cout << "Enter the amout to withdraw:" << endl;
            cin >> adamt;
            if (adamt > amt)
            {
                cout << "Your Balance is: $" << amt << "\n";
                cout << "The amout you entered is more than the amount in the account.\n";
                cout << "Do you want to try again? Press Y for yes, N for No" << "\n";
                cin >> Y_N;
                Y_N = tolower(Y_N);
                if (Y_N == 'y')
                {
                    goto tryagain;
                }
                else if(Y_N == 'n')
                {
                    cout << "Thank you for using the Service.\n";
                    break;
                }
            }  
            else if(amt > 0 && amt >= adamt)
            {
                amt -= adamt;
                cout << "Your Total new balance is: $" << amt << endl;
                cout << "Do you want to try again? Press Y for yes, N for No" << "\n";
                cin >> Y_N;
                Y_N = tolower(Y_N); 
                if (Y_N == 'y')
            {
                goto tryagain;
            }
            else if(Y_N == 'n')
            {
                cout << "Thank you for using the Service.\n";
                break;
            }
                
            } 

    }
    return 0;

}