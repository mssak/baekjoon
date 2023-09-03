#include<bits/stdc++.h>
#define MAX 2001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int b[MAX][MAX]{0};
    int n,m,k;
    cin>>n>>m>>k;

    bool istwo=!(m%2);
    bool flag=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char a;
            cin>>a;
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1];

            if(a=='B'){
                if(flag){
                    b[i][j]++;
                }
            }else{
                if(!flag){
                    b[i][j]++;
                }
            }
            flag=!flag;
        }
        if(istwo){
            flag=!flag;
        }
    }

    int ans=1e9;
    for(int i=0;i<=n-k;i++){
        for(int j=0;j<=m-k;j++){
            ans=min(ans,b[i+k][j+k]-b[i+k][j]-b[i][j+k]+b[i][j]);
            ans=min(ans,k*k-(b[i+k][j+k]-b[i+k][j]-b[i][j+k]+b[i][j]));
        }
    }

    cout<<ans;
}
