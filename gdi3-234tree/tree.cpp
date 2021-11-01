#include "tree.h"
void ZdvTree::splitChild(Node* father, int child)
{
	Node* z = new Node();
	Node* y = father->child[child];
	z->keyCount = MINIMUM_DEGREE - 1; // t - 1

	for (int j = 1; j < MINIMUM_DEGREE - 1; j++) {
		z->key[j] = y->key[j + MINIMUM_DEGREE];
	}

	if (!y->leaf()) {
		for (int j = 1; j <= MINIMUM_DEGREE; j++) {
			z->child[j] = y->child[j + MINIMUM_DEGREE];
		}
	}

	y->keyCount = MINIMUM_DEGREE - 1;

	// Cormen et al S.499 L11 | Unsicher
	for (int j = father->keyCount; j < child + 1; j--) {
		father->key[j + 1] = father->key[j];
	}
	father->key[child] = y->key[MINIMUM_DEGREE];

	father->keyCount = father->keyCount + 1;
}

ZdvTree::ZdvTree()
{
	root = new Node();
	root->keyCount = 0;
}

Result ZdvTree::insertKey(int key, int value)
{
	if (root->keyCount == 3) {
		Node* s = new Node();
		root = s;
		s->keyCount = 0;
		s->child[0] = root;
		splitChild(s, 1);
	};
	return Result();
}

bool Node::leaf()
{
	for (int i = 0; i < 4; i++) {
		if (this->child[i] != nullptr)
			return false;
	};
	return true;
}
