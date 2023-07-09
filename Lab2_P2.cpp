/*
* C++ code that displays a secret message (3 letters long) on result.txt from the input.txt file based on number of occurances
* CECS 275 - Spring 2022
* @Everardo Camarena
* @Calvin Veith
* version 1.0.0
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    //grab the data from the input.txt file, integrates into the code
    ifstream fin;
    fin.open("input.txt");
    
    //open the result.txt file to display the secret message on there
    ofstream fout;
    fout.open("result.txt");
    
    //grab the input n from the user, for number of occurences
    int n;
    cout<<"Enter value of N: "; cin>>n;
    
    //store our string from input.txt
    string st;

    //read each string in input.txt
    while(fin>>st)
    {
        int count_max = 0;
        string sub_st_max;

        //track our sub-string size
        for(int i=0; st[i+(n-1)]!='\0'; ++i)
        {
            string sub_st = st.substr(i, 3);
            int count = 0;
            //for each sub-string we track the occurence
            for(int j=0; st[j+(n-1)]!='\0'; ++j)
            {
            	//create a flag to see if the sub-string is enough to fufill size of 3
                int flag = 1;
                for(int k=0; k<=(n-1); ++k)
                {
                    if(sub_st[k] != st[j + k])
                        flag = 0;
                }
                if(flag == 1)
                    count++;
            }
            //if the occurence is greater than previous max update the max count and then store the sub-string
            if(count > count_max)
            {
                count_max = count;
                sub_st_max = sub_st;
            }
        }
        
        //display the sub-string that has max occurences, secret message
        cout<<st<<" "<<"secret message is: "<<sub_st_max<<endl;
        
        //write the result into result.txt
        fout<<sub_st_max<<endl;
    }
    
    //close up the files after use
    fin.close();
    fout.close();
    return 0;
}