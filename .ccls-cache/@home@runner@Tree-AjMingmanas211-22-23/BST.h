#include "node.h"

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();
  void destroyTree(TreeNodePtr);
  void insertNode(int);
  void printAll(int = 0);
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr, int);
  TreeNodePtr getRoot() { return rootPtr; }
};

void BST::insertNode(int value) {
  int inserted = 0;
  TreeNodePtr new_node, t;
  new_node = new TreeNode(value);
  if (new_node) {
    if (!rootPtr) {
      rootPtr = new_node;
    } else {
      t = rootPtr;
      while (!inserted) {
        if (value <= t->getValue()) {
          if (t->moveLeft())
            t = t->moveLeft();
          else {
            t->setLeft(new_node);
            inserted = 1;
          }
        } else {
          if (t->moveRight())
            t = t->moveRight();
          else {
            t->setRight(new_node);
            inserted = 1;
          }
        }
      }
    }
    ++size;
  }
}

BST::BST() {
  rootPtr = nullptr;
  size = 0;
}

BST::~BST() {
  cout << "Destroy BST" << endl;
  destroyTree(rootPtr);
}

void BST::printTree(TreeNodePtr treePtr, int l) {
  if (treePtr) {
    if (treePtr->moveRight()) {
      printTree(treePtr->moveRight(), l + 4);
    }
    if (l) {
      cout << setw(l) << " ";
    }
    if (treePtr->moveRight()) {
      cout << " /\n" << setw(l) << " ";
    }
    cout << treePtr->getValue() << '\n';

    if (treePtr->moveLeft()) {
      cout << setw(l) << " " << "\\\n";
      printTree(treePtr->moveLeft(), l + 4);
    }
  }
}

void BST::inOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    inOrder(treePtr->moveLeft());
    cout << treePtr->getValue() << " ";
    inOrder(treePtr->moveRight());
  }
}

void BST::preOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    cout << treePtr->getValue() << " ";
    preOrder(treePtr->moveLeft());
    preOrder(treePtr->moveRight());
  }
}

void BST::postOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    postOrder(treePtr->moveLeft());
    postOrder(treePtr->moveRight());
    cout << treePtr->getValue() << " ";
  }
}

void BST::destroyTree(TreeNodePtr treePtr) {
  if (treePtr) {
    destroyTree(treePtr->moveLeft());
    destroyTree(treePtr->moveRight());
    delete treePtr;
  }
}

void BST::printAll(int option) {
  switch (option) {
    case 1:
      inOrder(rootPtr);
      cout << endl;
      break;
    case 2:
      preOrder(rootPtr);
      cout << endl;
      break;
    case 3:
      postOrder(rootPtr);
      cout << endl;
      break;
    case 4:
      printTree(rootPtr, 0);
      break;
    default:
      cout << "Inorder" << endl;
      inOrder(rootPtr);
      cout << endl;
      cout << "Preorder" << endl;
      preOrder(rootPtr);
      cout << endl;
      cout << "Postorder" << endl;
      postOrder(rootPtr);
      cout << endl;
      cout << "Tree" << endl;
      printTree(rootPtr, 0);
      cout << endl;
  }
}
