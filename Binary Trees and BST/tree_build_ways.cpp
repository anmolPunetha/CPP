//preorder
node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

//level order
void level_order_build(node *&root){	
  int d,c1,c2;
	queue<node*> Q;

	cin>>d;
	root = new node(d);
	Q.push(root);
	while(Q.size() >= 1){
		node *n = Q.front();
		Q.pop();
		cin>>c1>>c2; // Children of n->data
		if(c1 != -1){
			n->left = new node(c1);
			Q.push(n->left);
		}
		if(c2 != -1){
			n->right = new node(c2);
			Q.push(n->right);
		}
	}
}
