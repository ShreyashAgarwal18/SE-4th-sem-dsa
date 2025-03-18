#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node() : left(nullptr), right(nullptr), data(0) {}
    node(int d) : data(d), left(nullptr), right(nullptr) {}
};

void insert(node *&root1, int val)
{
    node *p = new node(val);

    if (root1 == nullptr)
        root1 = p;
    else
    {
        node *temp = root1;
        while (true)
        {
            cout << "\n1.For Left Insert of " << temp->data << endl;
            cout << "2.For Right Insert of " << temp->data << endl;
            int c;
            cout << "Enter your choice: ";
            cin >> c;

            if (c == 1)
            {
                if (temp->left == nullptr)
                {
                    temp->left = p;
                    break;
                }
                else
                    temp = temp->left;
            }
            else if (c == 2)
            {
                if (temp->right == nullptr)
                {
                    temp->right = p;
                    break;
                }
                else
                    temp = temp->right;
            }
            else
                cout << "Invalid choice!!!" << endl;
        }
    }
}

void pre_rec(node *root1)
{
    if (root1 != nullptr)
    {
        cout << root1->data << " ";
        pre_rec(root1->left);
        pre_rec(root1->right);
    }
}

void in_rec(node *root1)
{
    if (root1 != nullptr)
    {
        in_rec(root1->left);
        cout << root1->data << " ";
        in_rec(root1->right);
    }
}

void post_rec(node *root1)
{
    if (root1 != nullptr)
    {
        post_rec(root1->left);
        post_rec(root1->right);
        cout << root1->data << " ";
    }
}

void lvlorder(node *root1)
{
    queue<node *> q;
    if (root1 != nullptr)
    {
        q.push(root1);
        while (!q.empty())
        {
            node *t = q.front();
            q.pop();
            cout << t->data << " ";
            if (t->left != nullptr)
                q.push(t->left);
            if (t->right != nullptr)
                q.push(t->right);
        }
    }
}

node *clone(node *root1)
{
    if (root1 == nullptr)
        return nullptr;
    node *t = new node(root1->data);
    t->left = clone(root1->left);
    t->right = clone(root1->right);
    return t;
}

bool chkeq(node *root1, node *root2)
{
    bool a1;
    bool a2;
    bool a3;
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    else
    {
        a1 = root1->data == root2->data;
        a2 = chkeq(root1->left, root2->left);
        a3 = chkeq(root1->right, root2->right);
    }
    if (a1 == true && a2 == true && a3 == true)
        return true;
    else
        return false;
}

node *mirror(node *root1)
{
    if (root1 == nullptr)
        return nullptr;
    node *t = new node(root1->data);
    t->left = mirror(root1->right);
    t->right = mirror(root1->left);
    return t;
}

void create_bst(node *&root, int val)
{
    if (root == nullptr)
    {
        root = new node(val);
        return;
    }
    if (val < root->data)
    {
        if (root->left == nullptr)
        {
            node *t = new node(val);
            root->left = t;
            return;
        }
        create_bst(root->left, val);
    }
    else
    {
        if (root->right == nullptr)
        {
            node *t1 = new node(val);
            root->right = t1;
            return;
        }
        create_bst(root->right, val);
    }
}

void del(node *&root, int val)
{
    if (root == nullptr)
    {
        cout << "Node not found";
    }

    if (val < root->data)
        del(root->left, val);
    else if (val > root->data)
        del(root->right, val);
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = root->right;
            while (temp->left != nullptr)
                temp = temp->left;
            root->data = temp->data;
            del(root->right, temp->data);
        }
    }
}

node *cbst(vector<int> &preorder, int &index, int minVal, int maxVal)
{
    if (index >= preorder.size())
        return nullptr;
    int key = preorder[index];
    if (key < minVal || key > maxVal)
        return nullptr;
    node *root = new node(key);
    index++;
    root->left = cbst(preorder, index, minVal, key);
    root->right = cbst(preorder, index, key, maxVal);
    return root;
}

