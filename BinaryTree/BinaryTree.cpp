#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

bool isMirror(Node* left, Node* right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }

    if (left == nullptr || right == nullptr) {
        return false;
    }

    return (left->data == right->data) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

int main() {
    // Створення дерева p

    Node* p = createNode(4);
    p->left = createNode(2);
    p->right = createNode(2);
    p->left->left = createNode(1);
    p->left->right = createNode(3);
    p->right->left = createNode(3);
    p->right->right = createNode(1);

    // Перевірка чи дерево дзеркальне

    if (isMirror(p->left, p->right)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}
