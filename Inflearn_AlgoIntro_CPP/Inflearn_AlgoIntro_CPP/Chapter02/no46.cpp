#include <iostream>
#include <queue>

using namespace std;

int N{}, K{};
void answerCode() {
	int cnt{}, sum{};
	vector<int> v(N+1);
	for (int n = 1; n <= N; n++) {
		cin >> v[n];
		sum += v[n];
	}
	cin >> K;

	// K초 뒤에 남은 작업이 없을 때
	if (K >= sum) {
		cout << -1;
		return;
	}

	int p{}; // v를 순환할 index
	// 정전 전까지 작업
	while (cnt < K) { // 정전 직전까지 카운트
		p++;
		if (p > N) p = 1; // 작업 개수보다 커지면 1로 초기화
		if (v[p] == 0) continue; // 종료된 작업이면 패스
		v[p]--;
		cnt++; // 시간 카운트
	}

	// 정전 끝난 뒤 해야하는 작업 찾기
	while (true) {
		p++;
		if (p > N) p = 1;
		if (v[p] != 0) break;
	}
	cout << p;
	return;
}

void myCode() {
	queue<pair<int, int>> q;
	for (int n = 1; n <= N; n++) {
		int t{};
		cin >> t;
		q.push({ n, t });
	}

	cin >> K;

	while (K > 0) {
		K--;
		int n = q.front().first;
		int t = q.front().second - 1;
		q.pop();
		if (t != 0) q.push({ n, t });
	}

	if (q.empty()) cout << -1;
	else cout << q.front().first;
}

int main() {
	cin >> N;

	answerCode();

	return 0;
}