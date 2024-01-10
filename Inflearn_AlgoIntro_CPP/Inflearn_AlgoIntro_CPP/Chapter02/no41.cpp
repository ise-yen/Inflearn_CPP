#include <iostream>
#include <vector>

using namespace std;

void Answer() {
	int N, b = 1, cnt{}, a{};
	cin >> N;
	a = N;
	a--;
	while (a > 0) {
		b++;
		a = a - b;
		if (a % b == 0) {
			int i{};
			for (i = 1; i < b; i++) {
				cout << (a / b) + i) << " + ";
			}
			cout << (a / b) + i << " = " << N;
			cnt++;
		}
	}
	cout << cnt;
}

int main() {
	int N{}, cnt{};
	cin >> N;

	for (int i = N / 2; i >= 1; i--) {
		int sum{};
		vector<int> v;
		for (int j = i; j <= N / 2 + 1; j++) {
			sum += j;
			v.push_back(j);
			if (sum == N) {
				for (int k = 0; k < v.size() - 1; k++) {
					cout << v[k] << " + ";
				}
				cout << v[v.size() - 1] << " = " << N << "\n";
				cnt++;
				break;
			}
			else if (sum > N) {
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}