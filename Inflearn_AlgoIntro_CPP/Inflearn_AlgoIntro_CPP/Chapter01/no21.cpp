#include <iostream>
#include <vector>

using namespace std;

vector<int> va, vb;

int main() {
	int N = 10;
	int tmp{};
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		va.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vb.push_back(tmp);
	}

	int sumA{}, sumB{};
	int res{};
	
	for (int i = 0; i < N; i++) {
		if (va[i] > vb[i]) {
			sumA += 3;
			res = 1;
		}
		else if (va[i] < vb[i]) {
			sumB += 3;
			res = 2;
		}
		else {
			sumA++;
			sumB++;
		}
	}

	cout << sumA << " " << sumB << "\n";

	if (sumA > sumB) cout << "A";
	else if (sumA < sumB) cout << "B";
	else {
		if (res == 1) cout << "A";
		else if (res == 2) cout << "B";
		else cout << "D";
	}

	return 0;
}