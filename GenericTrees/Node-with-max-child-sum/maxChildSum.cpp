#include<iostream>
using namespace std;
#include"../Tree.h"

class Pair{
    public:
    TreeNode<int>* node;
    int sum;
    Pair() : node{NULL}, sum{} {}
};

Pair maxSumNode(TreeNode<int>* root){
    int sum{root->data};
    for(int i{}; i<root->childrens.size(); i++){
        sum += root->childrens[i]->data;
    }

    Pair ans;
    ans.sum = sum;
    ans.node = root;
    for(int i{}; i<root->childrens.size(); i++){
        Pair tmpAns{maxSumNode(root->childrens[i])};
        if(ans.sum < tmpAns.sum){
            ans.sum = tmpAns.sum;
            ans.node = tmpAns.node;
        }        
    }

    return ans;
}

TreeNode<int>* maxSumChild(TreeNode<int>* root){
    return maxSumNode(root).node;
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    TreeNode<int>* ans{maxSumChild(root)};
    cout << ans->data << endl;
}