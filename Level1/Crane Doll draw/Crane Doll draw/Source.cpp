#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	vector<int> bucket;
	bool nextMove;
	for (int i = 0; i < moves.size(); i++)
	{
		nextMove = false;
		for (int j = 0; j < board.size(); j++)
		{
			for (int k = 0; k < board[j].size(); k++)
			{
				if (board[j][k] != 0 && (k + 1) == moves[i])
				{
					bucket.push_back(board[j][k]);
					board[j][k] = 0;
					nextMove = true;

					if (bucket.size() >= 2)
					{
						int top1 = bucket.back();
						bucket.pop_back();
						int top2 = bucket.back();
						bucket.pop_back();
						answer += 2;
						if (top1 != top2)
						{
							bucket.push_back(top2);
							bucket.push_back(top1);
							answer -= 2;
						}
					}

					break;
				}
			}

			if (nextMove)
				break;
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> board{
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 3},
		{0, 2, 5, 0, 1},
		{4, 2, 4, 4, 2},
		{3, 5, 1, 3, 1}
	};

	vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
	cout << solution(board, moves) << "\n";

	return 0;
}