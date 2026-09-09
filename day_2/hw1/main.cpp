#include <iostream>
#include <string>
#include "DataFrame.hpp"
#include "queue.hpp"

int main() {
	std::cout << "===== int queue test =====" << std::endl;		//int 템플릿으로 queue 테스트, 순서대로 1, 2, 3 push
	kmc::queue<int> q1;
	std::cout << "empty: " << (q1.empty() ? "true" : "false") << std::endl;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	std::cout << "size: " << q1.size() << std::endl;
	std::cout << "front: " << q1.front() << std::endl;
	std::cout << "back: " << q1.back() << std::endl;

	std::cout << "pop and print: ";		//pop으로 모든 값 삭제, 확인
	while (!q1.empty()) {
		std::cout << q1.back() << " ";
		q1.pop();
	}
	std::cout << std::endl;
	std::cout << "size after pop all: " << q1.size() << std::endl;

	std::cout << "===== double queue test =====" << std::endl;	//double 템플릿으로 queue 테스트, 순서대로 1.1, 2.2, 3.3 push
	kmc::queue<double> q2;
	q2.push(1.1);
	q2.push(2.2);
	q2.push(3.3);
	std::cout << "size: " << q2.size() << std::endl;
	std::cout << "front: " << q2.front() << ", back: " << q2.back() << std::endl;
	q2.clear();
	std::cout << "size after clear: " << q2.size() << std::endl;	//claer 함수로 queue 초기화 후 확인	
	std::cout << "empty after clear: " << (q2.empty() ? "true" : "false") << std::endl;

	std::cout << "===== string queue test =====" << std::endl;		//string 객체 추가, 객체 템플릿으로 동작 확인
	kmc::queue<std::string> q3;
	q3.push("hello");
	q3.push("world");
	std::cout << "front: " << q3.front() << ", back: " << q3.back() << std::endl;

	std::cout << "===== swap test =====" << std::endl;		//swap 확인
	kmc::queue<int> qa, qb;
	qa.push(10);
	qa.push(20);
	qb.push(100);
	std::cout << "before swap - qa.size: " << qa.size() << ", qb.size: " << qb.size() << std::endl;
	qa.swap(qb);
	std::cout << "after swap - qa.size: " << qa.size() << ", qb.size: " << qb.size() << std::endl;

	std::cout << "===== empty queue front() test =====" << std::endl;
	kmc::queue<int> q4;

	return 0;
}