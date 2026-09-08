class Pos {
	
	struct position {
		int x;
		int y;
	}typedef position;

	struct position* set;
	int size;
	int min_range;
	int max_range;

public:
	

	Pos();

	void fill_random();		//랜덤한 좌표로 배열 채우기

	float calc_dist(position p1, position p2);		//두 좌표의 거리 계산
	float calc_min();	//최소값 계산, 두 좌표 출력
	float calc_max();	//최대값 계산, 두 좌표 출력

	void process();		//각 함수 순차적으로 실행

	~Pos();
};
