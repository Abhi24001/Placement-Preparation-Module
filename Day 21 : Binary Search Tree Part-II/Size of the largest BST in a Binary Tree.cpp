int ans;
class prop{
public:
    bool bst;       
    int ma;        
    int mi;         
    int ms;         
    prop(){
        bst=true;
        ma=INT_MIN;
        mi=INT_MAX;
        ms=0;
    }
};
class Solution {
public:
    prop calcSum(TreeNode* root){
        if (root == NULL){
            return prop();
        }
        prop p;
        prop pl = calcSum(root->left);                       
        prop pr = calcSum(root->right);                       
        if ( pl.bst==true && pr.bst==true && root->val>pl.ma && root->val<pr.mi ){
            p.bst = true;                                                     
            p.ms = pl.ms + pr.ms + root->val;          
            p.mi  = min(root->val, pl.mi);
            p.ma = max(root->val, pr.ma);
        }
        else {
            p.bst=false;
            p.ms=max(pl.ms, pr.ms);
        }
        ans=max(ans, p.ms);
        return p;
    }
    int maxSumBST(TreeNode* root){
        ans = 0;
        calcSum(root);
        return ans;
    }
};
