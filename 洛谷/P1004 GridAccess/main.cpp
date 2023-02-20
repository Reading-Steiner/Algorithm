#include <iostream>
using namespace std;

constexpr int maxSize = 10;
int Chessboard[maxSize][maxSize]{};
int MaxValue[maxSize][maxSize][2 * maxSize]{};

int main()
{
	ios::sync_with_stdio(false);

	int size;
	cin >> size;
	while (true)
	{
		int x, y, value;
		cin >> x >> y >> value;
		Chessboard[x][y] = value;
		if ((x | y | value) == 0)
			break;
	}

	for (int l = 2; l <= 2 * size; l++)
	{
		for (int x1 = max(1, l - size); x1 <= min(size, l); x1++)
		{
			for (int x2 = max(1, l - size); x2 <= min(size, l); x2++)
			{
				if (x1 == x2)
				{
					MaxValue[x1][x2][l] = 
						max(max(MaxValue[x1 - 1][x2][l - 1], MaxValue[x1][x2 - 1][l - 1]), 
							max(MaxValue[x1 - 1][x2 - 1][l - 1], MaxValue[x1][x2][l - 1])) +
						Chessboard[x1][l - x1];
				}
				else
				{
					MaxValue[x1][x2][l] = 
						max(max(MaxValue[x1 - 1][x2][l - 1], MaxValue[x1][x2 - 1][l - 1]),
							max(MaxValue[x1 - 1][x2 - 1][l - 1], MaxValue[x1][x2][l - 1])) + 
						Chessboard[x1][l - x1] + Chessboard[x2][l - x2];
				}
			}
		}
	}
	cout << MaxValue[size][size][2 * size];
}