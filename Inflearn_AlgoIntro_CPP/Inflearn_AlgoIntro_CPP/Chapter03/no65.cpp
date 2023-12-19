#include <iostream>

using namespace std;

int map[8][8]{};
bool isVisit[8][8]{};
int N = 7;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isInMap(int r, int c) {
	if (r >= 1 && c >= 1 && r <= N && c <= N) return true;
	else return false;
}

int res{};
void dfs(int r, int c) {
	if (r == N && c == N) {
		res++;
		return;
	}

	isVisit[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dir[i][0];
		int nc = c + dir[i][1];
		if (!isInMap(nr, nc)) continue;
		if (map[nr][nc] == 0) {
			if (isVisit[nr][nc]) continue;
			isVisit[nr][nc] = true;
			dfs(nr, nc);
			isVisit[nr][nc] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 1);
	cout << res;
	return 0;
}