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

	};
}
#include "queue.cpp" 
#endif