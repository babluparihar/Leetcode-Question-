// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.


// steps
  apply inorder traversal
  take a element and go with that element 
  if element is more than the vector size return the false 
  else return answer
  
  
class BSTIterator {
public:
    vector<int>vec;
    int i;
    void inorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            vec.push_back(root->val);
            inorder(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
        i=0;
    }
    
    int next() {
        return vec[i++];
    }
    
    bool hasNext() {
        if(i>=vec.size())
        {
            return false;
        }
        return true;
    }
};
