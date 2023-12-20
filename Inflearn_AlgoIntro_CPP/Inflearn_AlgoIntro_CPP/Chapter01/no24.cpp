#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N{}, pre{};
	cin >> N;
	vector<bool> v(N, false);

	cin >> pre;
	bool isJolly = true;

	for (int i = 1; i < N; i++) {
		int now{};
		cin >> now;
		int a = abs(pre - now);
		if (a > 0 && a < N) v[a] = true;
		pre = now;
	}

	for (int i = 1; i < N; i++) {
		if (!v[i]) {
			isJolly = false;
			break;
		}
	}

	if (isJolly) cout << "YES";
	else cout << "NO";
	return 0;
}