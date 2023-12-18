#include <iostream>
#include <vector>

using namespace std;

vector<int> va, vb;

// 1 : ����
// 2 : ����
// 3 : ��
// 1 < 2
// 2 < 3
// 3 < 1

void answer(int N) {
	// A�� �̱�� ��츸 �켱������ �����ϱ�
	for (int i = 0; i < N; i++) {
		if (va[i] == vb[i]) cout << "D\n";
		else if (va[i] == 1 && vb[i] == 3) cout << "A\n";
		else if (va[i] == 2 && vb[i] == 1) cout << "A\n";
		else if (va[i] == 3 && vb[i] == 2) cout << "A\n";
		else cout << "B\n";
	}
}

int main() {
	int N{}, A{}, B{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		va.push_back(A);
	}
	for (int i = 0; i < N; i++) {
		cin >> B;
		vb.push_back(B);
	}

	for (int i = 0; i < N; i++) {
		if (va[i] == vb[i]) cout << "D\n";
		else if (va[i] == 3 && vb[i] == 1) cout << "B\n";
		else if (va[i] == 1 && vb[i] == 3) cout << "A\n";
		else if (va[i] < vb[i]) cout << "B\n";
		else if (va[i] > vb[i]) cout << "A\n";
	}

	return 0;
}