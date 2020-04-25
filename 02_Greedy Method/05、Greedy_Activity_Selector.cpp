# include<iostream>
# define dataLength 30000
using namespace std;

int main()
{
    // Setup
    int *temp = new int, *activityStart = new int[dataLength], *activityEnd = new int[dataLength];
    int *dataNo = new int(0), *tempAnsIdx = new int(0);
    bool *ans = new bool[dataLength];
    for (int i = 0 ; i< dataLength ; i++)
        ans[i] = 0;
    ans[0] = 1;

    // User Input
    while(!(cin.eof()))
    {
        cin >> *temp >> activityStart[*dataNo] >> activityEnd[*dataNo] ;
        (*dataNo)++;
    }
    (*dataNo) --;

    // Compute
    for (int i = 1 ; i< *dataNo ; i++)
        if ((activityStart[i] >= activityEnd[*tempAnsIdx]))
            ans[i] = 1, *tempAnsIdx = i;

    // Print Ans
    for (int i = 0 ; i< *dataNo ; i++)
        if (ans[i] == 1)
            cout << i+1 << " ";
    cout << endl;

    // Delete
    delete []activityStart;
    delete []activityEnd;
    delete []ans;
    delete temp;
    delete dataNo;
    delete tempAnsIdx;

    return 0;
}
