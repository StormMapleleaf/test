#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define _CRT_ONEXIT_T_DEFINED
// 二叉树结构体
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建二叉树
TreeNode* createTree() {
    char c;
    std::cin >> c;
    if (c == '#') {
        return NULL;
    }
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    if(root!=NULL)
    root->data = c;
    root->left = createTree();
    root->right = createTree();
    return root;
}

// 销毁二叉树
void destroyTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

// 查找结点
TreeNode* findNode(TreeNode* root, char data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }
    TreeNode* left = findNode(root->left, data);
    if (left != NULL) {
        return left;
    }
    TreeNode* right = findNode(root->right, data);
    if (right != NULL) {
        return right;
    }
    return NULL;
}

// 求二叉树高度
int getHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 输出二叉树
void printTree(TreeNode* root) {
    if (root == NULL) {
        printf(" ");
        return;
    }
    printf("%c", root->data);
    if (root->left != NULL || root->right != NULL) {
        printf("(");
        printTree(root->left);
        printf(",");
        printTree(root->right);
        printf(")");
    }
}

// 先序遍历
void preOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void inOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

// 后序遍历
void postOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

// 层次遍历
void levelOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        TreeNode* node = queue[front++];
        printf("%c ", node->data);
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}



int main() {
    // 创建二叉树
    printf("请输入二叉树的先序遍历序列：");
    TreeNode* root = createTree();

    // 输出二叉树
    printf("该二叉树的括号表示为：");
    printTree(root);
    printf("\n");

    // 查找结点
    printf("请输入要查找的结点：");
    char data;
    std::cin >> data;
    TreeNode* node = findNode(root, data);
    if (node != NULL) {
        printf("找到了结点%c\n", data);
    }
    else {
        printf("没有找到结点%c\n", data);
    }

    // 求二叉树高度
    int height = getHeight(root);
    printf("该二叉树的高度为：%d\n", height);

    // 先序遍历
    printf("该二叉树的先序遍历序列为：");
    preOrder(root);
    printf("\n");

    // 中序遍历
    printf("该二叉树的中序遍历序列为：");
    inOrder(root);
    printf("\n");

    // 后序遍历
    printf("该二叉树的后序遍历序列为：");
    postOrder(root);
    printf("\n");

    // 层次遍历
    printf("该二叉树的层次遍历序列为：");
    levelOrder(root);
    printf("\n");

    // 销毁二叉树
    destroyTree(root);

    return 0;
}