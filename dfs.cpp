#include <iostream>
using namespace std;

#define MAX 20

int n, e, adj[MAX][MAX], time, c, t;
char color[MAX], gt='d';
int d[MAX], f[MAX], p[MAX];

void dfs_visit(int u);
void dfs();
/*
void print_cycle(int u){
    int t=u;
    for(int v=1; v<=n; v++){
        if(adj[u][v]==1){
            cout << u<< " ";
            u=v;
        }

        if (v==t) break;
    }
}
*/
void print_cycle(int u, int t){

}

void dfs(){
    for (int u=1; u<=n; u++){
        color[u]='w';
    }
    time=0;

    for (int u=1; u<=n; u++){
        if(color[u]=='w')
            dfs_visit(u);
    }
    cout << endl;
}

void dfs_visit(int u){
    color[u]='g';
    time++;
    d[u]= time;
    cout << u << " ";
    if (u != t){
        for(int v=1; v<=n; v++){
        if (adj[u][v]==1){
            if(color[v] == 'w'){
                p[v]=u;

                dfs_visit(v);
            }
            /* Cycle detection */
            /*else if(color[v] == 'g'){
                if (u!=v){
                    cout << "\nCycle exists: ";
                    //cout << v << " ";
                    //c=1; t=v;
                    int r = v;
                    int i = u;
                    cout << v;
                    cout << u;
                    while(1)
                    {
                        cout << p[i] << " ";
                        i = p[i];
                        if(p[i] == r)
                            break;
                    }
                }
            }*/
        }
    }
    }

    /*if (c==1){
        cout << u << " ";
        if (u==t) {
            c=0;
            t=0;
        }
    }*/
    color[u] ='b';
    time++;
    f[u] = time;
}
int main(){
    int u, v;
    cout << "Enter Number of vertices: ";
    cin >> n;
    cout << "Enter Number of edges: ";
    cin >> e;

    cout << "Enter neighbour vertices: " << endl;

    for (int i=1; i<=e; i++){
        cin >> u >> v;
        switch(gt){
        case 'u':
            adj[v][u] = 1;
        case 'd':
            adj[u][v] = 1;
            break;
        }

    }

    dfs();

    cout << "d[] = ";
    for (int i=1; i<=n; i++){
        cout << d[i] << ' ';
    }

    cout << endl;
    cout << "f[] = ";
    for (int i=1; i<=n; i++){
        cout << f[i] << ' ';
    }

    cout << endl;

    cout << "p[] = ";
    for (int i=1; i<=n; i++){
        cout << p[i] << ' ';
    }

    cout << endl;
    /*
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}

/*
6
8
1 2
1 4
2 3
3 4
4 2
5 3
5 6
6 6
*/

/*
0 1 0 1 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 1 0 0 0 0
0 0 1 0 0 1
0 0 0 0 0 1
*/
