#include <bits/stdc++.h>
using namespace std;

class BinaryTree{
    public:
    int data;
    BinaryTree* left;
    BinaryTree* right;
};

BinaryTree* newNode(int val){
        BinaryTree* Node = new BinaryTree();
        Node->data = val;
        Node->left = NULL;
        Node->right = NULL;
        return Node;
    }

int maxlvl = 0;
void solve(BinaryTree* root, bool isLeft, int currlvl,BinaryTree** node){
    if(root==NULL){
        return;
    }
    currlvl++;
    if(!root->left && !root->right && isLeft && maxlvl < currlvl){
        *node = root;
        maxlvl = currlvl;
        return;
    }
    solve(root->left,true,currlvl+1,node);
    solve(root->right,false,currlvl+1,node);

}

BinaryTree* deepestLeftLeaf(BinaryTree* root){
    BinaryTree *node = NULL;
    solve(root,true,0,&node);
    return node;
}

int main() {
    BinaryTree* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    BinaryTree *result = deepestLeftLeaf(root);
    if (result)
        cout << "The deepest left child is " << result->data;
    else
        cout << "There is no left leaf in the given tree";
    return 0;
}
