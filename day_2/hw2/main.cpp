#include <iostream>
#include <fstream>
#include "queue.hpp"

using namespace std;

void readFile(kmc::queue<int>& q);
void writeFile(kmc::queue<int>& q);

int main() {
	kmc::queue<int> q;

	readFile(q);
	writeFile(q);
}

void readFile(kmc::queue<int>& q) {
	ifstream fin;	//파일 읽기용 객체 생성
	fin.open("input.txt");	//파일 열기
	if (!fin) {		//파일이 없으면 종료
		cout << "input.txt 를 찾을 수 없습니다." << endl;
		return;
	}

	cout << "파일 읽기 시작" << endl;

	int temp;
	for (int i = 0; i < 5; i++) {		//5개 데이터 읽고 queue에 저장
		fin >> temp;
		q.push(temp);
		cout << "input.txt: " << temp << " loaded: " << q.front() << endl;
	}

	fin.close();
	cout << "파일 읽기 종료\n" << endl;

}

void writeFile(kmc::queue<int>& q) {
	ofstream fout("output.txt");		//파일 작성용 객체 생성, 파일 열기

	if (!fout) {		//파일이 없으면 새로 작성, 있으면 덮어쓰기
		cout << "output.txt 를 찾을 수 없습니다. 파일을 새로 작성합니다." << endl;
		fout.open("output.txt");
	}
	else {
		cout << "output.txt 를 찾았습니다. 기존 파일을 덮어씁니다." << endl;
		//fout.close();
		//fout.open("output.txt", ios::trunc);
	}
	
	cout << "파일 쓰기 시작" << endl;

	while (!q.empty()) {		//queue에 저장된 모든 값 순서대로 저장
		fout << q.back() << endl;
		cout << "write: " << q.back() << endl;
		q.pop();
	}

	cout << "파일 쓰기 종료\n" << endl;

}