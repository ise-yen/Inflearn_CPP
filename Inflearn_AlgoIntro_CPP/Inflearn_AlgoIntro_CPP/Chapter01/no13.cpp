#include <iostream>
#include <string>

using namespace std;

int main() {
	string N{};
	int res{}, max{};
	cin >> N;

	int cnt[10]{ 0, };

	for (int i = 0; i < N.length(); i++) {
		cnt[N[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		if (max <= cnt[i]) {
			max = cnt[i];
			res = i;
		}
	}

	cout << res;

	return 0;
}

