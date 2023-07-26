class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int min_col = 0;
        int max_col = 0;
        int max_row = 0;
        map<pair<int,int>, vector<int>> nodes_by_level;
        dfs(root, 0, 0, nodes_by_level, min_col, max_col, max_row);
        
        vector<vector<int>> answer;
        for (int j=min_col; j<=max_col; j++){
            vector<int> nodes_at_col_j;
            for (int i=0; i<=max_row; i++){
                if (nodes_by_level.find({i,j})!=nodes_by_level.end()){
                    sort(nodes_by_level[{i,j}].begin(), nodes_by_level[{i,j}].end());
                
                    for (auto& elem: nodes_by_level[{i,j}]){
                        nodes_at_col_j.push_back(elem);
                    }
                }
            }
            answer.push_back(nodes_at_col_j);   
        }
        return answer;
    }
    void dfs(TreeNode*& node, const int& column, const int& row, map<pair<int,int>, vector<int>>& nodes_by_level, int& min_col, int& max_col, int& max_row){
        if (node == nullptr){
            return;
        }
        nodes_by_level[{row,column}].push_back(node->val);
        if (column<min_col){
            min_col = column;
        }
        if (column>max_col){
            max_col = column;
        }
        if (row > max_row){
            max_row = row;
        }
        dfs(node->left, column-1, row+1, nodes_by_level, min_col, max_col, max_row);
        dfs(node->right, column+1, row+1, nodes_by_level, min_col, max_col, max_row);
    }
};
