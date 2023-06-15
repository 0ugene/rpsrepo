#include <iostream>
#include <stdlib.h>
#include<time.h>  //Makes sure the rand() function returns a new random number each time the rand() function is called.
#include <map>
#include <iomanip>

std::string getchoice()      
//This function gets input from a user and returns the input if the input is contained 
//in a desired collection but returns the string "null" otherwise. Also has lower/upper case input-invariance.
{
    std::string input;
    std::map<int, std::string>choices{{1,"scissors"},{2,"rock"},{3,"paper"}};
    std::cout<<"Choose 'Rock', 'Paper', or 'Scissors'."<<std::endl;
    std::cin>>input;
    for (int i=0;i<input.length(); ++i)
    {
        input[i]=tolower(input[i]);
    }
    return (input==choices[1]||input==choices[2]||input==choices[3])?input:"null";
}

void check_winner(std::string player_choice, int& t)  //To evaluate player win/loss events and track the number of wins. 
{
    std::map<int, std::string>choices{{1,"scissors"},{2,"rock"},{3,"paper"}};
    std::map<std::string, int>inverse_choices{{"scissors",1},{"rock",2},{"paper",4}}; 
//"Inverse_choice": A pseudo-inverse of the 'choices' map. The following if-else sequence depends on all possible differences m-n for m, n 
//in {1,2,4}. If it was 3 instead of 4, there'd be repeated differences, e.g. 2-1=1 and 3-2=1. 
//The 4 ensures that each difference is unique.

    srand(time(NULL));
    std::string computer_choice=choices[(rand()%3)+1];
    if (player_choice==computer_choice)
    {
        std::cout<<"Player choice: "<<player_choice<<std::right<<std::setw(30)<<" Computer choice: "<<computer_choice<<std::endl;
        std::cout<<"It's a tie!"<<std::endl;
    }
    else if(inverse_choices[player_choice]-inverse_choices[computer_choice]==-1)
    {
        std::cout<<"Player choice: "<<player_choice<<std::right<<std::setw(30)<<" Computer choice: "<<computer_choice<<std::endl;
        std::cout<<"Rock smashes scissors!"<<std::endl;
        std::cout<<"You lose."<<std::endl;
    }
    else if(inverse_choices[player_choice]-inverse_choices[computer_choice]==1)
    {
        std::cout<<"Player choice: "<<player_choice<<std::right<<std::setw(30)<<" Computer choice: "<<computer_choice<<std::endl;
        std::cout<<"Rock smashes scissors!"<<std::endl;
        std::cout<<"You win!"<<std::endl;
        t+=1;
    }
    else if(inverse_choices[player_choice]-inverse_choices[computer_choice]==-2)
    {
        std::cout<<"Player choice: "<<player_choice<<std::right<<std::setw(30)<<" Computer choice: "<<computer_choice<<std::endl;
        std::cout<<"Paper covers rock!"<<std::endl;
        std::cout<<"You lose."<<std::endl;
    }
    else if(inverse_choices[player_choice]-inverse_choices[computer_choice]==2)
    {
        std::cout<<"Player choice: "<<player_choice<<std::right<<std::setw(30)<<" Computer choice: "<<computer_choice<<std::endl;
        std::cout<<"Paper covers rock!"<<std::endl;
        std::cout<<"You win!"<<std::endl;
        t+=1;
    }
    else if(inverse_choices[player_choice]-inverse_choices[computer_choice]==-3)
    {
        std::cout<<"Player choice: "<<player_choice<<std::right<<std::setw(30)<<" Computer choice: "<<computer_choice<<std::endl;
        std::cout<<"Scissors cuts paper!"<<std::endl;
        std::cout<<"You win!"<<std::endl;
        t+=1;
    }
    else
    {
        std::cout<<"Player choice: "<<player_choice<<std::right<<std::setw(30)<<" Computer choice: "<<computer_choice<<std::endl;
        std::cout<<"Scissors cuts paper!"<<std::endl;
        std::cout<<"You lose"<<std::endl;
    }

}

bool is_input_int(std::string input) //Will check if desired number (of games) entered is +integer.
{
    bool t_value=true;
    if (input[0]=='0')
        {
            t_value=false;
        }
    else
        {
            for (int i=0;i<input.length();++i)
                {
                if (isdigit(input[i])==false)
                {
                t_value=false;
                break;
                }
                }
        }
    return t_value;
}

void RPS()
{
std::string player_choice, total; int wins=0;
std::cout<<"How many games of 'rock, paper, scissors' would you like to play? ";
do
{
    std::cout<<"Enter a positive whole number.\n";
    std::cin>>total;
}
while(!(is_input_int(total)));
std::cout<<std::endl;

for(int i=0;i<stoi(total);++i)
{
    do
    {
        player_choice=getchoice();
    }
    while(player_choice=="null");

check_winner(player_choice, wins);
std::cout<<std::endl;
}

if (wins<=((stoi(total))/2))
{
std::cout<<"You won "<<wins<<"/"<<total<<" game(s)."<<std::endl;
}
else
{
std::cout<<"You won "<<wins<<"/"<<total<<" game(s)!"<<std::endl;
}
}


int main()
{
    RPS();
    return 0;
}