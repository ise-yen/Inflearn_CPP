#include <iostream>
#include <vector>

using namespace std;

int main() {
	int answer{};
	int H{}, W{};
	cin >> H >> W;

	vector<int> v(W+2, 0);
	vector<vector<int>> map(H+2, v);

	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			cin >> map[h][w];
			map[h][w] = map[h][w] + map[h - 1][w] + map[h][w - 1] - map[h - 1][w - 1];
		}
	}

	int R{}, C{};
	cin >> R >> C;

	for (int h = R; h <= H; h++) {
		for (int w = C; w <= W; w++) {
			int sum = map[h][w] + map[h - R][w - C] - map[h - R][w] - map[h][w - C];
			if (sum > answer) answer = sum;
		}
	}
	
	std::cout << answer;

	return 0;
}