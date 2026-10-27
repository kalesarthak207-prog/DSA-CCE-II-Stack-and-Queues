/*
 * Project  : Contact Book using Binary Search Tree
 * Course   : Data Structures and Algorithms [R25-EC-PCC-202]
 * Activity : CCE III - Unit V (Trees and Graphs)
 *
 * Data structure : Binary Search Tree (implemented manually)
 * Operations     : Insertion, Deletion, Searching,
 *                  Inorder / Preorder / Postorder traversal, Height, Count
 * Sorting        : Inorder traversal of the BST gives contacts sorted by name
 * OOP concepts   : Classes, constructors, destructor, operator overloading
 * NOTE           : No STL containers (vector, list, stack, queue, map, set) used.
 */
#include <iostream>
#include <cstring>
using namespace std;

/* ---------- Contact class: stores name and phone number ---------- */
class Contact {
public:
    char name[30];
    char phone[15];

    Contact() {                                   // default constructor
        strcpy(name, "");
        strcpy(phone, "");
    }
    Contact(const char* n, const char* p) {       // parameterized constructor
        strcpy(name, n);
        strcpy(phone, p);
    }
    // Operator overloading: contacts are compared by name
    bool operator<(const Contact& other) const  { return strcmp(name, other.name) < 0; }
    bool operator==(const Contact& other) const { return strcmp(name, other.name) == 0; }

    void display() const {
        cout << name << "  -  " << phone << endl;
    }
};

/* ---------- Node of the tree ---------- */
class Node {
public:
    Contact data;
    Node* left;
    Node* right;
    Node(Contact c) {
        data = c;
        left = NULL;
        right = NULL;
    }
};

/* ---------- Binary Search Tree ---------- */
class ContactTree {
    Node* root;

    // Insertion: smaller names go left, larger names go right
    Node* insert(Node* node, Contact c, bool& added) {
        if (node == NULL) {
            added = true;
            return new Node(c);
        }
        if (c == node->data) added = false;                       // duplicate name
        else if (c < node->data) node->left = insert(node->left, c, added);
        else node->right = insert(node->right, c, added);
        return node;
    }

    // Smallest node of a subtree (leftmost node)
    Node* findMin(Node* node) {
        while (node->left != NULL) node = node->left;
        return node;
    }

