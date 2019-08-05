
#include <bits/stdc++.h>
#define N 1001
#define ll long long int

using namespace std;

int parent[N];
int size[N];

void initialise(int n){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int root(int a){
    while(parent[a] != a){
        parent[a] = parent[parent[a]]; // modified, faster BUT changes parent.
        a = parent[a];
    }
    return a;
}

bool find(int a, int b){
    if(root(a) == root(b))
        return true;
    return false;
}

void weighted_union(int a, int b){
    int root_a = root(a);
    int root_b = root(b);
    if(size[root_a] < size[root_b]){
        parent[root_a] = parent[root_b];
        size[root_b] += size[root_a];
        size[root_a] = 0;
    }else{
        parent[root_b] = parent[root_a];
        size[root_a] += size[root_b];
        size[root_b] = 0;
    }
}

void printAnswer(int n){
    int var_size[n+1];
    for(int i = 1; i <= n; i++){
        var_size[i] = size[i];
    }
    sort(var_size+1, var_size+n+1);
    for(int i = 1; i <= n; i++){
        if(var_size[i] > 0)
            cout << var_size[i] << " ";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    initialise(n);
    vector<int> g[n];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        weighted_union(a, b);
        printAnswer(n);
        cout << "\n";
    }
    return 0;
}
