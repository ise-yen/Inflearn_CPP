#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N{}, K{};
	cin >> N >> K;
	vector<int> v;
	int max{}, sum{}, cnt{};
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
		if (cnt < K) {
			cnt++;
			sum += tmp;
		}
	}
	max = sum;
	for (int i = K; i < N; i++) {
		sum -= v[i - K];
		sum += v[i];
		max = max > sum ? max : sum;
	}

	cout << max;
	return 0;
}
