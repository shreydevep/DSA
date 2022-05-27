// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++


 
// Function to make a new node
// and return its pointer
struct NodeDetails {
    Node* ptr;
    int min, max;
};
Node* getNode(int data)
{
    Node* temp = new Node(0);
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
// Function to construct the BST
Node* constructBst(int arr[], int n)
{
    if (n == 0)
        return NULL;
 
    Node* root;
 
    queue<NodeDetails> q;
 
    // index variable to
    // access array elements
    int i = 0;
 
    // Node details for the
    // root of the BST
    NodeDetails newNode;
    newNode.ptr = getNode(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);
 
    // Getting the root of the BST
    root = newNode.ptr;
 
    // Until there are no more
    // elements in arr[]
    while (i != n) {
 
        // Extracting NodeDetails of a
        // node from the queue
        NodeDetails temp = q.front();
        q.pop();
 
        // Check whether there are more elements
        // in the arr[] and arr[i] can be
        // left child of 'temp.ptr' or not
        if (i < n
            && (arr[i] < temp.ptr->data
                && arr[i] > temp.min)) {
 
            // Create NodeDetails for newNode
            // and add it to the queue
            newNode.ptr = getNode(arr[i++]);
            newNode.min = temp.min;
            newNode.max = temp.ptr->data;
            q.push(newNode);
 
            // Make this 'newNode' as left child
            // of 'temp.ptr'
            temp.ptr->left = newNode.ptr;
        }
 
        // Check whether there are more elements
        // in the arr[] and arr[i] can be
        // right child of 'temp.ptr' or not
        if (i < n
            && (arr[i] > temp.ptr->data
                && arr[i] < temp.max)) {
 
            // Create NodeDetails for newNode
            // and add it to the queue
            newNode.ptr = getNode(arr[i++]);
            newNode.min = temp.ptr->data;
            newNode.max = temp.max;
            q.push(newNode);
 
            // Make this 'newNode' as right
            // child of 'temp.ptr'
            temp.ptr->right = newNode.ptr;
        }
    }
 
    // Root of the required BST
    return root;
}
//Function to construct the BST from its given level order traversal.

