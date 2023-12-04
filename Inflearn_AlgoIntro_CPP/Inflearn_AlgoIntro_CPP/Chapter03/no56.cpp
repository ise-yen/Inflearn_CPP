#include<iostream>

using namespace std;

void Recursive(int n) {
	if (n == 0) return;
	Recursive(n - 1);
	cout << n << " ";
}

int main() {
	int N{};

	cin >> N;

	Recursive(N);
	return 0;
}


/*
< 재귀의 스택 프레임 >
스택프레임 : 프로그램이 실행될 때, 함수가 호출되면 호출 정보를 기록하는 것


- 스택프레임 Recursive(int n=0) : 매개변수, 지역변수, 복귀할 주소
- 스택프레임 Recursive(int n=1) : 매개변수, 지역변수, 복귀할 주소
- 스택프레임 Recursive(int n=2) : 매개변수, 지역변수, 복귀할 주소(Recursive(int n=3)에서 Recursive(n-1);이 작성된 위치)
- 스택프레임 Recursive(int n=3) : 매개변수, 지역변수, 복귀할 주소(main함수에서 Recursive(N);이 작성된 위치)
- 스택프레임 main() : 매개변수, 지역변수, 복귀할 주소 등의 정보

*/