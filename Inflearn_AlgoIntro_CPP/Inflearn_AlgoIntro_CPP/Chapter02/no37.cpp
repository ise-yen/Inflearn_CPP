#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

void answer() {
	int S{}, N{};
	cin >> S >> N;
	int C[20]{};
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		int pos = -1, j{};
		// �ߺ��� ã��
		for (j = 0; j < S; j++) {
			if (C[j] == tmp) pos = j;
		}

		if (pos == -1) j = S - 1; // ��� ���� ���� �׳� �ٰ��� �̵�
		else j = pos; // ���� ���� : �ߺ����� ��ġ�� �ֽ����� ����
		for (j; j >= 1; j--) C[j] = C[j - 1];
		C[j] = tmp;
	}
	
	for (int i = 0; i < S; i++) {
		cout << C[i] << " ";
	}
}

void MyAnswer() {
	int S{}, N{};
	deque<int> dq;

	// �ߺ� �� ����
	cin >> S >> N;
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;

		// �ߺ��� ã��
		deque<int>::iterator it = find(dq.begin(), dq.end(), tmp);
		if (it == dq.end()) dq.push_front(tmp); // �ߺ� ������ �׳� �տ��� ����
		else { // �ߺ��� �ִٸ�
			// (tmp = *it�� �� �ʿ���� : �� ���� �� ���̴ϱ�)
			// �ϳ��� �ڷ� �б�. ���� ���ʿ� �����ϸ� it-1�� ���ϴϱ� �ݺ� ����
			for (it; it != dq.begin(); it--) {
				*it = *(it - 1);
			}
			*it = tmp;
		}

		// ���� ���� ����
		if (dq.size() > S) dq.pop_back();
	}

	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
}

int main() {
	MyAnswer();
}