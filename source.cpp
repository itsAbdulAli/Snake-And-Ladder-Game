
//  Snakes & Ladders Games
//  Names : Muhammad Abdul Ali & Umair
//  Roll No.s: 19L-0917 & 19L-0912



#include <SFML/Graphics.hpp>
#include <stdlib.h>     
#include <time.h> 
sf::RenderWindow window(sf::VideoMode(1000, 500), "Snakes & Ladders!");
sf::RectangleShape r1;
sf::RectangleShape r2;
sf::RectangleShape r3;
sf::RectangleShape r4;
sf::RectangleShape r5;
sf::RectangleShape c1;
sf::RectangleShape c2;
sf::RectangleShape c3;
sf::RectangleShape c4;
sf::Text num;
sf::RectangleShape s1;
sf::RectangleShape sn;
sf::CircleShape p1(6);
sf::CircleShape p2(6);
sf::CircleShape snakehead(13);
	sf::Font font;
	sf::Text headtext;
	sf::Text stairs; 
	sf::Text snakes;
	sf::Text wint; 
	sf::Text enter,dicee,turntext;
	bool win=false;
	float row1[6][2]={{-30,-360},{-130,-360},{-230,-360},{-350,-360},{-470,-360},{-580,-360}};
	float row2[6][2]={{-30,-260},{-130,-260},{-230,-260},{-350,-260},{-470,-260},{-580,-260}};
	float row3[6][2]={{-30,-180},{-130,-180},{-230,-180},{-350,-180},{-470,-180},{-580,-180}};
	float row4[6][2]={{-30,-100},{-130,-100},{-230,-100},{-350,-100},{-470,-100},{-580,-100}};
	float row5[6][2]={{-30,-10},{-130,-10},{-230,-10},{-350,-10},{-470,-10},{-580,-10}};
	void position_1(int);
	void position_2(int);
	bool pause=false;
	void snakes1();
	void snakes2();
	void stares1();
	void stares2();
	int ran(int);
