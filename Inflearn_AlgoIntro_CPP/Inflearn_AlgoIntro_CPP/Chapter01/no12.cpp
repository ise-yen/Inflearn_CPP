#include <iostream>
#include <cmath>

using namespace std;

int digit(int x) {
	int cnt{};

	while (x > 0) {
		cnt++;
		x /= 10;
	}

	return cnt;
}

int main() {
	int N{}, res{};

	cin >> N;

	int nDigit = digit(N); // N�� �ڸ���

	for (int i = 1; i < nDigit; i++) {
		int cnt = pow(10, i) - pow(10, i - 1); // i�ڸ����� ���� ���� ����
		res += cnt * i;
	}

	res += (N - pow(10, nDigit - 1) + 1) * nDigit;

	cout << res;
}