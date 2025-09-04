#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void print(int x){
    string s="";
    for(;x;x/=91){
        s+='#'+x%91;
        if(s.back()=='\\')s+='\\';
    }
    reverse(s.begin(),s.end());
    cout<<s;
}

int main(){

    freopen("output_string.txt","w",stdout);

    freopen("output_omega_count.txt","r",stdin);

    int omega_count;

    while(cin>>omega_count){
        print(omega_count);
        cout<<'~';
    }
    cout<<"\n\n";
    cin.clear();

    freopen("output_omega_sum.txt","r",stdin);

    int omega_sum;

    while(cin>>omega_sum){
        print(omega_sum);
        cout<<'~';
    }
    cout<<endl;
}