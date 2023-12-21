#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N{};
	cin >> N;
	vector<pair<int, int>> v;
	vector<pair<int, int>> ans;

	for (int i = 0; i < N; i++) {
		int score{};
		cin >> score;
		v.push_back({ score, i });
	}

	sort(v.begin(), v.end());

	int sameCnt = 1;
	for (int i = N - 1, rank = 0; i >= 0; i--) {
		if (i < N-1 && v[i].first == v[i + 1].first) {
			sameCnt++;
		}
		else {
			rank += sameCnt;
			sameCnt = 1;
		}
		ans.push_back({ v[i].second, rank });
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < N; i++) cout << ans[i].second << " ";

	return 0;
}