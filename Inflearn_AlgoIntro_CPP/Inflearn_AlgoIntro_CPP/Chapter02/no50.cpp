#include <iostream>
#include <vector>

using namespace std;

int main() {
	int answer{};
	int H{}, W{};
	cin >> H >> W;
	
	vector<int> v(W, 0);
	vector<vector<int>> map(H, v);

	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cin >> map[h][w];
		}
	}

	int R{}, C{};
	cin >> R >> C;

	for (int h = 0; h+R <= H; h++) {
		for (int w = 0; w+C <= W; w++) {
			int sum{};
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					sum += map[h+r][w+c];
				}
			}
			answer = answer < sum ? sum : answer;
		}
	}

	cout << answer;

	return 0;
}