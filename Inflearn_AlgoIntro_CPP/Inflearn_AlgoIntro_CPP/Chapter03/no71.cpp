#include <iostream>
#include <queue>

using namespace std;

int S{}, E{};

void bfs(int now) {
	queue<int> q;
	q.push(now);

	int cnt = -1;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		cnt++;
		if (now == E) {
			cout << cnt;
			break;
		}
		else if (now + 3 <= E) {
			q.push(now + 5);
		}
		else if (now < E) {
			q.push(now + 1);
		}
		else if (now > E) {
			q.push(now - 1);
		}
	}
}

int main() {
	cin >> S >> E;
	
	bfs(S);
	return 0;
}