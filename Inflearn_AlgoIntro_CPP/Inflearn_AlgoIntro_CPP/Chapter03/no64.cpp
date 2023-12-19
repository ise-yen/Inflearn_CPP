#include <iostream>
#include <vector>

using namespace std;

bool map[21][21]{};
bool isVisit[21]{};

int cnt{};


void dfs(int start, int N) {
	if (start == N) {
		cnt++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (map[start][i]) {
			if (isVisit[i]) continue;
			isVisit[start] = true;
			dfs(i, N);
			isVisit[start] = false;
		}
	}
}

int main() {
	int N{}, M{};
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a{}, b{};
		cin >> a >> b;
		map[a][b] = true;
	}

	dfs(1, N);

	cout << cnt;
	return 0;
}