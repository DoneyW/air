#include "Custom.h"

Custom_Tree::Custom_Tree()
{
	root = NULL;
}

Custom_Tree::Custom_Tree(std::vector<Custom> &cus)
{
	root = NULL;
	for (auto i : cus) {
		this->put(i.IDNumber, i.passWord);
	}
}

string Custom_Tree::get(string IDNumber)
{
	return get(root, IDNumber);
}

void Custom_Tree::put(string IDNumber, string passWord)
{
	root = put(root, IDNumber, passWord);
	root->color = BLACK;
}

Custom_Tree::Node* Custom_Tree::rotateRight(Node* h)
{
	Node* x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	x->N = h->N;
	h->N = 1 + size(h->left) + size(h->right);
	return x;
}

Custom_Tree::Node* Custom_Tree::rotateLeft(Node* h)
{
	Node* x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	x->N = h->N;
	h->N = 1 + size(h->left) + size(h->right);
	return x;
}

void Custom_Tree::flipColors(Node* h)
{
	h->color = RED;
	h->left->color = BLACK;
	h->right->color = BLACK;
}

int Custom_Tree::size(Node* h)
{
	if (h == NULL) return 0;
	return 1 + size(h->left) + size(h -> right);
}

bool Custom_Tree::isRed(Node* h)
{
	if (!h)return false;
	else return h->color == RED;
}

Custom_Tree::Node* Custom_Tree::put(Node* h,string IDnumber, string passWord)
{
	if (!h) return new Node(IDnumber, passWord);
	if (IDnumber < h->getNumber()) h->left = put(h->left, IDnumber, passWord);
	else if (IDnumber > h->getNumber()) h->right = put(h->right, IDnumber, passWord);
	else h->chgPassWord(passWord);
	if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
	if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
	if (isRed(h->left) && isRed(h->right)) flipColors(h);
	h->N = size(h->left) + size(h->right) + 1;
	return h;
}

string Custom_Tree::get(Node* h, string ID)
{
	if (!h) return string();
	if (h->getNumber() == ID) return h->getpassWord();
	else if (h->getNumber() > ID) return get(h->left, ID);
	else return get(h->right, ID);
}

Custom_Tree::Node::Node(string IDNumber, string passWord):IDNumber(IDNumber),
passWord(passWord)
{
	color = RED;
	N = 1;
	left = NULL;
	right = NULL;
}
