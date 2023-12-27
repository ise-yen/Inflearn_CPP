// 못 풀었음
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N{}, M{};
	cin >> N >> M;
	vector<int> map[30];
	vector<int> dis(N+1);
	vector<bool> isVisit(N + 1);

	for (int i = 0; i < M; i++) {
		int r{}, c{};
		cin >> r >> c;
		map[r].push_back(c);
	}

	queue<int> q;
	q.push(1);
	isVisit[1] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < map[front].size(); i++) {
			int next = map[front][i];
			// 방문 체크
			if (!isVisit[next]) {
				isVisit[next] = true;
				q.push(next);
				dis[next] = dis[front] + 1;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << i << " : " << dis[i] << "\n";
	}

	return 0;
}