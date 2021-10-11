//
// Created by Michael Soliman on 09/05/2021.
//

#include "iostream"
#include "vector"

struct Node {
    int color;
    bool isParent;
    std::vector<Node*> children;
};

/// a helper function to allocate a new node
Node* createNode(int color) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->color = color;

    return node;
}

void getPossibleFriends(Node* root, int &currentFriends, int count, int maxNoOfDarkStreets) {
    if (root == nullptr) return;

    /// if the current street(node) is dark, increment count of dark streets
    if (root->color == 1) count++;

    /// if current node does not have any children , means it's a leaf
    /// then check for friend (node) validity (if it passed the maxDarkStreets(nodes))
    if (root->children.empty()) {
        if (count <= maxNoOfDarkStreets)
            currentFriends++;
        return;
    }

    if(root->color == 0) count = 0;
    for (auto & child : root->children) {
        getPossibleFriends(child, currentFriends, count, maxNoOfDarkStreets);
    }


}
/// implementation not complete
/// TODO -- complete
int main() {
    /// N and M the number of nodes of the tree and the maximum number of consecutive dark nodes
    int N, M;
    std::cin >> N >> M;

    std::vector<Node *> nodes(N);

    /// initialize array of nodes
    int color;
    for (int i = 0; i < N; i++) {
        std::cin >> color;
        nodes[i] = createNode(color);
    }

    nodes[0]->isParent = true;

    std::vector<std::pair<int, int>> edges(N - 1);


    std::pair<int, int> tempEdge;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> tempEdge.first >> tempEdge.second;
        edges[i] = tempEdge;
    }

    for (int i = 1; i < N - 1; i++) {
        /// check if any node index is redundant, if yes, then it's definitely a parent
        std::pair<int, int> firstEdge;
        std::pair<int, int> secondEdge;

        for (int j = 1; j < N -1; j++) {
            if (i != j) {
                if (edges[i].first == edges[j].first || edges[i].first == edges[j].second) {
                    /// it's parent
                    nodes[edges[i].first - 1]->isParent = true;
//                    firstEdge = edges[i];
//                    secondEdge = edges[j];
                }
                if (edges[i].second == edges[j].first || edges[i].second == edges[j].second) {
                    nodes[edges[i].second - 1]->isParent = true;
                }
            }
        }

    }

    for (int i = 0; i < N-1; i++) {
        int firstIndex = edges[i].first;
        int secondIndex = edges[i].second;
        Node* firstNode = nodes[firstIndex];
        Node* secondNode = nodes[secondIndex];
        if (firstIndex == 1) {
            firstNode->children.push_back(nodes[secondIndex]);
            break;
        }
        if (secondIndex == 1) {
            secondNode->children.push_back(nodes[firstIndex]);
            break;
        }
        if (firstNode->isParent) {
            firstNode->children.push_back(nodes[secondIndex]);
        } else {
            secondNode->children.push_back(nodes[firstIndex]);
        }
    }



    int possibleFriends = 0;

    getPossibleFriends(nodes[0], possibleFriends, 0, M);

    std::cout<<possibleFriends;



    return 0;
}





