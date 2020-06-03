# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

int smallAnsArr[8000][201], itemTake[8000][201];

int main()
{
	// Setup
	int idx = 0, bagCapacity, data[8000][3], highestValue = 0;
	cin >> bagCapacity;
	while (cin >> data[idx][0] >> data[idx][1] >> data[idx][2])
	{
		if (data[idx][0] == -1 && data[idx][1] == -1 && data[idx][2] == -1)
			break;
		idx++;
	}
	for (int i = 0; i < bagCapacity + 1; i++)
		for (int j = 0; j < 201; j++)
			smallAnsArr[i][j] = 0, itemTake[i][j] = 0;

	// Compute
	int tempSmallAns, lowerIdx;
	for (int i = 0; i < idx; i++)
	{
		for (int j = 0; j < bagCapacity + 1; j++)
		{
			if (j >= data[i][1])
			{
				lowerIdx = j - data[i][1];
				tempSmallAns = max(smallAnsArr[i][lowerIdx] + data[i][2], smallAnsArr[i][j]);
				smallAnsArr[i + 1][j] = tempSmallAns;
				if (smallAnsArr[i][lowerIdx] + data[i][2] > smallAnsArr[i][j])
					itemTake[i][j] = 1;
			}
			else
				smallAnsArr[i + 1][j] = smallAnsArr[i][j];
		}
	}

	// Print
	for (int i = idx, j = bagCapacity; i >= 0; i--)
		if (itemTake[i][j] == 1)
			cout << i+data[0][0] << " ", j -= data[i][1];
	cout << endl << smallAnsArr[idx][bagCapacity] << endl;

	return 0;
}
