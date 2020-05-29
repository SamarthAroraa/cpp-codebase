//
//  main.cpp
//  top view tree
//
//  Created by Samarth Arora on 11/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class node{
public:
    int data;
    node* right;
    node* left;
    node(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
};
int nodes=0;
node* builtree(node* root){
    
    int val;
    cin>>val;
    if(val==-1)
        return NULL;
    nodes++;
    if(root==NULL)
    {
        node* n=new node(val);
        root=n;
    }

   
//        root;
        root->data=val;
        root->left=builtree(root->left);
        root->right=builtree(root->right);
    
    
    
    return root;
    
}
unordered_map<int, list<int>> levels;
void topview_generate(node* root,int level){
    if(root==NULL)
        return;
    levels[level].push_back(root->data);
    topview_generate(root->left, level-1);
    topview_generate(root->right, level+1);
    
}
void topview_print(){
    for(int i=-pow(2,nodes-1);i<pow(2, nodes-1);i++){
        if(levels.find(i)!=levels.end()){
            cout<<levels[i].front()<<" ";
        }
    }
}


using namespace std;
int main()
{
    node* root=NULL;
    root= builtree(root);
//    cout<<nodes;
    topview_generate(root, 0);
    topview_print();
    return 0;
}
