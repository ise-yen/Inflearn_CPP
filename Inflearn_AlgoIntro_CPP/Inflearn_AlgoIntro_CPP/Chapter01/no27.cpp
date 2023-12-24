#include<iostream>
#include<map>

using namespace std;

int prime[1001]{};

map<int, int> m;

int main() {
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

	cout << N << "! = ";

	for (int i = 2; i <= N; i++) {
		// i가 소수라면 바로 push
		if(prime[i] == 1)
			m.insert({ i, 1});
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

	for (auto it : m) {
		cout << it.second << " ";
	}
}