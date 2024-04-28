#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 1001;

int N{}, M{}; /// 학생 번호, 친구관계쌍 개수
int t1{}, t2{};
string answer;

vector<int> friends[MAX];

int unf[MAX]; // 집합 번호

/// v의 집합 번호 찾기
int Find(int v) {
	// 자기자신이 집합번호라면 자기자신을 리턴
	if (v == unf[v]) return v;
	
	// 자기자신 숫자와 다른 집합번호 소속이라면 : 재귀 탐색
	unf[v] = Find(unf[v]); // 메모이제이션 + 재귀
	return unf[v];
}

/// a와 b를 같은 집합으로 묶기
void Union(int a, int b) {
	// 집합번호 탐색
	a = Find(a); // a의 집합번호
	b = Find(b); // b의 집합번호

	// 같은 집합이 아니면 한쪽으로 합치기
	if (a != b) unf[a] = b;
}

void MakeFriend() {
	// 친구인 애들 입력
	for (int i = 0; i < M; i++) {
		int a{}, b{};
		cin >> a >> b;
		Union(a, b); // a와 b는 친구니까 같은 집합으로
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		unf[i] = i; // 자기 번호로 초기화
	}

	MakeFriend();

	int a{}, b{};
	cin >> a >> b;
	if (Find(a) == Find(b)) answer = "YES";
	else answer = "NO";

	cout << answer;
	return 0;
}




/*
i =  1 2 3 4 5 6 7 8 9
unf: 5 5 5 5 5 9 9 9 9

1=1=2 2=2
2=2=3 3=3
3=3=4 4=4
4=4=5 5=5
6=6=7 7=7
7=7=8 8=8
8=8=9 9=9
3=4=5 8=9
 */