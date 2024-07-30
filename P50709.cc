#include <iostream>
#include <queue>
using namespace std;

int main () {
    priority_queue<int> q;
    char x;
    int n;
    while (cin >> x) {
        if (x == 'S') {
            cin >> n;
            q.push(n);
            
        }
        if (x != 'A' and x != 'R' and x != 'I' and x != 'D' );
        else if (q.empty()) cout << "error!" << endl;
        else {
            if (x == 'A') cout << q.top() << endl;
            else if (x == 'R') q.pop();
            else if (x == 'I') {
             int t;
             cin>> t; 
             t = t + q.top();
              q.pop();
             q.push(t);
            }
            else if (x == 'D') {
                int t;
                cin>> t; 
                t = q.top() - t;
                q.pop();
                q.push(t);
            }
        }
        
        
    }


}