# 이진 트리 (Binary Tree)

![binary tree](./img/binary%20tree.png)

- 모든 노드가 2개이하의 서브 트리를 가지고 있는 트리를 이진 트리 라고 한다.
- 이진 트리는 다음과 같이 정의 된다.
  1. 공집합이거나
  2. 루트와 왼쪽 서브 트리, 오른쪽 서브 트리로 구성된 노드들의 유한 집합으로 정의된다. 이진 트리의 서브 트리들은 모두 이진트리여야한다.

## 이진 트리의 성질

    - n개의 노드를 가진 이진트리는 n-1의 간선을 가진다.
    - 높이가 h인 이진트리인 경우 최소 h개의 노드를 가지며 최대 개수는 2^h-1 개이다.
    - n개의 노드를 가진 이진트리의 높이는 최대 n이거나 최소 [log_2(n+1)]이 된다.

## 이진 트리의 분류

1. 포화 이진 트리(Full Binary Tree) : 트리의 각 레벨에 노드가 꽉 차있는 이진트리

2. 완전 이진 트리(Complete Binary Tree) : 높이가 k일 때 레벨 1부터 k-1까지는 노드가 모두 채워져 있고 마지막 레벨 k에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있는 이진트리

## 이진 트리 종류

- [스레드 이진 트리](./Thread%20binary%20tree/)
- [이진 탐색 트리](./Binary%20search%20tree/)

## 이진 트리 구현

[binary tree.c](./binary%20tree.c)

- 이진 트리는 배열에 저장할 수 있지만 포화 이진 트리나 완전 이진 트리가 아닌 각 노드들의 차수가 낮은 경우에는 비 효율적이다.
- 따라서 이진 트리는 보통 연결 리스트로 구현한다.

## 이진 트리 순회

- 이진 트리를 순회(traversal)한다는 것은 이진트리에 속하는 모든 노드를 한 번씩 방문하여 노드가 가지고 있는 데이터를 목적에 맞게 처리하는 것을 의미한다.
- 이진트리를 순회하는 표준적인 방법에는 전위(VLR), 중위(LVR), 후위(LRV)의 3가지 방법이 있다.

  - 전위순회(preorder traversal) : VLR

    - 루트 노드 방문
    - 왼쪽 서브트리 방문
    - 오른쪽 서브트리 방문

  - 중위순회(inorder traversal) : LVR

    - 왼쪽 서브트리 방문
    - 루트 노드 방문
    - 오른쪽 서브트리 방문

  - 후위순회(postorder raversal) : LRV

    - 왼쪽 서브트리 방문
    - 오른쪽 서브트리 방문
    - 루트 노드 방문

```c
// 중위 선회
void preorder(node* node){
    if(node!= NULL){
        printf("[%d] ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// 중위 선회
void inorder(node* node){
    if(node!= NULL){
        inorder(node->left);
        printf("[%d] ", node->data);
        inorder(node->right);
    }
}

// 중위 선회
void postorder(node* node){
    if(node!= NULL){
        postorder(node->left);
        postorder(node->right);
        printf("[%d] ", node->data);
    }
}

