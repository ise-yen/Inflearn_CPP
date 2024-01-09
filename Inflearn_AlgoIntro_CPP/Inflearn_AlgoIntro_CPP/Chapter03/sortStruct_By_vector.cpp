#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Loc {
	int x, y, z;

	// 생성자 : 구조차 이름과 똑같은 멤버함수
	Loc(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}

	// 연산자 오버로딩
	// const (call by reference) : 변경 위험성이 사라짐
	// operator () const : 상수 함수
	// return x < b.x; 오름차순
	// return x > b.x; 내림차순
	//bool operator < (const Loc &b) const {
	//	return x < b.x;
	//}

	bool operator < (const Loc& b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		if (z != b.z) return z < b.z;
	}
};

int main() {
	vector<Loc> XY;
	XY.push_back(Loc(2, 3, 5));
	XY.push_back(Loc(3, 6, 7));
	XY.push_back(Loc(2, 3, 1));
	XY.push_back(Loc(5, 2, 3));
	XY.push_back(Loc(3, 1, 6));

	// 정렬 전
	for (const Loc& pos : XY)
		cout << pos.x << " " << pos.y << " " << pos.z << "\n";
	cout << "\n";

	//  정렬
	sort(XY.begin(), XY.end());
	for (const Loc& pos : XY)
		cout << pos.x << " " << pos.y << " " << pos.z << "\n";
	cout << "\n";

	return 0;
}
