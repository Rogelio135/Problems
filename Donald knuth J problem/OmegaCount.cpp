#include<bits/stdc++.h>
using namespace std;

#define pb push_back

using ll=long long;
const ll N=1e6,C=1e5;

vector<ll>number(N);
vector<int>omega(N);
vector<int>sizes(33);

int sieve[C+5];
vector<int>primes;

int bound[10]={2500,1250,625,313,157,80,40,20,10,5};

int main(){
    freopen("output_omega_count.txt","w",stdout);
    
    for(int i=2;i<C;i++){
        if(sieve[i])continue;
        primes.pb(i);
        for(int k=2;k*i<N/100;k++)sieve[k*i]=1;
    }

    for(int i=0;i<2500;i++){
        for(int j=0;j<N;j++){
            number[j]=N*i+j+1;
            omega[j]=0;
        }

        for(auto p:primes)
            for(ll j=p-(N*i)%p-1;j<N;j+=p)
                while(number[j]%p==0)number[j]/=p, omega[j]++;

        for(int j=0;j<34;j++)sizes[j]=0;

        for(int j=0;j<N;j++){
            if(number[j]!=1)omega[j]++;
            if(omega[j])sizes[omega[j]-1]++;
        }

        for(int j=0;j<10;j++){
            if(i<bound[j])cout<<sizes[j]<<" ";
            else cout<<"0 ";   
        }
        cout<<"\n";
        cerr<<i<<"\n";
    }
}