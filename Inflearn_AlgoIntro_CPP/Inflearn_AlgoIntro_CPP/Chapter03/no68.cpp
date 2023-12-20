#include <iostream>
#include <vector>

using namespace std;

int N{}, M{}, minW = 1e9;
vector<pair<int, int>> map[21];
bool isVisit[21];

void dfs(int n, int sum) {
	if (n == N) {
		minW = minW < sum ? minW : sum;
		return;
	}

	for (int i = 0; i < map[n].size(); i++) {
		int nn = map[n][i].first;
		int w = map[n][i].second;

		if (isVisit[nn]) continue;
		isVisit[nn] = true;
		dfs(nn, sum + w);
		isVisit[nn] = false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		map[s].push_back({ e, w });
	}

	isVisit[1] = true;
	dfs(1, 0);

	cout << minW;

	return 0;
}