#include <iostream>

using namespace std;


class Switchable {      // 스위치 가능한 클래스
public:
    virtual void turnOn() = 0;      //가상함수 선언
    virtual void turnOff() = 0;
    ~Switchable() {}
};


class Fan : public Switchable {     // 저수준 클래스 Fan
public:
    virtual void turnOn(){          //가상함수 재정의
        cout << "Fan is spinning" << endl;
    }

    virtual void turnOff(){
        cout << "Fan is stopping" << endl;
    }
};


class Switch {      // 고수준 클래스
private:
    Switchable* device;     // 제어할 대상

public:
    Switch(Switchable* device) {
        this->device = device;
    }

    void turnOn() {     //저수준 클래스 제어
        device->turnOn();
    }

    void turnOff() {
        device->turnOff();
    }
};


int main() {
    // Fan 객체 생성
    Fan fan;

    // Switch에 Fan 연결
    Switch sw(&fan);

    sw.turnOn();
    sw.turnOff();
}