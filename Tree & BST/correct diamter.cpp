#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    node* left;
    node* right;
    
    node(int val)
    {
        data= val;
        left= NULL;
        right= NULL;
        
    }
};

static int idx= -1;
node* buildtree(vector<int>PreOrderSequence)
{
    idx++;
    if(PreOrderSequence[idx]==-1) return NULL;
    node* root= new node(PreOrderSequence[idx]);
    root->left= buildtree(PreOrderSequence);
    root->right= buildtree(PreOrderSequence);
    return root;
}

// ##preorder traversal

void preorderTraverse(node* root)

{
    if(root== NULL) return;
    cout<<root->data<< " ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
    
    
}

// Inorder Traverse

void InorderTraveser(node* root)
{
    if(root== NULL) return;
    InorderTraveser(root->left);
    cout<<root->data<<" ";
    InorderTraveser(root->right);
    
}

// postOrder Traverse
 void postOrderTraverse(node* root)
 {
    if(root == NULL) return;
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout<<root->data<< " ";
    
 }

  int height(node* root)
  {
      if(root== NULL) return 0;
      int left_height= height(root->left);
      int right_height= height(root->right);
      
      return max(left_height, right_height)+1;
  }
  static int ans=0;
  int diameter(node* root)
  {
      if(root==NULL) 
      {
          return 0;
      }
      int left_height= diameter(root->left);
      int right_height= diameter(root->right);
      ans= max(left_height + right_height, ans);
      return 1+ max(left_height, right_height);
  }

int main()
{
    cout<<"Aasif";
    vector<int> PreOrderSequence= {1,2,-1,-1,3,4,-1,-1,5, -1, -1};
    
    node* root= buildtree(PreOrderSequence);
    
    cout<<root->data;
    cout<<root->left->data;
    cout<<'\n';
    preorderTraverse(root);
    cout<<'\n';
    InorderTraveser(root);
    cout<<'\n';
    postOrderTraverse(root);
    cout<<'\n';
    cout<<height(root)<<'\n';
    cout<<'\n';
    cout<<diameter(root)<<'\n';
    
}
