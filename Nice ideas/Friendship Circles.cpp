#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first 
#define s second 

using ll=long long;
const int C=1e5+5;

int n;

pair<ld,ld> point[C];

int pivot;

bool comp(int a, int b){ 
    if(a==pivot)return 1;
    if(b==pivot)return 0;

    ld dya=point[a].s-point[pivot].s;
    ld dxa=point[a].f-point[pivot].f;

    ld dyb=point[b].s-point[pivot].s;
    ld dxb=point[b].f-point[pivot].f;

    if(dxa==dxb && dxa==0){
        return point[a].s>point[b].s;
    }
    if(dxa==0) return 1;
    if(dxb==0) return 0;

    dya/=dxa;

    dyb/=dxb;

    if(dya==dyb){
        return point[a].f>point[b].f;
    }

    return dya<dyb;
}

int main(){

    cin>>n;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;

        point[i]={x,y};

        //Moving to (0,0)
        if(i){
            point[i].f-=point[0].f;
            point[i].s-=point[0].s;
        }
    }

    point[0]={0,0};

    for(int i=1;i<n;i++){

        ld fc=(ld)1e8/(point[i].f*point[i].f + point[i].s*point[i].s);

        //invertion
        point[i].f*=fc;
        point[i].s*=fc;

    }

    int position[n];

    pivot=0;

    for(int i=0;i<n;i++){

        position[i]=i;

        if(point[i].f<point[pivot].f){
            pivot=i;
        } else if(point[i].f==point[pivot].f){
            if(point[i].s>point[pivot].s){
                pivot=i;
            }
        }
    }

    sort(position,position+n,comp);

    stack<int>convex;

    convex.push(position[0]);
    convex.push(position[1]);

    stack<pair<ld,ld>>vec;

    vec.push({point[position[1]].f-point[position[0]].f,point[position[1]].s-point[position[0]].s});

    for(int i=2;i<n;i++){
        int q=position[i];

        auto top_vector=vec.top();

        pair<ld,ld>aux;

        auto last=convex.top();

        aux={point[q].f-point[last].f,point[q].s-point[last].s};

        while((aux.s*top_vector.f-top_vector.s*aux.f)<0){
            convex.pop();
            vec.pop();

            top_vector=vec.top();

            last=convex.top();

            aux={point[q].f-point[last].f,point[q].s-point[last].s};

        }

        convex.push(q);

        vec.push(aux);

    }

    vector<int>ans;

    while(!convex.empty()){
        int l=convex.top();
        if(l)ans.pb(l);
        convex.pop();
    }

    cout<<ans.size()<<" ";

    sort(ans.begin(),ans.end());

    for(auto l:ans)cout<<l<<" ";

    cout<<"\n";
}
