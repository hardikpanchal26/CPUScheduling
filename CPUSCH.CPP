#include<iostream.h>
#include<string.h>
#include<conio.h>

int at[5], bt[5],pr[5],ct[5],wt[5],tt[5],exe[5];
char s[100];

void front();
void interface();
void print_data();
void nullify();

void fcfs();
void sjf();
void rr();
void priority();


int RR=0;
int filled=0;

void front()
{  gotoxy(19,10); textcolor(2);
   cprintf("IMPLEMENTATION OF CPU SCHEDULING ALGORITHMS");
   gotoxy(27,12); textcolor(9);
   cprintf("Developed by HARDIK PANCHAL");
   gotoxy(65,23); textcolor(7);
   cprintf("Press any key"); getch(); clrscr();
}

void interface()
{  gotoxy(19,2); textcolor(2);
   cprintf("IMPLEMENTATION OF CPU SCHEDULING ALGORITHMS");
   gotoxy(19,4); textcolor(5);
   cprintf("Data table :-");
   gotoxy(19,6); textcolor(9);
   cprintf("PROCESS  ARRIVAL_TIME  BURST_TIME  PRIORITY");
   char a='A';
   for(int i=0; i<5; i++)
   { textcolor(9); gotoxy(19,i+8);
     cprintf("[     ]  [          ]  [        ]  [      ]");
     textcolor(4);
     gotoxy(22,i+8); cprintf("%c",a++);
     gotoxy(33,i+8); cprintf("   ");
     gotoxy(46,i+8); cprintf("   ");
     gotoxy(57,i+8); cprintf("   ");
   }
   textcolor(4);
   for(i=0; i<5; i++)
   { gotoxy(33,i+8); if(filled==0) cin>>at[i]; else cout<<at[i];
     gotoxy(46,i+8); if(filled==0) cin>>bt[i]; else cout<<bt[i];
     gotoxy(57,i+8); if(filled==0) cin>>pr[i]; else cout<<pr[i];
   }
   filled=1;
   textcolor(2);
   gotoxy(19,15);
   cprintf("CPU Scheduling Algorithms");
   textcolor(6);
   cprintf("\n\n\r                  1. First Come First Served (FCFS)");
   cprintf("\n\r                  2. Shortest Job First (SJF) Non-Preemptive");
   cprintf("\n\r                  3. Round Robin (RR)");
   cprintf("\n\r                  4. Priority Algorithm Non-Preemptive");
   cprintf("\n\r                  5. EXIT");
   textcolor(7);
   cprintf("\n\n\r                  Enter your choice :     ");
   gotoxy(39,23); cprintf("   "); gotoxy(39,23);
}

void fcfs()
{  strcpy(s,"FIRST COME FIRST SERVED (FCFS)");

    int sum;
    ct[0]=at[0]+bt[0]; sum=ct[0];
    for(int i=0; i<5; i++)
   { exe[i]=i;
     if(i!=0)
     {sum+=bt[i];
      ct[i]=sum;
     }

     wt[i]=ct[i]-bt[i]-at[i];
     tt[i]=bt[i]+wt[i];
    }

   print_data();
}

void sjf()
{
  strcpy(s,"SHORTEST JOB FIRST (SJF) NON-PREEMPTIVE");
  int f[5],bt_copy[5],at_copy[5];
  int i,j;
  for(i=0; i<5; i++) {bt_copy[i]=bt[i]; at_copy[i]=at[i];}
  int time=at[0];

  for(i=0; i<5; i++)
  {int min=99,mindex;
  for(j=0; j<5; j++)
  { if(at_copy[j]<=time && at_copy[j]!=-1)
    {  if(bt_copy[j]<min)
       {  min=bt_copy[j]; mindex=j;
       }
    }
  } time+=bt_copy[mindex]; bt_copy[mindex]=99;
    at_copy[mindex]=-1; f[i]=mindex;
  }


 int sum;
 ct[0]=at[f[0]]+bt[f[0]]; sum=ct[0];
 for(i=0; i<5; i++)
 { exe[i]=f[i];
   if(i!=0)
   {sum+=bt[f[i]];
    ct[i]=sum;
   }
   wt[i]=ct[i]-bt[f[i]]-at[f[i]];
   tt[i]=bt[f[i]]+wt[i];
 }
 print_data();
}

void priority()
{
  strcpy(s,"PRIORITY ALGORITHM NON-PREEMPTIVE");
  int f[5],pr_copy[5],at_copy[5];
  int i,j;
  for(i=0; i<5; i++) {pr_copy[i]=pr[i]; at_copy[i]=at[i];}
  int time=at[0];

  for(i=0; i<5; i++)
  {int min=99,mindex;
  for(j=0; j<5; j++)
  { if(at_copy[j]<=time && at_copy[j]!=-1)
    {  if(pr_copy[j]<min)
       {  min=pr_copy[j]; mindex=j;
       }
    }
  } time+=bt[mindex]; pr_copy[mindex]=99; at_copy[mindex]=-1; f[i]=mindex;
  }
 int sum;
 ct[0]=at[f[0]]+bt[f[0]]; sum=ct[0];
 for(i=0; i<5; i++)
 { exe[i]=f[i];
   if(i!=0)
   {sum+=bt[f[i]];
    ct[i]+=sum;
   }
   wt[i]=ct[i]-bt[f[i]]-at[f[i]];
   tt[i]=bt[f[i]]+wt[i];
 }
 print_data();
}

