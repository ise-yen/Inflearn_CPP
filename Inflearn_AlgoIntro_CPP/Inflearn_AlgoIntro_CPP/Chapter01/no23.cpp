#include <iostream>

using namespace std;

void answer() {
	int N, pre, cnt = 0, max = 0;
	cin >> N;
	cin >> pre;
	cnt = max = 1;

	for (int i = 1; i < N; i++) {
		int now;
		cin >> now;
		if (now >= pre) {
			cnt++;
			if (cnt > max) max = cnt;
		}
		else cnt = 1;
		pre = now;
	}

}

int main() {
	int N{}, ans{}, cnt{}, before{};
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		if (i == 0) {
			before = tmp;
			cnt = 1;
		}
		else {
			if (before <= tmp) {
				cnt++;
				ans = ans > cnt ? ans : cnt;
			}
			else {
				cnt = 1;
			}
			before = tmp;
		}
	}

	cout << ans;

	return 0;
}