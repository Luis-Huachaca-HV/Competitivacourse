#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include "string"

using namespace std;

#define ll long long

ll remv_get(list<ll> &veco){
    list<ll> copi;
    copi = veco;
    veco.pop_front();
    return copi.front();

}
ll get_value(ll nini,ll cnt,ll nobj, map<ll,list<ll>> val,map<list<ll>,ll> &pesos,  ll i){
    //for (auto j = val[nini].begin(); j != val[nini].end(); j++){
        //cout << *val[1].end() << " " <<*val[nini].begin() << " " << *val[nini].end() <<  " aa"<<endl;
        //cout << val[nini].front();

        if(find(val[nini].begin(),val[nini].end(),nobj) != val[nini].end()){
            //cout << j << endl;
            pesos[{i,nobj}]=++cnt;
            //cout << cnt << " "<< i << " " << nobj <<" cnt" << endl;
            return 0;
            }
        else{
            cout << *val[nini].begin() << " be" << endl;
            //val[nini].pop_front();
            cout << *val[nini].begin() << " af" << endl;
            get_value(val[nini].pop_front(),++cnt,nobj,val,pesos,i);
        }
    //}
}

int main() {

    map<ll,list<ll>> val;

    map<list<ll>,ll> peso;
    val[1] = {};
    ll nv ,dv;

    cin >>nv>>dv;
    ll cnv = nv;
    vector<list<ll>> stval;
    nv = nv-1;
    while (nv--){
        ll ve,nve;
        cin >>ve>>nve;
        val[ve].push_back(nve);
        val[nve].push_back(ve);
        //cout << "A" <<endl;

        //ve=0;
        //nve=0;
    }
    //cout << *val[1].begin() << " beg" <<endl;
    int c = 1;

    while (c!=6 ){

        for(auto i = val[c].begin(); i != val[c].end() ;i++){
            cout << *i << " ";
        } cout <<endl;
        c++;
    }

    int a = 0;
    for(ll i = 1; i < cnv;++i){
        for(ll k = i+1 ; k <= cnv; ++k){
            peso[{i,k}] = 0;
            //cout << peso[a-1][0] << " " << peso[a-1][1] << endl;
            //get_value(i,1,k,val,peso,i);
        }
    }

    //int a = 0;


    for(ll i = 1; i < cnv;++i){
        for(ll k = i+1 ; k <= cnv; ++k){
            map<ll,list<ll>> valc(val);
            //peso[a++] = {i,k};
            //cout << i << " " << k << endl;
            get_value(i,0,k,valc,peso,i);
        }
    }

    //int a = 0;
    /*
    for(ll i = 1; i < cnv;++i){
        for(ll k = i+1 ; k <= cnv; ++k){
            //peso[{i,k}] = 0;

            cout << peso[{i,k}] << endl;
            //get_value(i,1,k,val,peso,i);
        }
    }*/


    return 0;

}
