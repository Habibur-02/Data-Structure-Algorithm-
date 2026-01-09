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


int main()
{
    cout<<"Aasif";
    vector<int> PreOrderSequence= {1,2,-1,-1,3,4,-1,-1,5, -1, -1};
    
    node* root= buildtree(PreOrderSequence);
    
    cout<<root->data;
    cout<<root->left->data;
    
}

