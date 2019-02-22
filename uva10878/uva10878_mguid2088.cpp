#include <cstdio>
#include <iostream>

using std::string;
using std::getline;
using std::cin;

int main(){
    string s;
    register unsigned int i;
    unsigned sum, found;
    while(getline(cin, s)){
        unsigned int bit = 128;
        i = sum = found = 0;
        if(s[i] != '|') continue;
        for(; s[i]; ++i){
            if(s[i] == ' ')
                bit >>= 1;
            else if(s[i] == 'o'){
                sum += bit;
                bit >>= 1;
            }
        }
        printf("%c", sum);
    }
    return 0;
}
