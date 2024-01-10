#include <iostream>
#include <vector>

using namespace std;

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