#include<iostream.h>
#include<conio.h>
#include<Ctype.h>
#include<process.h>
struct cell
{int flag;
 int f2;
};
struct octet
{ int pos[8][2];
};
struct quadrant
{int pos[4][2];
int ex;
};
struct dual
{int pos[2][2];
int ex;
};
struct solo
{int pos[2];
};
octet A[10];
int g=0;
quadrant B[10];
int bcheck=0;
dual C[10];
int y=0;
solo D[10];
int z=0;
void makemap(int sop[16],cell kmap[4][4],int n)
{for(int i=0;i<n;i++)
 {int x=sop[i]/4;
  if(sop[i]%4==0)
   kmap[x][0].flag=1;
  if(sop[i]%4==1)
   kmap[x][1].flag=1;
  if(sop[i]%4==2)
   kmap[x][3].flag=1;
  if(sop[i]%4==3)
   kmap[x][2].flag=1;
 }
 int temp;
 for(int j=0;j<4;j++)
 {temp=kmap[3][j].flag;
  kmap[3][j].flag=kmap[2][j].flag;
  kmap[2][j].flag=temp;
 }
}
int readmap(int i, int j)
{int minterm;
 if(i<2)
 {if(j<2)
   minterm=4*i+j;
  else
  {if(j==2)
    minterm=4*i+3;
   else
    minterm=4*i+2;
  }
 }
 else if(i==2)
 {if(j<2)
   minterm=12+j;
  else
  {if(j==2)
    minterm=15;
   else
    minterm=14;
  }
 }
 else
 {if(j<2)
   minterm=8+j;
  else
  {if(j==2)
    minterm=11;
   else
    minterm=10;
  }
 }  
 return minterm;
}
void change(cell kmap[4][4])
{for(int i=0;i<4;i++)
  for(int j=0;j<4;j++)
  {if(kmap[i][j].flag==0)
    kmap[i][j].flag=1;
   else
    kmap[i][j].flag=0;
  }
}
void oct(cell kmap[4][4])
{int i,j,k;
 for(i=0;i<3;i++)
   if((kmap[i][0].flag==1)&&(kmap[i][0].f2==0))
    {
     for(k=1;k<4;k++)
     {if(kmap[i][k].flag!=1)
	break;
     }
      if(k==4)
      {for(k=0;k<4;k++)
       {if(kmap[i+1][k].flag!=1)
	 break;
       }
       if(k==4)
       {for(int l=i;l<=i+1;l++)
	  for(int m=0;m<4;m++)
	  {A[g].pos[m+4*(l-i)][0]=l;
	   A[g].pos[m+4*(l-i)][1]=m;
	   kmap[l][m].f2++;
	  }
	 g++;
	}
       }
      }


 //end of row
 for(i=0;i<3;i++)
  if((kmap[0][i].flag==1)&&(kmap[0][i].f2==0))
    {
     for(k=1;k<4;k++)
     {if(kmap[k][i].flag!=1)
	break;
     }
      if(k==4)
      {for(k=0;k<4;k++)
       {if(kmap[k][i+1].flag!=1)
	 break;
       }
       if(k==4)
       {for(int l=i;l<=i+1;l++)
	  for(int m=0;m<4;m++)
	  {A[g].pos[m+4*(l-i)][0]=m;
	   A[g].pos[m+4*(l-i)][1]=l;
	   kmap[m][l].f2++;
	  }
	 g++;
	}
       }
      }
      //end of column
 for(k=0;k<4;k++)
 {if((kmap[0][k].flag!=1)||(kmap[0][k].f2!=0))
   break;
 }
 if(k==4)
 {for(k=0;k<4;k++)
  {if(kmap[3][k].flag!=1)
    break;
  }
  if(k==4)
  {for(int l=0;l<2;l++)
     for(int m=0;m<4;m++)
     {A[g].pos[m+4*l][0]=3*l;
      A[g].pos[m+4*l][1]=m;
      kmap[3*l][m].f2++;
     }
    g++;
   }
  }

 //end of top bottom row check
 for(k=0;k<4;k++)
 {if((kmap[k][0].flag!=1)||(kmap[k][0].f2!=0))
   break;
 }
 if(k==4)
 {for(k=0;k<4;k++)
  {if(kmap[k][3].flag!=1)
    break;
  }
  if(k==4)
  {for(int l=0;l<2;l++)
     for(int m=0;m<4;m++)
     {A[g].pos[m+4*l][0]=m;
      A[g].pos[m+4*l][1]=l*3;
      kmap[m][l*3].f2++;
     }
    g++;
   }
  }


 for(i=0;i<3;i++)
   if(kmap[i][0].flag==1)
    {for(k=1;k<4;k++)
     {if(kmap[i][k].flag!=1)
	break;
     }
      if(k==4)
      {for(k=0;k<4;k++)
       {if(kmap[i+1][k].flag!=1)
	 break;
       }
       if(k==4)
       {int ch=0;
	for(int l=i;l<=i+1;l++)
	 for(int m=0;m<4;m++)
	 {if(kmap[l][m].f2!=0)
	   continue;
	  ch=1;
	 }
	if(ch==1)
	{for(int l=i;l<=i+1;l++)
	  for(int m=0;m<4;m++)
	  {A[g].pos[m+4*(l-i)][0]=l;
	   A[g].pos[m+4*(l-i)][1]=m;
	   kmap[l][m].f2++;
	  }
	 g++;
	}
       }
      }
     }
 //end of row
 for(i=0;i<3;i++)
  if(kmap[0][i].flag==1)
    {for(k=1;k<4;k++)
     {if(kmap[k][i].flag!=1)
	break;
     }
      if(k==4)
      {for(k=0;k<4;k++)
       {if(kmap[k][i+1].flag!=1)
	 break;
       }
       if(k==4)
       {int ch=0;
	for(int l=i;l<=i+1;l++)
	 for(int m=0;m<4;m++)
	 {if(kmap[m][l].f2!=0)
	   continue;
	  ch=1;
	 }
	if(ch==1)
	{for(int l=i;l<=i+1;l++)
	  for(int m=0;m<4;m++)
	  {A[g].pos[m+4*(l-i)][0]=m;
	   A[g].pos[m+4*(l-i)][1]=l;
	   kmap[m][l].f2++;
	  }
	 g++;
	}
       }
      }
     }
 //end of column
 for(k=0;k<4;k++)
 {if(kmap[0][k].flag!=1)
   break;
 }
 if(k==4)
 {for(k=0;k<4;k++)
  {if(kmap[3][k].flag!=1)
    break;
  }
  if(k==4)
  {int ch=0;
   for(int l=0;l<2;l++)
    for(int m=0;m<4;m++)
    {if(kmap[l*3][m].f2!=0)
      continue;
     ch=1;
    }
   if(ch==1)
   {for(int l=0;l<2;l++)
     for(int m=0;m<4;m++)
     {A[g].pos[m+4*l][0]=3*l;
      A[g].pos[m+4*l][1]=m;
      kmap[3*l][m].f2++;
     }
    g++;
   }
  }
 }
 //end of top bottom row check
 for(k=0;k<4;k++)
 {if(kmap[k][0].flag!=1)
   break;
 }
 if(k==4)
 {for(k=0;k<4;k++)
  {if(kmap[k][3].flag!=1)
    break;
  }
  if(k==4)
  {int ch=0;
   for(int l=0;l<2;l++)
    for(int m=0;m<4;m++)
    {if(kmap[m][l*3].f2!=0)
      continue;
     ch=1;
    }
   if(ch==1)
   {for(int l=0;l<2;l++)
     for(int m=0;m<4;m++)
     {A[g].pos[m+4*l][0]=m;
      A[g].pos[m+4*l][1]=l*3;
      kmap[m][l*3].f2++;
     }
    g++;
   }
  }
 }
 //end of left right column check

}
void quadrant(cell kmap[4][4])
 {int k,d,gg,f;
  for(int i=0;i<4;i++)   //checks for rows
   {
    if(kmap[i][0].flag==1)
     if(kmap[i][0].f2==0)
      {
       for(k=0;k<4;k++)
	{if((kmap[i][k].flag!=1)||(kmap[i][k].f2!=0))
	  break;
	}
       if(k==4)
	{
	 for(int q=0;q<4;q++)
	  {B[bcheck].pos[q][0]=i;
	   B[bcheck].pos[q][1]=q;
	   kmap[i][q].f2++;
	  }
	 bcheck++;
	}
      }
    }

  for(i=0;i<3;i++)
   {f=0;
    if(kmap[i][0].flag==1)
     if(kmap[i][0].f2==0)              //checks for overlapping from the sides
      {for(int h=i;h<i+2;h++)
	{if((kmap[h][0].flag==1)&&(kmap[h][3].flag==1))
	  if((kmap[h][0].f2==0)&&(kmap[h][3].f2==0))
	   f++;
	}
       if(f==2)
	{int m=0,n=0;
	 for(int q=0;q<4;q++)
	  {if(q%2==0)
	    m=3;
	   else
	    m=0;
	   if(q>1)
	    n=1;
	   B[bcheck].pos[q][0]=i+n;
	   B[bcheck].pos[q][1]=m;
	   kmap[i+n][m].f2++;
	  }
	 bcheck++;
	}
      }                          //end of row checking
   }

  for(i=0;i<4;i++)       //checks for columns
   {if(kmap[0][i].flag==1)
     if(kmap[0][i].f2==0)
      {
       for(k=0;k<4;k++)
	{if((kmap[k][i].flag!=1)||(kmap[k][i].f2!=0))
	  break;
	}
       if(k==4)
	{
	 for(int q=0;q<4;q++)
	  {B[bcheck].pos[q][0]=q;
	   B[bcheck].pos[q][1]=i;
	   kmap[q][i].f2++;
	  }
	 bcheck++;
	}
      }
   }
  for(i=0;i<3;i++)
   {
    f=0;
    for(int h=i;h<i+2;h++)
     {
      if((kmap[0][h].flag==1)&&(kmap[3][h].flag==1))
      if((kmap[0][h].f2==0)&&(kmap[3][h].f2==0))
       f++;
     }
    if(f==2)
     {int m=0,n=0;
      for(int q=0;q<4;q++)
       {if(q%2==0)
	 m=3;
	else
	 m=0;
	if(q>1)
	 n=1;
	B[bcheck].pos[q][0]=m;
	B[bcheck].pos[q][1]=i+n;
	kmap[m][i+n].f2++;                //q,i
       }
      bcheck++;
     }
   }                                                //end of column checking

  for(i=0;i<3;i++)
    for(int j=0;j<3;j++)
      {if((kmap[i][j].flag==1)&&(kmap[i][j].f2==0))
	{int a=0,b=0,m=0;
	 for(int q=0;q<4;q++)
	  {if(q%2==1)
	    a=1;
	   else
	    a=0;
	   if(q>1)
	    b=1;
	   if((kmap[i+b][j+a].flag==1)&&(kmap[i+b][j+a].f2==0))
	    m++;
	  }
	 if(m==4)
	  {a=0;b=0;
	   for(q=0;q<4;q++)
	    {if(q%2==1)
	      a=1;
	     else
	      a=0;
	     if(q>1)
	      b=1;
	     B[bcheck].pos[q][0]=i+b;
	     B[bcheck].pos[q][1]=j+a;
	     kmap[i+b][j+a].f2++;
	    }
	   bcheck++;
	  }
	}
    }
  int qwe=0,fgh=0;
  for(int e=0;e<4;e++)
   {if((e==1)||(e==3))
     qwe=3;
    else
     qwe=0;
    if(e>1)
     fgh=3;
    if((kmap[qwe][fgh].flag!=1)||(kmap[qwe][fgh].f2!=0))
     break;
   }
  if(e==4)
   {qwe=0;
    fgh=0;
    for(int o=0;o<4;o++)
     {if(o%2==1)
       qwe=3;
      else
       qwe=0;
      if(o>1)
       fgh=3;
      B[bcheck].pos[o][0]=qwe;
      B[bcheck].pos[o][1]=fgh;
      kmap[qwe][fgh].f2++;
     }
    bcheck++;
   }				       //end of checking round 1

  for(i=0,gg=0;i<4;i++)   //checks for rows
   {
    if(kmap[i][0].flag==1)
     {for(k=0;k<4;k++)
       {if(kmap[i][k].flag!=1)
	 break;
       }
      for(d=0;d<4;d++)
       {if(kmap[i][d].f2==0)
	 gg++;
       }
      if((k==4)&&(gg>0))
       {
	for(int q=0;q<4;q++)
	 {B[bcheck].pos[q][0]=i;
	  B[bcheck].pos[q][1]=q;
	  kmap[i][q].f2++;
	 }
	bcheck++;
       }
     }
   }
  for(i=0;i<3;i++)
   {f=0;
    gg=0;                   //checks for overlapping from the sides
    for(int h=i;h<i+2;h++)
     {if((kmap[h][0].flag==1)&&(kmap[h][3].flag==1))
       {
	f++;
	if((kmap[h][0].f2==0)||(kmap[h][3].f2==0))
	 gg++;
       }
     }
    if((f==2)&&(gg>0))
     {
      int m=0,n=0;
      for(int q=0;q<4;q++)
       {
	if(q%2==0)
	 m=3;
	else
	 m=0;
	if(q>1)
	 n=1;
	B[bcheck].pos[q][0]=i+n;
	B[bcheck].pos[q][1]=m;
	kmap[i+n][m].f2++;
       }
       bcheck++;
     }
			      //end of row checking
   }
  for(i=0,gg=0;i<4;i++)       //checks for columns
   {if(kmap[0][i].flag==1)
     {for(k=0;k<4;k++)
       {if(kmap[k][i].flag!=1)
	 break;
       }
      for(d=0;d<4;d++)
       {if(kmap[d][i].f2==0)
	 gg++;
       }
      if((k==4)&&(gg>0))
       {
	for(int q=0;q<4;q++)
	 {B[bcheck].pos[q][0]=q;
	  B[bcheck].pos[q][1]=i;
	  kmap[q][i].f2++;
	 }
	bcheck++;
       }
     }
   }
  for(i=0;i<3;i++)
   {f=0;
    gg=0;
    for(int h=i;h<i+2;h++)
     {if((kmap[0][h].flag==1)&&(kmap[3][h].flag==1))
       {f++;
	if((kmap[0][h].f2==0)||(kmap[3][h].f2==0))
	 gg++;
       }
     }
    if((f==2)&&(gg>0))
     {int m=0,n=0;
      for(int q=0;q<4;q++)
       {if(q%2==0)
	 m=3;
	else
	 m=0;
	if(q>1)
	 n=1;
	B[bcheck].pos[q][0]=m;
	B[bcheck].pos[q][1]=i+n;
	kmap[m][i+n].f2++;         //q,i
       }
      bcheck++;
     }
   }
				 //end of column checking
  for(i=0;i<3;i++)
   for(j=0;j<3;j++)
     {gg=0;
      if(kmap[i][j].flag==1)
       {int a=0,b=0,m=0;
	for(int q=0;q<4;q++)
	 {if(q%2==1)
	   a=1;
	  else
	   a=0;
	  if(q>1)
	   b=1;
	  if(kmap[i+b][j+a].flag==1)
	   {m++;
	    if(kmap[i+b][j+a].f2==0)
	     gg++;
	   }
	 }
	if((m==4)&&(gg>0))
	 {a=0;b=0;
	  for(q=0;q<4;q++)
	   {if(q%2==1)
	     a=1;
	    else
	     a=0;
	    if(q>1)
	     b=1;
	    B[bcheck].pos[q][0]=i+b;
	    B[bcheck].pos[q][1]=j+a;
	    kmap[i+b][j+a].f2++;
	   }
	  bcheck++;
	 }
       }
     }
  qwe=0;
  fgh=0;
  int p=0;
  for(e=0;e<4;e++)
   {if((e==1)||(e==3))
     qwe=3;
    else
     qwe=0;
    if(e>1)
     fgh=3;
    if(kmap[qwe][fgh].flag==1)
     {if(kmap[qwe][fgh].f2==0)
       p++;
     }
    else
     break;
   }
  if((p>0)&&(e==4))
   {qwe=0;
    fgh=0;
    for(int o=0;o<4;o++)
     {if(o%2==1)
       qwe=3;
      else
       qwe=0;
      if(o>1)
       fgh=3;
      B[bcheck].pos[o][0]=qwe;
      B[bcheck].pos[o][1]=fgh;
      kmap[qwe][fgh].f2++;
     }
    bcheck++;
   }
 }

