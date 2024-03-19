#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N{}, K{};
	cin >> N;

	queue<pair<int, int>> q;
	for (int n = 1; n <= N; n++) {
		int t{};
		cin >> t;
		q.push({ n, t});
	}

	cin >> K;

	while (K > 0) {
		K--;
		int n = q.front().first;
		int t = q.front().second - 1;
		q.pop();
		if(t != 0) q.push({ n, t });
	}

	if (q.empty()) cout << -1;
	else cout << q.front().first;

	return 0;
}