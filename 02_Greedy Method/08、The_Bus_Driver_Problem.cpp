# include <iostream>
# include <algorithm>
using namespace std;

int main()
{
    while (1)
    {
        // Input
        int n, limit, cost;
        cin >> n >> limit >> cost;
        if (n == 0 && limit == 0 && cost == 0)
            break;
        int pathMorning[n], pathEvening[n], sumPath, sumCost = 0;

        for (int i = 0; i < n ; i++)
            cin >> pathMorning[i];
        for (int i = 0; i < n ; i++)
            cin >> pathEvening[i];

        // Sort
        sort (pathMorning, &pathMorning[n]);
        sort (pathEvening, &pathEvening[n]);

        // Compute
        for (int i = 0; i < n ; i++)
        {
            sumPath = pathMorning[i] + pathEvening[n - (i+1)];
            if (sumPath > limit)
                sumCost += ((sumPath - limit)*cost);
        }

        // Print Ans
        cout << sumCost << endl;
    }
    return 0;
}
