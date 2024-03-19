#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N{}, K{};
	cin >> N >> K;

	queue<int> q;
	for (int n = 1; n <= N; n++) q.push(n);
	int i{}, f{};
	while (!q.empty()) {
		i++;
		f = q.front();
		q.pop();
		if (i == K) i = 0;
		else q.push(f);
	}

	cout << f;

	return 0;
}