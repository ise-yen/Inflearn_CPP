#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<char> s;
	string str;
	cin >> str;

	bool flag = true;

	for (int i = 0; i < str.length(); i++) {
		if (s.empty()) {
			if(str[i] == '(') s.push(str[i]);
			else if(str[i] == ')') {
				flag = false;
				break;
			}
		}
		else {
			char c = s.top();

			if (c == '(') {
				if (str[i] == ')') s.pop();
				else if (str[i] == '(') s.push(str[i]);
			}
			else {
				flag = false;
				break;
			}
		}
	}
	
	if (!s.empty()) flag = false;

	if (flag) cout << "YES";
	else cout << "NO";
	return 0;
}