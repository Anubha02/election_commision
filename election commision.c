#include<avr/io.h>
#include<util/delay.h>
void lcdcmd(char x)
{
	
	PORTD=x;
	PORTC=0b00000100;
	_delay_ms(10);
	PORTC=0b00000000;
	_delay_ms(10);
}

void lcddata(char x)
{
	PORTD=x;
	PORTC=0b00000101;
	_delay_ms(10);
	PORTC=0b00000001;
	_delay_ms(10);
	
}
void display(char y[])
{
	int i;
	for(i=0;y[i]!='\0';i++)
	
	{
		lcddata(y[i]);
	}
}

void main()
{ int x;x=0;char a[10],b[10];int y;y=0;
	DDRA=0b00000000;
	DDRB=0b11111111;
	DDRC=0b11111111;
	DDRD=0b11111111;
		lcdcmd(0x38);
		lcdcmd(0x0E);
		t:
		PORTB=0b00000000;
		lcdcmd(0x01);
		display("WELCOME TO ELECTION 2016");
		lcdcmd(0x01);
		display("PARTY 1- BJP");
		lcdcmd(0xc1);
		display("PARTY 2-AAP");
		lcdcmd(0x01);
		display("ENTER VOTE");
		_delay_ms(2000);
		while(1)
		{
			if(PINA==0b00000001)
		{  lcdcmd(0x01);
			PORTB=0B00000001;
			
			x++;
			display("vote accepted");
			itoa(x,a,10);
			_delay_ms(2000);
			goto t;
		}
		   if(PINA==0b00000010)
		   {
			   lcdcmd(0x01);
			   PORTB=0B00000010;
			  y++;
			  display("VOTE ACCEPTED");
			   itoa(y,b,10);
			   _delay_ms(200);
			   goto t;
			
		   }
		   if(PINA==0b00000100)
		   {     
			   lcdcmd(0x01);
			   display("BJP-");
			   display(a);
			   lcdcmd(0xc0);
			   display("AAP-");
			   display(b);
			   _delay_ms(100);
			   
			   if(x>y)
			   {
				   lcdcmd(0xd0);
				   display("BJP HAS WON");
			   }
			   if(y>x)
			   {
				   lcdcmd(0xd0);
				   display("AAP HAS WON");
			   }				   
				   if(y==x)
				   {
					   lcdcmd(0xd0);
					   display("HUH A TIE");
		   
	}
}	   
		   }	
		   }