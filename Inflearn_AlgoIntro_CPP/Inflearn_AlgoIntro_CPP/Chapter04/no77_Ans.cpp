#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 1001;

int N{}, M{};
int t1{}, t2{};
string answer;

vector<int> friends[MAX];

void myCode_Linked() {
	for (int i = 0; i < M; i++) {
		int a{}, b{};
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	cin >> t1 >> t2;


	// 베프가 맞다면
	for (int i = 0; i < friends[t1].size(); i++) {
		if (friends[t1][i] == t2) {
			answer = "YES";
			return;
		}
	}

	// 베프가 아니라면
	for (int i = 0; i < friends[t1].size(); i++) {
		int t1_f = friends[t1][i]; // t1의 친구
		for (int j = 0; j < friends[t1_f].size(); j++) {
			int f = friends[t1_f][j]; // t1_f의 친구
			if (f == t1) continue; // t1이면 패스
			auto it = find(friends[t1].begin(), friends[t1].end(), f);
			// t1 친구 목록에 없으면
			if (it == friends[t1].end()) {
				friends[t1].push_back(f); // 친구추가
			}
		}
	}

	auto it = find(friends[t1].begin(), friends[t1].end(), t2);
	if (it == friends[t1].end()) answer = "NO";
	else answer = "YES";
}

// 공통원소가 있으면 같은 집합
// 없으면 서로소 집합
// 집합 관계는 트리로 표현
int unf[MAX]; // 집합번호. union & find
int Find(int v) { // 집합번호 찾기

	if (v == unf[v]) return v; // 자기자신이 집합번호라면 자기자신을 리턴
	else { // 그게 아니면 집합번호 재귀 탐색
		unf[v] = Find(unf[v]); // 메모이제이션
		return unf[v];
	}
}

int Union(int a, int b) { // 같은 집합으로 묶기
	// 집합번호 탐색
	a = Find(a);
	b = Find(b);

	// 집합번호가 서로 다르다면 같은 집합에 묶기
	if (a != b) unf[a] = b;
}

void answerCode() {
	// 집합번호를 가지자신으로 초기화
	// unf[학생번호] = 집합번호
	for (int i = 1; i <= N; i++) unf[i] = i;

	// 친구 입력
	for (int i = 0; i < M; i++) {
		int a{}, b{};
		cin >> a >> b;
		Union(a, b); // 친구끼리는 같은 집합으로 묶기
	}

	cin >> t1 >> t2;
	if (unf[t1] == unf[t2]) answer = "YES";
	else answer = "NO";
}

int main() {
	cin >> N >> M;

	cout << answer;

	return 0;
}

