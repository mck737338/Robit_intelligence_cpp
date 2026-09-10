#include <iostream>

using namespace std;


class Flyable {     //날 수 있는 객체
public:
    virtual void fly() = 0;
    ~Flyable() {}
};


class Bird {        // 기본 클래스
public:
    void eat() {        //공통 기능
        cout << "Bird is eating" << endl;
    }
};


class Sparrow : public Bird, public Flyable {   // 날 수 있는 새 클래스
public:
    virtual void fly(){ // fly 함수 재정의
        cout << "Sparrow is flying" << endl;
    }
};


class Penguin : public Bird {       // 날 수 없는 새, 다른 기능 없음
};

int main() {
    Sparrow sparrow;
    sparrow.eat();

    sparrow.fly();

    Penguin penguin;
    penguin.eat();
    //penguin.fly()     펭귄은 날 수 없음, fly가 선언 안 됨

}