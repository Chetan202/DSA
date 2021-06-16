//Binary Search Tree
//It has
//1.Insertion
//2.Deletion
//3.Traverse
//4.Search
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Create a Node
struct Node
{
    int data;
    Node *left;
    Node *right;
    //To store val for root node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
//To add nodes from root node -> ...
Node *InsertNode(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    else if (val > root->data)
    {
        root->right = InsertNode(root->right, val);
    }
    else
    {
        root->left = InsertNode(root->left, val);
    }
    return root;
}
//Inorder Traversing
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
//Preorder
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
//Postorder
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
//Search a node
bool search(Node *root, int search_no)
{
    if (root == NULL)
        return false;
 
    if (root->data == search_no)
        return true;
 
    /* then recur on left sutree */
    bool res1 = search(root->left, search_no);
    // node found, no need to look further
    if(res1) return true;
 
    /* node is not found in left,
    so recur on right subtree */
    bool res2 = search(root->right, search_no);
 
    return res2;
}

//DELETE A NODE
Node* FindMin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* DeleteNode(Node *root,int val){
    if(root == NULL)    return root;
    else if(val > root->data)   root->right = DeleteNode(root->right,val);
    else if(val < root->data)   root->left = DeleteNode(root->left,val);
    else{
        //Case 1: NO Child
        if(root->left == NULL &&root->right == NULL){
            delete root;
            root= NULL; 
        }//Case 2:  One Child
        else if(root->right == NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }else if(root->left == NULL){
            Node *temp = root;
            root=root->right;
            delete temp;
        }//Case 3: Two Child
        else{
            //Find the minimum Node
            Node* temp = FindMin(root->right);
            //store minimum Node of temp-ka->data as root-ka->data
            root->data = temp->data;
            //Delete the duplicated Node
            root->right = DeleteNode(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    //It is v.imp to set root node value
    root = InsertNode(root, 52);
    InsertNode(root, 25);
    InsertNode(root, 50);
    InsertNode(root, 15);
    InsertNode(root, 40);
    InsertNode(root, 45);
    //preorder traversal
    cout << "Inorder Traversal" << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal" << endl;
    preorder(root);
    cout << endl;
    DeleteNode(root,15);
    cout<<endl;
    cout << "Postorder Traversal" << endl;
    postorder(root);
    cout << endl;
    if (search(root, 80))
        cout << "Found"
             << "\n";
    else
        cout << "Not Found"
             << "\n";

    return 0;
}
