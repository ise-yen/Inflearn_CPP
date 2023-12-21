#include <iostream>
#include <queue>

using namespace std;

int map[8][8];
bool isVisit[7]{};
void bfs(int node) {
	queue<int> q;
	q.push(node);
	isVisit[node] = true;

	while (!q.empty()) {
		node = q.front();
		cout << node << " ";
		q.pop();
		for (int i = 1; i <= 7; i++) {
			if (map[node][i] == 1 && !isVisit[i]) {
				q.push(i);
				isVisit[i] = true;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 6; i++) {
		int a{}, b{};
		cin >> a >> b;
		map[a][b] = 1;
	}

	bfs(1);

	return 0;
}