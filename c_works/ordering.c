#include<stdio.h>
#include<stdlib.h>

struct chromo
{
    int x,y,dom,iden;
    struct chromo *up;
    struct chromo *down;
    struct chromo *domi;
};

struct chromo* head = NULL;
struct chromo* tail = NULL;
struct chromo* chromosome = NULL;
struct chromo* temp = NULL;
struct chromo* run = NULL;
struct chromo* ini = NULL;
struct chromo* dominator = NULL;

void ch_insert(int i){
    temp = (struct chromo*)malloc(sizeof(struct chromo));
    temp->iden = i;
    printf("%d X-co-ordinate:",i);
    scanf("%d",&(temp->x));
    printf("%d Y-co-ordinate:",i);
    scanf("%d",&(temp->y));
    temp->dom=0;
    temp->up=tail;
    temp->domi=NULL;
    temp->down=NULL;
    tail->down=temp;
    tail=temp;
}

void create(int n){
    int i=1;
    if(n!=0)
    if(head == NULL){
        head = (struct chromo*)malloc(sizeof(struct chromo));
        head->iden = i;
        printf("%d X-co-ordinate:",i);
        scanf("%d",&(head->x));
        printf("%d Y-co-ordinate:",i);
        scanf("%d",&(head->y));
        head->dom = 0;
        head->up = NULL;
        head->down = NULL;
        head->domi = NULL;
        tail = head;
        i++;
        for (; i <= n; i++)
        {
            ch_insert(i);
        }
    }
};

void ch_prep_min_min(){
    if(head != NULL){ 
    temp=head;
    run=head;
    while(run->down!=NULL){
    while(temp->down!= NULL){
        temp=temp->down;
        if((run->x<=temp->x && run->y<temp->y)||(run->x<temp->x && run->y<=temp->y)){
            if(run->domi==NULL){
            dominator = (struct chromo*)malloc(sizeof(struct chromo));
            run->domi=dominator;
            dominator->iden=temp->iden;
            dominator->x=temp->x;
            dominator->y=temp->y;
            dominator->dom=-1;
            dominator->domi=NULL;
            dominator->up=NULL;
            dominator->down=NULL;
            }
            else{
                ini = (struct chromo*)malloc(sizeof(struct chromo));
                dominator=run->domi;
                while(dominator->domi != NULL){
                    dominator=dominator->domi;
                }
                dominator->domi=ini;
                dominator=dominator->domi;
                dominator->iden=temp->iden;
                dominator->x=temp->x;
                dominator->y=temp->y;
                dominator->dom=-1;
                dominator->domi=NULL;
                dominator->up=NULL;
                dominator->down=NULL;

            }
                temp->dom = (temp->dom)+1;    
        } else if ((run->x>=temp->x && run->y>temp->y)||(run->x>temp->x && run->y>=temp->y))
        {
            if(temp->domi==NULL){
            dominator = (struct chromo*)malloc(sizeof(struct chromo));
            temp->domi=dominator;
            dominator->iden=run->iden;
            dominator->x=run->x;
            dominator->y=run->y;
            dominator->dom=-1;
            dominator->domi=NULL;
            dominator->up=NULL;
            dominator->down=NULL;
            }
            else{
                ini = (struct chromo*)malloc(sizeof(struct chromo));
                dominator=temp->domi;
                while(dominator->domi != NULL){
                    dominator=dominator->domi;
                }
                dominator->domi=ini;
                dominator=dominator->domi;
                dominator->iden=run->iden;
                dominator->x=run->x;
                dominator->y=run->y;
                dominator->dom=-1;
                dominator->domi=NULL;
                dominator->up=NULL;
                dominator->down=NULL;

            }
                run->dom = (run->dom)+1;
        }
        
    }
    run=run->down;
    temp=run;
    }
    }
}

void ch_print(){
    printf("\nSn. X  Y  DOM\n");
    if(head!=NULL){
        temp=head;
        printf(" %d  %d  %d  %d\n",temp->iden,temp->x,temp->y,temp->dom);
        while(temp->down!=NULL){
            temp=temp->down;
            printf(" %d  %d  %d  %d\n",temp->iden,temp->x,temp->y,temp->dom);
        }
    }
}

void ch_print_prep(){
    
    if(head!=NULL){
        temp=run=head;
        while(temp->down != NULL){
            printf(" %d",temp->iden);
        if(temp->domi!=NULL){
            dominator=temp->domi;
            while(dominator->domi!=NULL){
                printf("->%d",dominator->iden);
                dominator=dominator->domi;
            }
            printf("->%d",dominator->iden);
        }
        printf("\n ||\n");
        temp=temp->down;
        }
        printf(" %d",temp->iden);
          if(temp->domi!=NULL){
            dominator=temp->domi;
            while(dominator->domi!=NULL){
                printf("->%d",dominator->iden);
                dominator=dominator->domi;
            }
            printf("->%d",dominator->iden);
        }
    }
}

void adjust(int n){
    run=head;
    int i=0;
    int ranked[10];
    while(run!= NULL){
        if((run->dom)==0){
            ranked[i]=run->iden;
            i++;
        }
        run=run->down;
    }
    run=head;
    i=0;
    while(run != NULL){
                if(run->iden==ranked[i]){
                   if (run->domi !=NULL){
                    dominator=run->domi;
                    while (dominator != NULL)
                    {
                    ini=run;
                    if(((run->iden)-(dominator->iden))<0){
                        ini=ini->down;
                        while(ini!=NULL){
                            if(ini->iden==dominator->iden){
                                ini->dom -= 1;
                                break;
                            }
                            else{
                                ini=ini->down;
                            }
                        }
                    }else{
                        ini=ini->up;
                        while(ini!=NULL){
                            if(ini->iden==dominator->iden){
                                ini->dom -= 1;
                                break;
                            }
                            else{
                                ini=ini->up;
                            }
                        }
                    }
                    dominator=dominator->domi;
                    }
                   }
                   run->dom=-1;
                   i++;
                }
                run=run->down;
                
        }
}

void ranker(int n){
    int check,ranked=0;
    if(head != NULL){
        check=0;
        for (int i = 0; i < n; i++)
        {
            printf("\nF%d Ranked Points are:",i);
            temp=head;
            while(temp!= NULL){
                if((temp->dom)==0){
                   printf(" %d(%d,%d), ",(temp->iden),(temp->x),(temp->y));
                   check=1;
                   ranked++;
                }
                temp=temp->down;
        }
            if(check==0){
            break;}
            adjust(ranked);
            ranked=0;
            
        }
    }
}

int main(){

    int i,n,mod;
    printf("Specify Number of Chromosomes(n):\n");
    scanf("%d",&n);
    printf("\n");
    printf("Please Select Type of Problem:\n\t1.Min-Min\n\t2.Min-Max\n\t3.Max-Min\n\t4.Max-Max\n");
    scanf("%d",&mod);
    printf("\n");

    create(n);
    ch_print();
    printf("\n");
    ch_prep_min_min();
    ch_print_prep();
    ranker(n);
    return 0;
}