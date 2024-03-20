#include<iostream>
#include<stack>

using namespace std;

int main() {
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

	return 0;
}