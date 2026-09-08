class Arr {		//클래스 선언
	int size;		//배열의 크기와 주소는 private으로 선언
	int* arr;

public:
	Arr();		//public 영역에 생성자, 소멸자와 데이터 입력, 최대/최소/총합/평균 함수 선언
	void inputData();
	int max();
	int min();
	int total();
	int average();
	~Arr();
};
