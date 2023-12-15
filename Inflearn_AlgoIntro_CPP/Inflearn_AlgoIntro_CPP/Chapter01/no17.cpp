#include <iostream>

using namespace std;

int sumCard(int card) {
	int sum{};
	for (int i = 1; i <= card; i++) {
		sum += i;
	}
	return sum;
}

int main() {
	int N{};
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int card{}, ans{};
		cin >> card >> ans;
		if (ans == sumCard(card)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}