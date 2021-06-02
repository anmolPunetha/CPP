bool structureIdentical(node*root1, node*root2){
	bool equal=false;
	if(root1==NULL and root2==NULL){
		return true;
	}

	if(root1!=NULL and root2!=NULL){
		bool lt = structureIdentical(root1->left, root2->left);
		bool rt = structureIdentical(root1->right, root2->right);
		if(lt and rt){
			equal=true;
		}
	}
	// else{
	// 	equal=false;
	// }
	return equal;
}
