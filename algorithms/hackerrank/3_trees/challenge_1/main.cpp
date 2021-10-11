//
// Created by Michael Soliman on 05/05/2021.
//

#include <cmath>
#include "iostream"
#include "vector"

void buildBinaryTree(std::vector<int> &binaryTree, std::vector<int> inOrder,int length , int index,int level, int i) {
    /// if tree contains only one element, exit the function
    if(length == 1) return;

    /// loop over all the nodes in the current level,
    /// No of nodes is 2^currentLevel
    for (int j = 0; j < static_cast<int>(pow(2, level)); ++j) {
        /// the current index is half the tree at that level,
        /// at level 1 => index = 7 => current index = 3, which is the index of the first node in that level

        int currentIndex = (index / 2) + (index + 1) * j;
        binaryTree[i] = inOrder[currentIndex];
        i++;

        /// if binary tree size equals to the inOrder size, exit the function
        if (i == length) return;
    }

    /// call recursively with half the index, and with the next level of the tree
    buildBinaryTree(binaryTree, inOrder, length, index / 2, level + 1, i);
}

int main() {
    /// number of nodes
    int N;
    std::cin>> N;

    /// the inorder traversal of the tree
    std::vector<int> inOrder (N);
    for (int i = 0; i < N; i++) {
        std::cin>>inOrder[i];
    }

    /// the perfect binary tree
    std::vector<int> binaryTree (N);

    /// initialize the binary tree with root (the root is the middle node in the inorder trv tree
    binaryTree[0] = inOrder[N/2];

    /// first 3 args are the trees and its length,
    /// the index is half of the tree, level is the current level of the tree,
    /// and i the current index to add element at in binaryTree
    buildBinaryTree(binaryTree, inOrder, N, N/2, 1,  1);

    for (int i = 0; i < N; i++) {
        std::cout<<binaryTree[i]<< " ";
    }

    return 0;
}

