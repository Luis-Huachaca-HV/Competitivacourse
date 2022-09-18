#include <iostream>
#include <map>
#include "string"

using namespace std;

#define ll long long

int main() {

    string v[26]={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    map<string,string>m;

    for (int i = 1; i <= 26; ++i) {
        if (i >= 10){
            m[to_string((i)*10) ] = v[i-1];
        } else{
            m[to_string(i)] = v[i-1];
        }
    }

    //for (int j = 1; j < 26; j++) {
     //   cout << m[v[j]] << endl;
    //}


    ll tc;
    cin >> tc;
    while(tc--){
        ll lw;
        string wns = "" ;
        cin >> lw;
        cin >> wns;
        string pal = "";
        //cout << "m: " << m["100"] << endl;
        for(int k = lw-1; k >= 0; --k ){

            if(wns[k] == '0'){
                //cout << "sub "<<  m[val.substr(k-2,3)] << " ";
                pal.insert(0,m[wns.substr(k-2,3)]);
                k = k-2;
            }else{
                pal.insert(0,m[wns.substr(k,1)]);
            }
            //   cout << k << ' ';
        }
        //cout << endl;
        //pal.insert(0,"aaa");
        cout << pal << endl;
    }

    return 0;

}
