//
//  main.cpp
//  swap
//
//  Created by Jerry Cheng on 8/15/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    int n, m, k;
    fin >> n >> m >> k;
    int l[100], r[100];
    for (int i = 0; i < m; i++){
        fin >> l[i] >> r[i];
    }
    
    int a[100000];
    for (int i = 0; i < n; i++){
        a[i] = i;
    }
    for (int i = 0; i < m; i++){
        int temp[100000];
        for (int j = l[i] - 1; j < r[i]; j++){
            temp[j - l[i] + 1] = a[j];
        }
        int b = r[i] - l[i];
        for (int j = l[i] - 1; j < r[i]; j++){
            a[j] = temp[b];
            b--;
        }
    }
    int endcycle[100000];
    for (int i = 0; i < n; i++){
        //cout << a[i] << endl;
        endcycle[a[i]] = i;
    }
    
    vector<int> grouppath[100000];
    int cyclecountgroup[100000], groups[100000], currentgroup = 0, grouppathpos[100000];
    for (int i = 0; i < 100000; i++){
        cyclecountgroup[i] = -1;
    }
    for (int i = 0; i < n; i++){
        if (cyclecountgroup[i] < 0){
            int startpos = i, currentpos = endcycle[startpos];
            cyclecountgroup[currentpos] = currentgroup;
            grouppath[currentgroup].push_back(currentpos);
            grouppathpos[currentpos] = grouppath[currentgroup].size() - 1;
            int cyclecount = 1;
            while (startpos != currentpos){
                currentpos = endcycle[currentpos];
                cyclecount++;
                cyclecountgroup[currentpos] = currentgroup;
                grouppath[currentgroup].push_back(currentpos);
                grouppathpos[currentpos] = grouppath[currentgroup].size() - 1;
            }
            groups[currentgroup] = cyclecount;
            currentgroup++;
            //cout << cyclecount << endl;
        }
    }
    
    for (int i = 0; i <= currentgroup; i++){
        for (int j = 0; j < grouppath[i].size(); j++){
            //cout << grouppath[i][j] << ' ';
        }
        //cout << endl;
    }
     
    
    int ans[100000];
    for (int i = 0; i < n; i++){
        int group = cyclecountgroup[i];
        int remaining = k % groups[group];
        int locinloop = grouppathpos[i];
        //cout << remaining << ' ' << locinloop << endl;
        remaining = remaining + locinloop;
        remaining = remaining % grouppath[group].size();
        //cout << remaining << endl;
        if (remaining >= 0){
            ans[grouppath[group][remaining]] = i + 1;
        }else{
            ans[i] = i + 1;
        }
        /*
        int pos = i;
        for (int i = 0; i < remaining; i++){
            pos = endcycle[pos];
        }
        ans[pos] = i + 1;
         */
    }
    
    for (int i = 0; i < n; i++){
        fout << ans[i] << endl;
    }
    return 0;
}
