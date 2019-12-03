#define _CRT_SECURE_NO_WARNINGS 1

#define Weight int
#define Symbol char

typedef struct TreeNode{
	
}TNode, *Tlist;

typedef struct Tree{
	Symbol symbol;
	Weight vel;
	struct Tree* next;
};
