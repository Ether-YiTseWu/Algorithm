# include <iostream>
using namespace std;

int main()
{
	// Setup
	int* start = new int, * D = new int, * I = new int, * index = new int(1);
	cin >> *start;

	// Compute
	while ((*start)--)
	{
		cin >> *D >> *I;
		if (*D == 1)
		{
			cout << "1" << endl;
			continue;
		}
		for (int i = 0; i < *D -1; i++)
		{
			if (*I % 2 == 0)
				*index = *index * 2 + 1, * I /= 2;
			else
				*index *= 2, *I = (*I+1)/2;
		}
		cout << *index << endl;
		*index = 1;
	}

	// -1
	cin >> *start;

	// Delete
	delete start;
	delete D;
	delete I;
	delete index;

	return 0;
}
