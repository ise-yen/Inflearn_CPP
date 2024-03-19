#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 9;
vector<vector<int>> map(MAX, vector<int>(MAX));

int main() {
	for (int i = 0; i < MAX; i++) {
		int sum{}, near{};
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];
			sum += map[i][j];
		}

		// 소수점 첫 번째 자리에서 반올림
		// int ave = sum / MAX;
		// if (sum % MAX >= 5) ave++;
		int ave = round(sum / (double)MAX);

		int min = 101;
		for (int j = 0; j < MAX; j++) {
			if (min > abs(ave - map[i][j])) {
				min = abs(ave - map[i][j]);
				near = map[i][j];
			}
			else if (min == abs(ave - map[i][j])) {
				if(near < map[i][j]) near = map[i][j];
			}
		}

		cout << ave << " " << near << "\n";
	}

	return 0;
}