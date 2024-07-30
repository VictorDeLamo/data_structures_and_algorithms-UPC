#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main () {
    string comando;
    map<string,int> mp;
    while(cin >> comando) {
        if (comando == "minimum?") {
            if (mp.empty()) cout << "indefinite minimum" << endl;
            else {
                auto it = mp.begin();
                
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (comando == "maximum?") {
            if (mp.empty()) cout << "indefinite maximum" << endl;
            else {
                auto it = mp.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (comando == "store") {
            string palabra;
            cin >> palabra;
            ++mp[palabra];
        }
        else if (comando == "delete") {
            string palabra;
            cin >> palabra;
            auto it = mp.find(palabra);
            if (it != mp.end()) {
                if (--mp[palabra] == 0) mp.erase(palabra);
            }
            
        }
    }
}