#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>
#include "queue.hpp"
#include "DataFrame.hpp"

namespace kmc {
	template <typename T>
	queue<T>::queue() {		//queue 생성자, queue 객체 생성 시 크기 0으로 초기화
		this->size_ = 0;
	}

	template <typename T>
	bool queue<T>::empty() {		//empty 함수, 크기가 0이면 true, 아니면 false 반환
		if (this->size_ == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	template <typename T>		//가상함수 size 재정의, protected 영역의 size_ 반환
	size_t queue<T>::size() {
		return this->size_;
	}

	template <typename T>
	T& queue<T>::front() {		//queue 객체의 맨 앞 값(마지막에 들어온 값) 반환
		if (this->empty()) {
			std::cout << "queue is empty" << std::endl;
		}
		else {
			return this->data_[0];
		}
		
	}

	template <typename T>
	T& queue<T>::back() {		//queue 객체의 맨 뒷 값(가장 먼저 들어온 값) 반환
		if (this->empty()) {
			std::cout << "queue is empty" << std::endl;
		}
		else {
			return this->data_[this->size_ - 1];
		}
		
	}

	template <typename T>
	void queue<T>::push(T value) {		//push 함수
		
		T* space = new T[this->size_ + 1];	//더 큰 공간 할당, front에 value 저장
		space[0] = value;

		for (int i = 0; i < this->size_; i++) {
			space[i + 1] = this->data_[i];		//나머지 값 옮기기
		}
		
		if (this->size_ != 0) {
			delete[] this->data_;	//빈 배열이 아닐 때, 공간 삭제
		}

		this->size_++;		//크기 1 증가
		
		this->data_ = space;	//이동한 배열주소로 주소 변경
	}

	template <typename T>
	void queue<T>::pop() {		//pop 함수
		if (this->empty()) {	//queue가 비어있으면 종료
			return;
		}

		this->size_--;	//크기 1 감소
		T* space = new T[this->size_];		//더 작은 공간 생성

		for (int i = 0; i < this->size_; i++) {
			space[i] = this->data_[i];		//마지막 값 제외하고 값 옮기기
		}

		delete[] this->data_;	//기존의 배열 삭제
		this->data_ = space;	//이동한 배열 주소로 주소 변경
	}

	template <typename T>
	void queue<T>::swap(queue<T>& data) {		//swap 함수
		size_t temp_size = data.size();
		T* temp_data = new T[temp_size];
		if (!data.empty()) {		//대상 queue가 비었으면 값 읽지 않음
			for (int i = temp_size - 1; i >= 0; i--) {
				temp_data[i] = data.back();
				data.pop();
			}
		}


		while (!this->empty()) {
			data.push(this->back());	//대상 queue에 값 넣기, 현재 객체의 값 삭제
			this->pop();
		}

		this->size_ = temp_size;	//대상 객체의 기존 크기로 변경
		delete [] this->data_;		//기존 배열 삭제
		this->data_ = temp_data;	//대상 객체의 배열 받기

	}

	template <typename T>
	void queue<T>::clear() {		//clear 함수 재정의
		this->size_ = 0;	//크기 0으로 변경
		delete [] this->data_;	//데이터 삭제
		this->data_ = nullptr;	//null 포인터로 주소 초기화
	}
}

#endif