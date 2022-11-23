#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_36 {
public:
	LeetCode_36() {
		vector<vector<char>> board = { 
			{'.','.','.','.','5','.','.','1','.'},
			{'.','4','.','3','.','.','.','.','.'},
			{'.','.','.','.','.','3','.','.','1'},
			{'8','.','.','.','.','.','.','2','.'},
			{'.','.','2','.','7','.','.','.','.'},
			{'.','1','5','.','.','.','.','.','.'},
			{'.','.','.','.','.','2','.','.','.'},
			{'.','2','.','9','.','.','.','.','.'},
			{'.','.','4','.','.','.','.','.','.'} };

		printf("%s\n", isValidSudoku(board) ? "true" : "false");
	}

    bool isValidSudoku(vector<vector<char>>& board) {
		vector<char> c(9);

		for (vector<char>& r : board) {
			for (char& g : r) {
				if (g == '.')
					continue;

				for (char& v : c) {
					if (g == v) {
						return false;
					}
				}

				c.push_back(g);
			}

			c.clear();
		}

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[j][i] == '.')
					continue;

				for (char& v : c) {
					if (board[j][i] == v) {
						return false;
					}
				}

				c.push_back(board[j][i]);
			}

			c.clear();
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int x = i * 3; x < (i + 1) * 3; ++x) {
					for (int y = j * 3; y < (j + 1) * 3; ++y) {
						if (board[x][y] == '.')
							continue;

						for (char& v : c) {
							if (board[x][y] == v) {
								return false;
							}
						}

						c.push_back(board[x][y]);
					}
				}

				c.clear();
			}
		}

		return true;
    }
};
