#include <iostream>
#include <algorithm>
#include <queue>

class BinTree {
public:
    void BuildTree ();
    bool IsBalanced ();
private:
struct Node {
    Node (int d) {
        data = d;
        right = nullptr;
        left = nullptr;
    }
    int data;
    Node *left;
    Node *right;
};
    bool IsBalanced (Node* node);
    int Hight (Node* nd);
    Node* tree_ = nullptr;
};

int BinTree::Hight (Node* nd) {
    if (nd == nullptr) {
        return 0;
    }
    else {
        return (1 + std::max(Hight(nd->left), Hight(nd->right)));
    }
}

void BinTree::BuildTree () {
    int cur;
    while (std::cin >> cur) {
        Node** cur_node = &tree_;
        while (*cur_node != nullptr) {
            if (cur < (*cur_node)->data) {
                cur_node = &((*cur_node)->left);
            }
            else {
                cur_node = &((*cur_node)->right);
            }
        }
        *cur_node = new Node(cur);
    }
}

bool BinTree::IsBalanced (Node* nd) {
    if (nd == nullptr) {
        return true;
    }
    return (std::abs(Hight(nd->left) - Hight(nd->right)) <= 1 && IsBalanced (nd->left) && IsBalanced (nd->right));
}

bool BinTree::IsBalanced () {
    return IsBalanced(tree_);
}

int main () {
    BinTree tree;
    tree.BuildTree();
    if (tree.IsBalanced()) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}