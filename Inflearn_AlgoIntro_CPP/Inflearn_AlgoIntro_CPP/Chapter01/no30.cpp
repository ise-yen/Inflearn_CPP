#include <iostream>
#include <algorithm>

using namespace std;

void answer() {
	int N{}, ans{};
	cin >> N;

	/*
	0 0 0 1
	0 0 0 2
	0 0 0 3
	... 
	... 
	0 0 3 0
	0 0 3 1
	0 0 3 2
	0 0 3 3
	... 
	0 1 3 0
	0 1 3 1
	0 1 3 2
	0 1 3 3
	... 
	... 
	0 3 0 0
	0 3 0 1
	0 3 0 2
	... 
	... 
	*/

	// �ڸ������� 3 ���� �Ǵ�

	// ���� �ڸ��� ����, cur�� ���� ����, ������ ����
	int cur{}, left = 1, right{};
	int k = 1; // �ڸ���

	while (left > 0) {
		left = N / (k * 10);
		cur = (N/k) % 10;
		right = N % k;
		if (cur < 3) ans += left * k;
		else if (cur == 3) {
			ans += (left)*k + right + 1; // +1�� ���� : 0�� �� �����ؾ��ؼ�
		}
		else ans += (left + 1) * k;
		k *= 10;
	}

	cout << ans;
}

int main() {
	answer();
	return 0;
}