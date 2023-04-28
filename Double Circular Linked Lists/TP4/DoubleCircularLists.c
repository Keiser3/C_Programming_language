#include<stdio.h>
#include<stdlib.h>
struct nd_0
{
struct nd_0 *prv_1;
struct nd_0 *nxt_1;
int dta;
};
struct nd_0 *head;
void insrtion_begnng();
void insrtion_lst();
void delnt_begnng();
void deln_lst();
void show();
void srch();
void main ()
{
int choce =0;
while(choce != 8)
{
printf("\n*********Main_Menu_for_Display*********\n");
printf("\nChoose_any_one_option_from_list ...\n");
printf("\n----------------------------------------------------\n"); printf("\n1.Insertion_At_start\n2.Insertion_At_last\n3.Delet_at_Beginning\n4.Deletion_frm_end\n5.find\n6.display_val\n7.stop\n");
printf("\nSelect_the_desired_choice?\n");
scanf("\n%d",&choce);
switch(choce)
{
case 1:
insrtion_begnng();
break;
case 2:
insrtion_lst();
break;
case 3:
delnt_begnng();
break;
case 4:
deln_lst();
break;
case 5:
srch();
break;
case 6:
show();
break;
case 7:
exit(0);
break;
default:
printf("Select_entry_of_your_choicce..");
}
}
}
void insrtion_begnng()
{
struct nd_0 *ptr_0,*temp_1;
int item_0;
ptr_0 = (struct nd_0 *)malloc(sizeof(struct nd_0));
if(ptr_0 == NULL)
{
printf("\nList_Overflow");
}
else
{
printf("\nEnter desired_element");
scanf("%d",&item_0);
ptr_0->dta=item_0;
if(head==NULL)
{
head = ptr_0;
ptr_0 -> nxt_1 = head;
ptr_0 -> prv_1 = head;
}
else
{
temp_1 = head;
while(temp_1 -> nxt_1 != head)
{
temp_1 = temp_1 -> nxt_1;
}
temp_1 -> nxt_1 = ptr_0;
ptr_0 -> prv_1 = temp_1;
head -> prv_1 = ptr_0;
ptr_0 -> nxt_1 = head;
head = ptr_0;
}
printf("\nInserted_Node..\n");
}
}
void insrtion_lst()
{
struct nd_0 *ptr_0,*temp_1;
int itm_0;
ptr_0 = (struct nd_0 *) malloc(sizeof(struct nd_0));
if(ptr_0 == NULL)
{
printf("\niList_overflow");
}
else
{
printf("\nEnter desired_val");
scanf("%d",&itm_0);
ptr_0->dta=itm_0;
if(head == NULL){
    head = ptr_0;
    ptr_0 -> nxt_1 = head;
    ptr_0 -> prv_1 = head;
 }
else{
    temp_1 = head;
    while(temp_1->nxt_1 !=head)
    {
    temp_1 = temp_1->nxt_1;
    }
            temp_1->nxt_1 = ptr_0;
            ptr_0 ->prv_1=temp_1;
            head -> prv_1 = ptr_0;
            ptr_0 -> nxt_1 = head;
    }
 }
printf("\nnode_insertd_at_lst\n");
}
void delnt_begnng()
{
struct nd_0 *temp_1;
if(head == NULL)
{
printf("\n List_UNDERFLOW");
}
else if(head->nxt_1 == head)
{
head = NULL;
free(head);
printf("\ndelete_node_at_beginning\n");
}
else
{
temp_1 = head;
while(temp_1 -> nxt_1 != head)
{
temp_1 = temp_1 -> nxt_1;
}
temp_1 -> nxt_1 = head -> nxt_1;
head -> nxt_1 -> prv_1 = temp_1;
free(head);
head = temp_1 -> nxt_1;
}
}
void deln_lst()
{
struct nd_0 *ptr_1;
if(head == NULL)
{
printf("\n List_Underflow");
}
else if(head->nxt_1 == head)
{
head = NULL;
free(head);
printf("\nDeleted_Node\n");
}
else
{
ptr_1 = head;
if(ptr_1->nxt_1 != head)
{
ptr_1 = ptr_1 -> nxt_1;
}
ptr_1 -> prv_1 -> nxt_1 = head;
head -> prv_1 = ptr_1 -> prv_1;
free(ptr_1);
printf("\nDeleted_Node\n");
}
}
void show()
{
struct nd_0 *ptr_0;
ptr_0=head;
if(head == NULL)
{
printf("\nnot_to_print_anything;;");
}
else
{
printf("\n Need_to_print_some_values ... \n");
while(ptr_0 -> nxt_1 != head)
{
printf("%d\n", ptr_0 -> dta);
ptr_0 = ptr_0 -> nxt_1;
}
printf("%d\n", ptr_0 -> dta);
}
}
void srch()
{
struct nd_0 *ptr_0;
int itm,i_0=0,flag=1;
ptr_0 = head;
if(ptr_0 == NULL)
{
printf("\nBlank_all_elements.\n");
}
else
{
printf("\nSearch_for_items?\n");
scanf("%d",&itm);
if(head ->dta == itm)
{
printf("found_location_item %d",i_0+1);
flag=0;
}
else
{
while (ptr_0->nxt_1 != head)
{
if(ptr_0->dta == itm)
{
printf("element_at_location %d ",i_0+1);
flag=0;
break;
}
else
{
flag=1;
}
i_0++;
ptr_0 = ptr_0 -> nxt_1;
}
}
if(flag != 0)
{
printf("Element_Not_found\n");
}
}
}