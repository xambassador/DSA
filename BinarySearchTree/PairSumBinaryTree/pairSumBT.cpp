#include<iostream>
#include<algorithm>
using namespace std;
#include"../BST.h"

void preorder(BinarySearchTreeNode<int>* root, vector<int>& v) {
    if(root == NULL) return;
    v.push_back(root->data);
    preorder(root->left,v);
    preorder(root->right,v);
}

void pairSum1(vector<int>& v, int sum) {
    int i{};    
    int j{v.size()-1};
    while(i < j) {
        if(v[i] + v[j] == sum) {
            cout << v[i] << " " << v[j] << endl; 
            i++;
            j--;
        }else if(v[i] + v[j] < sum) i++;
        else j--;
    }
}

void pairSum(BinarySearchTreeNode<int>* root, int sum) {
    vector<int> v;
    preorder(root,v);
    sort(v.begin(), v.end());
    pairSum1(v,sum);
} 


int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    int sum;
    cin >> sum;
    pairSum(root,sum);
}