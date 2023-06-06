#include <iostream>
#include<string>
using namespace std;

class Node {
public:
    string key;
    string meaning;
    Node* left;
    Node* right;

    Node(string k, string m) {
        key = k;
        meaning = m;
        left = NULL;
        right = NULL;
    }
};

class Dictionary {
private:
    Node* root;

public:
    Dictionary() {
        root = NULL;
    }

    void insert(string key, string meaning) {
        root = insertNode(root, key, meaning);
        cout << "Keyword inserted successfully!" << endl;
    }

    void remove(string key) {
        root = removeNode(root, key);
        cout << "Keyword removed successfully!" << endl;
    }

    void update(string key, string newMeaning) {
        Node* node = search(root, key);
        if (node == NULL) {
            cout << "Keyword not found in the dictionary!" << endl;
            return;
        }
        node->meaning = newMeaning;
        cout << "Meaning updated successfully!" << endl;
    }

    void displayAscending() {
        cout << "Dictionary contents (ascending order):" << endl;
        if (root == NULL) {
            cout << "Dictionary is empty." << endl;
        } else {
            displayAscending(root);
        }
    }

    void displayDescending() {
        cout << "Dictionary contents (descending order):" << endl;
        if (root == NULL) {
            cout << "Dictionary is empty." << endl;
        } else {
            displayDescending(root);
        }
    }

    int getMaxComparisons(string key) {
        int comparisons = 0;
        Node* node = search(root, key);
        if (node != NULL) {
            comparisons = getMaxComparisons(root, key);
        }
        return comparisons;
    }

private:
    Node* insertNode(Node* root, string key, string meaning) {
        if (root == NULL) {
            return new Node(key, meaning);
        }
        if (key < root->key) {
            root->left = insertNode(root->left, key, meaning);
        } else if (key > root->key) {
            root->right = insertNode(root->right, key, meaning);
        }
        return root;
    }

    Node* removeNode(Node* root, string key) {
        if (root == NULL) {
            return root;
        }
        if (key < root->key) {
            root->left = removeNode(root->left, key);
        } else if (key > root->key) {
            root->right = removeNode(root->right, key);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = getMinNode(root->right);
            root->key = temp->key;
            root->meaning = temp->meaning;
            root->right = removeNode(root->right, temp->key);
        }
        return root;
    }

    Node* getMinNode(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* search(Node* root, string key) {
        if (root == NULL || root->key == key) {
            return root;
        }
        if (key < root->key) {
            return search(root->left, key);
        }
        return search(root->right, key);
    }

    void displayAscending(Node* root) {
        if (root != NULL) {
            displayAscending(root->left);
            cout << root->key << " : " << root->meaning << endl;
            displayAscending(root->right);
        }
    }

    void displayDescending(Node* root) {
        if (root != NULL) {
            displayDescending(root->right);
            cout << root->key << " : " << root->meaning << endl;
            displayDescending(root->left);
        }
    }

    int getMaxComparisons(Node* root, string key) {
        int comparisons = 1;
        while (root->key != key) {
            if (key < root->key) {
                root = root->left;
            } else {
                root = root->right;
            }
            comparisons++;
        }
        return comparisons;
    }
};

int main() {
    Dictionary dictionary;
    int choice;
    string key, meaning, newMeaning;

    while (true) {
        cout << "_____________________________" << endl;
        cout << "           MENU" << endl;
        cout << "1. Add a keyword" << endl;
        cout << "2. Remove a keyword" << endl;
        cout << "3. Update the meaning of a keyword" << endl;
        cout << "4. Display the dictionary in ascending order" << endl;
        cout << "5. Display the dictionary in descending order" << endl;
        cout << "6. Get the maximum comparisons for a keyword" << endl;
        cout << "7. Exit" << endl;
        cout << "_____________________________" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the keyword to add: ";
                cin >> key;
                cout << "Enter the meaning of the keyword: ";
                cin.ignore();
                getline(cin, meaning);
                dictionary.insert(key, meaning);
                break;
            case 2:
                cout << "Enter the keyword to remove: ";
                cin >> key;
                dictionary.remove(key);
                break;
            case 3:
                cout << "Enter the keyword to update: ";
                cin >> key;
                cout << "Enter the new meaning of the keyword: ";
                cin.ignore();
                getline(cin, newMeaning);
                dictionary.update(key, newMeaning);
                break;
            case 4:
                dictionary.displayAscending();
                break;
            case 5:
                dictionary.displayDescending();
                break;
            case 6:
                cout << "Enter the keyword to get maximum comparisons: ";
                cin >> key;
                cout << "Maximum comparisons required: " << dictionary.getMaxComparisons(key) << endl;
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}