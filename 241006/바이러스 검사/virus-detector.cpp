#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int cap, mem;
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    v.resize(n);

    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    cin >> cap >> mem;

    for(int i = 0; i < n; ++i){
        ans++;
        if(v[i] < cap){
            continue;
        }

        v[i] -= cap;
        ans += (v[i] / mem);
        if((v[i] % mem) != 0){
            ans++;
        }

    }

    cout << ans;

    return 0;
}