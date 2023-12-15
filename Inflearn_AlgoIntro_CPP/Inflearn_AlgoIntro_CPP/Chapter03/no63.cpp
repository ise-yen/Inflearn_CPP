#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N{}, M{};

	cin >> N >> M;
	vector<int> v(N+1, 0);
	vector<vector<int>> map(N+1, v);

	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		map[s][e] = w;
	}

	for (int i = 1; i < map.size(); i++) {
		for (int j = 1; j < map[i].size(); j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}