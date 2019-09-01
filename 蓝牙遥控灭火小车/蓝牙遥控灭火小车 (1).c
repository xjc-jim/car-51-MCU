#include<reg52.h>
sbit out=P0^0;
sbit q=P1^0;
sbit m=P1^1;
sbit y=P1^2;
sbit t=P1^3;
int l,k=17000;
void delay(int f);
void main()
{
TMOD=0x20;
TH1=0xfd;
TL1=0xfd;
TR1=1;
SM0=0;
SM1=1;
REN=1;
while(1)
{
	while(1)
	 {
	  if(RI==1)
	  {	 
	  RI=0;
	  if(SBUF==0x39)
	  {
	  y=1;
	  t=0;
	  }
	  if(SBUF==0x53)
	  {
	  y=1;
	  t=1;
	  }

	   if(SBUF==0x36)
  {
	  	
       while(1)
    {
	  l--;
	  k++;
      q=1;
      m=0;
	  if(k>=17000) 
	  {
	  q=1;
	  m=1;
	  break;
	  }
	  
	   if(SBUF==0x38)
	  {
	   RI=0;
	   break;
	  }
	}

   }
	  
	  if(SBUF==0x37)
	  {
       
       	 while(1)
     {
	   l++;
	   k--;
       q=0;
       m=1;
	   if(l>=17000) 
	   {
	   q=1;
	   m=1;
	   break;
	   }
	   
	   if(SBUF==0x38)
       {  	   
	   RI=0;
	   break;
	   	 }
	  }	 

	   
      }
	  
     if(SBUF==0x38)
    {
      q=0;
      m=0;
    }



	   if(SBUF==0x31)
	   {
	   P1=0xff;
		 }

	   if(SBUF==0x32)
	   {
	   P1=0x5f;
			}

	   	if(SBUF==0x33)
	  	{
		P1=0xaf;
		}

		if(SBUF==0x34)
		{
		P1=0x6f;
		}

		if(SBUF==0x35)
		{
		P1=0x9f;
		}
	 	
		
	   }
	   	if(out==0) 
	   {
	   P1=0xff;
	   break;
	    }  
	 }
	
	 	while(1)
	 {

	  if(RI==1)
	  {
	   if(SBUF==0x31)
	   {
	   P1=0xff;
		 }

	   if(SBUF==0x32)
	   {
	   P1=0x5f;
			}

	   	if(SBUF==0x33)
	  	{
		P1=0xaf;
		}

		if(SBUF==0x34)
		{
		P1=0x6f;
		}

		if(SBUF==0x35)
		{
		P1=0x9f;
		}
	 	RI=0;
		  
	   }
	   if(out==1) 
	   {
	   break;
	   }	  
	 }
   }
}

