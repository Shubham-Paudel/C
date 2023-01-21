 #include <graphics.h>
 #include <conio.h>
 #include <stdio.h>
 #define    MAX   15


   struct Queue
   {
      int st[MAX];
   };

   void Insert(struct Queue *Q,int val);
   void Delete(struct Queue *Q);
   void DISPLAY(struct Queue Q);
   void main()
   {
      char ch;
      int num,tot,i;

      struct Queue Que;
      Que.st[0]=2;
      Que.st[1]=2;

      while(1)
      {
	 clrscr();
	 printf("********************");
	 printf("QUEUE");
	 printf("********************");
	 printf("\n 1. Insert");
	 printf("\n 2. Delete");
	 printf("\n 3. Display");
	 printf("\n 4. Exit");
	 printf("\n Enter your choice: ");
	 ch=getche();
      switch(ch)
      {
	 case '1':
	    printf("\n How Many Element To Insert: ");
	    scanf("%d",&tot);
	    if (tot>MAX-2)
	    {
	    printf("\nYou can only enter %d numbers!!",MAX-2);
	    break;
	    }
	    for(i=0;i<tot;i++)
	    {
	       printf("\n Enter the number to Insert:- ");
	       scanf("%d",&num);
	       Insert(&Que,num);
	    }
	    printf("\n Inserted . . .");
	    getch();
	    break;
	 case '2':
	    printf("\n How Many Element To Delete:");
	    scanf("%d",&tot);
	    for(i=0;i<tot;i++)
	    {
	       Delete(&Que);
	    }
	    getch();
	    break;
	 case '3':
	    DISPLAY(Que);
	    break;
	 case '4':
	    printf("\n Exiting . . .");
	    getch();
	    exit(0);
	 default:
	    break;
	}
      }
   }

   void Insert(struct Queue *Q,int val)
   {
      if(Q->st[1]>=MAX+1)
      {
	 printf("\n Queue is Full!!");
	 getch();
	 return;
      }
      Q->st[Q->st[1]]=val;
      Q->st[1]=Q->st[1]+1;
   }

   void Delete(struct Queue *Q)
   {
      if(Q->st[0]==Q->st[1])
      {
	 printf("\nQueue is empty!!");
	 getch();
	 return;
      }
      printf("\nThe deleted element is %d",Q->st[0]);
      Q->st[0]=Q->st[0]+1;
   }

   void DISPLAY(struct Queue Q)
   {
      int gd=DETECT,gm,i;
      int j=400;
      char str[10];
      if(Q.st[0]>=Q.st[1])
      {
	 printf("Queue is empty!!");
	 getch();
	 return;
      }

      initgraph(&gd,&gm,"c:\\turboc3\\bgi");

      setbkcolor(BLACK);
      outtextxy(20,20," Press Any Key...");
      getch();

      setfillstyle(10,7);
      for(i=2;i<MAX;i++)
      {
	 setcolor(CYAN);
	 bar(200,j,400,j-20);
	 rectangle(200,j,400,j-20);
	 j=j-20;
      }
      j=400;
      for(i=2;i<Q.st[0];i++)
      {
	 setcolor(BLUE);
	 rectangle(200,j,400,j-20);
	 j=j-20;
      }
      setfillstyle(1,BLUE);
      for (i=Q.st[0];i<Q.st[1];i++)
      {
	 setcolor(RED);
	 delay(200);
	 bar(200,j,400,j-20);
	 rectangle(200,j,400,j-20);
	 sprintf(str,"%d",Q.st[i]);
	 setcolor(4);
	 outtextxy(280,j-10,str);
	 j=j-20;
      }
      j=390;
      for(i=2;i<Q.st[0];i++)
	 j=j-20;
      outtextxy(135,j,"Front->");
      j=390;
      for(i=3;i<Q.st[1];i++)
	 j=j-20;
      outtextxy(410,j,"<-Rear");
      getch();
      restorecrtmode();
   }
