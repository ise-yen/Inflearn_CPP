#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

void answer() {
	int S{}, N{};
	cin >> S >> N;
	int C[20]{};
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		int pos = -1, j{};
		// 중복값 찾기
		for (j = 0; j < S; j++) {
			if (C[j] == tmp) pos = j;
		}

		if (pos == -1) j = S - 1; // 상관 없을 때는 그냥 다같이 이동
		else j = pos; // 삽입 정렬 : 중복값만 위치를 최신으로 변경
		for (j; j >= 1; j--) C[j] = C[j - 1];
		C[j] = tmp;
	}
	
	for (int i = 0; i < S; i++) {
		cout << C[i] << " ";
	}
}

void MyAnswer() {
	int S{}, N{};
	deque<int> dq;

	// 중복 값 정렬
	cin >> S >> N;
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;

		// 중복값 찾기
		deque<int>::iterator it = find(dq.begin(), dq.end(), tmp);
		if (it == dq.end()) dq.push_front(tmp); // 중복 없으면 그냥 앞에서 삽입
		else { // 중복값 있다면
			// (tmp = *it을 할 필요없음 : 그 값이 그 값이니까)
			// 하나씩 뒤로 밀기. 제일 앞쪽에 도착하면 it-1을 못하니까 반복 종료
			for (it; it != dq.begin(); it--) {
				*it = *(it - 1);
			}
			*it = tmp;
		}

		// 제일 뒤쪽 삭제
		if (dq.size() > S) dq.pop_back();
	}

	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
}

int main() {
	MyAnswer();
}