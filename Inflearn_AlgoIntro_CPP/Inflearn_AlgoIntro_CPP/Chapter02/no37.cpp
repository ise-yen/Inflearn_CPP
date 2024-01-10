#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

// i : 0 1 2 3 4
// v : 1 2 3
// v : 1 3 2

int main() {
	int S{}, N{};
	deque<int> dq;

	cin >> S >> N;
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		deque<int>::iterator it = find(dq.begin(), dq.end(), tmp);
		if (it == dq.end()) dq.push_back(tmp);
		else {
			int tmp = *it;
			for (it; it != dq.end()-1; it++) {
				*it = *(it + 1);
			}
			*it = tmp;
		}

		// 캐시 크기보다 커지면 처음 들어왔던 제일 앞쪽 삭제
		if (dq.size() > S) dq.pop_front();
	}

	for (int i = dq.size() - 1; i >= 0; i--) {
		cout << dq[i] << " ";
	}

}