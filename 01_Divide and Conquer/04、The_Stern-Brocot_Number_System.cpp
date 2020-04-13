#include <iostream>
using namespace std;

int main()
{
    // Setup
    int *n = new int, *m = new int;
    int *Ln = new int, *Ld = new int, *Mn = new int, *Md = new int, *Rn = new int, *Rd = new int;

    while(1)
    {
        // User Input
        cin >> *n >> *m;
        if (*n == 1 && *m == 1)
            break;
        long double *Fdd = new long double, *Mdd = new long double;
        *Ln = *Rd = 0, *Ld = *Mn = *Md = *Rn = 1;
        *Fdd = *n / (long double)*m, *Mdd = *Mn / (long double)*Md;

        // Compute
        while(!(*Md == *m && *Mn == *n))
        {
            if(*Fdd > *Mdd)
            {
                *Ln = *Mn;
                *Ld = *Md;
                *Mn += *Rn;
                *Md += *Rd;
                cout << "R";
            }
            else
            {
                *Rn = *Mn;
                *Rd = *Md;
                *Mn += *Ln;
                *Md += *Ld;
                cout << "L";
            }
            *Mdd = *Mn / (long double)*Md;
        }
        cout << endl;
        delete Fdd;
        delete Mdd;
    }

    // Delete
    delete n;
    delete m;
    delete Ln;
    delete Ld;
    delete Mn;
    delete Md;
    delete Rn;
    delete Rd;

    return 0;
}
