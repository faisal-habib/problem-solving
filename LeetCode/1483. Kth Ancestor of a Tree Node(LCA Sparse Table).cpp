/// lca using sparse table
/// create table( pre-processing) - NlogN
/// query - logN
/**
Create sparse table (a 2D table) for saving every node's 2^0 th parent, 2^1 th parent, 2^2 th parent...
If it doesn't have 2^i th parent, then keep -1 as the parent

If we want to find 25 th parent of node n, first find 2^4=16 th parent (which is the largest power of 2 <= 25)
Then find 25-16=9 th parent of previous parent(16 th parent)

*/

class TreeAncestor {
public:
    int table[50004][17];   // 2^16 = 65,536 > 5*10^4
    int totalNode;

    void _LCA(int N, vector<int>& parent) {
        memset(table, -1, sizeof(table));
        for(int i=0; i<N; i++) table[i][0] = parent[i];    // at 0 position we're keeping direct parent

        for(int j=1; (1<<j)<N; j++) {
            // loop will run till 2^j<N
            for(int i=0; i<N; i++) {
                if(table[i][j-1]!=-1) table[i][j] = table[table[i][j-1]][j-1];
            }
        }
    }

    TreeAncestor(int n, vector<int>& parent) {
        totalNode = n;
        _LCA(n, parent);
    }

    int getKthAncestor(int node, int k) {
        if(k>=totalNode) return -1;
        int kthAncestor = node, count = 0;
        for(int i=0; i<17; i++) {
            if(k & (1<<i)) {
                kthAncestor = table[kthAncestor][i];
                if(kthAncestor==-1) return -1;
            }
        }
        return kthAncestor;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
