# include <iostream>
# include <algorithm>
using namespace std;

int main()
{
    // Input
    int length, price[50001][2], idx = 1;
    cin >> length;
    while(cin >> price[idx][0] >> price[idx][1])
    {
        if (price[idx][0] == 0 && price[idx][1] == 0)
            break;
        idx ++;
    }

    // Setup
    int *smallAnsArray = new int[length + 1], smallAns;
    smallAnsArray[0] = 0;

    // Compute
    for (int i = 1 ; i < length + 1 ; i++)
    {
        smallAns = -999;
        for (int j = 1 ; j <= i ; j++)
            smallAns =  max(smallAns, price[j][1] + smallAnsArray[i-j]);
        smallAnsArray[i] = smallAns;
    }

    // Print Ans
    cout << smallAnsArray[length] << endl;

    delete []smallAnsArray;
    return 0;
}
