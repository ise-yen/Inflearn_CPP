#include<iostream>
#include<stack>

using namespace std;

void notRecur(int N, stack<int>* s) {
	while (N > 0) {
		s->push(N % 2);
		N /= 2;
	}

	while (!s->empty()) {
		cout << s->top();
		s->pop();
	}
}

void recur(int N) {
	if (N == 0) return;
	recur(N / 2);
	cout << N % 2;
}

int main() {
	int N{};
	stack<int> s;

	cin >> N;

	recur(N);

	return 0;
}

