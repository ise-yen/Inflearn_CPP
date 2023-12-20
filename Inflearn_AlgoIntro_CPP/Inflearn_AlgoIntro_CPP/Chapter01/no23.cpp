#include <iostream>

using namespace std;

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