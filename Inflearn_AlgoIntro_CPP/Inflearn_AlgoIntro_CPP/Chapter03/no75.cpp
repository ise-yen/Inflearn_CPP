#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct Schedule{
	int m, d;
	Schedule(int a, int b) {
		m = a;
		d = b;
	}
	
	bool operator < (const Schedule& s) const {
		if (d != s.d) return d > s.d; // ��������
		return m > s.m;
	}
};

int main() {
	vector<Schedule> T;
	priority_queue<int> PQ;

	int N{}, max{}, sum{};
	cin >> N;

	for (int i = 0; i < N; i++) {
		int M{}, D{};
		cin >> M >> D;
		T.push_back(Schedule(M, D));
		if (D > max) max = D; // ��¥�� ���� �� �� ã��
	}

	// ��������
	sort(T.begin(), T.end());

	int j = 0;
	for (int i = max; i >= 1; i--) { // ���� ��¥
		// ���� ���� ���鸸 ����
		for (; j < N; j++) {
			if (T[j].d < i) break; // ���� ��¥�� ���� ���� ��¥���� ������ �н�
			PQ.push(T[j].m);
		}
		if (!PQ.empty()) {
			sum += PQ.top();
			PQ.pop();
		}
	}

	cout << sum;

	return 0;
}