node *cbst(vector<int> &preorder)
{
    int index = 0;
    return cbst(preorder, index, INT_MIN, INT_MAX);
}

int height(node *root)
{
    if (root == nullptr)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

bool sbst(node *root, int val)
{
    node *t = root;
    while (t != nullptr)
    {
        if (t->data == val)
            return true;
        else if (t->data > val)
            t = t->left;
        else
            t = t->right;
    }
    return false;
}

int main()
{
    node *root1 = nullptr;
    node *root2 = nullptr;

    int ch;

    do
    {
        cout << "\n1.Create Binary Tree";
        cout << "\n2.Preorder Recursive";
        cout << "\n3.Preorder Iterative";
        cout << "\n4.Inorder Recursive";
        cout << "\n5.Inorder Iterative";
        cout << "\n6.Postorder Recursive";
        cout << "\n7.Postorder Iterative";
        cout << "\n8.Level Order";
        cout << "\n9.Clone";
        cout << "\n10.Check Equal Trees";
        cout << "\n11.Mirror Image";
        cout << "\n12.Create BST";
        cout << "\n13.Delete node from BST";
        cout << "\n14.BST from Preorder & Inorder";
        cout << "\n15.Height";
        cout << "\n16.Search in BST";
        cout << "\n17.Exit";

        cout << "\n\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            int n;
            cout << "Enter the number of nodes to insert: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int val;
                cout << "\nEnter value for node " << i + 1 << ": ";
                cin >> val;
                insert(root1, val);
            }
            cout << "Binary Tree Created\n";
            break;

        case 2:
            cout << "\nPreorder Recursive Traversal: ";
            pre_rec(root1);
            cout << endl;
            break;

        case 3:
            cout << "\nPreorder Iterative Traversal: ";
            break;

        case 4:
            cout << "\nInorder Recursive Traversal: ";
            in_rec(root1);
            cout << endl;
            break;

        case 5:
            cout << "\nInorder Iterative Traversal: ";
            break;

        case 6:
            cout << "\nPostorder Recursive Traversal: ";
            post_rec(root1);
            cout << endl;
            break;

        case 7:
            cout << "\nPostorder Iterative Traversal: ";
            break;

        case 8:
            cout << "\nLevel order Traversal: ";
            lvlorder(root1);
            cout << endl;
            break;

        case 9:
            root2 = clone(root1);
            cout << "\nClone Created" << endl;
            break;

        case 10:
            cout << (chkeq(root1, root2) ? "\nTrees are Equal" : "\nTrees are not Equal") << endl;
            break;

        case 11:
            root2 = mirror(root1);
            cout << "\nMirror image created" << endl;
            break;

        case 12:
            int x;
            cout << "\nEnter the number of nodes to insert: ";
            cin >> x;
            for (int i = 0; i < x; i++)
            {
                int val;
                cout << "\nEnter value for node " << i + 1 << ": ";
                cin >> val;
                create_bst(root2, val);
            }
            cout << "Binary Search Tree Created\n";
            break;

        case 13:
            int y;
            cout << "Enter value to delete from BST: ";
            cin >> y;
            del(root2, y);
            break;

        case 14:
        {
            int m;
            cout << "Enter size of Preorder: ";
            cin >> m;
            vector<int> preorderVals(m);
            for (int i = 0; i < m; i++)
                cin >> preorderVals[i];
            root2 = cbst(preorderVals);
            break;
        }
        break;

        case 15:
        {
            int h1 = height(root1);
            int h2 = height(root2);
            cout << "Height of Binary tree is: " << h1 << endl;
            cout << "Height of Binary Search tree is: " << h2 << endl;
            break;
        }

        case 16:
            int key;
            cout << "Enter the Value to be Searched: ";
            cin >> key;
            if (sbst(root2, key))
                cout << "Element found\n";
            else
                cout << "Element not found\n";
            break;
        }
    } while (ch != 17);
}
