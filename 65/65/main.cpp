//
//  main.cpp
//  65
//
//  Created by Jerry Cheng on 8/15/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s;
    cin >> s;
    
    stack<char> operators;
    stack<int> operands;
    for (int i = 0; i < s.length(); i++){
        char x[10], y;
        int j = 0;
        while (i < s.length() && int(s[i]) >= int('0') && int(s[i]) <= int('9')){
            x[j] = s[i];
            i++;
            j++;
        }
        if (i < s.length()){
            y = s[i];
        }else{
            y = 'a';
        }
        
        int z = 0, multiplier = 1;
        for (int k = j - 1; k >= 0; k--){
            z = z + multiplier * (int(x[k]) - int('0'));
            multiplier = multiplier * 10;
        }
        
        cout << z << ' ' << y << endl;
        if (operators.empty()){
            operands.push(z);
            operators.push(y);
        }else{
            if (operators.top() == '+'){
                if (y == '*'){
                    operands.push(z);
                    operators.push(y);
                }else{
                    int temp;
                    temp = operands.top();
                    operands.pop();
                    temp = temp + z;
                    operands.push(temp);
                    operators.pop();
                    operators.push(y);
                }
            }else{
                int temp;
                temp = operands.top();
                operands.pop();
                temp = temp * z;
                operands.push(temp);
                operators.pop();
                operators.push(y);
            }
        }
        cout << operands.top() << endl;
    }
    operators.pop();
    //cout << 'a' << endl;
    //cout << operands.size() << ' ' << operators.top() << endl;
    while(!operators.empty()){
        if (operators.top() == '+'){
            int temp;
            temp = operands.top();
            operands.pop();
            temp = temp + operands.top();
            operands.pop();
            operands.push(temp);
            operators.pop();
        }else{
            int temp;
            temp = operands.top();
            operands.pop();
            temp = temp * operands.top();
            operands.pop();
            operands.push(temp);
            operators.pop();
        }
    }
    cout << operands.top() << endl;
    return 0;
}
