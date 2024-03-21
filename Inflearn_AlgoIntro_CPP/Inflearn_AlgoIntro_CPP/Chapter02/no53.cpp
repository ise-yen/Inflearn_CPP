#include<iostream>
#include<stack>

using namespace std;


void myCode() {
	int N{}, K{}, answer{};
	cin >> N >> K;
	stack<char> s;
	while (N > 0) {
		char c{};
		if (K == 16 && N % K >= 10) {
			c = 'A' + (N % K - 10);
		}
		else c = '0' + (N % K);
		s.push(c);
		N /= K;
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

void answerCode() {
	int n{}, k{};
	cin >> n >> k;
	stack<int> s;
	char str[20] = "0123456789ABCDEF";

	while (n > 0) {
		s.push(n % k);
		n /= k;
	}
	while (!s.empty()) {
		cout << str[s.top()];
		s.pop();
	}
}