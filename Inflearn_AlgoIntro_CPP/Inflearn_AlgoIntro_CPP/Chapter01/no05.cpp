#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int gender = str[7] - '0';
	int age10 = str[0] - '0';
	int age1 = str[1] - '0';

	int year = 2019 + 1;
	int age{};
	char wm{};

	if (gender == 1) {
		age = year - (1900 + age10 * 10 + age1);
		wm = 'M';
	}
	else if (gender == 2) {
		age = year - (1900 + age10 * 10 + age1);
		wm = 'W';
	}
	else if (gender == 3) {
		age = year - (2000 + age10 * 10 + age1);
		wm = 'M';
	}
	else if (gender == 4) {
		age = year - (2000 + age10 * 10 + age1);
		wm = 'W';
	}

	cout << age << " "  << wm;
	return 0;
}
