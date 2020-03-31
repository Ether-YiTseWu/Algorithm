#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Setup
    int *inputNum = new int[50001], *breakIdx = new int, *temp = new int;

    // Input
    for (int i = 0; i<50001 ; i++)
    {
        if(cin.eof())
        {
            *breakIdx = i;
            break;
        }
        cin >> inputNum[i];
    }

    // Function from "algorithm" header file
    sort(inputNum, inputNum + (*breakIdx -1));

    // Bubble sort
    /*
    for (int i = 0; i< *breakIdx -1 ; i++)
    {
        for (int j = i+1; j< *breakIdx -1 ; j++)
        {
            if(inputNum[i] > inputNum[j])
            {
                *temp = inputNum[i];
                inputNum[i] = inputNum[j];
                inputNum[j] = *temp;
            }
        }
    }
    */

    // Print
    for (int i = 0; i< *breakIdx -1 ; i++)
        cout << inputNum[i] << " ";
    cout << endl;

    delete []inputNum;
    delete breakIdx;
    delete temp;

    return 0;
}
