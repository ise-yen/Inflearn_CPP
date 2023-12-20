#include <iostream>
#include <vector>

using namespace std;

vector<int> map[21];
int isVisit[21];
int N{}, M{}, res{};

void dfs(int node) {
	if (node == N) {
		res++;
		return;
	}

	for (int i = 0; i < map[node].size(); i++) {
		int nextNode = map[node][i];
		if (isVisit[nextNode]) continue;
		isVisit[nextNode] = true;
		dfs(nextNode);
		isVisit[nextNode] = false;
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int r{}, c{};
		cin >> r >> c;
		map[r].push_back(c);
	}

	isVisit[1] = true;
	dfs(1);
	cout << res;

	return 0;
}