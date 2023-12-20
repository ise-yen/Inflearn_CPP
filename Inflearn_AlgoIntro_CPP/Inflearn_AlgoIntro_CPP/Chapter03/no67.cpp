#include <iostream>
#include <vector>

using namespace std;

int N{}, M{}, minW = 1e9;
int map[21][21];
bool isVisit[21];

void dfs(int n, int sum) {
	if (n == N) {
		minW = minW < sum ? minW : sum;
		return;
	}

	for (int i = 1; i <= N; i++) {
		int w = map[n][i];

		if (isVisit[i]) continue;
		if (map[n][i] != 0) {
			isVisit[i] = true;
			dfs(i, sum + w);
			isVisit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		map[s][e] = w;
	}

	isVisit[1] = true;
	dfs(1, 0);

	cout << minW;

	return 0;
}