/**
 *
 *  @name Depth-first search
 *  @author A B M Ruman
 *
 **/
#include <iostream>
using namespace std;

#define MAX 20

int nodes, edges, start, goal, time,
    discovered[MAX], finished[MAX], parent[MAX],
    adjacencyMatrix[MAX][MAX];
char color[MAX], graphType='d';
bool found = false;

void dfs_visit(int, int);
void dfs(int, int);
void print_cycle(int, int);

int main(){
    int u, v;

    cout << "Enter Number of vertices: ";
    cin >> nodes;

    cout << "Enter Number of edges: ";
    cin >> edges;

    cout << "Enter graph type [undirected=u, directed=d]: ";
    cin >> graphType;

    cout << "Enter start node: ";
    cin >> start;

    cout << "Enter goal node: ";
    cin >> goal;

    cout << "Enter neighbour vertices: " << endl;

    for (int i=1; i<=edges; i++){
        cin >> u >> v;

        switch(graphType){
        case 'u':
            adjacencyMatrix[v][u] = 1;
        case 'd':
            adjacencyMatrix[u][v] = 1;
            break;
        }
    }
    cout <<"Result:\n";

    dfs(start,goal);

    if (!found)
        cout << "\nGoal not found.\n";

    return 0;
}

void dfs(int s, int g){
    for (int i=1; i<=g; i++){
        color[i]='w';
    }
    time=0;

    if(color[s]=='w')
        dfs_visit(s,g);

    cout << endl;
}

void dfs_visit(int s, int g){
    color[s]='g';
    time++;
    discovered[s]= time;
    cout << s << " ";
    if (s == g) {
        found = true;
        cout << "\nGoal Found.\n";
        return;
    }

    for(int v=1; v<=nodes; v++){
        if (adjacencyMatrix[s][v]==1){
            if(color[v] == 'w'){
                parent[v]=s;

                dfs_visit(v,g);

                if(v==g){
                    return;
                }
            }
            /* Cycle detection */
            /*else if(color[v] == 'g'){
                if (u!=v){
                    cout << "\nCycle exists: ";
                    //cout << v << " ";
                    //c=1; z=v;
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

    color[s] ='b';
    time++;
    finished[s] = time;
}

void print_cycle(int u, int t){
    //int t=u;
    for(int v=1, t=u; v<=nodes; v++){
        if(adjacencyMatrix[t][v]==1){
            cout << t<< " ";
            t=v;
        }

        if (v==u) break;
    }
}

