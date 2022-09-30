/*
 ID: jerry.c1
 TASK: wormhole
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct a{
    int x, y;
};

bool compare(struct a a, struct a b){
    return a.x < b.x;
}

bool loop(int pairs[], int n, int x[], int y[]){
    for (int i = 0; i < n; i++){//all starting wormholes
        bool a = true;
        int current = pairs[i];
        int start = current;
        int w = 0;
        struct a all[12];
        for (int i = 0; i < n; i++){
            all[i].x = x[i];
            all[i].y = y[i];
        }
        sort(all, all + n, compare);
        while ((a) && (w < n)){
            for (int j = 0; j < n; j++){ //checking all wormholes for next wormhole
                if (j != current){
                    if ((all[j].y == all[current].y) && (all[j].x > all[current].x)){ //checking if wormhole is to right
                        for (int k = 0; k < n; k++){ //finding wormhole in pairs[]
                            if (pairs[k] == j){
                                if (k % 2 == 0){
                                    current = pairs[k + 1];
                                }else{
                                    current = pairs[k - 1];
                                }//found next wormhole
                                j = n;
                                if (current == start){
                                    //cout << current << endl;
                                    return true;
                                }
                                break;
                            }
                        }
                    }
                }
                if (j == n - 1){
                    a = false;
                }
            }
            w++;
        }
    }
    return false;
}

int total = 0;
void all(int n, int a[], int b[], int pairs[], int d, int lasti, bool used[]){
    if (d == n / 2){
        //bool a = loop(pairs, n, a, b);
        if (loop(pairs, n, a, b)){
            total++;
        }
        /*
        for (int i = 0; i < n; i++){
            cout << pairs[i] << ' ';
        }
        cout << endl;
         */
        return;
    }
    
    for (int i = lasti; i < n; i++){
        /*
        cout << d << " " << i << ":";
        for (int j = 0; j < n; j++) {
            cout << used[j];
        }
        cout << endl;
         */
        if (!used[i]){
            used[i] = true;
            //cout << i << endl;
            for (int j = i + 1; j < n; j++){
                if (!used[j]){
                    used[j] = true;
                    /*
                    for (int i = 0; i < n; i++){
                        cout << used[i] << ' ';
                    }
                    cout << used << endl;
                     */
                    pairs[d * 2] = i;
                    pairs[d * 2 + 1] = j;
                    all(n, a, b, pairs, d + 1, i, used);
                    used[j] = false;
                }
            }
            used[i] = false;
        }
    }
}

int main() {
    /*
    int x[4] = {0, 5, 6, 3};
    int y[4] = {0, 0, 0, 5};
    int p[4] = {0, 3, 1, 2};
    cout << loop(p, 4, x, y) << endl;
     */
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    int n, a[12], b[12], pairs[12];
    bool used[12];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i] >> b[i];
        used[i] = false;
        pairs[i] = 0;
    }
    all(n, a, b, pairs, 0, 0, used);
    fout << total << endl;
    return 0;
}


/*
 4
 0 0
 5 0
 6 0
 3 5
*/
