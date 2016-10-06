#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char d;
    Node* left;
    Node* right;
};

Node* getNewNode(char d) {
    Node* node = new Node;

    node->d = d;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, char d) {
    Node* node = getNewNode(d);

    if(root == NULL) {
        root = node;
        return root;
    }

    if(root->d >= d) root->left = insert(root->left, d);
    else root->right = insert(root->right, d);

    return root;
}

void levelOrder(Node* root) {

    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front(); 
        q.pop();

        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);

        cout << temp->d << "-->";
    }

    cout << endl;
}

int main() {
    Node* root;
    root = NULL;

    root = insert(root, 'E');
    root = insert(root, 'C');
    root = insert(root, 'B');
    root = insert(root, 'A');
    root = insert(root, 'D');

    root = insert(root, 'H');
    root = insert(root, 'F');
    root = insert(root, 'K');
    root = insert(root, 'G');
    root = insert(root, 'I');
    root = insert(root, 'J');

    levelOrder(root);

    return 0;
}
