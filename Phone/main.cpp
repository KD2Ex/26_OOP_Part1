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

bool isPhoneNumber(string value) {
    if (value.length() == 12) {
        for (int i = 1; i < 12; i++) {
            if (!isdigit(value[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}




class Address {
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


class Phone {
    map<string, Address> addressBookNames;
    map<string, Address> addressBookPhones;
    
public:
    void add(string name, string number) {
        Address address;
        address.setName(name);
        address.setPhoneNumber(number);

        addressBookNames.insert(pair<string,Address>(name, address));
        addressBookPhones.insert(pair<string,Address>(number, address));
        
    }

    void call(string value) {

        _Rb_tree_iterator<pair<const basic_string<char>, Address>> user;

        if (isPhoneNumber(value)) {
            if (addressBookPhones.find(value) != addressBookPhones.end()) {
                user = addressBookPhones.find(value);
            } else {
                cout << "Invalid phone number\n";
                return;
            }

        } else {
            if (addressBookNames.find(value) != addressBookNames.end()) {
                user = addressBookNames.find(value);
            } else {
                cout << "Invalid phone number\n";
                return;
            }
        }

        cout << "CALL to " << user->second.getName() << " on number " << user->second.getPhoneNumber() << endl;
    }

    void sms(string value, string message) {

        _Rb_tree_iterator<pair<const basic_string<char>, Address>> user;

        if (isPhoneNumber(value)) {
            if (addressBookPhones.find(value) != addressBookPhones.end()) {
                user = addressBookPhones.find(value);
            } else {
                cout << "Invalid phone number\n";
                return;
            }

        } else {
            if (addressBookNames.find(value) != addressBookNames.end()) {
                user = addressBookNames.find(value);
            } else {
                cout << "Invalid phone number\n";
                return;
            }
        }

        cout << "Message: \n" << message << "\n sent to " << user->second.getName()
        << " on number " << user->second.getPhoneNumber() << endl;
    }


    
};



int main() {
    int i;
    Phone phone;


    map<string, int> commands;
    commands[ADD_NAME] = Commands::ADD;
    commands[CALL_NAME] = Commands::CALL;
    commands[SMS_NAME] = Commands::SMS;
    commands[EXIT_NAME] = Commands::EXIT;

    while (true) {
        string inputCommand;

        cout << "Enter the command:\n";
        cin >> inputCommand;

        switch (commands[inputCommand]) {
            case Commands::ADD: {
                string name;
                string phoneNumber;

                cout << "Enter name and phone number\n";
                cin >> name >> phoneNumber;

                while (!isPhoneNumber(phoneNumber)) {
                    cout << "Invalid phone number. Enter valid phone number:\n";
                    cin >> phoneNumber;
                }

                phone.add(name, phoneNumber);
                break;
            }
            case Commands::CALL: {
                string value;

                cout << "Enter the name or phone number of contact\n";
                cin >> value;

                phone.call(value);
                break;
            }
            case Commands::SMS: {
                string value;
                string message;

                cout << "Enter the name or phone number of contact and message\n";
                cin >> value >> message;

                phone.sms(value, message);
                break;
            }
            case Commands::EXIT: {
                return 0;
            }
            default: {
                cout << "Wrong command.\n";
            }
        }
    }
}