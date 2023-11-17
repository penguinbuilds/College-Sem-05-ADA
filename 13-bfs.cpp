#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void details() {
    cout << endl;
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

struct TreeNode {
    int data;
    vector<TreeNode*> children;
    TreeNode(int value) : data(value) {}
};

void BFS(TreeNode* root) {
    if (!root)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        cout << current->data << " ";
        q.pop();

        for (TreeNode* child : current->children) {
            if (child)
                q.push(child);
        }
    }
}

TreeNode* buildTree() {
    int n, rootValue;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Please enter a positive number of nodes." << endl;
        return nullptr;
    }

    cout << "Enter the value of the root node: ";
    cin >> rootValue;

    TreeNode* root = new TreeNode(rootValue);
    vector<TreeNode*> nodeQueue;
    nodeQueue.push_back(root);

    for (int i = 1; i < n; i++) {
        int parentValue, childValue;
        cout << "Enter the parent value and child value for node " << i + 1 << ": ";
        cin >> parentValue >> childValue;

        TreeNode* newNode = new TreeNode(childValue);
        for (TreeNode* node : nodeQueue) {
            if (node->data == parentValue) {
                node->children.push_back(newNode);
                nodeQueue.push_back(newNode);
                break;
            }
        }
    }

    return root;
}

int main() {
    details();
    
    TreeNode* root = buildTree();
    if (root) {
        cout << "Breadth-First Search (BFS) of the tree: ";
        BFS(root);
        cout << endl;
    }

    cout << endl;

    return 0;
}
