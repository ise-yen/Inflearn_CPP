#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N{}, answer{};
	cin >> N;

	vector<int> v(N, -1);
	vector<vector<int>> map(N, v);

	vector<int> front;
	for (int n = 0; n < N; n++) {
		int tmp{};
		cin >> tmp;
		for (int i = 0; i < N; i++) {
			map[i][n] = tmp;
		}
	}

	for (int n = N-1; n >= 0; n--) {
		int tmp{};
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			if(map[n][j] > tmp) map[n][j] = tmp;
			answer += map[n][j];
		}
	}

	cout << answer;

	return 0;
}