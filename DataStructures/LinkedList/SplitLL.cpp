//Function which appends the node in the linked list.
void insert(node **headRef,node **LastNode,int data){
    node *New = new node;
    New->data = data;
    New->next = NULL;
    if(*headRef == NULL){
        *headRef = New;
        *LastNode = New;
    }
    else{
        (*LastNode)->next = New;
        *LastNode = New;
    }
}
//function which splits the linked list alternatively
void alternatingSplitList(struct node* headRef, struct node** aRef, struct node** bRef){
    int counter = 0;
    node *Alast = NULL,*Blast = NULL;
    node *Ptr = headRef;
    while(Ptr){
        if(counter % 2 == 0){
            insert(aRef,&Alast,Ptr->data);
        }
        else if(counter % 2 != 0)
            insert(bRef,&Blast,Ptr->data);
        Ptr = Ptr->next;
        counter++;
    }
}
