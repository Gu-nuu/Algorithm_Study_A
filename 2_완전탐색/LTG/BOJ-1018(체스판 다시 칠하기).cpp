#include <iostream>
#include <string>

using namespace std;

int main() {
	int row, col;
	string *board;
	string B_first[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
	};
	string W_first[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
	};

	cin >> row >> col;
	board = new string[row];

	for (int i = 0; i < row; i++) {
		cin >> board[i];
	}

	int B_count, W_count, min = 32;

	for (int i = 0; i <= row - 8; i++) {
		for (int j = 0; j <= col - 8; j++) {
			B_count = 0;
			W_count = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (board[i + k][j + l] != B_first[k][l])
						B_count++;
					if (board[i + k][j + l] != W_first[k][l])
						W_count++;
				}
			}
			if (B_count < W_count) {
				if (B_count < min)
					min = B_count;
			}
			else {
				if (W_count < min)
					min = W_count;
			}
		}
	}
	cout << min;
}