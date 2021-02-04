#include<gtest/gtest.h>
#include "../maxSum.cpp"

int testArr1[] {324, 3, 23, -234, 32, -4, 324, 435, -5775};
// int testArr1[] {-1,2,3};
int testArr2[] {3, 5, 2, 6 ,3, 6};
Node* tree {new Node[4*9]}; 

TEST(queryTest, maxSum) {
    if (tree == NULL) {
        std::cout << "Heap memory is full " << std::endl;
        return;
    }
    buildTree(testArr1,tree,0,sizeof(testArr1)/sizeof(int),1);
    ASSERT_EQ(350, query(tree,0,sizeof(testArr1)/sizeof(int),1,1-1,4-1).maxSum);
    ASSERT_EQ(32, query(tree,0,sizeof(testArr1)/sizeof(int),1,3-1,5-1).maxSum);
    ASSERT_EQ(787, query(tree,0,sizeof(testArr1)/sizeof(int),1,5-1,9-1).maxSum);
    delete tree;
    tree = new Node[4*sizeof(testArr2)/sizeof(int)];
    buildTree(testArr2,tree,0,sizeof(testArr2)/sizeof(int),1);
    ASSERT_EQ(13, query(tree,0,sizeof(testArr2)/sizeof(int),1,2-1,4-1).maxSum);
    ASSERT_EQ(2, query(tree,0,sizeof(testArr2)/sizeof(int),1,3-1,3-1).maxSum);
    ASSERT_EQ(25, query(tree,0,sizeof(testArr2)/sizeof(int),1,1-1,6-1).maxSum);
    delete tree;
    tree = 0;
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}