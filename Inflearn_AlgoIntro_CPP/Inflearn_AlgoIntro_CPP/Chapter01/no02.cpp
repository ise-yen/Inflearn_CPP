#include<iostream>

using namespace std;

int main() {
	int A{}, B{}, sum{};

	cin >> A >> B;

	for (int i = A; i <= B; i++) {
		sum += i;
		if (i != B) cout << i << " + ";
		if (i == B) cout << i << " = " << sum;
	}
	return 0;
}
