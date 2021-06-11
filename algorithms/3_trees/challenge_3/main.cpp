//
// Created by Michael Soliman on 07/05/2021.
//

#include "iostream"
#include "vector"


struct Node {
    int data;
    Node *left, *right, *parent;
};

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;

    return node;
}

int getTreeSize(Node *root){
    /// get the tree size from the current node
    /// for opt. get it in treeSum
    if(root == nullptr){
        return 0;
    }
    else{
        return 1 + getTreeSize(root->left) + getTreeSize(root->right);
    }
}

// TODO need handling corner case where subtrees are not next to each other
int treeSum(Node *root, int &count, int maxSize) {
    if (root == nullptr)
        return 0;

    /// using postOrder traversal to start from bottom first then going up
    int leftSum = treeSum(root->left, count, maxSize);
    int rightSum = treeSum(root->right, count, maxSize);

    /// if the sum of the left subtree is equal to right subtree and equal to zero,
    /// and if both has the same size => increment the counter
    if(leftSum == rightSum && leftSum != 0) {
        ///check if same size (-needs refactoring) and if greater than  M
        int leftTreeSize = getTreeSize(root->left);
        int rightTreeSize = getTreeSize(root->right);

        if(leftTreeSize == rightTreeSize && leftTreeSize > maxSize){
             count++;
        }
    }
    return leftSum + rightSum + root->data;
}


int isSameSumAndSize(Node *root, int maxSize) {
    int count = 0;

    treeSum(root,count ,maxSize);

    if (count > 0)
        return 1;
    return 0;
}

int main() {
    /// the number of nodes in the tree N, the size M and edges in the tree E.
    int N, M, E;

    std::cin>>N>>M;

    std::vector<Node*> nodes (N);
    for (int i = 0; i < N; i++) {
        int data;
        std::cin>>data;
        nodes[i] = createNode(data);
    }

    std::cin>>E;

    for (int i = 0; i < E; i++) {
        char child;
        int parentIndex, childIndex;
        std::cin>>child>>parentIndex>>childIndex;

        /// fill nodes vector with data from input
         if(child == 'L') nodes[parentIndex]->left = nodes[childIndex];
         else nodes[parentIndex]->right = nodes[childIndex];
    }

    int result = isSameSumAndSize(nodes[0], M);

    std::cout<<result;
    return 0;
}
