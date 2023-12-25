#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N{};
vector<pair<int, int>> v;
vector<pair<int, int>> ans;
vector<int> a;
vector<int> b;

void answer() {
	cin >> N;
	// 처음에는 다 1등 : 등수 배열을 1로 초기화
	for (int i = 0; i < N; i++) {
		int score{};
		cin >> score;
		a.push_back(score);
		b.push_back(1);
	}

	// 이중 for문 : i(1~5), j(1~5)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// i랑 j랑 비교
			// if(i < j) => 등수++
			if (a[j] > a[i]) b[i]++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << b[i] << " ";
	}

}

void mine() {
	cin >> N;
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
}

int main() {
	answer();
	return 0;
}