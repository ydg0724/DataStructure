#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* right, * left;
}TreeNode;


TreeNode* search(TreeNode*, int);
//��ȯ���� Ž�� �Լ�
TreeNode* search(TreeNode* node, int key) {
    if (node == NULL) return NULL;
    if (key == node->key) return node;
    else if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode* new_node(int item) {
    TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
    tmp->key = item;
    tmp->left = tmp->right = NULL;
    return tmp;
}

TreeNode* insert_node(TreeNode* node, int key) {
    //Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
    if (node == NULL) return new_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);

    return node;
    // ����� ��Ʈ �����͸� ��ȯ�Ѵ�.
}

TreeNode* Minimum(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
    if (root == NULL) return root; //������ �����Ͱ� ���� ���
    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else { //key == root->key
        //1���� ���
        if (root->left == NULL && root->right == NULL)
            root = NULL;
        //2���� ���
        if (root->left == NULL) {
            root = root->right;
        }
        if (root->right == NULL) {
            root = root->left;
        }
        //3���� ���
        else {
            TreeNode* tmp = Minimum(root->right);
            root->key = tmp->key;
            root->right = delete_node(root->right, tmp->key);
        }
    }
    return root;
}



void inorder(TreeNode* root) { //LVR
    if (root) {
        inorder(root->left);    //L
        printf("[%d]", root->key);  //V
        inorder(root->right);   //R
    }
}

int main() {
    TreeNode* root = NULL;
    TreeNode* tmp = NULL;


    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
    inorder(root);
    printf("\n\n");
    
    return 0;


}