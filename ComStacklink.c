#include<stdio.h> //Header Files included
#include<stdlib.h>

struct node{ // struct node type data to replicate linklist
    int data;
    struct node *link;
}*top = NULL; //globally defining top of the stack

int isEmpty(){ // is empty function to check stack is underflow or not
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

void Push(int data){ // push function to add the element in the list 

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;

    printf("%d is the element added in the new node \n",newNode->data);


}

int Pop(){
 // pop funciton to pop the  elements for the stack
    struct node *temp = top;
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }

    int val = temp->data;

    top = top->link;
    free(temp);
    temp = NULL;
    return val;


}

int Peek(){  // to see the top element of the stack

    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }

    return top->data;



}

void Print(){  // display all eleemnts


    struct node *temp = top;

    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }


    while(temp){

        printf("-> %d",temp->data);
        temp = temp->link;

    }


}

int main(){ // main function to call those  funciton 

    int data,choice;
    while(1){

        printf("\n"); 
        printf("1.Push Elment ? \n"); 
        printf("2. Pop Element ?\n"); 
        printf("3. Peek Element ?\n"); 
        printf("4. Print Elements ?\n"); 
        printf("5. Exit?\n"); 
        printf("Enter Your choice = ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter your data = ");
            scanf("%d",&data);
            Push(data);
            break;

            case 2:
            printf("%d is the element delete ",Pop());
            break;

            case 3:
            printf("%d is the top element of the stack",Peek());
            break;

            case 4:
            Print();
            break;

            case 5:
            exit(1);

            default:
            printf("Invalid Input");



        } 



    }


    return 1;
}