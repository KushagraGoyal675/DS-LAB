#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

int isBSTUtil(struct Node* node, int min, int max) {
    if (node == NULL)
        return 1;

    if (node->data < min || node->data > max)
        return 0;

    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int isValidBST(struct Node* root, struct Node* min, struct Node* max) {
    if (root == NULL)
        return 1;

    if (min != NULL && root->data <= min->data)
        return 0;

    if (max != NULL && root->data >= max->data)
        return 0;

    return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

int isBalancedUtil(struct Node* node, int* height) {
    if (node == NULL) {
        *height = 0;
        return 1;
    }

    int lh = 0, rh = 0;
    int l = isBalancedUtil(node->left, &lh);
    int r = isBalancedUtil(node->right, &rh);

    *height = 1 + max(lh, rh);

    return l && r && abs(lh - rh) <= 1;
}

int isBalanced(struct Node* root) {
    int height = 0;
    return isBalancedUtil(root, &height);
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    return root;
}

struct Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct Node* node = newNode(arr[mid]);
    node->left = sortedArrayToBST(arr, start, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, end);
    return node;
}

struct ListNode {
    int data;
    struct ListNode* next;
};

struct Node* sortedListToBSTUtil(struct ListNode** head_ref, int n) {
    if (n <= 0)
        return NULL;

    struct Node* left = sortedListToBSTUtil(head_ref, n / 2);

    struct Node* root = newNode((*head_ref)->data);
    root->left = left;

    *head_ref = (*head_ref)->next;

    root->right = sortedListToBSTUtil(head_ref, n - n / 2 - 1);

    return root;
}

struct Node* sortedListToBST(struct ListNode* head) {
    int n = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }
    return sortedListToBSTUtil(&head, n);
}

int kthSmallest(struct Node* root, int k) {
    if (root == NULL)
        return -1;

    int count = countNodes(root->left);

    if (count + 1 == k)
        return root->data;

    if (count + 1 > k)
        return kthSmallest(root->left, k);

    return kthSmallest(root->right, k - count - 1);
}

int kthLargest(struct Node* root, int k) {
    int n = countNodes(root);
    return kthSmallest(root, n - k + 1);
}

void printKDistance(struct Node* root, int k) {
    if (root == NULL)
        return;

    if (k == 0) {
        printf("%d ", root->data);
        return;
    }

    printKDistance(root->left, k - 1);
    printKDistance(root->right, k - 1);
}

struct Node* flatten(struct Node* root) {
    if (root == NULL)
        return NULL;

    root->left = flatten(root->left);
    root->right = flatten(root->right);

    if (root->left != NULL) {
        struct Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        struct Node* t = root->right;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
    }

    return root;
}

void mirror(struct Node* node) {
    if (node == NULL)
        return;

    mirror(node->left);
    mirror(node->right);

    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

struct Node* mergeTrees(struct Node* root1, struct Node* root2) {
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;

    root1->data += root2->data;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}

struct Node* inorderSuccessor(struct Node* root, struct Node* x) {
    if (x->right != NULL) {
        return minValueNode(x->right);
    }

    struct Node* successor = NULL;
    while (root != NULL) {
        if (root->data > x->data) {
            successor = root;
            root = root->left;
        } else if (root->data < x->data) {
            root = root->right;
        } else
            break;
    }

    return successor;
}

struct Node* inorderPredecessor(struct Node* root, struct Node* x) {
    if (x->left != NULL) {
        return maxValueNode(x->left);
    }

    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (root->data < x->data) {
            predecessor = root;
            root = root->right;
        } else if (root->data > x->data) {
            root = root->left;
        } else
            break;
    }

    return predecessor;
}

int main() {
    struct Node* root = NULL;
    int choice, value, k;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Check if the tree is a BST\n");
        printf("3. Validate BST\n");
        printf("4. Find height of the BST\n");
        printf("5. Check if the BST is balanced\n");
        printf("6. Find LCA of two nodes\n");
        printf("7. Convert sorted array to BST\n");
        printf("8. Find kth smallest element\n");
        printf("9. Find kth largest element\n");
        printf("10. Print nodes at k distance\n");
        printf("11. Flatten BST to sorted linked list\n");
        printf("12. Mirror of BST\n");
        printf("13. Merge Two BSTs\n");
        printf("14. Find Successor\n");
        printf("15. Find Predecessor\n");
        printf("16. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);

                printf("Node inserted.\n");
                break;
            case 2:
                printf("Is the tree a BST? %s\n", isBST(root) ? "Yes" : "No");
                break;
            case 3:
                printf("Is the tree a valid BST? %s\n", isValidBST(root, NULL, NULL) ? "Yes" : "No");
                break;
            case 4:
                printf("Height of the BST: %d\n", height(root));
                break;
            case 5:
                printf("Is the BST balanced? %s\n", isBalanced(root) ? "Yes" : "No");
                break;
            case 6:
                int n1, n2;
                printf("Enter two values for LCA: ");
                scanf("%d %d", &n1, &n2);
                struct Node* lca = LCA(root, n1, n2);
                printf("LCA of %d and %d: %d\n", n1, n2, lca ? lca->data : -1);
                break;
            case 7:
                printf("Enter the number of elements in the sorted array: ");
                int n;
                scanf("%d", &n);
                int* arr = (int*)malloc(n * sizeof(int));
                printf("Enter the elements of the sorted array: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                root = sortedArrayToBST(arr, 0, n - 1);
                printf("BST created from sorted array.\n");
                free(arr);
                break;
            case 8:
                printf("Enter k for kth smallest: ");
                scanf("%d", &k);
                printf("The %dth smallest element: %d\n", k, kthSmallest(root, k));
                break;
            case 9:
                printf("Enter k for kth largest: ");
                scanf("%d", &k);
                printf("The %dth largest element: %d\n", k, kthLargest(root, k));
                break;
            case 10:
                printf("Enter distance k: ");
                scanf("%d", &k);
                printf("Nodes at distance %d from root: ", k);
                printKDistance(root, k);
                printf("\n");
                break;
            case 11:
                root = flatten(root);
                printf("BST flattened to sorted linked list.\n");
                break;
            case 12:
                mirror(root);
                printf("BST mirrored.\n");
                break;
            case 13:
                struct Node* root2 = NULL;
                printf("Enter values for the second BST (enter -1 to stop): ");
                while (1) {
                    int val;
                    scanf("%d", &val);
                    if (val == -1)
                        break;
                    root2 = insert(root2, val);
                }
                root = mergeTrees(root, root2);
                printf("BSTs merged.\n");
                break;
            case 14:
                printf("Enter value to find successor: ");
                scanf("%d", &value);
                struct Node* successor = inorderSuccessor(root, newNode(value));
                printf("Successor of %d: %d\n", value, successor ? successor->data : -1);
                break;
            case 15:
                printf("Enter value to find predecessor: ");
                scanf("%d", &value);
                struct Node* predecessor = inorderPredecessor(root, newNode(value));
                printf("Predecessor of %d: %d\n", value, predecessor ? predecessor->data : -1);
                break;
            default:
                return 0;
        }
    }

    return 0;
}