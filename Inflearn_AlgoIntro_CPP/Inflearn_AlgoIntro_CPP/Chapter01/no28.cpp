#include<iostream>
#include<map>

using namespace std;

int prime[1001]{};

map<int, int> m;

void mine2() {
	// 2나 5로만 소인수분해
	int N{}, cnt1{}, cnt2{};
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int tmp = i;
		int j = 2;
		while (tmp > 1) {
			if (tmp % j == 0) {
				if (j == 2) cnt1++;
				else if (j == 5) cnt2++;
				tmp /= j;
			}
			else {
				if (j == 2) j = 5;
				else break;
			}
		}
	}
	if (cnt1 < cnt2) cout << cnt1;
	else cout << cnt2;
}

void mine() {

	int N{};
	cin >> N;

	prime[0] = prime[1] = -1;
	for (int i = 2; i <= N; i++) {
		if (prime[i] == 0) {
			prime[i] = 1;
			for (int j = i * 2; j <= N; j += i) {
				prime[j] = -1;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		// i가 소수라면 바로 push
		if (prime[i] == 1)
			m.insert({ i, 1 });
		else if (prime[i] == -1) {
			int tmp = i;
			int k = 2;
			while (tmp > 1 || k <= i) {
				if (prime[k] != 1) {
					k++;
				}
				if (tmp % k == 0) {
					m[k]++;
					tmp /= k;
				}
				else {
					k++;
				}
			}
		}
	}

	int cnt = m[2] < m[5] ? m[2] : m[5];

	cout << cnt;
}

int main() {
	mine2();
}