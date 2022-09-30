//
//  main.cpp
//  lifeguards
//
//  Created by Jerry Cheng on 2/22/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

struct lifeguard{
    int start, end;
};

struct time{
    int t, pos;
    bool start;
};

bool compare (lifeguard a, lifeguard b){
    return a.start < b.start;
}

bool comparet (struct time a, struct time b){
    return a.t < b.t;
}

int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int n;
    lifeguard a[100001];
    fin >> n;
    struct time all[200000];
    for (int i = 0; i < n; i++){
        fin >> a[i].start >> a[i].end;
    }
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++){
        all[i * 2].t = a[i].start;
        all[i * 2].start = true;
        all[i * 2].pos = i;
        all[i * 2 + 1].t = a[i].end;
        all[i * 2 + 1].start = false;
        all[i * 2 + 1].pos = i;
    }
    sort(all, all + n*2, comparet);
    for (int i = 0; i < n * 2; i++){
        //cout << all[i].t << endl;
    }
    int totals[100000], count = 0, total = all[n * 2 - 1].t - all[0].t;
    set<int> b;
    for (int i = 0; i < n * 2; i++){
        if (all[i].start){
            count++;
            b.insert(all[i].pos);
        }else{
            count--;
            b.erase(all[i].pos);
        }
        
        if (b.size() == 1){
            for (int j : b){
                totals[j] = totals[j] + all[i + 1].t - all[i].t;
            }
        }else if ((b.size() == 0) && (i != n * 2 - 1)){
            total = total - (all[i + 1].t - all[i].t);
        }
    }
    int min = 1000000000;
    for (int i = 0; i < n; i++){
        if (totals[i] < min){
            min = totals[i];
        }
        //cout << totals[i] << endl;
    }
    //cout << total << ' ' << min << endl;
    
    fout << total - min << endl;
    return 0;
}

/*
 if (b.size() == 1){
 for (int k : b){
 last = k;
 time = a[j].end;
 }
 }else if (last != -1){
 total[last] = a[j].end - time;
 last = -1;
 }
 
 if (b.size() == 1){
 int x;
 for (int k : b){
 x = k;
 }
 if (a[i + 1].start < a[j + 1].end){
 total[x] = a[i + 1].start - a[i].start;
 }else{
 total[x] = a[j + 1].end - a[i].start;
 }
 }
 
 if (b.size() == 1){
 int x;
 for (int k : b){
 x = k;
 }
 if (a[i + 1].start < a[j + 1].end){
 total[x] = a[i + 1].start - a[j].end;
 }else{
 total[x] = a[j + 1].end - a[j].end;
 }
 }
*/
