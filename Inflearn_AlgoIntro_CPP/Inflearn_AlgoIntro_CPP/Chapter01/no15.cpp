#include <iostream>
#include <vector>

using namespace std;

void answer(int n) {
	int cnt{};
	for (int i = 2; i <= n; i++) {
		bool isPri = true;
		for (int j = 2; j*j <= i; j++) {
			if (i % j == 0) {
				isPri = false;
				break;
			}
		}

		if (isPri) cnt++;
	}
	cout << cnt;
}

int main() {
	int N{}, res{};
	cin >> N;
	vector<int> v(N+1); // 0 미탐색, 1 소수, 2 소수x

	for (int i = 2; i <= N; i++) {
		if (v[i] != 0) continue;
		
		v[i] = 1;
		res++;
		for (int j = i + i; j <= N; j += i) {
			if(v[j] == 0) v[j] = 2;
		}
	}

	cout << res;

	answer(N);

	return 0;
}