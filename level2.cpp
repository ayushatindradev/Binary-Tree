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
Node* lowsestCommonAncestor(Node* root,Node* p,Node* q){
    if(root == NULL){
        return NULL;
    }

    if(root == p || root == q){
        return root;
    }
    Node* left = lowsestCommonAncestor(root->left,p,q);
    Node* right = lowsestCommonAncestor(root->right,p,q);

    if(left!=NULL && right !=NULL){
        return root;
    }
    if(left!=NULL){
        return left;
    }
    if(right!=NULL){
        return right;
    }
}
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right)+1);
}
void inorderUtil(Node* root ,bool &ans){
    if(root!=NULL){
        inorderUtil(root->left,ans);
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)>1){
            ans = ans && false;
        }
        inorderUtil(root->right,ans);
    }
}

bool isBalancedBinaryTree(Node* root){
    bool ans = true;
    inorderUtil(root,ans);
    return ans;

}
vector<vector<int>> result;
void fill(Node* root,int sum,vector<int> &temp,int targetSum){
    if(!root){
        return;
    }
    sum+=root->data;
    temp.push_back(root->data);

    if(!root->left && !root->right){
        if(sum == targetSum){
            result.push_back(temp);
        }
        return;
    }
    fill(root->left,sum,temp,targetSum);
    fill(root->right,sum,temp,targetSum);
    

}
vector<vector<int>> pathSum(Node* root,int targetSum){
    int sum = 0;
    vector<int> temp;
    fill(root,sum,temp);
    return result;
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

    Node* p = root->left; // Node with value 2
    Node* q = root->right; // Node with value 3
    Node* lca = lowsestCommonAncestor(root, p, q);
    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }
    cout << "Height of the tree: " << height(root) << endl;
    cout << "Is the tree balanced? " << (isBalancedBinaryTree(root) ? "Yes" : "No") << endl;


}
