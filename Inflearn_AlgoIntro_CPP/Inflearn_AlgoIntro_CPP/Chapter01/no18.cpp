#include <iostream>

using namespace std;

int main() {
	int N{}, M{};
	cin >> N >> M;

	int ans{};
	int cnt{};
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		if (tmp > M) cnt++;
		else cnt = 0;
		ans = ans > cnt ? ans : cnt;
	}
	if (ans == 0) cout << -1;
	else cout << ans;
	return 0;
}