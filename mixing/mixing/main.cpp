/*
 ID: jerry.c1
 TASK: milk
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct farmer{
    int p, amt;
};

bool compare(farmer a, farmer b){
    return a.p < b.p;
}

int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int n, m;
    fin >> n >> m;
    farmer a[5000];
    for (int i = 0; i < m; i++){
        fin >> a[i].p >> a[i].amt;
    }
    sort(a, a + m, compare);
    
    int cost = 0, amt = 0;
    for (int i = 0; i < m; i++){
        if (amt + a[i].amt < n){
            amt = amt + a[i].amt;
            cost = cost + a[i].amt * a[i].p;
        }else if (amt < n){
            cost = cost + (n - amt) * a[i].p;
            amt = n;
        }else{
            break;
        }
    }
    fout << cost << endl;
    return 0;
}
