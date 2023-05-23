/* Question 1(Programming):
Write a C++ program to build a binary search tree based on the following number sequence.
Then print out this tree in preorder, inorder, and post order. You must implement the three
traversal print functions recursively. Failed to build a binary search tree structure will cause a 0
in this section.
[6, 10, 7, 14, 3, 11, 5, 15, 4, 13, 12, 2, 8, 9, 1 */



#include <iostream>

using namespace std;

# include <iostream>
# include <cstdlib>
using namespace std;

//Node Declaration

struct node
{
int info;
struct node *left;
struct node *right;
}*r;


// Class Declaration

class BST
{
public:
void insert(node*, node*);
void preorder(node *);
void inorder(node *);
void postorder(node *);
BST()
{
r = NULL;
}
};



int main()
{
BST bst;

int arr[] ={6, 10, 7, 14, 3, 11, 5, 15, 4, 13, 12, 2, 8, 9, 1};
node *temp;

for(int i=0;i<15;++i) {
temp = new node;
temp->info = arr[i];
bst.insert(r, temp);
}
cout << "Inorder Traversal of BST:" << endl;
bst.inorder(r);
cout << endl;
cout << "Preorder Traversal of BST:" << endl;
bst.preorder(r);
cout << endl;
cout << "Postorder Traversal of BST:" << endl;
bst.postorder(r);
cout << endl;

}


// Inserting Element into the Tree

void BST::insert(node *tr, node *newnode)
{
if (r == NULL)
{
r = new node;
r->info = newnode->info;
r->left = NULL;
r->right = NULL;
cout << "Root Node is Added" << endl;
return;
}
if (tr->info == newnode->info)
{
cout << "Element already in the tree" << endl;
return;
}
if (tr->info > newnode->info)
{
if (tr->left != NULL)
{
insert(tr->left, newnode);
}
else
{
tr->left = newnode;
(tr->left)->left = NULL;
(tr->left)->right = NULL;
cout << "adding node to the left" << endl;
return;
}
}
else
{
if (tr->right != NULL)
{
insert(tr->right, newnode);
}
else
{
tr->right = newnode;
(tr->right)->left = NULL;
(tr->right)->right = NULL;
cout << "adding node to the right" << endl;
return;
}
}
}


void BST::preorder(node *ptr)
{
if (r == NULL)
{
cout << "empty tree" << endl;
return;
}
if (ptr != NULL)
{
cout << ptr->info << " ";
preorder(ptr->left);
preorder(ptr->right);
}
}
int max(int a, int b)
{
return (a >= b)? a: b;
}


void BST::inorder(node *ptr)
{
if (r == NULL)
{
cout << "empty tree" << endl;
return;
}
if (ptr != NULL)
{
inorder(ptr->left);
cout << ptr->info << " ";
inorder(ptr->right);
}
}


void BST::postorder(node *ptr)
{
if (r == NULL)
{
cout << "empty tree" << endl;
return;
}
if (ptr != NULL)
{
postorder(ptr->left);
postorder(ptr->right);
cout << ptr->info << " ";
}
}

