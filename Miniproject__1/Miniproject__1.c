/**************************************************************************************************
 Name        : Vehicle Control system
 Author      : Haneen Ehab Mounir
 **************************************************************************************************/
#include<stdio.h>
/*
 * PROTOTYPES OF FUNCTIONS *
 */
void welcome();//Prototype for welcome function
void sensorssetmenue(char x);//Prototype of sensorssetmenue functtion
int trafficlight(char color);// prototype of traffic color function (pass by value)
void display_variables(void);//prototype of display_variables function
void display_states(void);//prototype of  display_states function
void engine_temp(int temp);//prototype of engine temp _function
void speed(void);//prototype of speed function
void temp_room(int temp); //prototype of temp room function

typedef enum{OFF,ON}state; //state instead of typedef enum
state ENGINE=OFF; //type of off and on at engine
state AC=OFF;     //type of off and on at ac
state CONTROLLER=OFF; //type of off and on at controller
/***********************************************************************************************/
/*
 * If i want to use all the variables and states in only one struct
 * typedef enum {OFF,ON}state;

struct vehicle_variables{
    int speed;
	float room_temp;
	float engine_temp;
	int ENGINE;
	int AC;
	int CONTROLLER;
};
struct vehicle_variables v;

 access( v.AC) ....ect

*/
/***********************************************************************************************/

struct vehicle_variables{
    int speed;
	float room_temp;
	float engine_temp;

};
struct vehicle_variables v; //type of this struct it's name is V
/***********************************************************************************************/

int main()
{
     v.room_temp=35; //initial value of room temperature in the  main
     v.speed=10;     //initial value of speed in the  main
     v.engine_temp=90; //initial value of engine temperature in the  main


     printf("Welcome to vehicle control system \n");
	 fflush(stdout);
     welcome(); // call welcome function

}
/***********************************************************************************************/

void welcome() //welcome function
{   char y;
//print the welcome menue
	printf("a.Turn on the vehicle engine \n");
    fflush(stdout);
	printf("b.Turn off the vehicle engine \n");
    fflush(stdout);
	printf("c.Quit the system \n");
    fflush(stdout);
	scanf(" %c",&y); //scanf the choice
	switch(y)
		{
		case'a': //if the user choose choice a he will go to sensorsetmenue function
            ENGINE=ON; //Turn oN the engine
			sensorssetmenue(y);
	    break;
		case'b':
        ENGINE=OFF;
		welcome(y);//return back to welcome function
	    break;
		case'c':
		printf("Quit the system");//quit the system
	    break;
		}
}
/***********************************************************************************************/
void sensorssetmenue(char x)
{ //Display the choices if you click turn on the vehicle
	printf("a.Turn off the engine \n");
	fflush(stdout);
	printf("b.set the traffic color \n");
	fflush(stdout);
	printf("c.set the room temperature \n");
	fflush(stdout);
	printf("d.set the engine temperature \n");
	fflush(stdout);
	scanf(" %c",&x); //take the choice from the user
	//I use scanf function because i don't pass by value something already in main
	switch(x)
		{
	case'a':
		welcome(); //return to welcome
		break;
	case'b':
		trafficlight(x); //call the traffic color function
		break;
	case'c':
		temp_room(x); // call the temp room function
		break;
	case'd':
		engine_temp(x); // call the engine temp
		break;
		}
}
/***********************************************************************************************/
int trafficlight(char color) //pass by value
{
printf("Enter the required color");
fflush(stdout);
scanf(" %c",&color);
switch(color)
{
case'G':
case'g':
	v.speed=100; //change the speed to 100 by access the structure
	break;
case'O':
case'o':
	v.speed=30;  //change the speed to 30 by access the structure
	speed();
	break;
case'R':
case'r':
	v.speed=0;    //change the speed to 0 by access the structure
	break;
	}

display_variables(); // after choosing the traffic color display the variables
display_states();    // after choosing the traffic color display the States
sensorssetmenue(color); // return to sensorsset menue if you want to change anything else
return v.speed; // return the value of speed
}
/***********************************************************************************************/

void speed(void)
{
	if(v.speed==30) //if the speed is 30 km/hr so
	{
		v.room_temp=((v.room_temp*5)/4)+1; // the room temp change in to this equation
		v.engine_temp=((v.engine_temp*5)/4)+1; // the engine temp change in to this equation
		AC=ON; //Ac will be on if it's off
		CONTROLLER=ON; //Ac will be on if it's off
	}
}
/***********************************************************************************************/

void temp_room(int temp)
{
	printf("Enter the required room temperature");
    fflush(stdout);
	scanf("%d",&temp);
	if((temp<10) || (temp>30)) //if temperature is less than 10 or bigger than 30
	{
		v.room_temp=20; // set the temp room to 20
		AC=ON; // turn the Ac on

	}
	else
	{
		v.room_temp=35;   // set the temp room to 35
		AC=OFF;           // turn the Ac off

	}
	display_variables(); // after choosing the traffic color display the variables
	display_states();    // after choosing the traffic color display the States

	sensorssetmenue(temp); // return to sensorsset menue if you want to change anything else

}
/***********************************************************************************************/
void engine_temp(int temp)
{
	printf("Enter the required engine temperature");
    fflush(stdout);
	scanf("%d",&temp);
	if((temp<100) || (temp>150)) //if  engine temperature is less than 10 or bigger than 30
	{
		v.engine_temp=125; // set engine temp to 125
	    CONTROLLER=ON; // turn the controller on


	}
	else
	{
		v.engine_temp=90; // set engine temp to 90
	    CONTROLLER=OFF;   // turn the controller off



	}
	display_variables(); // after choosing the traffic color display the variables
	display_states();    // after choosing the traffic color display the States
	sensorssetmenue(temp); // return to sensorsset menue if you want to change anything else
}
/***********************************************************************************************/
void display_variables(void)
{
  // display the vehicle speed
	printf("The vehicle speed is %d \n",v.speed);
	fflush(stdout);
// display the room temperature
    printf("The room temperature is %2f \n",v.room_temp);
	fflush(stdout);
// display the engine temperature
    printf("The engine temperature is %2f \n",v.engine_temp);
	fflush(stdout);
}
/***********************************************************************************************/
void display_states(void)
{
	if(AC==ON)
	{
		printf("AC is ON \n");
	}
	if(AC==OFF)
		{
			printf("AC is OFF \n");
		}
	if(ENGINE==ON)
		{
			printf("ENGINE is ON \n");
		}
	if(ENGINE==OFF)
		{
			printf("ENGINE is OFF \n");
		}
	if(CONTROLLER==ON)
		{
			printf("CONTROLLER is ON \n");
		}
	if(CONTROLLER==OFF)
			{
				printf("CONTROLLER is OFF \n");
			}
}
/***********************************************************************************************/





