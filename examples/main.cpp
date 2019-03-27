#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

vector<string> names;

void read_from_console() {
    string temp;

    cout << endl;
    cout << "Enter name:" << endl;
    cin >> temp;
    names.push_back(temp);

    cout << endl << endl;
}

void print_all() {
    cout << endl;
    if (!names.empty()) {
        for (auto it = names.begin(); it < names.end(); it++) {
            cout << *it << endl;
        }
    } else {
        cout << "List is empty!";
    }
    cout << endl << endl;
}

void print_menu() {
    cout << "Commands:" << endl;
    cout << "R: read name" << endl;
    cout << "S: print all list" << endl;
    cout << "Q: exit" << endl;
    cout << endl;
    cout << "Enter command: ";
}

int main()
{
    char choise = ' ';

    do {
        print_menu();
        cin >> choise;
        switch (toupper(choise)) {
            case 'R':   read_from_console();
                        break;

            case 'S':   print_all();
                        break;
            default:    break;
        }
    } while (toupper(choise) != 'Q');
    return 0;
}