void minquad(cell kmap[4][4])
{for(int i=0;i<bcheck;i++)
 {int flag=0;
  for(int j=0;j<4;j++)
  {if(kmap[B[i].pos[j][0]][B[i].pos[j][1]].f2!=1)
    continue;
   flag=1;
  }
  if(flag==0)
   {B[i].ex=0;
    for(int j=0;j<4;j++)
     kmap[B[i].pos[j][0]][B[i].pos[j][1]].f2--;
   }
  else
   B[i].ex=1;
 }
}
void duo(cell kmap[4][4])
{int i,j,k;
 for(i=0;i<4;i++)
 for(j=0;j<4;j++)
 {if((kmap[i][j].flag==1)&&(kmap[i][j].f2==0))
    {if((kmap[i][j+1].flag==1)&&(kmap[i][j+1].f2==0)&&(j<3))
     {for(int l=j;l<=j+1;l++)
      {C[y].pos[l-j][0]=i;
       C[y].pos[l-j][1]=l;
       kmap[i][l].f2++;
      }

      y++;
     }
     if((kmap[i+1][j].flag==1)&&(kmap[i+1][j].f2==0)&&(i<3))
     {for(int l=i;l<=i+1;l++)
      {C[y].pos[l-i][0]=l;
       C[y].pos[l-i][1]=j;
       kmap[l][j].f2++;
      }
      y++;
     }
     if(i==3)
      if((kmap[0][j].flag==1)&&(kmap[0][j].f2==0))
      {for(int l=i;l<=i+1;l++)
       {C[y].pos[l%3][0]=l%4;
	C[y].pos[l%3][1]=j;
	kmap[l%4][j].f2++;
       }
       y++;
      }
     if(j==3)
      if((kmap[i][0].flag==1)&&(kmap[i][0].f2==0))
      {for(int l=j;l<=j+1;l++)
       {C[y].pos[l%3][0]=i;
	C[y].pos[l%3][1]=l%4;
	kmap[i][l%4].f2++;
       }
       y++;
      }
    }
 }
 for(i=0;i<4;i++)
 for(j=0;j<4;j++)
 {if((kmap[i][j].flag==1)&&(kmap[i][j].f2==0))
   {if((kmap[i][j+1].flag==1)&&(j<3))
     {for(int l=j;l<=j+1;l++)
      {C[y].pos[l-j][0]=i;
       C[y].pos[l-j][1]=l;
       kmap[i][l].f2++;
      }
      y++;
     }
     if((kmap[i][j-1].flag==1)&&(j>0))
     {for(int l=j;l>=j-1;l--)
      {C[y].pos[j-l][0]=i;
       C[y].pos[j-l][1]=l;
       kmap[i][l].f2++;
      }
      y++;
     }
     if((kmap[i+1][j].flag==1)&&(i<3))
     {for(int l=i;l<=i+1;l++)
      {C[y].pos[l-i][0]=l;
       C[y].pos[l-i][1]=j;
       kmap[l][j].f2++;
      }
      y++;
     }
     if((kmap[i-1][j].flag==1)&&(i>0))
     {for(int l=i;l>=i-1;l--)
      {C[y].pos[i-l][0]=l;
       C[y].pos[i-l][1]=j;
       kmap[l][j].f2++;
      }
      y++;
     }
     if(i==3)
      if(kmap[0][j].flag==1)
      {for(int l=i;l<=i+1;l++)
       {C[y].pos[l%3][0]=l%4;
	C[y].pos[l%3][1]=j;
	kmap[l%4][j].f2++;
       }
       y++;
      }
      if(i==0)
      if(kmap[3][j].flag==1)
      {for(int l=i;l<=i+1;l++)
       {C[y].pos[l][0]=l*3;
	C[y].pos[l][1]=j;
	kmap[l*3][j].f2++;
       }
       y++;
      }
     if(j==3)
      if(kmap[i][0].flag==1)
      {for(int l=j;l<=j+1;l++)
       {C[y].pos[l%3][0]=i;
	C[y].pos[l%3][1]=l%4;
	kmap[i][l%4].f2++;
       }
       y++;
      }
      if(j==0)
      if(kmap[i][3].flag==1)
      {for(int l=j;l<=j+1;l++)
       {C[y].pos[l][0]=i;
	C[y].pos[l][1]=l*3;
	kmap[i][l*3].f2++;
       }
       y++;
      }
    }
 }
}
void minduo(cell kmap[4][4])
{for(int i=0;i<y;i++)
 {int flag=0;
  for(int j=0;j<2;j++)
  {if(kmap[C[i].pos[j][0]][C[i].pos[j][1]].f2!=1)
    continue;
   flag=1;
  }
  if(flag==0)
   {C[i].ex=0;
    for(int j=0;j<2;j++)
     kmap[C[i].pos[j][0]][C[i].pos[j][1]].f2--;
   }
  else
   C[i].ex=1;
 }
}
void single(cell kmap[4][4])
{for(int i=0;i<4;i++)
  for(int j=0;j<4;j++)
   {if((kmap[i][j].flag==1)&&(kmap[i][j].f2==0))
    {D[z].pos[0]=i;
     D[z].pos[1]=j;
     kmap[i][j].f2++;
     z++;
    }
   }
}

