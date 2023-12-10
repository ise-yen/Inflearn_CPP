#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N{};
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int cnt{};
		for (int j = 1; j <= (int)sqrt(i); j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		cnt *= 2;

		if ((int)sqrt(i) * (int)sqrt(i) == i) {
			cnt--;
		}
		cout << cnt << " ";
	}

	return 0;
}

int cnt[50001];
void answer() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			cnt[j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << cnt[i] << " ";
	}
}