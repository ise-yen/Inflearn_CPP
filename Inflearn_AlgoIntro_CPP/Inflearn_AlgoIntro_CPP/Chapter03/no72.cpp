#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N{}, K{};
	cin >> N >> K;
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	int k = 0;
	while (q.size() > 1) {
		k++;
		int f = q.front();
		q.pop();
		if (k == K) {
			k = 0;
		}
		else {
			q.push(f);
		}
	}

	cout << q.front();

	return 0;
}