#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	string str, tmp;
	cin >> str;

	int itc = str.find('C');
	int ith = str.find('H');

	int ans{};
	if (itc + 1 == ith) {
		ans += 12;
	}
	else {
		string cstr;
		for (int it = itc + 1; it < ith; it++) {
			cstr.push_back(str[it]);
		}
		ans = stoi(cstr) * 12;
	}

	if (ith == str.length() - 1) {
		ans++;
	}
	else {
		string hstr;
		for (int it = ith + 1; it < str.length(); it++) {
			hstr.push_back(str[it]);
		}
		ans = ans + stoi(hstr);
	}

	cout << ans;
	return 0;
}