void rr()
{ int n; RR=1;
  gotoxy(19,24); cprintf("Enter value of quantum : ");
  cin>>n;
  clrscr();
  textcolor(2);
  strcpy(s,"     ROUND ROBIN ALGORITHM (RR)");
  int bbt[5],bsum=0;
  int count[5]={0,0,0,0,0};
  for(int i=0; i<5; i++)
  { bbt[i]=bt[i]; bsum+=bt[i];
    exe[i]=i;
  }
  int time=at[0],x=0;
  while(bsum>0)
  for(i=0; i<5; i++)
  {  if(at[i]<=time)
     {
       if(bbt[i]>n)
       { gotoxy(x*3+3,6); cprintf("³ %c",i+65);
	 bsum-=n; bbt[i]-=n;
	 count[i]++; time+=n;
	 gotoxy(x*3+6,7); cprintf("%d",time);  x++;
       }
       else if(bbt[i]>0)
       { gotoxy(x*3+3,6); cprintf("³ %c",i+65);
	 bsum-=bbt[i];
	 wt[i]=time-(count[i]*n)-at[i];
	 time+=bbt[i]; bbt[i]=0;
	 gotoxy(x*3+6,7); cprintf("%d",time);  x++;
	 ct[i]=time; tt[i]=wt[i]+bt[i];
       }
     }
  }
  gotoxy(3,7); cprintf("%d",at[0]);
  gotoxy(x*3+3,6); cprintf("³");
  print_data();
}

void print_data()
{  if(RR==0)
   {clrscr();
    textcolor(2);
   gotoxy(3,7); cprintf("%d ",at[0]);

    for(int i=0; i<5; i++)
   {
   gotoxy(i*3+3,6); cprintf("³ %c",exe[i]+65);
   gotoxy(i*3+6,7); cprintf("%d ",ct[i]);
   }
   gotoxy(18,6); cprintf("³");
   }
   RR=0;
   gotoxy(23,2); textcolor(2);
   cprintf("%s",s);

   gotoxy(3,5); textcolor(4);
   cprintf("Grantt Chart");

   gotoxy(3,9); textcolor(9);
   cprintf("PROCESS  ARRIVAL_TIME  CUMMULATIVE  BURST_TIME  PRIORITY  WAIT_TIME  TA_TIME");
   char a='A';
   for(int i=0; i<5; i++)
   { textcolor(9);
   gotoxy(3,i+11);
   cprintf("[     ]  [          ]  [         ]  [        ]  [      ]  [       ]  [     ]");
   textcolor(4);
   gotoxy(6,i+11); cprintf("%c",a++);
   gotoxy(16,i+11); cprintf("   ");
   textcolor(2);
   gotoxy(30,i+11); cprintf("   ");
   textcolor(4);
   gotoxy(43,i+11); cprintf("   ");
   gotoxy(54,i+11); cprintf("   ");
   textcolor(2);
   gotoxy(64,i+11); cprintf("   ");
   gotoxy(74,i+11); cprintf("   ");
   }
   textcolor(4);
   int wtime=0,ttime=0;
   for(i=0; i<5; i++)
   { wtime+=wt[i];
     ttime+=tt[i];
     gotoxy(17,i+11); cout<<at[i];
     gotoxy(30,exe[i]+11); cout<<ct[i];
     gotoxy(43,i+11); cout<<bt[i];
     gotoxy(54,i+11); cout<<pr[i];
     gotoxy(64,exe[i]+11); cout<<wt[i];
     gotoxy(74,exe[i]+11); cout<<tt[i];

   }
   gotoxy(3,18); textcolor(7);
   cprintf("Waiting Time            : %d",wtime);
   gotoxy(3,19);
   cprintf("Average Waiting Time    : %.2f",float(wtime)/5);
   gotoxy(3,20);
   cprintf("Turnaround Time         : %d",ttime);
   gotoxy(3,21);
   cprintf("Average Turnaround Time : %.2f ",float(ttime)/5);
   gotoxy(34,21);
   nullify();
   getch();
}

void nullify()
{ for(int i=0; i<5; i++)
  {exe[i]=0; ct[i]=0; wt[i]=0; tt[i]=0;}
}

void main()
{
   int choice;
   clrscr();
   front();
   menu:
   clrscr();
   interface();
   cin>>choice;
   switch(choice)
   { case 1 : fcfs(); goto menu;
     case 2 : sjf(); goto menu;
     case 3 : rr(); goto menu;
     case 4 : priority(); goto menu;
     case 5 : break;
   }

}
