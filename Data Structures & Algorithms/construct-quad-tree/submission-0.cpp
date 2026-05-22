/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* create(int h1, int h2, int v1, int v2, vector<vector<int>> &grid){
        
        unordered_set<int> unique;
        for(int i=v1;i<v2;i++){
            for(int j=h1;j<h2;j++){
                unique.insert(grid[i][j]);
            }
            if(unique.size()>1)break;
        }
        if(unique.size()>1){
            Node *curr = new Node(1, false);

            int midH = h1 + (h2-h1)/2;
            int midV = v1 + (v2-v1)/2;

            curr->topLeft=create(h1,midH,v1,midV,grid);
            curr->topRight=create(midH,h2,v1,midV,grid);
            curr->bottomLeft=create(h1,midH,midV,v2,grid);
            curr->bottomRight=create(midH,h2,midV,v2,grid);

            return curr;
        }
        
        Node* curr = new Node(grid[v1][h1], true);

        return curr;
    }

    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        return create(0,n,0,m,grid);
    }
};