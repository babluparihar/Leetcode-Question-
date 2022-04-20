// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.


// steps
"THIS IS NOT OPTIMIED SOLUTON"
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






"WE CAN SOLVE THIS  QUESTION USING STACK USING ORDER OF H SIZE (here H is height of tree) :)
  
  
  link to access this solution how to solve using the stack
  https://leetcode.com/problems/binary-search-tree-iterator/discuss/1430547/C%2B%2B-Simple-Solution-using-Stack-O(h)-Time-Complexity-(-with-Diagrammatic-Explanation-)




class BSTIterator {
public:
    stack<TreeNode*>s;
    void parital_inorder(TreeNode *root)
    {
       if(root!=NULL)
       {
           s.push(root);
           parital_inorder(root->left);
       }
    }
    BSTIterator(TreeNode* root) {
        parital_inorder(root);
    }
    
    int next() {
        TreeNode* x=s.top();
        s.pop();
        parital_inorder(x->right);
        return x->val;
    }
    
    bool hasNext() {
        return !s.size()==0;
    }
};
