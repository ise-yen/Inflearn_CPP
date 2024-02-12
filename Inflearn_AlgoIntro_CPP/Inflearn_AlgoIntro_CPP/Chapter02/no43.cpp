#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N{}, M{};
int answer{};

int CntV(int s) {
	int cnt = 1, sum{};
	for (int i = 0; i < N; i++) {
		if (sum + v[i] > s) { // ������ ������ �� �ִ뺸�� ũ��?
			cnt++; // dvd ���� �߰�
			sum = v[i];
		}
		else { // ���ص� �Ǹ�?
			sum += v[i]; // �߰�
		}
	}

	return cnt;
}

int main() {
	cin >> N >> M;
	int lt = 1, rt{}; // lt = �ּ� �뷮, rt = �ִ� �뷮
	for (int i = 0; i < N; i++) {
		int num{};
		cin >> num;
		v.push_back(num); // ���� ����
		rt += num; // �ִ� �뷮 ����
	}

	while (lt <= rt) {
		int mid = (lt + rt) / 2; // �߰� �뷮��

		if (CntV(mid) <= M) { // dvd ������ M���϶�� : �� �ٿ��� �ȴ�
			answer = mid; // �뷮 �ּҰ� ����
			rt = mid - 1;
		}
		else lt = mid + 1;
	}

	cout << answer;
	return 0;
}