//
//  main.cpp
//  auto
//
//  Created by Jerry Cheng on 4/27/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct dict{
    string word;
    int loc;
};

bool c(dict a, dict b){
    return a.word < b.word;
}

dict d[2000000];
string a[2000000];
int k[2000000];
int main(){
    ifstream fin("auto.in");
    ofstream fout("auto.out");
    int w, n;
    fin >> w >> n;
    for (int i = 0; i < w; i++){
        fin >> d[i].word;
        d[i].loc = i + 1;
    }
    for (int i = 0; i < n; i++){
        fin >> k[i] >> a[i];
    }
    //fout<<3<<endl<<1<<endl<<-1<<endl; return 0;
    sort(d, d + w, c);
    
    
    /*
    for (int i = 0; i < w; i++){
        cout << d[i].word << endl;
    }
    */
    
    for (int i = 0; i < n; i++){
        int l = -1, r = w, mid;
        while (l + 1 < r){
            mid = (r + l) / 2;
            if(!(mid>=0&&mid<w))return 0;
            if (d[mid].word >= a[i]){
                r = mid;
            }else{
                l = mid;
            }
        }
        bool none = false;
        //cout << 'a' << r << endl;
        r = r + k[i] - 1;
        //cout << 'a' << r << endl;
        if (r > w - 1){
            none = true;
        }else if (a[i].length() > d[r].word.length()){
            none = true;
        }else{
            if (!(r>=0&&r<w)) return 0;
            for (int j = 0; j < a[i].length(); j++){
                if (!(j<d[r].word.length())) return 0;
                if (a[i][j] != d[r].word[j]){
                    none = true;
                }
            }
        }
        if (none){
            fout << -1 << endl;
        }else{
            if (!(r>=0&&r<w)) return 0;
            fout << d[r].loc << endl;
        }
    }
    return 0;
}
