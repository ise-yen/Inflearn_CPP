#include<iostream>
#include<stack>
#include<string>

using namespace std;

string str{};
stack<char> s;

void myCode() {
	for (int i = 0; i < str.length(); i++) {
		if (s.empty()) s.push(str[i]);
		else {
			if (s.top() == '(' && str[i] == ')') s.pop();
			else s.push(str[i]);
		}
	}

	if (s.empty()) cout << "YES";
	else cout << "NO";
}

void answerCode() {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else {
			if (s.empty()) {
				cout << "NO";
				return;
			}
			else s.pop();
		}
	}

	if (s.empty()) cout << "YES";
	else cout << "NO";
}

int main() {
	cin >> str;
}
