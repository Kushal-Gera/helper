#include <bits/stdc++.h>

using namespace std;

bool helper(vector<int> vect, int k, int sum) {

    int till_now = 0;
    int i = 0;
    int k_used = 0;

    while (k_used < k) {
        if (i == vect.size())
            return true;
        if (till_now + vect[i] > sum) {
            k_used++;
            till_now = 0;
            continue;
        }
        till_now += vect[i];
        i++;
    }

    return false;
}

int helperMain(vector<int> vect, int k, int sum) {

    int si = 0;
    int ei = sum;
    int ans = ei;

    while (si <= ei) {
        int mid = (si + ei) / 2;

        if (helper(vect, k, mid)) {
            ans = min(ans, mid);
            ei = mid - 1;
        } else {
            si = mid + 1;
        }
    }

    return ans;
}


int main() {


    int k = 1;
    vector<int> vect = {10, 20, 35, 20};
    int sum = 0;
    for(auto x : vect)
        sum += x;

    cout << helperMain(vect, k, sum);


    return 0;

}