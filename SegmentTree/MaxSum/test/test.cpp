#include "maxSum.cpp"
#include<gtest/gtest.h>

int ans;

TEST(queryTest, maxSum) {
    ASSERT_EQ(2, ans);
}


void run() {
    int n;
    std::cin >> n;

    int* arr {new int[n]};
    Node* tree {new Node[4*n]};
    for(int i{}; i<n; i++) std::cin >> arr[i];

    int q;
    std::cin >> q;
    while(q--) {
        int xi, yi;
        std::cin >> xi >> yi;
        ans = query(tree, 0, n-1, 1, xi-1, yi-1).maxSum;
    }
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    run();
    return RUN_ALL_TESTS();
}