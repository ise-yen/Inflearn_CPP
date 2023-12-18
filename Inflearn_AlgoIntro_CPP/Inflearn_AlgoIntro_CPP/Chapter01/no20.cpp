#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 1 : 가위
	// 2 : 바위
	// 3 : 보
	// 1 < 2
	// 2 < 3
	// 3 < 1

	int N{}, A{}, B{};
	cin >> N;
	vector<int> va;
	vector<int> vb;
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