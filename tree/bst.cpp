#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* getNewNode(int data) {
    Node* node = new Node;

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, int data) {
    Node* node = getNewNode(data);

    if(root == NULL) {
        root = node;
    } else if(root->data >= data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

bool search(Node* root, int data) {
    if(root == NULL) {
        return false;
    }

    if(root->data == data) {
        return true;
    } else if(data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void print(Node* root) {
    if(root == NULL) {
        return;
    }

        print(root->left);
    cout << root->data << " ";
        print(root->right);
    return;
}

int findMin(Node* root) {
    if(root == NULL) {
        return -1;
    }

    while(root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

int findMaxRecursion(Node* root) {
    if(root == NULL) {
        cout << "Error: Tree is empty\n";
        return -1;
    }

    if(root->right == NULL) {
        return root->data;
    }

    return findMaxRecursion(root->right);
}

int findHeight(Node* root) {
    if(root == NULL) return -1;

    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

//<root><left><right>
void preorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << "-->";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//<left><right><root>
void postOrderTraversal(Node* root) {
    if(root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << "-->";
}

//<left><root><right>
void inOrderTraversal(Node* root) {
    if(root == NULL) return;

    inOrderTraversal(root->left);
    cout << root->data << "-->";
    inOrderTraversal(root->right);
}

int main() {
    Node* root;
    root = NULL;

    root = insert(root, 5);    
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);

    root = insert(root, 4);
    print(root);

    cout << endl;

    cout << "Min: " << search(root, 16) << endl;

    cout << "Max: " << findMaxRecursion(root) << endl;

    cout << "Height: " << findHeight(root) << endl;

    cout << "PreOrder Traversal\n";

    preorderTraversal(root);   cout << endl;

    cout << "Postorder Traversal\n";

    postOrderTraversal(root);   cout << endl;

    cout << "InOrder Traversal\n";

    inOrderTraversal(root);    cout << endl;

    return 0;
}
