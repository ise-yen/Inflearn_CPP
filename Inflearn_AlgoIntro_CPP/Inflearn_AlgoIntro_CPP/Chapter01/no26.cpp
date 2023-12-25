#include <iostream>
#include <vector>

using namespace std;

int N{};
vector<pair<int, int>> v;

void answer() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int average{};
		cin >> average;
		v.push_back(average);
	}

	cout << "1 ";

	for (int i = 1; i < N; i++) {
		cnt = 1; // 앞지를수 없는 사람 수
		// 앞사람들만 보기
		for (int j = i - 1; j >= 0; j--) {
			// 앞사람이 나보다 크면 앞지를 수 없는 사람 증가
			if (a[j] >= a[i]) cnt++;
		}
		cout << cnt << " ";
	}

}

void mine() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int average{};
		cin >> average;
		v.push_back({ average, i + 1 });
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j].first < v[i].first) v[i].second--;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << v[i].second << " ";
	}
}
int main(){
	return 0;
}