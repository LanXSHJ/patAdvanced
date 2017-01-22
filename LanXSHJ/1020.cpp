#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node* tree;
typedef struct node {
    int key;
    tree left;
    tree right;
};
tree buildTree(int * postorder, int *inorder, int size) {
    tree T;
    int i = 0;
    if (!size) {
        return(NULL);
    }

    T = (tree)malloc(sizeof(struct node));
    T->key = postorder[size - 1];
    for (i = 0; i < size; i++) {
        if (postorder[size - 1] == inorder[i])
            break;
    }
    T->left = buildTree(postorder, inorder, i);
    T->right = buildTree(postorder + i, inorder + i + 1, size - i - 1);
    return T;
}
int main() {
    int N;
    cin >> N;
    int postorder[32];
    int inorder[32];
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    tree root = buildTree(postorder, inorder, N);
    queue<tree> nodeQueue;
    nodeQueue.push(root);
    bool flag = false;
    while (!nodeQueue.empty()) {
        tree t = nodeQueue.front();
        int k = (t->key);
        if (flag) {
            cout << ' ';
        }
        flag = true;
        cout << k;
        nodeQueue.pop();
        if (t->left != NULL) {
            nodeQueue.push(t->left);
        }
        if (t->right != NULL) {
            nodeQueue.push(t->right);
        }
    }
    return 0;
}