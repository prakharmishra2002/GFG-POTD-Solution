struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
*/
struct Pair{int h,d;};
struct Pair f(struct Node* r){struct Pair p={0,0};if(!r)return p;struct Pair a=f(r->left),b=f(r->right);p.h=1+(a.h>b.h?a.h:b.h);int m=a.d>b.d?a.d:b.d, s=a.h+b.h; p.d=m>s?m:s; return p;}
int diameter(struct Node* root){return f(root).d;}

2)
int max(int a, int b){ return a > b ? a : b; }

struct Pair {
    int h, d;
};

struct Pair f(struct Node* r) {
    struct Pair p = {0, 0};
    if (!r) return p;
    struct Pair a = f(r->left), b = f(r->right);
    p.h = 1 + max(a.h, b.h);
    int m = a.d > b.d ? a.d : b.d;
    int s = a.h + b.h;
    p.d = m > s ? m : s;
    return p;
}

int diameter(struct Node* root) {
    return f(root).d;
}
