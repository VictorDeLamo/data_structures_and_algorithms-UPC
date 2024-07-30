#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string name;
    map <string,int> people;
    while (cin >> name){
        bool presence = (people.find(name) != people.end());
        string action;
        cin >> action;
        if (action == "enters"){
            if (presence) cout << name << " is already in the casino" << endl;
            else people[name] = 0;
        } 
        else if (action == "leaves"){
            auto it = people.find(name);
            if (it == people.end()) cout << name << " is not in the casino" << endl;
            else {
                cout << name << " has won " << people[name]<< endl;
                people.erase(it);
            }
        }
        else {
            int money;
            cin >> money;
            if (not (presence)) cout << name << " is not in the casino" << endl;
            else {
                people[name] += money;
            }
        }
    }
    cout << "----------" << endl;
    auto it = people.begin();
    while (it != people.end()) {
        cout << it->first << " is winning " << it->second << endl;
        ++it;
    }

}