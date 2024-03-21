#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;
int N{};
stack<int> s;
string answer{};

void myCode(){
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
}

void answerCode() {
	int pos = 1;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		s.push(tmp);
		answer.push_back('P');
		while (!s.empty() && s.top() == pos) {
			s.pop();
			answer.push_back('O');
			pos++;
		}
	}

	if (!s.empty()) answer = "impossible";
}


int main() {
	cin >> N;
	answerCode();
	cout << answer;
}
