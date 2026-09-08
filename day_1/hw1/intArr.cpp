#include "intArr.h"
#include <iostream>

Arr::Arr() {		//클래스 선언 시 배열의 크기 지정
	std::cout << "몇 개의 원소를 할당하겠습니까? : ";
	std::cin >> size;
	arr = new int[size];		//new 연산자를 통해 동적 할당
}

void Arr::inputData() {		//데이터 입력받기

	for (int i = 0; i < size; i++) {		//해당 객체의 배열 크기(size)만큼 입력받기
		std::cout << "정수형 데이터 입력: ";
		std::cin >> arr[i];		//객체의 배열에 값 저장
	}
}

int Arr::max() {
	int mx = arr[0];		//배열의 첫 값을 시작값으로 저장
	for (int i = 0; i < size; i++) {
		mx = (arr[i] > mx) ? arr[i] : mx;		//배열 원소가 현재 값보다 클 때, 해당 값으로 바꾸기
	}

	return mx;
}

int Arr::min() {
	int mn = arr[0];		//배열의 첫 값을 시작값으로 저장
	for (int i = 0; i < size; i++) {
		mn = (arr[i] < mn) ? arr[i] : mn;		//배열 원소가 현재 값보다 작을 때, 해당 값으로 바꾸기
	}

	return mn;
}

int Arr::total() {
	int tot = 0;		//시작값 0
	for (int i = 0; i < size; i++) {		//모든 원소 더하기
		tot += arr[i];
	}

	return tot;
}

int Arr::average() {
	int avr = total() / size;		//(배열 원소의 총합) 나누기 (배열 크기)

	return avr;
}

Arr::~Arr() {
	delete arr;
	std::cout << "객체가 성공적으로 소멸되었습니다." << std::endl;		//소멸 시 출력 문장
}