    // Deletion: handles leaf, one child and two children cases
    Node* remove(Node* node, const char* name, bool& deleted) {
        if (node == NULL) {
            deleted = false;
            return NULL;
        }
        int cmp = strcmp(name, node->data.name);
        if (cmp < 0) node->left = remove(node->left, name, deleted);
        else if (cmp > 0) node->right = remove(node->right, name, deleted);
        else {
            deleted = true;
            if (node->left == NULL) {                  // no left child
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == NULL) {                 // no right child
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* successor = findMin(node->right);    // two children: inorder successor
            node->data = successor->data;
            bool dummy;
            node->right = remove(node->right, successor->data.name, dummy);
        }
        return node;
    }

    // Traversals
    void inorder(Node* node) {                         // Left, Root, Right
        if (node == NULL) return;
        inorder(node->left);
        node->data.display();
        inorder(node->right);
    }
    void preorder(Node* node) {                        // Root, Left, Right
        if (node == NULL) return;
        node->data.display();
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node* node) {                       // Left, Right, Root
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        node->data.display();
    }

    int height(Node* node) {
        if (node == NULL) return 0;
        int l = height(node->left);
        int r = height(node->right);
        return (l > r ? l : r) + 1;
    }
    int count(Node* node) {
        if (node == NULL) return 0;
        return 1 + count(node->left) + count(node->right);
    }
    void freeTree(Node* node) {
        if (node == NULL) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }

public:
    ContactTree() { root = NULL; }                     // constructor
    ~ContactTree() { freeTree(root); }                 // destructor

    bool addContact(Contact c) {
        bool added = false;
        root = insert(root, c, added);
        return added;
    }
    bool deleteContact(const char* name) {
        bool deleted = false;
        root = remove(root, name, deleted);
        return deleted;
    }
    void searchContact(const char* name) {             // iterative BST search
        Node* current = root;
        while (current != NULL) {
            int cmp = strcmp(name, current->data.name);
            if (cmp == 0) {
                cout << "Found: ";
                current->data.display();
                return;
            }
            current = (cmp < 0) ? current->left : current->right;
        }
        cout << "Contact not found.\n";
    }
    void showInorder()   { if (root == NULL) cout << "Contact book is empty.\n"; else inorder(root); }
    void showPreorder()  { if (root == NULL) cout << "Contact book is empty.\n"; else preorder(root); }
    void showPostorder() { if (root == NULL) cout << "Contact book is empty.\n"; else postorder(root); }
    int getHeight() { return height(root); }
    int getCount()  { return count(root); }
};

/* ---------- Main: menu-based interface ---------- */
int main() {
    ContactTree book;
    int choice;
    char name[30], phone[15];

    do {
        cout << "\n======= CONTACT BOOK (BST) =======\n";
        cout << "1. Add contact\n";
        cout << "2. Search contact\n";
        cout << "3. Delete contact\n";
        cout << "4. Display sorted list (Inorder)\n";
        cout << "5. Display Preorder\n";
        cout << "6. Display Postorder\n";
        cout << "7. Height of tree\n";
        cout << "8. Total contacts\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name (one word): ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phone;
            if (book.addContact(Contact(name, phone))) cout << "Contact added.\n";
            else cout << "Name already exists.\n";
            break;
        case 2:
            cout << "Enter name to search: ";
            cin >> name;
            book.searchContact(name);
            break;
        case 3:
            cout << "Enter name to delete: ";
            cin >> name;
            if (book.deleteContact(name)) cout << "Contact deleted.\n";
            else cout << "Contact not found.\n";
            break;
        case 4: book.showInorder(); break;
        case 5: book.showPreorder(); break;
        case 6: book.showPostorder(); break;
        case 7: cout << "Height of tree: " << book.getHeight() << endl; break;
        case 8: cout << "Total contacts: " << book.getCount() << endl; break;
        case 0: cout << "Thank you!\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

/*PS C:\Users\Student\Downloads> 
 > cd "d:\sarthak kale\" ; if ($?) { g++ ContactBookBST.cpp -o ContactBookBST } ; if ($?) { .\ContactBookBST }

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 1
Enter name (one word): sarthak 
Enter phone number: 9373567890
Contact added.

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 1
Enter name (one word): sidharth
Enter phone number: 9878095678
Contact added.

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 1
Enter name (one word): atharv
Enter phone number: 9076565445
Contact added.

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 4
atharv  -  9076565445
sarthak  -  9373567890
sidharth  -  9878095678

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 4
atharv  -  9076565445
sarthak  -  9373567890
sidharth  -  9878095678

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice:
4
atharv  -  9076565445
sarthak  -  9373567890
sidharth  -  9878095678

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 5
sarthak  -  9373567890
atharv  -  9076565445
sidharth  -  9878095678

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 
5
sarthak  -  9373567890
atharv  -  9076565445
sidharth  -  9878095678

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 6
atharv  -  9076565445
sidharth  -  9878095678
sarthak  -  9373567890

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 
6
atharv  -  9076565445
sidharth  -  9878095678
sarthak  -  9373567890

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 7
Height of tree: 2

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 
7
Height of tree: 2

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 
8
Total contacts: 3

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 3
Enter name to delete: atharv
Contact deleted.

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 4
sarthak  -  9373567890
sidharth  -  9878095678

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: 
4
sarthak  -  9373567890
sidharth  -  9878095678

======= CONTACT BOOK (BST) =======
1. Add contact
2. Search contact
3. Delete contact
4. Display sorted list (Inorder)
5. Display Preorder
6. Display Postorder
7. Height of tree
8. Total contacts
0. Exit
Enter choice: */
