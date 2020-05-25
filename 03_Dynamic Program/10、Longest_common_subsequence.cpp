# include <iostream>
# include <string>
using namespace std;

int main()
{
	// Setup
	string s1, s2;
	int** smallAnsArray, s1Length, s2Length, arrRowSize, arrColumnSize;

	cin >> s1 >> s2;

	s1Length = s1.size(), s2Length = s2.size();
	arrRowSize = s1Length + 1, arrColumnSize = s2Length + 1;

	smallAnsArray = new int* [arrRowSize];
	for (int i = 0; i < arrRowSize; i++)
		smallAnsArray[i] = new int[arrColumnSize];

	for (int i = 0; i < arrRowSize; i++)
		smallAnsArray[i][0] = 0;
	for (int i = 0; i < arrColumnSize; i++)
		smallAnsArray[0][i] = 0;

	// Compute
	for (int i = 1; i < arrRowSize; i++)
	{
		for (int j = 1; j < arrColumnSize; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				smallAnsArray[i][j] = smallAnsArray[i - 1][j - 1] + 1;
			else if (smallAnsArray[i - 1][j] >= smallAnsArray[i][j - 1])
				smallAnsArray[i][j] = smallAnsArray[i - 1][j];
			else
				smallAnsArray[i][j] = smallAnsArray[i][j - 1];
		}
	}
    /*
	for (int i = 0; i < arrRowSize; i++)
	{
		for (int j = 0; j < arrColumnSize; j++)
			cout << smallAnsArray[i][j] << ", ";
		cout << endl;
	}*/

	// Print Ans
	cout << smallAnsArray[s1Length][s2Length] << endl;

	return 0;
}
