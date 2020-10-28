#include<iostream>
using namespace std;
#include"../BST.h"


// Method 1
/******************************************************************************************/
int Sum(BinarySearchTreeNode<int>* root) {
    if(root == NULL) return 0;
    return root->data + Sum(root->left) + Sum(root->right);
}

int help(BinarySearchTreeNode<int>* root, int sum) {
    if(root == NULL) return 0;

    int rightSum {Sum(root->right)};
    
    root->data = root->data + rightSum + sum;
    
    int leftans {help(root->left, root->data)};
    int ans;
    if(sum == 0) {
        ans = help(root->right,sum);
    }else{
        ans = help(root->right, sum);
    }
    return ans;
}
/******************************************************************************************/


// Method 2
/******************************************************************************************/
int Position(int key, vector<int> v, int start, int end){
    if(start > end){
        return -1;
    }
    int mid = (start+end)/2;
    if(v[mid] == key){
        return mid;
    }
    if(key < v[mid]){
        return Position(key,v,start,mid-1);
    }
    if(key > v[mid]){
        return Position(key,v,mid+1,end);
    }
}

void help1(BinarySearchTreeNode<int>* root, vector<int>& v){
    if(root == NULL){
        return;
    }
    int position = Position(root->data,v,0,v.size()-1);
    int sum = v[position];
    if(position < v.size()-1){
        for(int i = position+1; i<v.size();i++){
			sum += v[i];
        }
    }
    root->data = sum;
    help1(root->left,v);
    help1(root->right,v);
}

void Inorder(BinarySearchTreeNode<int>* root, vector<int> &v){
    if(root == NULL){
     	return;
    }
    Inorder(root->left,v);
    v.push_back(root->data);
    Inorder(root->right,v);
}
/******************************************************************************************/


void replaceSum(BinarySearchTreeNode<int>* root){
    // int ans {help(root,0)};
    vector<int> v;
    Inorder(root, v);
    help1(root, v);
}


int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    replaceSum(root);
    printLevelWise(root);
    delete root;
}