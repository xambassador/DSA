#include<iostream>
using namespace std;
#include"../Tree.cpp"

int height(TreeNode<int>* root){
    if(root == NULL) return 1;
    int* heightOfSubtrees{new int[root->childrens.size()]};
    // Find all subtrees height and save into array.
    for(int i{}; i<root->childrens.size(); i++){
        heightOfSubtrees[i] = height(root->childrens[i]);
    }
    
    // Find max height subtree
    int ans{};
    for(int i{}; i<root->childrens.size(); i++){
        if(heightOfSubtrees[i] > ans){
            ans = heightOfSubtrees[i];
        }
    }
    // return final height including root
    return ans + 1;
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    int ans{height(root)};
    cout << ans << endl;
}