class TreeNode {   
                                        
   TreeNode *leftPtr; // pointer to left subtree 
   int data; // node value                               
   TreeNode *rightPtr; // pointer to right subtree
public:
        TreeNode(int); 
        ~TreeNode();
        void setLeft(TreeNode* t);
        void setRight(TreeNode* t){rightPtr=t;}
        int getValue(){return data;}
        TreeNode* moveRight(){ return rightPtr; }
        TreeNode* moveLeft(){ return leftPtr; }

       

}; // end structure treeNode 
        

typedef TreeNode * TreeNodePtr; 
// synonym for TreeNode*
void TreeNode::setLeft(TreeNode *t){
  leftPtr=t;
}
TreeNode::TreeNode(int x){
   data =x;
   leftPtr=NULL;
   rightPtr=NULL;
  
}
TreeNode::~TreeNode(){
  cout<<"Deleting "<< data<<endl;
  
}
