#include <iostream>
#include "queue.hpp"

using namespace kmc;

template <typename T>
void print_queue(queue<T>& q) {
	queue<T> temp = q.copy();		//출력할 queue 객체 복사

	while (!temp.empty()) {
		std::cout << temp.back() << " ";		//순서대로 값 꺼내서 출력
		temp.pop();
	}
	std::cout << "\n";
	
}

int main() {
	std::cout << "\n\na, b, c 생성\n\n";
	queue<int> a;		//객체 a, b, c에 각각 1~3, 4~6, 7~9를 순서대로 push
	a.push(1);
	a.push(2);
	a.push(3);

	queue<int> b;
	b.push(4);
	b.push(5);
	b.push(6);

	queue<int> c;
	c.push(7);
	c.push(8);
	c.push(9);

	print_queue(a);		//push된 값 확인
	print_queue(b);
	print_queue(c);

	
	std::cout << "\nd = a + b 실행\n";
	queue<int> d = a + b;	//새로운 객체 d에 a, b의 합(이어붙인 값) 저장
	print_queue(d);

	std::cout << "\nd += c 실행\n";
	d += c;					//d에 c의 값 더하기(이어붙이기)
	print_queue(d);
}