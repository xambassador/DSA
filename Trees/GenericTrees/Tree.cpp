#include<iostream>
#include<queue>
using namespace std;
#include"TreeNode.h"

// Take input level wise(BFS)
TreeNode<int>* takeInputLevelWise(){
    int data;
    cout << "Enter root's data : ";
    cin >> data;
    TreeNode<int>* root{new TreeNode<int>(data)};
    queue<TreeNode<int>*> pendingTreeNodes;
    pendingTreeNodes.push(root);
    while(!pendingTreeNodes.empty()){
        int numChilds{};
        TreeNode<int>* node{pendingTreeNodes.front()};
        cout << "Enter number of childrens of " << node->data << " :";
        cin >> numChilds;

        cout << "Enter childrens of : " << node->data << endl; 
        for(int i{}; i<numChilds; i++){
            cin >> data;
            TreeNode<int>* newNode{new TreeNode<int>(data)};
            pendingTreeNodes.push(newNode);
            node->childrens.push_back(newNode);
        }
        pendingTreeNodes.pop();
    }

    return root;
}



// Take tree input from user
// DFS approach
TreeNode<int>* takeInput(){
    // Take root data and ask for how many childrens root have
    int data;
    cout << "Enter root data : ";
    cin >> data;
    TreeNode<int>* root{new TreeNode<int>(data)};

    int numChilds;
    cout << "Enter number of childs of : " << root->data << endl;
    cin >> numChilds;

    // Call recursion for taking subtree
    for(int i{}; i<numChilds; i++){
        // Call on evry child and they return root node of that subtree
        TreeNode<int>* tmpRoot{takeInput()};
        root->childrens.push_back(tmpRoot);
    }

    return root;
}


// Print tree level wise(BFS)
void printLevelWise(TreeNode<int>* root){
    // Edge case if tree is empty
    if(root == NULL) return;

    queue<TreeNode<int>*> pendingTreeNodes;
    pendingTreeNodes.push(root);
    while(!pendingTreeNodes.empty()){
        TreeNode<int>* front{pendingTreeNodes.front()};
        cout << front->data << ": ";
        for(int i{}; i<front->childrens.size(); i++){
            pendingTreeNodes.push(front->childrens[i]);
            if(i == front->childrens.size()-1){
                cout << front->childrens[i]->data;
            }else{
                cout << front->childrens[i]->data << ",";
            }
        }
        cout << endl;
        pendingTreeNodes.pop();
    }
}


// Print tree in following order(DFS)
/* root : childrens */
void print(TreeNode<int>* root){
    cout << root->data << " :";
    for(int i{}; i<root->childrens.size(); i++){
        cout << root->childrens[i]->data << ",";
    }cout << endl;

    // Subtrees are printed by recursion
    for(int i{}; i<root->childrens.size(); i++){
        print(root->childrens[i]);
    }
}

// 1 3 2 3 4 2 5 6 2 7 8 2 9 10 0 0 0 0 0 2 11 12 0 0

int main(){
    // TreeNode<int>* root{takeInput()};
    TreeNode<int>* root{takeInputLevelWise()};
    // print(root);
    printLevelWise(root);
}