bool floydCycleRemoval(Node *head)
{
    Node *fast = head;
    Node *slow = head;
   while(fast!=NULL and fast->next!=NULL){
       fast=fast->next->next;
       slow=slow->next;
       if(fast==slow){ //detected
           slow = head; //make slow same as head
           while(slow!=fast){ //find next node when slow =fast
               slow=slow->next;
               fast=fast->next;
           }
           node*temp=slow;
           while(temp->next!=fast){ //remove the link
               temp=temp->next;
           }
           temp->next=NULL;   
           return true;
       }
   }
   return false;
}
