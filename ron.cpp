#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream cin("ron.in");
ofstream cout("ron.out");

const int VMAX = 1e5*2;
const int N = 5e4;

int prim[VMAX+1];
int v1[N+1];
int v2[N+1];
int poz[N+1];

void ciur(){

for (int i = 2; i*i<=VMAX; i++){
    if(prim[i]==0){
        for (int j = i*i; j<=VMAX;j+=i){
            prim[j]=1;
        }
    }
}

}

void sumpart(){
int s = 0;
for (int i = 2; i<=VMAX; i++){
    s+=!(prim[i]);
    prim[i]=s;
}

}

bool cmp(int p1, int p2){
    return (v1[p1]<v1[p2]);
}

int main()
{

    int c,n;

    cin>>c>>n;

    if(c==1){
        int maxx = 0;
        ciur();
        sumpart();
        for (int i = 1; i<=n;i++){
            int poz, l;
            cin>>poz>>l;
            int e = poz+l-1;
            int pr = prim[(int)sqrt(e)]-prim[(int)sqrt(poz-1)];
            maxx = max(maxx, pr);

        }
        cout<<maxx;

    }

    if(c==2){
        for (int i = 1; i<=n;i++){
        int poz1, l;
        cin>>poz1>>l;
        int e = poz1+l-1;
        v1[i]=poz1;
        v2[i]=e;
        poz[i]=i;
        }
        sort(poz,poz+n+1,cmp);

        int emax = 0;
        int ctr=0;
        for (int i = 1; i<=n;i++){
            int pos = poz[i];
            if(v1[pos]>emax){
                ctr++;
            }
            emax = max(emax, v2[pos]+1);
        }
        cout<<ctr;
    }


    return 0;
}
