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

// this section is just for leetcode 100. Same Tree problem. 
static int idx1= -1;
node* buildtree_for_identity_problem(vector<int>PreOrderSequence)
{
    idx1++;
    if(PreOrderSequence[idx1]==-1) return NULL;
    node* root= new node(PreOrderSequence[idx1]);
    root->left= buildtree_for_identity_problem(PreOrderSequence);
    root->right= buildtree_for_identity_problem(PreOrderSequence);
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
  
  int count_node(node* root)
  {
      if(root == NULL) return 0;
      int left_node_sum= count_node(root->left);
      int right_node_sum= count_node(root->right);
      return left_node_sum + right_node_sum + 1;
  }
  
  int sum_node(node* root)
  {
      
      if(root== NULL) return 0;
      int left_sum=sum_node(root->left);
      int right_sum= sum_node(root->right);
      return left_sum + right_sum + root->data;
  }

  

  bool is_identical(node* root1, node* root2)
  {
      if(root2==NULL || root1== NULL)
      return root1==root2;
      
      bool left_identical= is_identical(root1->left, root2->left);
      bool right_identical= is_identical(root1->right, root2->right);
      return left_identical && right_identical && root2->data== root1->data;
      
      
      
  }
  
  int max_height_for_calculate_diameter(node* root)
  {
      if(root==NULL) return 0;
      return max(max_height_for_calculate_diameter(root->left) ,max_height_for_calculate_diameter(root->right))  + 1;
  }
  
  int min_height_for_calculate_diameter(node* root)
  {
      if(root==NULL) return 0;
      return min(min_height_for_calculate_diameter(root->left) ,min_height_for_calculate_diameter(root->right))  + 1;
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
    cout<<count_node(root)<<'\n';
    cout<<sum_node(root)<<'\n';
    vector<int> PreOrderSequence1= {1,2,-1,-1,3,4,-1,-1,5, -1, -1};
    
    node* root1= buildtree_for_identity_problem(PreOrderSequence1);
    
    // cout<<root1->data<<'\n';
    
    cout<<is_identical(root, root1)<<'\n';
int diameter= max_height_for_calculate_diameter(root1)+ min_height_for_calculate_diameter(root1);
    cout<<diameter - 1<<'\n';
}
