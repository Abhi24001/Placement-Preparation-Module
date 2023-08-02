void cei(BinaryTreeNode<int>*node,int x,int &val){

    if(node==NULL){

      

        return;

    }

    if(node->data==x){

        val=x;

        return;

    }

    if(node->data>x){

        if(val!=-1){

     val=min(val,node->data);

        }

        else 

        {

            val=node->data;

        }

        cei(node->left,x,val);

    }else if(node->data<x){

        cei(node->right,x,val);

    }

}

int findCeil(BinaryTreeNode<int> *node, int x){

    // Write your code here.

    int val=-1;

    cei(node,x,val);

    return val;

 

}
