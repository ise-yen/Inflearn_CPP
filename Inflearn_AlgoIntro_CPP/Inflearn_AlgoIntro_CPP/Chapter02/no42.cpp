#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int N{}, M{}, answer{};
void binarySearch(int left, int right) {
	if (left > right) return;

	int mid = (left + right) / 2;
	if (v[mid] == M) {
		answer = mid + 1;
		return;
	}
	else if (v[mid] > M) {
		binarySearch(left, mid - 1);
	}
	else {
		binarySearch(mid + 1, right);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		if (tmp <= M) answer++; // 구현
		v.push_back(tmp);
	}

	cout << answer << "\n"; // 구현

	sort(v.begin(), v.end());
	binarySearch(0, N - 1);
	cout << answer; // 이분검색
	return 0;
}