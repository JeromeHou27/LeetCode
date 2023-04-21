#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_79 {
public:
	LeetCode_79() {
		vector<vector<char>> board = { {'A','B','C','E'} ,{'S','F','C','S'},{'A','D','E','E'} };
		string word = "ABCCED";

		printf("%s\n", exist(board, word) ? "true" : "false");
	}

	vector<short> logs;
	short pos = 0;

	bool run(vector<vector<char>>& board, char x, char y, string& word, char& offset) {
		pos = y * 100 + x;
		for (short& log : logs) {
			if (log == pos)
				return false;
		}

		if (board[y][x] != word[offset])
			return false;

		if (offset + 1 >= word.size())
			return true;

		logs.push_back(y * 100 + x);
		++offset;

		if (x - 1 >= 0 && run(board, x - 1, y, word, offset))
			return true;

		if (x + 1 < board[y].size() && run(board, x + 1, y, word, offset))
			return true;

		if (y - 1 >= 0 && run(board, x, y - 1, word, offset))
			return true;

		if (y + 1 < board.size() && run(board, x, y + 1, word, offset))
			return true;

		logs.pop_back();
		--offset;

		return false;
	}

    bool exist(vector<vector<char>>& board, string word) {
		char x = 0;
		char y = 0;
		char offset = 0;

		logs.reserve(word.size());

		if (board.size() * board[0].size() < word.size())
			return false;

		for (y = 0; y < board.size(); ++y) {
			for (x = 0; x < board[y].size(); ++x) {
				if (run(board, x, y, word, offset))
					return true;
			}
		}

		return false;
    }
};