int turn=2;
void drawdice(int);
int dicenum=0;
int position1=0;
int position2=0;
int counter=0;
int counter2=0;
int x;
int y;
void wincheck1();
void wincheck2();
int main()
{
    font.loadFromFile("text.ttf");
       srand(time(NULL)); 
	   p1.setOutlineColor(sf::Color::Blue);
	   p1.setOutlineThickness(7);
	   p1.setFillColor(sf::Color::Transparent);
	   p2.setOutlineColor(sf::Color::Green);
	   p2.setOutlineThickness(7);
	   p2.setFillColor(sf::Color::Transparent);
   p1.setOrigin(sf::Vector2f (0,-440));
   p2.setOrigin(sf::Vector2f(-20,-440));
   font.loadFromFile("text.ttf");
   enter.setFont(font);
   enter.setCharacterSize(18);
   enter.setFillColor(sf::Color::Red);
   enter.setOrigin(sf::Vector2f(-680,-80));
   turntext.setFont(font);
   turntext.setCharacterSize(20);
   turntext.setFillColor(sf::Color::Red);
   turntext.setOrigin(sf::Vector2f(-680,-50));
   headtext.setFont(font);
   headtext.setString("Snake And Ladder Game");
   headtext.setCharacterSize(24); 
   headtext.setFillColor(sf::Color::Yellow);
   headtext.setOrigin(sf::Vector2f(-680,-20));
   stairs.setFont(font);
   stairs.setCharacterSize(20);
   stairs.setFillColor(sf::Color::Yellow);
   stairs.setOrigin(sf::Vector2f(-680,-145));
   stairs.setString("   ");
   snakes.setFont(font);
   snakes.setCharacterSize(20);
   snakes.setFillColor(sf::Color::Yellow);
   snakes.setOrigin(sf::Vector2f(-680,-145));
   snakes.setString("   ");
   
	while (window.isOpen())
    {
       window.clear();
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
       		
 		
		r1.setSize(sf::Vector2f(669, 70));
		r1.setFillColor(sf::Color::Cyan);
        r1.setOutlineThickness(0);
        r1.setOrigin(-2,-360);
		window.draw(r1);
		r2.setSize(sf::Vector2f(669, 100));
		r2.setFillColor(sf::Color::Red);
        r2.setOutlineThickness(0);
        r2.setOrigin(-2,-260);
		window.draw(r2);
		r3.setSize(sf::Vector2f(669, 80));
		r3.setFillColor(sf::Color::Cyan);
        r3.setOutlineThickness(0);
        r3.setOrigin(-2,-180);
		window.draw(r3);
        r4.setSize(sf::Vector2f(669, 90));
		r4.setFillColor(sf::Color::Red);
        r4.setOutlineThickness(0);
        r4.setOrigin(-2,-90);
		window.draw(r4);
		r5.setSize(sf::Vector2f(669, 89));
		r5.setFillColor(sf::Color::Cyan);
        r5.setOutlineThickness(0);
        r5.setOrigin(-2,-10);
		window.draw(r5);
		c1.setSize(sf::Vector2f(100, 420));
		c1.setFillColor(sf::Color::Transparent);
		c1.setOutlineColor(sf::Color::Black);
		c1.setOutlineThickness(3);
		c1.setOrigin(-90,-10);
		window.draw(c1);
		c2.setSize(sf::Vector2f(120, 420));
		c2.setFillColor(sf::Color::Transparent);
		c2.setOutlineColor(sf::Color::Black);
		c2.setOutlineThickness(3);
		c2.setOrigin(-310,-10);
		window.draw(c2);
		c3.setSize(sf::Vector2f(120, 420));
		c3.setFillColor(sf::Color::Transparent);
		c3.setOutlineColor(sf::Color::Black);
		c3.setOutlineThickness(3);
		c3.setOrigin(-551,-10);
		window.draw(c3);
		num.setFont(font);
        num.setCharacterSize(18);
		num.setFillColor(sf::Color::Black);
		num.setOrigin(sf::Vector2f(-30,-360));
		num.setString("1");
		window.draw(num);
	    num.setOrigin(sf::Vector2f(-130,-360));
		num.setString("2");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-230,-360));
		num.setString("3");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-350,-360));
		num.setString("4");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-470,-360));
		num.setString("5");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-580,-360));
		num.setString("6");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-30,-260));
		num.setString("12");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-130,-260));
		num.setString("11");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-230,-260));
		num.setString("10");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-350,-260));
		num.setString("9");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-470,-260));
		num.setString("8");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-580,-260));
		num.setString("7");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-30,-180));
		num.setString("13");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-130,-180));
		num.setString("14");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-230,-180));
		num.setString("15");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-350,-180));
		num.setString("16");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-470,-180));
		num.setString("17");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-580,-180));
		num.setString("18");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-30,-100));
		num.setString("24");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-130,-100));
		num.setString("23");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-230,-100));
		num.setString("22");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-350,-100));
		num.setString("21");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-470,-100));
		num.setString("20");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-580,-100));
		num.setString("19");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-30,-30));
		num.setString("25");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-130,-30));
		num.setString("26");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-230,-30));
		num.setString("27");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-350,-30));
		num.setString("28");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-470,-30));
		num.setString("29");
		window.draw(num);
		num.setOrigin(sf::Vector2f(-580,-30));
		num.setString("30");
		window.draw(num);
		s1.setSize(sf::Vector2f(10, 260));
		s1.setFillColor(sf::Color::Transparent);
		s1.setOutlineColor(sf::Color::Yellow);
		s1.setOutlineThickness(3);
		s1.setOrigin(-250,-120);
		window.draw(s1);
		s1.setSize(sf::Vector2f(10, 100));
		s1.setOrigin(-485,-280);
		window.draw(s1);
		s1.setSize(sf::Vector2f(10, 230));
		s1.setOrigin(-110,-70);
		window.draw(s1);
		s1.setSize(sf::Vector2f(10, 100));
		s1.setOrigin(-457,-45);
		window.draw(s1);
		sn.setSize(sf::Vector2f(10, 200));
		sn.setFillColor(sf::Color::Magenta);
		sn.setOrigin(-60,-210);
		window.draw(sn);
		sn.setSize(sf::Vector2f(240, 10));
		sn.setFillColor(sf::Color::Magenta);
		sn.setOrigin(-60,-210);
		window.draw(sn);
		sn.setSize(sf::Vector2f(10, 180));
		sn.setFillColor(sf::Color::Magenta);
		sn.setOrigin(-290,-37);
		window.draw(sn);
		sn.setSize(sf::Vector2f(10, 100));
		sn.setFillColor(sf::Color::Magenta);
		sn.setOrigin(-390,-130);
		window.draw(sn);
		sn.setSize(sf::Vector2f(-70,10));
		sn.setFillColor(sf::Color::Magenta);
		sn.setOrigin(-400,-230);
		window.draw(sn);
		sn.setSize(sf::Vector2f(10, 80));
		sn.setFillColor(sf::Color::Magenta);
		sn.setOrigin(-320,-230);
		window.draw(sn);
		sn.setSize(sf::Vector2f(10, 160));
		sn.setFillColor(sf::Color::Magenta);
		sn.setOrigin(-600,-140);
		window.draw(sn);
        sn.setSize(sf::Vector2f(10, 200));
		sn.setFillColor(sf::Color::Magenta);
		sn.setOrigin(-440,-200);
		window.draw(sn);
		sn.setSize(sf::Vector2f(100, 10));
		sn.setFillColor(sf::Color::Magenta);
		sn.setOrigin(-350,-390);
		window.draw(sn);
		snakehead.setOrigin(-434,-195);
		snakehead.setFillColor(sf::Color::White);
		window.draw(snakehead);
		snakehead.setOrigin(-283,-33);
		snakehead.setFillColor(sf::Color::White);
		window.draw(snakehead);
		snakehead.setOrigin(-384,-125);
		snakehead.setFillColor(sf::Color::White);
		window.draw(snakehead);
		snakehead.setOrigin(-592,-135);
		snakehead.setFillColor(sf::Color::White);
		window.draw(snakehead);
		window.draw(p1);
		window.draw(p2);
		window.draw(headtext);
		wincheck1();
		wincheck2();
				if(win != true)
			{
			 window.draw(turntext);
		 
				if (turn % 2 == 0 )
				          {
					turntext.setString("Player BLUE Turn:");
					turntext.setColor(sf::Color::Blue);
					enter.setString("Press Left Arrow key to turn the dice");
					if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))&&counter==0)
							{
							window.draw(enter);
					        window.display();
							
					         }
				    counter++;
					if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))&&counter!=0)
							{
						    
							window.draw(enter);
							counter++;
							
					         }
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					       {
							  y = ran(dicenum);
							  position_1(y);
							  stares1();
							  snakes1();
							  drawdice(y);
							  turn++;
							 
						   }
				}  
			
			   
				else if (turn % 2 == 1)
				{
				   
					turntext.setString("Player GREEN Turn:");
					turntext.setColor(sf::Color::Green);
					enter.setString("Press Right Arrow Key to turn the dice");
					if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))&&counter2==0)
							{
							window.draw(enter);
					        window.display();
						
					         }
				     counter2++;
					 if ((!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))&&counter2!=0)
							{
								
								window.draw(enter);
								counter2++;
							
					         }
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					       {
							 
							   x =ran(dicenum);
							   position_2(x); 
							   stares2();
							   snakes2();
							   drawdice(x);
							   turn++;
							   
						   }
					
				   
		        }
				

				
		}
		else
		{
			if (position1==30)
			{
				wint.setFont(font);
				wint.setString("PLAYER BLUE WINS");
				wint.setCharacterSize(20);
				wint.setFillColor(sf::Color::Blue);
				wint.setOrigin(sf::Vector2f(-680,-150)); 
				window.draw(wint);
			}
			if(position2==30)
			{
				wint.setFont(font);
				wint.setString("PLAYER GREEN WINS");
				wint.setCharacterSize(20);
				wint.setFillColor(sf::Color::Green);
				wint.setOrigin(sf::Vector2f(-680,-150)); 
				window.draw(wint);

			}


		}
	   window.draw(dicee);
	   window.draw(stairs);
	   window.draw(snakes);
	   window.display();
	  }
	  srand(1); 
	  return 0;	
		}
 int ran(int num)
{
	
   num = rand() % 6+1 ;
    
   return num;
}
void drawdice(int num)
{

   dicee.setFont(font);
   dicee.setCharacterSize(20);
   dicee.setFillColor(sf::Color::White);
   dicee.setOrigin(sf::Vector2f(-680,-120));
   if(num==0)
	   dicee.setString("0");
   if(num==1)
	   dicee.setString("Dice gives 1");
   if(num==2)
	   dicee.setString("Dice gives 2");
   if(num==3)
	   dicee.setString("Dice gives 3");
   if(num==4)
	   dicee.setString("Dice gives 4");
   if(num==5)
	   dicee.setString("Dice gives 5");
   if(num== 6)
	   dicee.setString("Dice gives 6");
 
   

}
void position_1(int dice)
{
		position1=position1+dice;
		if(position1>30)
			position1=position1-dice;
	
	if (position1==1)
	     p1.setOrigin(sf::Vector2f (row1[0][0]-10,row1[0][1]));
	if (position1==2)
         p1.setOrigin(sf::Vector2f (row1[1][0]-10,row1[1][1]));
	if (position1==3)
     	 p1.setOrigin(sf::Vector2f (row1[2][0]-10,row1[2][1]));
	if (position1==4)
	     p1.setOrigin(sf::Vector2f (row1[3][0]-10,row1[3][1]));
	if (position1==5)
		 p1.setOrigin(sf::Vector2f (row1[4][0]-10,row1[4][1]));
	if (position1==6)
		 p1.setOrigin(sf::Vector2f (row1[5][0]-10,row1[5][1]));
	if (position1==7)
		 p1.setOrigin(sf::Vector2f (row2[5][0]-10,row2[5][1]));
	if (position1==8)
		p1.setOrigin(sf::Vector2f (row2[4][0]-10,row2[4][1]));
	if (position1==9)
		p1.setOrigin(sf::Vector2f (row2[3][0]-10,row2[3][1]));
	if (position1==10)
		p1.setOrigin(sf::Vector2f (row2[2][0]-10,row2[2][1]));
	if (position1==11)
		p1.setOrigin(sf::Vector2f (row2[1][0]-10,row2[1][1]));
	if (position1==12)
		p1.setOrigin(sf::Vector2f (row2[0][0]-10,row2[0][1]));
	if (position1==13)
		p1.setOrigin(sf::Vector2f (row3[0][0]-10,row3[0][1]));
	if (position1==14)
	   p1.setOrigin(sf::Vector2f (row3[1][0]-10,row3[1][1]));
	if (position1==15)
		p1.setOrigin(sf::Vector2f (row3[2][0]-10,row3[2][1]));
	if (position1==16)
		p1.setOrigin(sf::Vector2f (row3[3][0]-10,row3[3][1]));
	if (position1==17)
		p1.setOrigin(sf::Vector2f (row3[4][0]-10,row3[4][1]));
	if (position1==18)
		p1.setOrigin(sf::Vector2f (row3[5][0]-10,row3[5][1]));
	if (position1==19)
		p1.setOrigin(sf::Vector2f (row4[5][0]-10,row4[5][1]));
	if (position1==20)
		p1.setOrigin(sf::Vector2f (row4[4][0]-10,row4[4][1]));
	if (position1==21)
		p1.setOrigin(sf::Vector2f (row4[3][0]-10,row4[3][1]));
	if (position1==22)
		p1.setOrigin(sf::Vector2f (row4[2][0]-10,row4[2][1]));
	if (position1==23)
		p1.setOrigin(sf::Vector2f (row4[1][0]-10,row4[1][1]));
	if (position1==24)
		p1.setOrigin(sf::Vector2f (row4[0][0]-10,row4[0][1]));
	if (position1==25)
		p1.setOrigin(sf::Vector2f (row5[0][0]-10,row5[0][1]));
	if (position1==26)
		p1.setOrigin(sf::Vector2f (row5[1][0]-10,row5[1][1]));
	if (position1==27)
		p1.setOrigin(sf::Vector2f (row5[2][0]-10,row5[2][1]));
	if (position1==28)
		p1.setOrigin(sf::Vector2f (row5[3][0]-10,row5[3][1]));
	if (position1==29)
		p1.setOrigin(sf::Vector2f (row5[4][0]-10,row5[4][1]));
	if (position1==30)
		p1.setOrigin(sf::Vector2f (row5[5][0]-10,row5[5][1]));
	
}
void position_2(int dice)
{
	position2=position2+dice;
		if(position2>30)
			position2=position2-dice;
		
	if (position2==1)
	     p2.setOrigin(sf::Vector2f (row1[0][0],row1[0][1]));
	if (position2==2)
         p2.setOrigin(sf::Vector2f (row1[1][0],row1[1][1]));
	if (position2==3)
     	 p2.setOrigin(sf::Vector2f (row1[2][0],row1[2][1]));
	if (position2==4)
	     p2.setOrigin(sf::Vector2f (row1[3][0],row1[3][1]));
	if (position2==5)
		 p2.setOrigin(sf::Vector2f (row1[4][0],row1[4][1]));
	if (position2==6)
		 p2.setOrigin(sf::Vector2f (row1[5][0],row1[5][1]));
	if (position2==7)
		 p2.setOrigin(sf::Vector2f (row2[5][0],row2[5][1]));
	if (position2==8)
		p2.setOrigin(sf::Vector2f (row2[4][0],row2[4][1]));
	if (position2==9)
		p2.setOrigin(sf::Vector2f (row2[3][0],row2[3][1]));
	if (position2==10)
		p2.setOrigin(sf::Vector2f (row2[2][0],row2[2][1]));
	if (position2==11)
		p2.setOrigin(sf::Vector2f (row2[1][0],row2[1][1]));
	if (position2==12)
		p2.setOrigin(sf::Vector2f (row2[0][0],row2[0][1]));
	if (position2==13)
		p2.setOrigin(sf::Vector2f (row3[0][0],row3[0][1]));
	if (position2==14)
	   p2.setOrigin(sf::Vector2f (row3[1][0],row3[1][1]));
	if (position2==15)
		p2.setOrigin(sf::Vector2f (row3[2][0],row3[2][1]));
	if (position2==16)
		p2.setOrigin(sf::Vector2f (row3[3][0],row3[3][1]));
	if (position2==17)
		p2.setOrigin(sf::Vector2f (row3[4][0],row3[4][1]));
	if (position2==18)
		p2.setOrigin(sf::Vector2f (row3[5][0],row3[5][1]));
	if (position2==19)
		p2.setOrigin(sf::Vector2f (row4[5][0],row4[5][1]));
	if (position2==20)
		p2.setOrigin(sf::Vector2f (row4[4][0],row4[4][1]));
	if (position2==21)
		p2.setOrigin(sf::Vector2f (row4[3][0],row4[3][1]));
	if (position2==22)
		p2.setOrigin(sf::Vector2f (row4[2][0],row4[2][1]));
	if (position2==23)
		p2.setOrigin(sf::Vector2f (row4[1][0],row4[1][1]));
	if (position2==24)
		p2.setOrigin(sf::Vector2f (row4[0][0],row4[0][1]));
	if (position2==25)
		p2.setOrigin(sf::Vector2f (row5[0][0],row5[0][1]));
	if (position2==26)
		p2.setOrigin(sf::Vector2f (row5[1][0],row5[1][1]));
	if (position2==27)
		p2.setOrigin(sf::Vector2f (row5[2][0],row5[2][1]));
	if (position2==28)
		p2.setOrigin(sf::Vector2f (row5[3][0],row5[3][1]));
	if (position2==29)
		p2.setOrigin(sf::Vector2f (row5[4][0],row5[4][1]));
	if (position2==30)
		p2.setOrigin(sf::Vector2f (row5[5][0],row5[5][1]));
//stares2();
}
void stares1()
{
	if (position1==3)
	{position1=22;
	p1.setOrigin(sf::Vector2f (row4[2][0]-10,row4[2][1]));
	stairs.setString("Stairs Taken");
	}
	
	else if (position1==5)
	{position1=8;
	p1.setOrigin(sf::Vector2f (row2[4][0]-10,row2[4][1]));
	stairs.setString("Stairs Taken");
   }
	
	else if (position1==11)
	{position1=26;
	p1.setOrigin(sf::Vector2f (row5[1][0]-10,row5[1][1]));
	stairs.setString("Stairs Taken");
	}
	
	else if (position1==20)
	{position1=29;
	p1.setOrigin(sf::Vector2f (row5[4][0]-10,row5[4][1]));
	stairs.setString("Stairs Taken");
	}
	else  stairs.setString("   ");
}
void stares2()
{
	if (position2==3)
		{
			position2=22;
			p2.setOrigin(sf::Vector2f (row4[2][0],row4[2][1]));
			stairs.setString("Stairs Taken");
			
	}
	
	else if (position2==5)
		{
			position2=8;
			p2.setOrigin(sf::Vector2f (row2[4][0],row2[4][1]));
			stairs.setString("Stairs Taken");
	}

	
	else if (position2==11)
		{
			position2=26;
			p2.setOrigin(sf::Vector2f (row5[1][0],row5[1][1]));
	        stairs.setString("Stairs Taken");
	}
	else if (position2==20)
		{
			position2=29;
			p2.setOrigin(sf::Vector2f (row5[4][0],row5[4][1]));
			stairs.setString("Stairs Taken");
	}
	else  stairs.setString("   ");
	
}
void snakes1()
{
	if (position1==17)
	{
		position1=4;
	    p1.setOrigin(sf::Vector2f (row1[3][0]-10,row1[3][1]));
		snakes.setString("Snake Bitten!");
	}
	else if (position1==21)
	{
		position1=9;
    		p1.setOrigin(sf::Vector2f (row2[3][0]-10,row2[3][1]));
			snakes.setString("Snake Bitten!");
	}
	else if (position1==27)
	{
		position1=1;
		 p1.setOrigin(sf::Vector2f (row1[0][0]-10,row1[0][1]));
		 snakes.setString("Snake Bitten!");
	}
	else if (position1==19)
	{
		position1=7;
		p1.setOrigin(sf::Vector2f (row2[5][0]-10,row2[5][1]));
		snakes.setString("Snake Bitten!");
	}
	else snakes.setString("    ");
}
void snakes2()
{
	if (position2==17)
	{
		position2=4;
	    p2.setOrigin(sf::Vector2f (row1[3][0]-10,row1[3][1]));
		snakes.setString("Snake Bitten!");
	}
	else if (position2==21)
	{
		position2=9;
    	p2.setOrigin(sf::Vector2f (row2[3][0]-10,row2[3][1]));
		snakes.setString("Snake Bitten!");
	}
	else if (position2==27)
	{
		position2=1;
	    p2.setOrigin(sf::Vector2f (row1[0][0]-10,row1[0][1]));
		snakes.setString("Snake Bitten!");
	}
	else if (position2==19)
	{
		position2=7;
		p2.setOrigin(sf::Vector2f (row2[5][0]-10,row2[5][1]));
		snakes.setString("Snake Bitten!");
	}
	else snakes.setString("     ");
}
void wincheck1()
{
	if (position1==30)
	{
		win=true;
	}
}
void wincheck2()
{
	if (position2==30)
	{
		win=true;
	}
}

 


