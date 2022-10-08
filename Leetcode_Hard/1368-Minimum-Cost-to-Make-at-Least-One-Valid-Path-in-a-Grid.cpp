class Solution {
public:
    int minCost(vector<vector<int>>& C) {
        int A=C.size(),B=C[0].size();
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> x={1,0,-1,0},y={0,1,0,-1};
        vector<vector<int>> dis(A,vector<int>(B,INT_MAX));
        dis[0][0]=0;
        while(q.size()>0){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int xx=x[i]+a,yy=y[i]+b;
                if(xx<0 || xx>=A  || yy<0 || yy>=B) continue;
                if(x[i]==-1){
                    if(C[a][b]==4 and dis[xx][yy]>dis[a][b]) dis[xx][yy]=dis[a][b],q.push({xx,yy});
                    else if(dis[xx][yy]>dis[a][b]+1) dis[xx][yy]=dis[a][b]+1,q.push({xx,yy});
                }
                else if(x[i]==1){
                    if(C[a][b]==3 and dis[xx][yy]>dis[a][b]) dis[xx][yy]=dis[a][b],q.push({xx,yy});
                    else if(dis[xx][yy]>dis[a][b]+1) dis[xx][yy]=dis[a][b]+1,q.push({xx,yy});
                }
                else if(y[i]==-1){
                    if(C[a][b]==2 and dis[xx][yy]>dis[a][b]) dis[xx][yy]=dis[a][b],q.push({xx,yy});
                    else if(dis[xx][yy]>dis[a][b]+1) dis[xx][yy]=dis[a][b]+1,q.push({xx,yy});
                }
                else if(y[i]==1){
                    if(C[a][b]==1 and dis[xx][yy]>dis[a][b]) dis[xx][yy]=dis[a][b],q.push({xx,yy});
                    else if(dis[xx][yy]>dis[a][b]+1) dis[xx][yy]=dis[a][b]+1,q.push({xx,yy});                
                }
            }
        }
        return dis[A-1][B-1];
    }
};
