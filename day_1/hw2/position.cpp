#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "position.h"

using namespace std;

Pos::Pos() {

	cout << "Please define the number of points: ";		//입력값을 객체의 size에 저장, 좌표 구조체 포인터에 동적할당
	cin >> size;
	set = new position[size];

	cout << "Please define minimum of coor. value: ";	//최소, 최대 좌표 입력
	cin >> min_range;
	cout << "Please define maximum of coor. value: ";
	cin >> max_range;
}

void Pos::fill_random() {
	srand((unsigned int)(time(NULL)));		//랜덤 시드값 재설정

	cout << "\n\nGenerate Random points" << endl;

	for (int i = 0; i < size; i++) {
		position dummy;		//무작위 좌표를 저장할 변수
		dummy.x = min_range + rand() % (max_range - min_range + 1);	//x, y에 최소값 ~ 최대값 중 무작위값 저장
		dummy.y = min_range + rand() % (max_range - min_range + 1);

		cout << "Point " << i + 1 << "X: " << dummy.x << ", Y: " << dummy.y << endl;	//좌표 출력

		set[i] = dummy;		//배열에 좌표 저장
	}
}

float Pos::calc_dist(position p1, position p2) {
	int dx = p1.x - p2.x;		//입력받은 두 좌표의 x, y 변량 계산
	int dy = p1.y - p2.y;

	float dist = sqrt(dx * dx + dy * dy);		// 두 좌표 거리 계산

	return dist;
}

float Pos::calc_min() {
	int index1 = 0;		//인접한 두 좌표, 초기값은 인덱스 0과 1
	int index2 = 1;
	float min = calc_dist(set[0], set[1]);		//거리 초기값 계산

	for (int i = 0; i < size - 1; i++) {		//이중 for문으로 nCr의 모든 경우의 수 탐색
		for (int j = i + 1; j < size; j++) {
			float dist = calc_dist(set[i], set[j]);

			if (dist < min) {		//탐색한 거리가 저장된 값보다 작으면 좌표와 거리 새로 저장
				index1 = i;
				index2 = j;
				min = dist;
			}
		}
	}

	cout << "MinDist=" << min << endl;		//거리, 좌표 출력
	cout << "Pair of Min Coor." << "(x, y): P1(" << set[index1].x << ',' << set[index1].y << ") & P2(" << set[index2].x << ',' << set[index2].y << ')' << endl;
	return min;
}

float Pos::calc_max() {
	int index1 = 0;		//인접한 두 좌표, 초기값은 인덱스 0과 1
	int index2 = 1;
	float max = calc_dist(set[0], set[1]);		//거리 초기값 계산

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			float dist = calc_dist(set[i], set[j]);

			if (dist > max) {		//탐색한 거리가 저장된 값보다 크면 좌표와 거리 새로 저장
				index1 = i;
				index2 = j;
				max = dist;
			}
		}
	}

	cout << "MaxDist=" << max << endl;		//거리, 좌표 출력
	cout << "Pair of Max Coor." << "(x, y): P1(" << set[index1].x << ',' << set[index1].y << ") & P2(" << set[index2].x << ',' << set[index2].y << ')' << endl;
	return max;
}


void Pos::process() {		//랜덤한 좌표로 채우기, 최소값, 최대값 찾기 실행
	fill_random();			//좌표 배열 채우기

	cout << "\n-------- Result --------\n";
	calc_min();		//최소, 최대값과 좌표 출력
	cout << "\n";
	calc_max();

	cout << "\n\n***************** Completed *****************\n";
}

Pos::~Pos() {
	delete set;
}