//
// Created by Michael Soliman on 09/05/2021.
//


#include "iostream"
#include "vector"
#include "unordered_map"

enum QueryType {
    SUB_TREE_SIZE = 1,
    SUB_TREES_COUNT = 2,
};

struct Node {
    [[maybe_unused]] int index;
    Node *left, *right;
};

/// a helper function to allocate a new node
Node* createNode(int index) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;

    return node;
}

/// get the tree size from the current node
/// tree sizes are cached results from previous recursions
/// to speed up calculating tree size
int getTreeSize(Node *root,  std::unordered_map<int, int> &treeSizes){
    if(root == nullptr){
        return 0;
    }
    /// if key is found
    /// return the stored size
    if(treeSizes.find(root->index) !=  treeSizes.end()){
        return treeSizes[root->index];
    }
    /// else key is not found
    /// store the value
    int size =  1 + getTreeSize(root->left, treeSizes) + getTreeSize(root->right, treeSizes);
    treeSizes[root->index] = size;
    return size;

}

/// get subtrees count based on the given size
void getSubTreesCount(Node* root,int size , int &count, std::unordered_map<int, int>& treeSizes) {
    if (root == nullptr) return;

    int leftSize = getTreeSize(root->left, treeSizes);
    int rightSize = getTreeSize(root->right, treeSizes);

    if (leftSize == size) {
        count++;
    }
    /// only go to the next left node when the size of its subtree is greater than the given size
    if (leftSize > size){
        getSubTreesCount(root->left, size, count, treeSizes);
    }

    if (rightSize == size)  {
        count++;
    }
    /// only go to the next right  node when the size of its subtree is greater than the given size
    if (rightSize > size){
        getSubTreesCount(root->right, size, count, treeSizes);
    }
}

/// \IMPLEMENTATION DONE
/// \TESTCASES PASSED 10 out of 11
int main() {
    /// the number of nodes in the tree N.
    /// and number of queries Q
    int N, Q;
    std::cin>>N;

    std::vector<Node*> nodes(N);

    /// initialize array of nodes
    for (int i = 0; i < N; i++) {
        nodes[i] = createNode(i+1);
    }

    for (int i = 0; i < N; i++) {
        int leftIndex, rightIndex;
        std::cin >> leftIndex >> rightIndex;

        if (leftIndex == -1) {
            nodes[i]->left = nullptr;
        } else {
            nodes[i]->left = nodes[leftIndex-1];
        }
        if (rightIndex == -1) {
            nodes[i]->right = nullptr;
        } else {
            nodes[i]->right = nodes[rightIndex-1];
        }
    }

    std::cin>>Q;

    /// a vector to hold query data
    std::vector<std::pair<int, int>> queries(Q);

    /// temp pair to store user data
    std::pair<int, int> queryData;
    for (int i = 0; i < Q; i++) {
        std::cin >> queryData.first;
        std::cin >> queryData.second;

        queries[i] = queryData;
    }

    /// a map that holds tree size for each node
    /// key corresponds to the node index, value is the tree size for that node
    std::unordered_map<int, int> treeSizes;

    for (int i = 0; i < Q; i++) {
        /// loop over all the queries and execute them
        switch (queries[i].first) {
            /// if type one, print the tree size
            case QueryType::SUB_TREE_SIZE : {
                /// [queries[i].second] is the node number
                Node* requestedNode = nodes[queries[i].second - 1];
                std::cout<<getTreeSize(requestedNode, treeSizes)<<std::endl;
                break;
            }
            /// if type two, print the count of subtrees that has the same given size
            case QueryType::SUB_TREES_COUNT : {
                /// [queries[i].second] is the requested size
                int requestedSize = queries[i].second;
                int count = 0;
                if (getTreeSize(nodes[0], treeSizes) == requestedSize) count++;
                getSubTreesCount(nodes[0], requestedSize, count, treeSizes);
                std::cout<<count<<std::endl;
                break;
            }
        }
    }

    return 0;
}



