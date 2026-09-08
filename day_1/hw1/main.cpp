#include <iostream>
#include "intArr.h"

using namespace std;

int main() {
	Arr array;		//객체 만들기
	array.inputData();	//값 받기
	cout << "최대값: " << array.max() << endl;		//최대/최소/총합/평균 출력하기
	cout << "최소값: " << array.min() << endl;
	cout << "전체합: " << array.total() << endl;
	cout << "평 균: " << array.average() << endl;
}
