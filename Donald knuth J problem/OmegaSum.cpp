#include<bits/stdc++.h>
using namespace std;

#define pb push_back

using ll=long long;
const ll N=1e7,C=1e5;

vector<ll>number(N);
vector<int>omega(N);

int sieve[C+5];
vector<int>primes;

int main(){
    freopen("output_omega_sum.txt","w",stdout);
    
    for(int i=2;i<C;i++){
        if(sieve[i])continue;
        primes.pb(i);
        for(int k=2;k*i<N/100;k++)sieve[k*i]=1;
    }

    for(int i=0;i<1000;i++){
        for(int j=0;j<N;j++){
            number[j]=N*i+j+1;
            omega[j]=0;
        }

        for(auto p:primes)
            for(ll j=p-(N*i)%p-1;j<N;j+=p)
                while(number[j]%p==0)number[j]/=p, omega[j]++;
        
        ll omega_sum=0;

        for(int j=0;j<N;j++){
            if(number[j]!=1)omega[j]++;
            omega_sum+=omega[j];
        }

        cout<<omega_sum<<" ";

        cerr<<i<<"\n";
    }
}