char final[100];
int fct=0;
void octconvert()
{int a,b,j;
 for(int i=0;i<g;i++)
  {int a=A[i].pos[0][0];
   int f=0;
   for(j=0;j<8;j++)
    if(A[i].pos[j][0]!=a)
    {b=A[i].pos[j][0];
     f++;
    }
   if(f==4)
   {if(((a==0)&&(b==1))||((b==0)&&(a==1)))
    {final[fct]='a';
     fct++;
    }
    if(((a==1)&&(b==2))||((b==1)&&(a==2)))
    {final[fct]='B';
     fct++;
    }
    if(((a==2)&&(b==3))||((b==2)&&(a==3)))
    {final[fct]='A';
     fct++;
    }
    if(((a==0)&&(b==3))||((b==0)&&(a==3)))
    {final[fct]='b';
     fct++;
    }
    final[fct]='+';
    fct++;
   //oct along row where a,b=row
   }
   else
   {a=A[i].pos[0][1];
    for(j=0;j<8;j++)
     if(A[i].pos[j][1]!=a)
     {b=A[i].pos[j][1];
      break;
     }
    if(((a==0)&&(b==1))||((b==0)&&(a==1)))
    {final[fct]='c';
     fct++;
    }
    if(((a==1)&&(b==2))||((b==1)&&(a==2)))
    {final[fct]='D';
     fct++;
    }
    if(((a==2)&&(b==3))||((b==2)&&(a==3)))
    {final[fct]='C';
     fct++;
    }
    if(((a==0)&&(b==3))||((b==0)&&(a==3)))
    {final[fct]='d';
     fct++;
    }
    final[fct]='+';
    fct++;
    //insert code for ot along column where a,b=col
   }
  }
}
void quadconvert()
{int a,b,c,d,j,f;
 for(int i=0;i<bcheck;i++)
  if(B[i].ex==1)
  {a=B[i].pos[0][0];
   f=0;
   for(j=0;j<4;j++)
   {if(B[i].pos[j][0]!=a)
     f++;
   }
   if(f==0)
   {if(a==0)
    {final[fct]='a';
     final[fct+1]='b';
     fct+=2;
    }
    if(a==1)
    {final[fct]='a';
     final[fct+1]='B';
     fct+=2;
    }
    if(a==2)
    {final[fct]='A';
     final[fct+1]='B';
     fct+=2;
    }
    if(a==3)
    {final[fct]='A';
     final[fct+1]='b';
     fct+=2;
    }
    final[fct]='+';
    fct++;
   //quad along row where a=row
   }
   if(f==3)
   {a=B[i].pos[0][1];
    if(a==0)
    {final[fct]='c';
     final[fct+1]='d';
     fct+=2;
    }
    if(a==1)
    {final[fct]='c';
     final[fct+1]='D';
     fct+=2;
    }
    if(a==2)
    {final[fct]='C';
     final[fct+1]='D';
     fct+=2;
    }
    if(a==3)
    {final[fct]='C';
     final[fct+1]='d';
     fct+=2;
    }
    final[fct]='+';
    fct++;
    //quad along column with a=col
   }
   if(f==2)
   {c=B[i].pos[0][1];
    for(j=0;j<4;j++)
    {if(B[i].pos[j][0]!=a)
      b=B[i].pos[j][0];
     if(B[i].pos[j][1]!=c)
      d=B[i].pos[j][1];
    }
    if(((a==0)&&(b==1))||((b==0)&&(a==1)))
    {final[fct]='a';
     fct++;
    }
    if(((a==1)&&(b==2))||((b==1)&&(a==2)))
    {final[fct]='B';
     fct++;
    }
    if(((a==2)&&(b==3))||((b==2)&&(a==3)))
    {final[fct]='A';
     fct++;
    }
    if(((a==0)&&(b==3))||((b==0)&&(a==3)))
    {final[fct]='b';
     fct++;
    }
    if(((c==0)&&(d==1))||((d==0)&&(c==1)))
    {final[fct]='c';
     fct++;
    }
    if(((c==1)&&(d==2))||((d==1)&&(c==2)))
    {final[fct]='D';
     fct++;
    }
    if(((c==2)&&(d==3))||((d==2)&&(c==3)))
    {final[fct]='C';
     fct++;
    }
    if(((c==0)&&(d==3))||((d==0)&&(c==3)))
    {final[fct]='d';
     fct++;
    }
    final[fct]='+';
    fct++;
    //quad where a,b=row and c,d=col
   }
  }
}
void duoconv()
{int a,b,c,j,f;
 for(int i=0;i<y;i++)
  if(C[i].ex==1)
  {f=0;
   a=C[i].pos[0][0];
   if(C[i].pos[1][0]!=a)
   {b=C[i].pos[1][0];
    f++;
   }
   if(f==0)
   {b=C[i].pos[0][1];
    c=C[i].pos[1][1];
    if(a==0)
    {final[fct]='a';
     final[fct+1]='b';
     fct+=2;
    }
    if(a==1)
    {final[fct]='a';
     final[fct+1]='B';
     fct+=2;
    }
    if(a==2)
    {final[fct]='A';
     final[fct+1]='B';
     fct+=2;
    }
    if(a==3)
    {final[fct]='A';
     final[fct+1]='b';
     fct+=2;
    }
    if(((b==0)&&(c==1))||((c==0)&&(b==1)))
    {final[fct]='c';
     fct++;
    }
    if(((b==1)&&(c==2))||((c==1)&&(b==2)))
    {final[fct]='D';
     fct++;
    }
    if(((b==2)&&(c==3))||((c==2)&&(b==3)))
    {final[fct]='C';
     fct++;
    }
    if(((b==0)&&(c==3))||((c==0)&&(b==3)))
    {final[fct]='d';
     fct++;
    }
    final[fct]='+';
    fct++;
    //doublet along row where a=row and b,c=col
   }
   if(f==1)
   {c=C[i].pos[0][1];
    if(((a==0)&&(b==1))||((b==0)&&(a==1)))
    {final[fct]='a';
     fct++;
    }
    if(((a==1)&&(b==2))||((b==1)&&(a==2)))
    {final[fct]='B';
     fct++;
    }
    if(((a==2)&&(b==3))||((b==2)&&(a==3)))
    {final[fct]='A';
     fct++;
    }
    if(((a==0)&&(b==3))||((b==0)&&(a==3)))
    {final[fct]='b';
     fct++;
    }
    if(c==0)
    {final[fct]='c';
     final[fct+1]='d';
     fct+=2;
    }
    if(c==1)
    {final[fct]='c';
     final[fct+1]='D';
     fct+=2;
    }
    if(c==2)
    {final[fct]='C';
     final[fct+1]='D';
     fct+=2;
    }
    if(c==3)
    {final[fct]='C';
     final[fct+1]='d';
     fct+=2;
    }
    final[fct]='+';
    fct++;
    //doublet along column where a,b=row and c=col
   }
  }
}
void soloconv()
{int a,b;
 for(int i=0;i<z;i++)
 {a=D[i].pos[0];
  b=D[i].pos[1];
   if(a==0)
    {final[fct]='a';
     final[fct+1]='b';
     fct+=2;
    }
    if(a==1)
    {final[fct]='a';
     final[fct+1]='B';
     fct+=2;
    }
    if(a==2)
    {final[fct]='A';
     final[fct+1]='B';
     fct+=2;
    }
    if(a==3)
    {final[fct]='A';
     final[fct+1]='b';
     fct+=2;
    }
    if(b==0)
    {final[fct]='c';
     final[fct+1]='d';
     fct+=2;
    }
    if(b==1)
    {final[fct]='c';
     final[fct+1]='D';
     fct+=2;
    }
    if(b==2)
    {final[fct]='C';
     final[fct+1]='D';
     fct+=2;
    }
    if(b==3)
    {final[fct]='C';
     final[fct+1]='d';
     fct+=2;
    }
    final[fct]='+';
    fct++;
  //solo where a=row and b=col
 }
}
char telloct(int i)
{int a,b,j,c;
 a=A[i].pos[0][0];
 int f=0;
 for(j=0;j<8;j++)
  if(A[i].pos[j][0]!=a)
  {b=A[i].pos[j][0];
   f++;
  }
 if(f==4)
 {if(((a==0)&&(b==1))||((b==0)&&(a==1)))
   c='a';
  if(((a==1)&&(b==2))||((b==1)&&(a==2)))
   c='B';
  if(((a==2)&&(b==3))||((b==2)&&(a==3)))
   c='A';
  if(((a==0)&&(b==3))||((b==0)&&(a==3)))
   c='b';
   //oct along row where a,b=row
 }
 else
 {a=A[i].pos[0][1];
  for(j=0;j<8;j++)
   if(A[i].pos[j][1]!=a)
   {b=A[i].pos[j][1];
    break;
   }
  if(((a==0)&&(b==1))||((b==0)&&(a==1)))
   c='c';
  if(((a==1)&&(b==2))||((b==1)&&(a==2)))
   c='D';
  if(((a==2)&&(b==3))||((b==2)&&(a==3)))
   c='C';
  if(((a==0)&&(b==3))||((b==0)&&(a==3)))
   c='d';
  //oct along column where a,b=col
 }
return c;
}
char* tellquad(int i)
{int a,b,c,d,j,f;
 char ch[2];
 a=B[i].pos[0][0];
 f=0;
 for(j=0;j<4;j++)
 {if(B[i].pos[j][0]!=a)
   f++;
 }
 if(f==0)
 {if(a==0)
  {ch[0]='a';
   ch[1]='b';
  }
  if(a==1)
  {ch[0]='a';
   ch[1]='B';
  }
  if(a==2)
  {ch[0]='A';
   ch[1]='B';
  }
  if(a==3)
  {ch[0]='A';
   ch[1]='b';
  }

 //quad along row where a=row
 }
 if(f==3)
 {a=B[i].pos[0][1];
  if(a==0)
  {ch[0]='c';
   ch[1]='d';
  }
  if(a==1)
  {ch[0]='c';
   ch[1]='D';
  }
  if(a==2)
  {ch[0]='C';
   ch[1]='D';
  }
  if(a==3)
  {ch[0]='C';
   ch[1]='d';
  }
  //quad along column with a=col
 }
 if(f==2)
 {c=B[i].pos[0][1];
  for(j=0;j<4;j++)
  {if(B[i].pos[j][0]!=a)
    b=B[i].pos[j][0];
   if(B[i].pos[j][1]!=c)
    d=B[i].pos[j][1];
  }
  if(((a==0)&&(b==1))||((b==0)&&(a==1)))
  {ch[0]='a';
  }
  if(((a==1)&&(b==2))||((b==1)&&(a==2)))
  {ch[0]='B';
  }
  if(((a==2)&&(b==3))||((b==2)&&(a==3)))
  {ch[0]='A';
  }
  if(((a==0)&&(b==3))||((b==0)&&(a==3)))
  {ch[0]='b';
  }
  if(((c==0)&&(d==1))||((d==0)&&(c==1)))
  {ch[1]='c';
  }
  if(((c==1)&&(d==2))||((d==1)&&(c==2)))
  {ch[1]='D';
  }
  if(((c==2)&&(d==3))||((d==2)&&(c==3)))
  {ch[1]='C';
  }
  if(((c==0)&&(d==3))||((d==0)&&(c==3)))
  {ch[1]='d';
  }
  //quad where a,b=row and c,d=col
 }
return ch;
}
char* tellduo(int i)
{int a,b,c,j,f;
 char ch[3];
 f=0;
 a=C[i].pos[0][0];
 if(C[i].pos[1][0]!=a)
 {b=C[i].pos[1][0];
  f++;
 }
 if(f==0)
 {b=C[i].pos[0][1];
  c=C[i].pos[1][1];
  if(a==0)
  {ch[0]='a';
   ch[1]='b';
  }
  if(a==1)
  {ch[0]='a';
   ch[1]='B';
  }
  if(a==2)
  {ch[0]='A';
   ch[1]='B';
  }
  if(a==3)
  {ch[0]='A';
   ch[1]='b';
  }
  if(((b==0)&&(c==1))||((c==0)&&(b==1)))
  {ch[2]='c';
  }
  if(((b==1)&&(c==2))||((c==1)&&(b==2)))
  {ch[2]='D';
  }
  if(((b==2)&&(c==3))||((c==2)&&(b==3)))
  {ch[2]='C';
  }
  if(((b==0)&&(c==3))||((c==0)&&(b==3)))
  {ch[2]='d';
  }
  //doublet along row where a=row and b,c=col
 }
 if(f==1)
 {c=C[i].pos[0][1];
  if(((a==0)&&(b==1))||((b==0)&&(a==1)))
  {ch[0]='a';
  }
  if(((a==1)&&(b==2))||((b==1)&&(a==2)))
  {ch[0]='B';
  }
  if(((a==2)&&(b==3))||((b==2)&&(a==3)))
  {ch[0]='A';
  }
  if(((a==0)&&(b==3))||((b==0)&&(a==3)))
  {ch[0]='b';
  }
  if(c==0)
  {ch[1]='c';
   ch[2]='d';
  }
  if(c==1)
  {ch[1]='c';
   ch[2]='D';
  }
  if(c==2)
  {ch[1]='C';
   ch[2]='D';
  }
  if(c==3)
  {ch[1]='C';
   ch[2]='d';
  }
  //doublet along column where a,b=row and c=col
 }
return ch;
}

