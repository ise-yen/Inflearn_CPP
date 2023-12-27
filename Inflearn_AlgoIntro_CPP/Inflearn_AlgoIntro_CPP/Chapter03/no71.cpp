#include <iostream>
#include <queue>

using namespace std;

int S{}, E{};
int ch[10001]{};
void answer(int front) {
	int d[3] = { 1, -1, 5 };
	queue<int> q;
	q.push(front);
	ch[S] = 1;
	int pos{};
	while (!q.empty()) {
		front = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			pos = front + d[i];
			if (pos == E) {
				cout << ch[front];
				return;
			}
			if (ch[pos] == 0) {
				ch[pos] = ch[front] + 1;
				q.push(pos);
			}
		}
	}

	return;
}

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