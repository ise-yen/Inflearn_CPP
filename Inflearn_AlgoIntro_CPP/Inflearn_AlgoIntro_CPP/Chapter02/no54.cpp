#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	string str{};
	cin >> str;
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (s.empty()) s.push(str[i]);
		else {
			if (s.top() == '(' && str[i] == ')') s.pop();
			else s.push(str[i]);
		}
	}

	if (s.empty()) cout << "YES";
	else cout << "NO";

	return 0;
}