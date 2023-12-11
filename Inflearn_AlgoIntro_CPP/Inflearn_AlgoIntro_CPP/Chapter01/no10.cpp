#include <iostream>

using namespace std;

int digit_sum(int x) {
	int sum{};

	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}

	return sum;
}

int main() {
	int N{}, max{}, res{};

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x{};
		cin >> x;

		if (max < digit_sum(x)) {
			max = digit_sum(x);
			res = x;
		}
		else if (max == digit_sum(x)) {
			res = res < x ? x : res;
		}
	}

	cout << res;
}