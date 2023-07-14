#include <iostream>
#include <iomanip>
using namespace std;

#include "BST.h"

int main(int argc, char** argv) {
  unsigned int i; // counter to loop from 1-10
  BST b;

  for (i = 1; i < argc; ++i) {
    b.insertNode(atoi(argv[i]));
  }

  cout << "1. Inorder 2. Preorder 3. Postorder 4. Tree\n";
  int choice;
  cout << ": ";
  cin >> choice;

  switch (choice) {
    case 1:
      cout << "Inorder\n";
      break;
    case 2:
      cout << "Preorder\n";
      break;
    case 3:
      cout << "Postorder\n";
      break;
    case 4:
      cout << "Tree\n";
      break;
    default:
      cout << "Inorder\n";
      break;
  }

  b.printAll(choice);

  return 0;
}
