// B6

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    Node *insertToBst(Node *root, int d)
    {

        if (root == NULL)
        {
            root = new Node(d);
            return root;
        }

        if (d > root->data)
        {
            root->right = insertToBst(root->right, d);
            return root;
        }
        else
        {
            root->left = insertToBst(root->left, d);
            return root;
        }
    }
    void create(Node *&root)
    {
        int data;
        cout << "Enter Element to insert in BST (if not enter -1) :" << endl;
        cin >> data;
        while (data != -1)
        {
            root = insertToBst(root, data);
            cin >> data;
        }
    }
    void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    Node *search(Node *root, int key)
    {

        if (root == NULL)
            return NULL;
        if (root->data == key)
            return root;

        if (root->data < key)
            return search(root->right, key);

        else
        {
            return search(root->left, key);
        }
    }
    void minValue(Node *root)
    {
        Node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        cout << "min :" << temp->data;
    }
    void maxValue(Node *root)
    {
        Node *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        cout << "max :" << temp->data;
    }
    Node *mirror(Node *root)
    {
        if (root == NULL)
            return root;
        else
        {
            Node *temp;

            /* do the subtrees */
            mirror(root->left);
            mirror(root->right);

            /* swap the pointers in this node */
            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }
    int maxDepth(Node *root)
    {
        if (root == NULL)
            return 0;
        else
        {

            int lDepth = 1 + maxDepth(root->left);
            int rDepth = 1 + maxDepth(root->right);

            if (lDepth > rDepth)
                return (lDepth);
            else
                return (rDepth);
        }
    }
};

int main()
{
    BST b;
    int key;
    Node *root = NULL;
    Node *p;
    int ch;
    cout << "**********MENU**********" << endl;
    cout << "\n1.Create\n2.Inorder\n3.Search\n4.Min\n5.Max\n6.Mirror image\n7.Height of BST\n8.Exit\n";
    while (1)
    {
        cout << "\nEnter a choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.create(root);
            break;
        case 2:
            b.inOrder(root);
            break;
        case 3:
            cout << "\nEnter key to be searched : ";
            cin >> key;
            p = b.search(root, key);
            if (p == NULL)
                cout << "\nElement not found";
            else
                cout << "\nElement found :" << p->data;
            break;
        case 4:
            b.minValue(root);
            break;
        case 5:
            b.maxValue(root);
            break;
        case 6:
            b.mirror(root);
            break;
        case 7:
            cout << "Height of tree :" << b.maxDepth(root);
            break;

        case 8:
            exit(1);
        }
    }
    return 0;
}
