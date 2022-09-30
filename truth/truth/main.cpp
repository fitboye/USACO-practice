//
//  main.cpp
//  truth
//
//  Created by Jerry Cheng on 11/7/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct statement{
    int position, cow, x;
};

bool works;
int cowstate[1001];
vector<statement> a[1001];

void search(int currentcow, int currentcowstate, int maxpos){
    //cout << 'a' << endl;
    if (cowstate[currentcow] == 0){
        cowstate[currentcow] = currentcowstate;
    }else if (cowstate[currentcow] != currentcowstate){
        works = false;
        return;
    }else{
        return;
    }
    
    for (int i = 0; i < a[currentcow].size(); i++){
        if (a[currentcow][i].position < maxpos){
            search(a[currentcow][i].cow, currentcowstate * a[currentcow][i].x, maxpos);
        }
    }
}

int main() {
    ifstream fin("truth.in");
    ofstream fout("truth.out");
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; i++){
        statement y;
        int z;
        char x;
        y.position = i;
        fin >> y.cow >> z >> x;
        if (x == 'T'){
            y.x = 1;
        }else{
            y.x = -1;
        }
        a[z].push_back(y);
        int swap = z;
        z = y.cow;
        y.cow = swap;
        a[z].push_back(y);
    }
    
    int l = 0, r = m + 1;
    while (r - l > 1){
        int mid = (r + l)/2;
        
        works = true;
        for (int j = 1; j <= n; j++){
            cowstate[j] = 0;
        }
        for (int j = 1; j <= n; j++){
            if (cowstate[j] == 0){
                search(j, -1, mid);
            }
        }
        
        if (works){
            l = mid;
        }else{
            r = mid;
        }
    }
    fout << l << endl;
    return 0;
}
