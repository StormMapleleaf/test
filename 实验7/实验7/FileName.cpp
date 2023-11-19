#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define _CRT_ONEXIT_T_DEFINED
// �������ṹ��
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ����������
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

// ���ٶ�����
void destroyTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

// ���ҽ��
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

// ��������߶�
int getHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// ���������
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

// �������
void preOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// �������
void inOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

// �������
void postOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

// ��α���
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
    // ����������
    printf("�����������������������У�");
    TreeNode* root = createTree();

    // ���������
    printf("�ö����������ű�ʾΪ��");
    printTree(root);
    printf("\n");

    // ���ҽ��
    printf("������Ҫ���ҵĽ�㣺");
    char data;
    std::cin >> data;
    TreeNode* node = findNode(root, data);
    if (node != NULL) {
        printf("�ҵ��˽��%c\n", data);
    }
    else {
        printf("û���ҵ����%c\n", data);
    }

    // ��������߶�
    int height = getHeight(root);
    printf("�ö������ĸ߶�Ϊ��%d\n", height);

    // �������
    printf("�ö������������������Ϊ��");
    preOrder(root);
    printf("\n");

    // �������
    printf("�ö������������������Ϊ��");
    inOrder(root);
    printf("\n");

    // �������
    printf("�ö������ĺ����������Ϊ��");
    postOrder(root);
    printf("\n");

    // ��α���
    printf("�ö������Ĳ�α�������Ϊ��");
    levelOrder(root);
    printf("\n");

    // ���ٶ�����
    destroyTree(root);

    return 0;
}