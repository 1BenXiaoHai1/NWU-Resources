#include<stdio.h>
#include "BinTree.h"

int main() {
	NODE *root;
	Create(&root);
	Input(&root);
	printf("%d\n", NumNode(root));
	printf("%d\n", NumNode(root));
	Destroy(&root);
	return 0;
}

int NumNode(const NODE *root) {
	if (root != NULL) {
		return NumNode(root->lch) + NumNode(root->right) + 1;
	} else {
		return 0;
	}
}
