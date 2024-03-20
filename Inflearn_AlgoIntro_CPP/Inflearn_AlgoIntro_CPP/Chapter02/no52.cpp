#include<iostream>
#include<vector>

using namespace std;

int ugly[3] = { 2, 3, 5 };

int main() {
	int N{}, cnt{};
	cin >> N;

	int n = 0;
	while(true) {
		n++;
		int tmp = n;
		bool isUgly = true;
		while (tmp > 1) {
			isUgly = false;
			for (int u = 0; u < 3; u++) {
				if (tmp % ugly[u] == 0) {
					tmp /= ugly[u];
					isUgly = true;
				}
			}

			if (tmp == 1) {
				isUgly = true;
				break;
			}
			if (isUgly) continue;
			else break;
		}
		if (isUgly) cnt++;
		if (cnt == N) break;
	}

	cout << n;

	return 0;
}