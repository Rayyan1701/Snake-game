#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
bool gameover=false;
int score;
int fruit=0;
int fruitX=15,fruitY=15;
int size=0;
char ch;

class snake_element
{   public:
	string snake_part;
	int snakeX;
	int snakeY;
	
	
	
	
	void board();
	void display()
	{
		for(int k=0; k<=size; k++)
		{
		for(int i=0; i<=25;i++)
	   {
		for(int j=0;j<=60;j++)
		{
			
			if(i==this[k].snakeX&&j==this[k].snakeY)
			{cout<<this[k].snake_part;}
			
			
		}
		
	   }
   }
	}
	void moveleft()
	{
		
		for(int i=size;i>=1;i--)
		{
			
			this[i]=this[i-1];
		}
		snakeX=(snakeX-1);
	}
	void moveright()
	{
		for(int i=size;i>=1;i--)
		{
			
			this[i]=this[i-1];
		}
		snakeX=(snakeX+1);
	}
	void movedown()
	{
		for(int i=size;i>=1;i--)
		{
			
			this[i]=this[i-1];
		}
		snakeY=(snakeY+1);
	}
	void moveup()
	{
		for(int i=size;i>=1;i--)
		{
			
			this[i]=this[i-1];
		}
		snakeY--;
	}
	void addtail()
	{
		if(size==0)
		{
			
			if(ch=='a')
			{cout<<"a"<<endl;this[size+1].snakeX=this[size].snakeX; this[size+1].snakeY=(this[size].snakeY); size++;}
			else if(ch=='s')
			{cout<<"s"<<endl;this[size+1].snakeX=this[size].snakeX; this[size+1].snakeY=(this[size].snakeY); size++; }
			else if(ch=='d')
			{cout<<"d"<<endl;this[size+1].snakeX=this[size].snakeX; this[size+1].snakeY=(this[size].snakeY); size++;}
			else if(ch=='w')
			{cout<<"w"<<endl;this[size+1].snakeX=this[size].snakeX; this[size+1].snakeY=(this[size].snakeY); size++;}
				
		}
		else if(size>=1&&size<=10)
		{
			if(this[size-1].snakeX==this[size].snakeX-1)
			{
				this[size+1].snakeX=this[size].snakeX+1;
				this[size+1].snakeY=this[size].snakeY;
				size++;
			}
			else if(this[size-1].snakeX==this[size].snakeX+1)
			{
				this[size+1].snakeX=this[size].snakeX-1;
				this[size+1].snakeY=this[size].snakeY;
				size++;
			}
			else if(this[size-1].snakeY==this[size].snakeY+1)
			{
				this[size+1].snakeY=this[size].snakeY;
				this[size+1].snakeX=this[size].snakeX-1;
				size++;
			}
			else if(this[size-1].snakeY==this[size].snakeY-1)
			{
				this[size+1].snakeY=this[size].snakeY;
				this[size+1].snakeX=this[size].snakeX+1;
				size++;
			}
		}
	}
	
	snake_element operator=(const snake_element &obj)
	{
		
		this->snakeX=obj.snakeX;
		this->snakeY=obj.snakeY;
		return *this;
	}
	
	
	bool snake_exist(int i,int j)
	{
		for(int k=0;k<=size;k++)
				{
					if(this[k].snakeX==j&&this[k].snakeY==i)
					{
						return true;
						
					}
				}
	  return false;
	}
	
	
	
	
	
};
void snake_element:: board()
{
	
	
	
	
	for(int i=0; i<=25;i++)
	{
		for(int j=0;j<=60;j++)
		{
			if(i==0||i==1||i==24||i==25)
			{
				cout<<"#";
			}
			else if(j==0||j==1||j==59||j==60)
			{
				cout<<"#";
			}
			else if(this->snake_exist(i,j))
			{
				cout<<snake_part;
				for(int k=0;k<size;k++)
				{
					if(this[k].snakeX==i&&this[k].snakeY==j)
					{
						cout<<this[k].snake_part;
						
					}
				}
			}
			
				
			
			else if(i==fruitY&&j==fruitX)
			{
				cout<<fruit;
			}
			else if(snakeX==fruitX&&snakeY==fruitY)
			{
				fruitX=rand()%55;
	            fruitY=rand()%23;
	            this->addtail();
	           
	            score+=10;
	            
			}
			
			else{
				cout<<" ";
			}
			
		}
		cout<<endl;
	}
	 if(snakeY==24||snakeY==1||snakeX==1||snakeX==59)
			{
				gameover=true;
			}
	    
		
}

 
int main()
{
	snake_element s[10];
	s[0].snakeX=3;s[0].snakeY=3;
	cout<<"START GAME"<<endl;
	
	for(int i=0;i<10;i++)
	{
	s[i].snake_part='0';
	
    }


	
	
	while(!gameover)
	{
		
		cout<<"Score = "<<score<<endl;
		s[0].board();
		ch=getch();
		if(ch=='a')
		{ s[0].moveleft(); }
		else if(ch=='s')
		{ s[0].movedown(); }
		else if(ch=='d')
		{ s[0].moveright(); }
		else if(ch=='w')
		{ s[0].moveup(); }
		
		system("cls");
	}
	cout<<"Score = "<<score<<endl;
	cout<<"GAME OVER!!!"<<endl;
	
	
	
	
	
}
