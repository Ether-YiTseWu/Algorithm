# include <iostream>
# include <algorithm>
# include <iomanip>
using namespace std;

int main()
{
    // Setup
    int bagSpace, endIdx = 0;
    double data[40000][3], unitPrice[40000], ans = 0;
    cin >> bagSpace;
    while(cin >> data[endIdx][0] >> data[endIdx][1])
    {
        data[endIdx][2] = unitPrice[endIdx] = data[endIdx][0] / data[endIdx][1];
        endIdx ++;
    }

    // Compute
    sort(unitPrice, &unitPrice[endIdx]);
    for (int i = (endIdx - 1) ; i >= 0 ; i--)
    {
        int idx;
        for (int j = 0 ; j < endIdx ; j++)
        {
            if (unitPrice[i] == data[j][2])
            {
                idx = j;
                break;
            }
        }
        if (bagSpace <= 0)
            break;
        else if (bagSpace >= data[idx][1])
        {
            ans      += data[idx][0];
            bagSpace -= data[idx][1];
        }
        else if (bagSpace < data[idx][1])
        {
            ans      += (bagSpace*unitPrice[i]);
            bagSpace = 0;
        }
    }

    // Print Ans
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}
