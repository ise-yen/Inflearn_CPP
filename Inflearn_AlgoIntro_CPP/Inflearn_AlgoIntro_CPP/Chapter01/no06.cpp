#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string str{};
	cin >> str;

	int num{}, ans{};
	int unit = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		int tmp = str[i] - '0';
		if (tmp >= 0 && tmp < 10) {
			num += unit * tmp;
			unit *= 10;
		}
	}

	for (int i = 1; i <= sqrt(num); i++) {
		if (num % i == 0) {
			ans += 2;
		}
	}
	cout << num << "\n" << ans;
}