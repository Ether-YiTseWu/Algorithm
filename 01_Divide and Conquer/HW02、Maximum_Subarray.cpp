# include<iostream>
using namespace std;

int main()
{
    int *inputNum = new int[50001];
    int *breakIdx = new int(0), *maxSum = new int(0), *sum = new int(0);

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

    // Compute
    for (int i = 0; i<*breakIdx - 1; i++)
    {
        *sum = 0;
        if (i > 0 && (inputNum[i] < inputNum[i-1]) )
            continue;
        for (int j = i; j<*breakIdx - 1; j++)
        {
            *sum += inputNum[j];
            if (*sum > *maxSum)
                *maxSum = *sum;
        }
    }

    // Print
    cout << *maxSum << endl;

    delete []inputNum;
    delete breakIdx;
    delete maxSum;
    delete sum;

    return 0;
}
