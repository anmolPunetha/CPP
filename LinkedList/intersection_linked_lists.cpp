Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
       //calculate lengths of each first
    int a1=0;
    int a2=0;
    Node * temp1=l1;
    Node*temp2=l2;
    while(temp1!=NULL){
        a1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        a2++;
        temp2=temp2->next;
    }

    //calculate the difference and move d nodes in longer LL
    //after that move each step one by one in both, intersection p both will reach
    int d;
    if(a1>a2){
        d=a1-a2;
        Node*t=l1;
        Node*q=l2;
        for(int i=1;i<=d;i++){
            t=t->next;
        }
        while(t!=q){
            t=t->next;
            q=q->next;
        }
            return t;
    }
    else{
        d=a2-a1;
        Node*q=l1;
        Node*t=l2;
        for(int i=1;i<=d;i++){
            t=t->next;
        }
        while(t!=q){
            t=t->next;
            q=q->next;
        }
            return t;
    }
}
