#include <iostream>
#include <map>
#include <string>

using namespace std;

#define ADD_NAME "add"
#define CALL_NAME "call"
#define SMS_NAME "sms"
#define EXIT_NAME "exit"

enum Commands {
    ADD = 1,
    CALL,
    SMS,
    EXIT
};

class Phone {
    map<string, Adress> adressBookNames;
    map<string, Adress> adressBookPhones;
    
public:
    void add(string name, string number) {
        Adress adress;
        adress.setName(name);
        adress.setPhoneNumber(number);

        adressBookNames.insert(pair<string,Adress>(name, adress));
        adressBookPhones.insert(pair<string,Adress>(number, adress));
        
    }

    void callOnName(string name) {
        auto user = adressBookNames.find(name);

        cout << "CALL to " << user->second.getName() << " on number " << 
        user->second.getPhoneNumber();
    }

    void callOnNumber(string phone) {
        auto user = adressBookPhones.find(phone);
        cout << "CALL to " << user->second.getName() << " on number " << 
        user->second.getPhoneNumber();
    }

    
};

class Adress {
    string name;
    string phone;
public: 
    
    string getName() {
        return name;
    }

    string getPhoneNumber() {
        return phone;
    }

    void setName(string value) {
        name = value;
    }

    void setPhoneNumber(string value) {
        phone = value;
    }
};

class PhoneNumber {
    const string code = "+7";
    char phone[10];

    

public:
    void setPhoneNumber(char* value) {
        for (int i = 0; i < 10; i++) {
            phone[i] = value[i];
        }
    }

    void getPhoneNumber() {
        return 
    }
};

int main() {
    int i;

    map<string, int> commands;
    commands[ADD_NAME] = Commands::ADD;
    commands[CALL_NAME] = Commands::CALL;
    commands[SMS_NAME] = Commands::SMS;
    commands[EXIT_NAME] = Commands::EXIT;

    string inputCommand;
    cin >> inputCommand;

    switch(commands[inputCommand]) {
        case Commands::ADD: {
             
            break;
        }
    }
}