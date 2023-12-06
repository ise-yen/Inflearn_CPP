#include<iostream>

using namespace std;

int main() {
	int N{}, minN = 100, maxN = 2;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n < minN) minN = n;
		if (n > maxN) maxN = n;
	}

	cout << maxN - minN;
	return 0;
}

