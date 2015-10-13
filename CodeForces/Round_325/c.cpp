#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;


struct Kid {
    int office, hall, confidence;
    Kid(int a, int b, int c) {
        office = a;
        hall = b;
        confidence = c;
    }
};

vector<Kid> v;

void debug_confidence(int n) {
    for (int i=0; i<n; i++) 
        cerr << v[i].confidence << " ";
    cerr << "\n";
}

int main() {
    freopen("c.in", "r", stdin);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back(Kid(a,b,c));
    }
    vector<int> ret;
    for (int i=0; i<n; i++) {
        if (v[i].confidence >= 0) {
            debug_confidence(n);
            ret.push_back(i+1);
            queue<int> leaving;
            int decrease = v[i].office, j = i+1;
            while (decrease > 0 && j<n) {
                if (v[j].confidence >= 0) {
                    v[j].confidence -= decrease;
                    decrease--;
                    if (v[j].confidence < 0) {
                        leaving.push(j);
                    }
                }
                j++;
            }
            while (!leaving.empty()) {
                int left_id = leaving.front(); leaving.pop();
                for (int j = left_id + 1; j<n; j++) {
                    if (v[j].confidence >= 0) {
                        v[j].confidence -= v[left_id].hall;
                        if (v[j].confidence < 0) {
                            leaving.push(j);
                        }
                    }
                }
            }
        }
    }

    cout << ret.size() << "\n";
    for (int i=0; i<ret.size(); i++)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}
