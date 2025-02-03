int max(int a,int b){return a>b?a:b;}
int height(struct Node* node){return node?1+max(height(node->left),height(node->right)):-1;}
