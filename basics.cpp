#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root ==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root ==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root); //step 1->push the root node into the queue 

    while(!q.empty()){
        Node* curr = q.front();
        // step 2-> store the front node in curr
        cout<<curr->data<<" ";
        // step 3-> pop the front node from the queue
        q.pop();

        // step 4-> push the left and right children of curr into the queue
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
        // step 5-> repeat the process until the queue is empty




    }
}
int main(){
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);

    // cout<<"Root: " << root->data << endl;
    // cout<<"Left Child: " << root->left->data << endl;
    // cout<<"Right Child: " << root->right->data << endl;

    // ✅ Let’s put it all together in main():
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;


    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;


    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;



}
