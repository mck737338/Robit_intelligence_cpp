#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "DataFrame.hpp"

namespace kmc {
	template <typename T>
	class queue : public DataFrame<T> {
	public:
		queue();
		//queue(T* array);

		bool empty();
		virtual size_t size();
		T& front();
		T& back();
		void push(T value);
		void pop();
		void swap(queue<T>& data);
		void clear();
		
		queue<T> copy();

		template <typename T>
		queue<T> operator+(queue<T>& queue2) {
			queue<T> temp1 = this->copy();		//연산자 호출한 객체 복사
			queue<T> temp2 = queue2.copy();		//매개변수 객체 복사

			while (!temp2.empty()) {		//호출한 객체 사본에 매개변수 객체값 push
				temp1.push(temp2.back());
				temp2.pop();
			}

			return temp1;		//합쳐진 객체 반환

		}

	};


	template <typename T>
	void operator+=(queue<T>& queue1, queue<T>& queue2) {
		queue<T> temp = queue1 + queue2;	//두 객체 합 저장

		queue1.swap(temp);		//1번 객체(대상 객체)를 두 객체 합으로 변경
	}
}
#include "queue.cpp" 
#endif