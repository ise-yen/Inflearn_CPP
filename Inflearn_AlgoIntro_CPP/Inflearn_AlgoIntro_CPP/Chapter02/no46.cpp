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

	// K�� �ڿ� ���� �۾��� ���� ��
	if (K >= sum) {
		cout << -1;
		return;
	}

	int p{}; // v�� ��ȯ�� index
	// ���� ������ �۾�
	while (cnt < K) { // ���� �������� ī��Ʈ
		p++;
		if (p > N) p = 1; // �۾� �������� Ŀ���� 1�� �ʱ�ȭ
		if (v[p] == 0) continue; // ����� �۾��̸� �н�
		v[p]--;
		cnt++; // �ð� ī��Ʈ
	}

	// ���� ���� �� �ؾ��ϴ� �۾� ã��
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