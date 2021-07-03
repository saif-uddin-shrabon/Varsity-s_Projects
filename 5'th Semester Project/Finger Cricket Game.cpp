#include<bits/stdc++.h>
using namespace std;

void Match_Overview()
{
    string line;
    ifstream file("Finger_Cricket_Game_Overview.txt");
    while (getline(file,line))
    {
        cout<<line<<endl;
    }
    file.close();
    

}
 void Reset(){
     fstream file;
    file.open("Finger_Cricket_Game_Overview.txt", ios::out);
    file.close();
 }

int main()
{
    
    system("Color 5");
    cout<<"\t\t\t\t\t*************************************"<<endl;
    cout<<"\t\t\t\t\t\tFinger Cricket Game"<<endl;
    cout<<"\t\t\t\t\t*************************************"<<endl;
    cout<<endl;
    
   
    ofstream file; //file
    file.open("Finger_Cricket_Game_Overview.txt", ios::out | ios::app);  //file
  /*  cout<<"You want to show the previous match Overview ?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. NO"<<endl;
    int a;
    cin>>a;
    if(a==1) Match_Overview();
    if(a==1) cout<<"Game Start Now"<<endl;
    */
    string player;
    cout<<"Enter the player name : ";
    //cin>>player;
    getline(cin,player);
    file<<"===> Computer vs "<<player<<endl; //file

    cout<<endl;

    //Toss Area
    cout<<"\t\t\t\t Toss"<<endl;
    cout<<"\t\t\t\t======"<<endl;
    cout<<endl;
    file<<"\t\t\tToss"<<endl;  //file
    file<<"\t\t\t*********"<<endl;  //file
    cout<<"NOTE: If Toss result is EVEN, computer won the toss, otherwise Player win the toss!"<<endl<<endl;
    srand(time(0));
    int cs = rand()%5+1;
    cout<<"Enter Your Finger Number : ";
    int F;
    cin>>F;

    int sumF= cs + F;
    if(sumF%2!=0)
    {
        cout<<"The number is "<<sumF<<" It's a ODD number"<<endl<<endl;
        cout<<player<<" won the Toss! & "<<player<<" choce Bat first"<<endl;
        file<<player<<" won the Toss! & "<<player<<" choce Bat first"<<endl; //file
    }
    else
    {
        cout<<"The number is "<<sumF<<" It's a EVEN number"<<endl<<endl;
        cout<<"Computer are won the Toss! & Computer choce Bat first"<<endl;
        file<<"Computer are won the Toss! & Computer choce Bat first"<<endl; //file
    }

    if(sumF%2!=0)
    {
        int player_score =0;
        for(int i=1; i<=6; i++)
        {
            srand(time(0));
            int computer = rand()%5+1;
            file<<i<<". Computer Finger ( Ball ): "<<computer<<endl; //file
            //player_score+=computer;
            cout<<"Enter your finger number : ";
            int fingerp;
            cin>>fingerp;

            if(fingerp <= 5 && fingerp >0)
            {
                 file<<i<<". Enter your finger number (Bat) : "<<fingerp<<endl; //file
                cout<<endl;
                if( computer == fingerp)
                {
                    cout<<player<<" is OUT!"<<endl;
                    file<<player<<" is OUT!"<<endl; //file
                    break;
                }
                player_score+=fingerp;

            }
            else
            {
                cout<<"it's a wrong finger number"<<endl;
                i--;
            }


        }
        cout<<endl;
        cout<<player<<" Scored :"<<player_score<<endl;
        cout<<"Now, Computer come to Bat."<<endl;
        file<<endl; //file
        file<<"2nd Inings : Computer Come To Bat"<<endl; //file

        int computer_score =0;
        for(int i=1; i<=6; i++)
        {
            srand(time(0));
            int computer = rand()%5+1;
             file<<i<<". Computer Finger ( Bat ): "<<computer<<endl; //file
            //computer_score+=computer;
            cout<<"Enter your finger number : ";
            int fingerp;
            cin>>fingerp;
            cout<<endl;
            if(fingerp<=5 && fingerp >0)
            {
                file<<i<<". Enter your finger number (Ball) : "<<fingerp<<endl; //file
                if( computer == fingerp)
                {
                    cout<<"Computer is OUT!"<<endl;
                    file<<"Computer is OUT!"<<endl; //file
                    break;
                }
                computer_score+=fingerp;
            }
            else
            {
                cout<<"it's a wrong finger number"<<endl;
                i--;
            }

        }
        cout<<endl;
        cout<<"Computer Score is : "<<computer_score<<endl;
        file<<endl;
        file<<"Player Score is : "<<player_score<<endl;  //file
        file<<"Computer Score is : "<<computer_score<<endl;  //file
        if(player_score > computer_score){
            cout<<player<<" is win the match!"<<endl;
            file<<player<<" is win the match!"<<endl; //file
        }
        else if(player_score < computer_score){
            cout<<"Computer is win the match!"<<endl;
            file<<"Computer is win the match!"<<endl; //file
        }
        else{
             cout<<"The match is drawn\n";
             file<<"The match is drawn"<<endl; //file
        }
      file<<endl;
      file.close();
    }

    else
    {
        int player_score =0;
        for(int i=1; i<=6; i++)
        {
            srand(time(0));
            int computer = rand()%5+1;
            file<<i<<". Computer Finger ( Bat ): "<<computer<<endl; //file
            // player_score+=computer;
            cout<<"Enter your finger number : ";
            int fingerp;
            cin>>fingerp;
            cout<<endl;
            if(fingerp<=5 && fingerp >0)
            {
                 file<<i<<". Enter your finger number (Ball) : "<<fingerp<<endl; //file
                if( computer == fingerp)
                {
                    cout<<"Computer is OUT!"<<endl;
                    break;
                }
                player_score+=fingerp;
            }
            else
            {
                cout<<"it's a wrong finger number"<<endl;
                i--;
            }


        }
        cout<<endl;
        cout<<"Computer Score is :"<<player_score<<endl;
        cout<<"Now "<<player<<" are Bating now"<<endl;
        file<<"2nd Inings : "<<player<<" are Bating now" <<endl; //file


        int computer_score =0;
        for(int i=1; i<=6; i++)
        {
            srand(time(0));
            int computer = rand()%5+1;
            file<<i<<". Computer Finger ( Ball ): "<<computer<<endl; //file
            //computer_score+=computer;
            cout<<"Enter your finger number : ";
            int fingerp;
            cin>>fingerp;
            cout<<endl;
            if(fingerp<=5 && fingerp >0)
            {
                  file<<i<<". Enter your finger number (Bat) : "<<fingerp<<endl; //file
                if( computer == fingerp)
                {
                    cout<<player<<" is OUT!"<<endl;
                    break;
                }
                computer_score+=fingerp;
            }
            else
            {
                cout<<"it's a wrong finger number"<<endl;
                i--;
            }
        }


        cout<<endl;
        cout<<player<<" Score is : "<<computer_score<<endl;
        file<<"Player Score is : "<<player_score<<endl;  //file
        file<<"Computer Score is : "<<computer_score<<endl;  //file

        if(player_score > computer_score){
            cout<<"Computer is win the match!"<<endl;
            file<<"Computer is win the match!"<<endl; //file
        }
        else if(player_score < computer_score){
            cout<<player<<" is win the match!"<<endl;
            file<<player<<" is win the match!"<<endl; //file
        }

        else
        {
            cout<<"The match is drawn\n";
            file<<"The match is drawn"<<endl;
        }
        file<<endl;
        file.close();
    }
    file<<endl;
   cout<<"If You Want to Match Over you must Enter the Overview Option Otherwise End Game"<<endl;
    cout<<"1. Match Overview"<<endl;
    cout<<"2. Reset Match Overview"<<endl;
    cout<<"3. Game End"<<endl;
    int n;
    cin>>n;
    if(n==1)
       Match_Overview();
       else if(n==2) Reset();
       else return(0);
}
