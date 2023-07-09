/*
 * This C++ program displays the total number of digit that givin by user 
 * CECS 275 - Spring 2022 
 * @author Calvin Veith 
 * @author Everardo Camarena
 * @version 2.18.2022
 *
 */
  #include <iostream>
  #include <string>
  #include <fstream>
   using namespace std;

   ofstream outfile;

 int main(){
// delcare place holders for user input that is a number
 int getnum;

 // declare a place holder of yes and no question and set to y or Y for yes
 char TryItAgein = 'y';

 // declare other vable
 int NextNum;
 int digit;
 int addDigit;

 // open file
 outfile.open("Problem1.txt");
while (TryItAgein == 'y' || TryItAgein == 'Y')
{
    // ask the user for a postive n umber
    cout << "Please enter a postive number: "<< endl;
    cin >> getnum;

    // set or reset the declare vables
    NextNum = getnum;
    addDigit = 0;

    // check the user number is postive
    if (getnum < 0){
        outfile << "You had enter a negtive Number. please enter a postive number. " << endl;
        cout << "You had enter a negtive Number. please enter a postive number. " << endl;
        TryItAgein = 'y';
     }
    else if (getnum == 0){
        cout << "You had enter Number Zero. please enter a postive number." << endl;
        outfile << "You had enter Number Zero. please enter a postive number." << endl;
        TryItAgein = 'y';
    }
    else{

        while (NextNum > 0)
        {
            digit = NextNum % 10;
            addDigit = addDigit + digit;
            NextNum = NextNum / 10;
        }
        // write the output
        outfile << "You have enter " << getnum << endl;
        outfile << "The Sum of all the digit of " << getnum << " is " << addDigit << "." << endl;
        cout << "You have enter " << getnum << endl;
        cout << "The Sum of all the digit of " << getnum << " is " << addDigit << "." << endl;
        
        
        // use a space or any other letter to get in the while loop BESIDE n/N or y/Y
        TryItAgein = ' ';
        while (TryItAgein != 'n' || TryItAgein != 'N' || TryItAgein != 'y' || TryItAgein != 'Y')
        {
            cout << "You want to try a different number? (Y/N): ";
            cin >> TryItAgein;
            outfile << "You want to try a different number? (Y/N): " << TryItAgein << endl;
            if (TryItAgein == 'n' || TryItAgein == 'N'){
                outfile << "Thank for using the progarm and Problem1.txt will hold all the activity" << endl;
                cout << "Thank for using the progarm and Problem1.txt will hold all the activity" << endl;
                break;
            }
            else if (TryItAgein == 'y' || TryItAgein == 'Y')
            {
                break;
            }
            else
            {
                outfile << "invaild anwser. Please try Again" << endl;
                cout << "invaild anwser. Please try Again" << endl;
            }
        }
        
    }   
}
    outfile.close();
    return 0;
}
