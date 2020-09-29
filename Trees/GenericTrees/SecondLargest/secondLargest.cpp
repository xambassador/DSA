#include<iostream>
using namespace std;
#include"../Tree.h"

class Pair{
    public:
    TreeNode<int>* L;
    TreeNode<int>* S;
};

Pair help(TreeNode<int>* root){
    Pair ans;
    ans.L = root;
    ans.S = NULL;
    for(int i{}; i<root->childrens.size(); i++){
        Pair recAns{help(root->childrens[i])};

        if(recAns.S == NULL && ans.S == NULL){
            if(recAns.L->data > ans.L->data) {
                ans.S = ans.L;
                ans.L = recAns.L;
            }else{
                ans.S = recAns.L;
            }
        }

        else if(recAns.S == NULL && ans.S != NULL){
            if(recAns.L->data > ans.L->data){
                ans.S = ans.L;
                ans.L = recAns.L;
            }else{
                if(recAns.L->data > ans.S->data){
                    ans.S = recAns.L;
                }
            }
        }

        else if(recAns.S != NULL && ans.S == NULL){
            if(recAns.L->data > ans.L->data){
                if(ans.L->data > recAns.S->data){
                    ans.S = ans.L;
                }else{
                    ans.S = recAns.S;
                }
            }else{
                ans.S = recAns.L;
            }
        }

        else if(recAns.S != NULL && ans.S != NULL){
            if(ans.L->data < recAns.L->data){
                if(ans.L->data < recAns.S->data){
                    ans.S = recAns.S;
                }else{
                    ans.S = ans.L;
                }
                ans.L = recAns.L;
            }else{
                if(ans.S->data > recAns.L->data){
                    ans.S = recAns.L;
                }
            }
        }
    }
    return ans;
}


void help1(TreeNode<int>* root, TreeNode<int>** L, TreeNode<int>** S){
    if(*L == NULL){
        *L = root;
    }

    else if(root->data > (*L)->data) {
        *S = *L;
        *L = root;
    }

    else if(*S == NULL || root->data > (*S)->data){
        *S = root;
    }

    for(int i{}; i<root->childrens.size(); i++){
        help1(root->childrens[i], L, S);
    }
}


TreeNode<int>* secondLargest(TreeNode<int>* root){
    // if(root == NULL) return root;

    // Pair ans{help(root)};
    // if(ans.S == NULL) return NULL;
    // if(ans.L->data == ans.S->data) return NULL;

    // cout << "L and S : " << ans.L->data << " " << ans.S->data << endl;
    // return ans.S;

    // TreeNode<int>* L{NULL};
    // TreeNode<int>* S{NULL};
    // help1(root, &L, &S);
    // if(S == NULL) return NULL;
    // if(L->data == S->data) return NULL;
    // return S;
}

// 10 3 20 30 40 0 0 2 40 50 0 0
// 10 3 20 30 15 2 40 50 2 60 70 1 100 0 0 2 80 90 0 0 0 1 100 0

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    TreeNode<int>* ans{secondLargest(root)};
    if(ans != NULL) cout << ans->data << endl;
}
