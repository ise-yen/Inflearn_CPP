#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	int N{};
	cin >> N;
	stack<int> s;
	string answer{};
	int num = 1;
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		s.push(tmp);
		answer.push_back('P');
		while (!s.empty()) {
			if (s.top() == num) {
				answer.push_back('O');
				s.pop();
				num++;
			}
			else break;
		}
	}

	if(!s.empty()) answer = "impossible";

	cout << answer;
	return 0;
}