#include <iostream>
#include <string>

using namespace std;

void answer() {
	int N{}, cnt{};
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int tmp = i;
		int digit{};
		while (tmp > 0) {
			digit = tmp % 10;
			if (digit == 3) cnt++;
			tmp /= 10;
		}
	}

	cout << cnt;
}

void mine() {
	int N{}, ans{};
	cin >> N;

	for (int i = 1; i <= N; i++) {
		string str = to_string(i);
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '3') ans++;
		}
	}

	cout << ans;
}

int main() {
	answer();
	return 0;
}