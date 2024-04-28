#include<iostream>
#include<queue>

using namespace std;

const int MAX = 21;
int map[MAX][MAX];
bool isVisit[MAX][MAX];

int dir[][2] = { {1, 0}, {-1 ,0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

bool isInMap(int r, int c, int R, int C) {
	if (r >= 0 && r < R && c >= 0 && c < C) return true;
	else return false;
}

void bfs(int r, int c, int N) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	isVisit[r][c] = true;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int i = 0; i < sizeof(dir) / sizeof(dir[0]); i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (!isInMap(nr, nc, N, N)) continue;
			if (!map[nr][nc]) continue;
			if (isVisit[nr][nc]) continue;
			q.push({ nr, nc });
			isVisit[nr][nc] = true;
		}
	}
}

int main() {
	int N{}, answer{};
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !isVisit[i][j]) {
				bfs(i, j, N);
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}