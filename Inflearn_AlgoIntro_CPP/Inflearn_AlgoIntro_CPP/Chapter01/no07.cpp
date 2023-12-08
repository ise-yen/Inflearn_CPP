#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	int interval = 'a' - 'A';

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') cout << str[i];
		else if (str[i] >= 'A' && str[i] <= 'Z') cout << char(str[i] + interval);
	}
	return 0;
}