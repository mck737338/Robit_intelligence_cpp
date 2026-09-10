#include <iostream>
#include <string>

using namespace std;


class User {            //User 클래스 정의
private:
    string name;
    string email;

public:
    User(string name, string email) {
        this->name = name;
        this->email = email;
    }

    string getName() {
        return name;    //이름 반환
    }

    string getEmail() {
        return email;   //메일 주소 반환
    }
};


class UserRepository {  //저장만 책임지는 클래스
public:
    void saveUser(User user) {
        cout << "User saved to database: " << user.getName() << endl;
    }
};


class EmailService {    //이메일 전송만 책임지는 클래스
public:
    void sendWelcomeEmail(User user) {
        cout << "Welcome email sent to: " << user.getEmail() << endl;
    }
};


class UserActivityLogger {  //활동 기록만 책임지는 클래스
public:
    void logUserActivity(User user) {
        cout << "Logging activity for user: " << user.getName() << endl;
    }
};


class UserService {         //사용자 등록만 책임지는 클래스
private:    //저장, 이메일 전송, 활동 기록 클래스를 
    UserRepository userRepository;
    EmailService emailService;
    UserActivityLogger userActivityLogger;

public:
    void registerUser(User& user) {
        userRepository.saveUser(user);
        emailService.sendWelcomeEmail(user);
        userActivityLogger.logUserActivity(user);
    }
};

int main() {
    User user("kmc", "1234@gmail.com");

    UserService userService;
    userService.registerUser(user);

    return 0;
}