char* tellsolo(int i)
{int a,b;
 char c[4];
 a=D[i].pos[0];
 b=D[i].pos[1];
 if(a==0)
 {c[0]='a';
  c[1]='b';
 }
 if(a==1)
 {c[0]='a';
  c[1]='B';
 }
 if(a==2)
 {c[0]='A';
  c[1]='B';
 }
 if(a==3)
 {c[0]='A';
  c[1]='b';
 }
 if(b==0)
 {c[2]='c';
  c[3]='d';
 }
 if(b==1)
 {c[2]='c';
  c[3]='D';
 }
 if(b==2)
 {c[2]='C';
  c[3]='D';
 }
 if(b==3)
 {c[2]='C';
  c[3]='d';
 }
 //solo where a=row and b=col
return c;
}
void clear(cell kmap[4][4])
{for(int i=0;i<4;i++)
  for(int j=0;j<4;j++)
  {kmap[i][j].flag=0;
   kmap[i][j].f2=0;
  }
 fct=g=bcheck=y=z=0;
}

void main()
{
 clrscr();
 cout<<"\n\n\n\n\n\n\n\n";
   cout<<"****************************\n";
 cout<<"--------------------------------------------------------------------------------\n";
 cout<<"~~~~~~~~~~~~K -  MAP~~~~~~~~~~~~~\n";
 cout<<"--------------------------------------------------------------------------------\n";
 cout<<"****************************";
 getch();
 clrscr();
 int choice=0;
 cell kmap[4][4];
 char F[10];
 int sop[16], n,i,j;
 start:
 clrscr();
 clear(kmap);
 cout<<"\n1.Enter in SOP\n2.Enter in POS\n3.Exit\nEnter Choice: ";
 cin>>choice;
 switch(choice)
 {case 1:cout<<"\nEnter no of terms in SOP: ";
	 cin>>n;
	 cout<<"\nEnter SOP terms: ";
	 for(i=0;i<n;i++)
	  cin>>sop[i];
	 makemap(sop,kmap,n);
	 break;
  case 2:cout<<"\nEnter no of terms in POS: ";
	 cin>>n;
	 cout<<"\nEnter POS terms: ";
	 for(i=0;i<n;i++)
	  cin>>sop[i];
	 makemap(sop,kmap,n);
	 change(kmap);
	 break;
  case 3:cout<<"\nThank You!";
	 exit(0);
 }
 clrscr();
 for(j=0;j<4;j++)
 {for(i=0;i<4;i++)
   cout << char(218) << char(196)<<char(196)<< char(196)<< char(191);
  cout<<endl;
  for(i=0;i<4;i++)
   cout << char(179) << char(32) <<kmap[j][i].flag<< char(32)<<char(179);
  cout<<endl;
  for(i=0;i<4;i++)
   cout << char(192) << char(196) << char(196)<<char(196)<<char(217);
  cout<<endl;
 }
 cout<<"\nChoose output format:\n1.SOP\n2.POS\nEnter Choice: ";
 cin>>choice;
 if(choice==2)
  change(kmap);
 oct(kmap);
 if(g!=0)
  cout<<"Octets:\n";
 for(int r=0;r<g;r++)
 {cout<<"(";
  for(i=0;i<8;i++)
  {cout<<"m"<<readmap(A[r].pos[i][0],A[r].pos[i][1]);
   if(i!=7)
    cout<<",";
  }
  cout<<")= ";
  if(choice==1)
  {if(telloct(r)=='a'||telloct(r)=='b'||telloct(r)=='c'||telloct(r)=='d')
    cout<<char(toupper(telloct(r)))<<"'";
   else
    cout<<telloct(r);
  }
  else
  {if(telloct(r)=='A'||telloct(r)=='B'||telloct(r)=='C'||telloct(r)=='D')
    cout<<telloct(r)<<"'";
   else
    cout<<char(toupper(telloct(r)));
  }
  cout<<"\n";
 }
 int br;
 quadrant(kmap);
 minquad(kmap);
 if(bcheck!=0)
  cout<<"\nQuadrants:\n";
 for(i=0;i<bcheck;i++)
  if(B[i].ex==1)
  {cout<<"(";
   for(j=0;j<4;j++)
   {cout<<"m"<<readmap(B[i].pos[j][0],B[i].pos[j][1]);
    if(j!=3)
     cout<<",";
   }
   cout<<")= ";
   if(choice==1)
   {for(br=0;br<2;br++)
    {if(tellquad(i)[br]=='a'||tellquad(i)[br]=='b'||tellquad(i)[br]=='c'||tellquad(i)[br]=='d')
      cout<<char(toupper(tellquad(i)[br]))<<"'";
     else
      cout<<tellquad(i)[br];
    }
   }
   else
   {for(br=0;br<2;br++)
    {if(tellquad(i)[br]=='A'||tellquad(i)[br]=='B'||tellquad(i)[br]=='C'||tellquad(i)[br]=='D')
     {cout<<tellquad(i)[br]<<"'";
      if(br!=1)
       cout<<"+";
     }
     else
     {cout<<char(toupper(tellquad(i)[br]));
      if(br!=1)
       cout<<"+";
     }
    }
   }
   cout<<"\n";
  }
 duo(kmap);
 minduo(kmap);
 if(y!=0)
  cout<<"\nDoublets:\n";
 for(r=0;r<y;r++)
  if(C[r].ex==1)
  {cout<<"(";
   for(i=0;i<2;i++)
   {cout<<"m"<<readmap(C[r].pos[i][0],C[r].pos[i][1]);
    if(i!=1)
     cout<<",";
   }
   cout<<")= ";
   if(choice==1)
   {for(br=0;br<3;br++)
    {if(tellduo(r)[br]=='a'||tellduo(r)[br]=='b'||tellduo(r)[br]=='c'||tellduo(r)[br]=='d')
      cout<<char(toupper(tellduo(r)[br]))<<"'";
     else
      cout<<tellduo(r)[br];
    }
   }
   else
   {for(br=0;br<3;br++)
    {if(tellduo(r)[br]=='A'||tellduo(r)[br]=='B'||tellduo(r)[br]=='C'||tellduo(r)[br]=='D')
     {cout<<tellduo(r)[br]<<"'";
      if(br!=2)
       cout<<"+";
     }
     else
     {cout<<char(toupper(tellduo(r)[br]));
       if(br!=2)
       cout<<"+";
     }
    }
   }
   cout<<"\n";
  }
 single(kmap);
 if(z!=0)
  cout<<"\nSingles:\n";
 for(r=0;r<z;r++)
 {cout<<"("<<"m"<<readmap(D[r].pos[0],D[r].pos[1])<<")= ";
  if(choice==1)
  {for(br=0;br<4;br++)
   {if(tellsolo(r)[br]=='a'||tellsolo(r)[br]=='b'||tellsolo(r)[br]=='c'||tellsolo(r)[br]=='d')
     cout<<char(toupper(tellsolo(r)[br]))<<"'";
    else
     cout<<tellsolo(r)[br];
   }
  }
  else
  {for(br=0;br<4;br++)
   {if(tellsolo(r)[br]=='A'||tellsolo(r)[br]=='B'||tellsolo(r)[br]=='C'||tellsolo(r)[br]=='D')
    {cout<<tellsolo(r)[br]<<"'";
     if(br!=3)
      cout<<"+";
    }
    else
    {cout<<char(toupper(tellsolo(r)[br]));
     if(br!=1)
      cout<<"+";
    }
   }
  }
  cout<<"\n";
 }
 octconvert();
 quadconvert();
 duoconv();
 soloconv();
 if(choice==1)
 {cout<<"\nSOP: ";
  for(i=0;i<fct-1;i++)
   {if(final[i]=='a'||final[i]=='b'||final[i]=='c'||final[i]=='d')
     cout<<char(toupper(final[i]))<<"'";
    else
     cout<<final[i];
   }
 }
 else
 {cout<<"\nPOS: (";
  for(i=0;i<fct-1;i++)
   {if(final[i]=='A'||final[i]=='B'||final[i]=='C'||final[i]=='D')
    {if(final[i+1]=='+')
      cout<<final[i]<<"'";
     else
      cout<<final[i]<<"'+";
    }
    else if(final[i]=='+')
     cout<<").(";
    else
    {if(final[i+1]=='+')
      cout<<char(toupper(final[i]));
     else
      cout<<char(toupper(final[i]))<<"+";
    }
   }
  cout<<")";
 }
 cout<<"\n1. Return to Menu 2. Exit: ";
 cin>>choice;
 if(choice==1)
  goto start;
 else
  cout<<"\nThank You!";
 getch();
}
