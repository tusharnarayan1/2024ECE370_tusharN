#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> v;
    string input;
    int maxlen = 0;
    int counter = 0;
    int maxindex = 0;
    while (true)
    {
        cout << "Enter a string:" << endl;
        cin >> input;
        v.push_back(input);
        counter++;
        if (input.length() > maxlen)
        {
            maxlen = input.length();
            maxindex = counter;
        }
        if (input == "exit")
        {
            break; 
        }

    }

    cout << "The longest string is:" << v[maxindex];


}