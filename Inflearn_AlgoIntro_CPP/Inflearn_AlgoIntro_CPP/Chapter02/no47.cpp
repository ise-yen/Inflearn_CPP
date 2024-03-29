#include <iostream>

using namespace std;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int map[60][60];

int main() {
	int N{};
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int cnt{};
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			bool isUp = true;
			for (int i = 0; i < 4; i++) {
				int nr = r + dir[i][0];
				int nc = c + dir[i][1];
				if (map[r][c] <= map[nr][nc]) {
					isUp = false;
					break;
				}
			}
			if (isUp) cnt++;
		}
	}

	cout << cnt;
	return 0;
}