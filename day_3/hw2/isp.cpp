#include <iostream>

using namespace std;


class Workable {        //일하는 객체
public:
    virtual void work() = 0;    // 가상함수 work 선언
    ~Workable() {}
};


class Eatable {         // 식사하는 객체
public:
    virtual void eat() = 0;     //가상함수 eat 선언
    ~Eatable() {}
};


class Employee : public Workable, public Eatable {      // 사람 노동자 클래스, 일, 식사하는 클래스
public:
    virtual void work(){        //가상함수 work 재정의
        cout << "Employee is working" << endl;
    }

    virtual void eat(){         //가상함수 eat 재정의
        cout << "Employee is eating" << endl;
    }
};


class Robot : public Workable {         // 로봇 클래스, 일만 함, 식사 X
public:
    virtual void work(){        //가상함수 work 재정의
        cout << "Robot is working" << endl;
    }
};

int main() {
    Employee employee;
    employee.work();
    employee.eat();

    Robot robot;
    robot.work();

    // Robot은 Eatable이 아님, eat을 구현하지 않음
}