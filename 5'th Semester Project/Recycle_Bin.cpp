#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

string name1[12], name2[12], bowler1[8], bowler2[8];
int Run1[12], Run2[12], fball1[12], fball2[12], bwick1[8], bwick2[8], brun1[8], brun2[8];
string team1, team2;
vector<pair<pair<int, int>, string>> v1, v2, u1, u2;
int out1 = 0, out2 = 0, runteam1 = 0, runteam2 = 0;

void resetHistory()
{
    fstream file;
    file.open("scoreboard.txt", ios::out);
    file.close();
}

void loadEverything()
{
    string line;
    int cnt=0;
    ifstream f1("scoreboard.txt");
    if (f1)
        while (getline(f1, line))
        {
            if(line[0]=='#')
            {
                cout<<"------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"\n\n\t\t\t\t**MATCH NO. "<<++cnt<<"**"<<endl;
                continue;
            }
            cout << line << endl;
        }
    f1.close();
}

void SCOREBOARD()
{
    fstream fout;
    fout.open("scoreboard.txt", ios::app);
    fout<<"#"<<endl;

    cout << "\n\t\t\t\t" << team1 << " TEAM SCORECARD\n";
    fout << "\n\t\t\t\t" << team1 << " TEAM SCORECARD\n";
    cout << "\t\t\t\t==========================\n";
    fout << "\t\t\t\t==========================\n";
    cout << "\t\tPlayer Name\tRun Scored\t Ball Faced \t\tStrike Rate\n";
    fout << "\t\tPlayer Name\tRun Scored\t Ball Faced \t\tStrike Rate\n";
    cout << "\t\t-----------\t----------\t ---------- \t\t-----------\n";
    fout << "\t\t-----------\t----------\t ---------- \t\t-----------\n";
    for (int i = 0; i < 11; i++)
    {
        cout << "\t\t" << name1[i] << "\t\t" << Run1[i] << " runs\t\t from " << fball1[i] << " balls \t\t";
        fout << "\t\t" << name1[i] << "\t\t" << Run1[i] << " runs\t\t from " << fball1[i] << " balls \t\t";
        float strikerate = ((float)Run1[i] / fball1[i]) * 100;
        if (Run1[i] == 0)
        {
            cout << "0.00\n";
            fout << "0.00\n";
            continue;
        }
        cout << fixed << setprecision(2) << strikerate << "\n";
        fout << fixed << setprecision(2) << strikerate << "\n";
        //Sleep(1170);
    }

    cout << "\n\n\t\t\t\t" << team2 << " TEAM SCORECARD\n";
    fout << "\n\n\t\t\t\t" << team2 << " TEAM SCORECARD\n";
    cout << "\t\t\t\t==========================\n";
    fout << "\t\t\t\t==========================\n";
    cout << "\t\tPlayer Name\tRun Scored\t Ball Faced \t\tStrike Rate\n";
    fout << "\t\tPlayer Name\tRun Scored\t Ball Faced \t\tStrike Rate\n";
    cout << "\t\t-----------\t----------\t ---------- \t\t-----------\n";
    fout << "\t\t-----------\t----------\t ---------- \t\t-----------\n";
    for (int i = 0; i < 11; i++)
    {
        cout << "\t\t" << name2[i] << "\t\t" << Run2[i] << " runs\t\t from " << fball2[i] << " balls \t\t";
        fout << "\t\t" << name2[i] << "\t\t" << Run2[i] << " runs\t\t from " << fball2[i] << " balls \t\t";
        float strikerate = ((float)Run2[i] / fball2[i]) * 100.00;
        if (Run2[i] == 0)
        {
            cout << "0.00\n";
            fout << "0.00\n";
            continue;
        }
        cout << fixed << setprecision(2) << strikerate << "\n";
        fout << fixed << setprecision(2) << strikerate << "\n";
        //  Sleep(1170);
    }
}

void Sort()
{

    for (int i = 0; i < 11; i++)
    {
        v1.push_back(make_pair(make_pair(Run1[i], fball1[i]), name1[i]));
    }
    sort(v1.rbegin(), v1.rend());

    for (int i = 0; i < 11; i++)
    {
        v2.push_back(make_pair(make_pair(Run2[i], fball2[i]), name2[i]));
    }
    sort(v2.rbegin(), v2.rend());

    for (int i = 0; i < 5; i++)
    {
        u1.push_back(make_pair(make_pair(bwick1[i], brun1[i]), bowler1[i]));
    }
    sort(u1.rbegin(), u1.rend());

    for (int i = 0; i < 5; i++)
    {
        u2.push_back(make_pair(make_pair(bwick2[i], brun2[i]), bowler2[i]));
    }
    sort(u2.rbegin(), u2.rend());
}

void SUMMARY()
{
    fstream fout;
    fout.open("scoreboard.txt", ios::app);
    Sort();

    cout << "\n\n\t\t\t\t        SUMMERY\n\t\t\t =======================================\n";
    fout << "\n\n\t\t\t\t        SUMMERY\n\t\t\t =======================================\n";

    cout << "\t\t" << team1 << " " << runteam1 << "-" << out1 << "\t\t\t\t" << team2 << " " << runteam2 << "-" << out2 << "\n";
    fout << "\t\t" << team1 << " " << runteam1 << "-" << out1 << "\t\t\t\t" << team2 << " " << runteam2 << "-" << out2 << "\n";

    cout << "\t\t"<< "---------------\t\t\t\t---------------"<< "\n";
    fout << "\t\t"<< "---------------\t\t\t\t---------------"<< "\n";

    cout << "\t\t" << v1[0].second << " " << v1[0].first.first << "(" << v1[0].first.second << ")\t| " << u2[0].second << " " << u2[0].first.first << "-" << u2[0].first.second << "\t\t" << v2[0].second << " " << v2[0].first.first << "(" << v2[0].first.second << ")\t| " << u1[0].second << " " << u1[0].first.first << "-" << u1[0].first.second << "\n";
    fout << "\t\t" << v1[0].second << " " << v1[0].first.first << "(" << v1[0].first.second << ")\t| " << u2[0].second << " " << u2[0].first.first << "-" << u2[0].first.second << "\t\t" << v2[0].second << " " << v2[0].first.first << "(" << v2[0].first.second << ")\t| " << u1[0].second << " " << u1[0].first.first << "-" << u1[0].first.second << "\n";

    cout << "\t\t" << v1[1].second << " " << v1[1].first.first << "(" << v1[1].first.second << ")\t| " << u2[1].second << " " << u2[1].first.first << "-" << u2[1].first.second << "\t\t" << v2[1].second << " " << v2[1].first.first << "(" << v2[1].first.second << ")\t| " << u1[1].second << " " << u1[1].first.first << "-" << u1[1].first.second << "\n";
    fout << "\t\t" << v1[1].second << " " << v1[1].first.first << "(" << v1[1].first.second << ")\t| " << u2[1].second << " " << u2[1].first.first << "-" << u2[1].first.second << "\t\t" << v2[1].second << " " << v2[1].first.first << "(" << v2[1].first.second << ")\t| " << u1[1].second << " " << u1[1].first.first << "-" << u1[1].first.second << "\n";

    cout << "\t\t" << v1[2].second << " " << v1[2].first.first << "(" << v1[2].first.second << ")\t| " << u2[2].second << " " << u2[2].first.first << "-" << u2[2].first.second << "\t\t" << v2[2].second << " " << v2[2].first.first << "(" << v2[2].first.second << ")\t| " << u1[2].second << " " << u1[2].first.first << "-" << u1[2].first.second << "\n";
    fout << "\t\t" << v1[2].second << " " << v1[2].first.first << "(" << v1[2].first.second << ")\t| " << u2[2].second << " " << u2[2].first.first << "-" << u2[2].first.second << "\t\t" << v2[2].second << " " << v2[2].first.first << "(" << v2[2].first.second << ")\t| " << u1[2].second << " " << u1[2].first.first << "-" << u1[2].first.second << "\n";

    // cout << "\n\n\t\t\t\t\t    THANK YOU!!\n";
    // fout << "\n\n\t\t\t\t\t    THANK YOU!!\n";

    // cout << "\t\t\t\t\t\t     TEAM RECYCLE BIN\n";
    // fout << "\t\t\t\t\t\t     TEAM RECYCLE BIN\n";
    cout<<"\n\n";
    fout<<"\n\n";
    fout.close();
    
    
}

int Toss()
{
    srand(time(0));
    return rand() % 2;
}

void welcomeRPS()
{
    system("cls");
    //  cout<<"\t\t\t  ====================================\n";
    Sleep(50);

    cout<<"\n\t\t\t\t\tW";Sleep(50);
    cout<<"E";Sleep(50);
    cout<<"L";Sleep(50);
    cout<<"C";Sleep(50);
    cout<<"O";Sleep(50);
    cout<<"M";Sleep(50);
    cout<<"E";Sleep(50);
    cout<<" T";Sleep(50);
    cout<<"O\n";Sleep(50);

    cout<<"\t\t\t\t\tT";Sleep(50);
    cout<<"H";Sleep(50);
    cout<<"E";Sleep(50);
    cout<<"  G";Sleep(50);
    cout<<"A";Sleep(50);
    cout<<"M";Sleep(50);
    cout<<"E\n";Sleep(50);

    cout<<"\t\t\t\t  R";Sleep(50);
    cout<<"O";Sleep(50);
    cout<<"C";Sleep(50);
    cout<<"K,";Sleep(50);
    cout<<" P";Sleep(50);
    cout<<"A";Sleep(50);
    cout<<"P";Sleep(50);
    cout<<"E";Sleep(50);
    cout<<"R";Sleep(50);
    cout<<" & ";Sleep(50);
    cout<<"S";Sleep(50);
    cout<<"C";Sleep(50);
    cout<<"I";Sleep(50);
    cout<<"S";Sleep(50);
    cout<<"S";Sleep(50);
    cout<<"O";Sleep(50);
    cout<<"R";Sleep(150);
    cout<<"\n\t\t\t  ------------------------------------\n\n";Sleep(150);
    //system("cls");
}

int computer_choice()
{
    srand(time(0));
    return rand()%3;
}

void loadedscore()
{
    string s;
    ifstream file("RPSscore.txt");

    while(getline(file, s))
    {
        cout<<s<<endl;
    }
    file.close();
}

void saveScore(string name, int ps, int cs)
{
    ofstream file;
    file.open("RPSscore.txt", ios::app);
    file<<"\n"<<name<<"\t\t"<<ps<<"\t\t"<<cs;
    file.close();
}

void resetRpsHistory()
{
    fstream file;
    file.open("RPSscore.txt", ios::out);
    file.close();
}

void game()
{
    system("color 6");
    //welcomeRPS();

    int user_score=0;
    int pc_score=0;
    cout<<"\nEnter your Name: ";
    string username;
    cin>>username;

    cout<<"\nEnter total rounds of game: ";
    int r;
    cin>>r;

    while(r<=0)
    {
        cout<<"Invalid input!!!"<<endl;
        cout<<"Enter total rounds of game: ";
        cin>>r;
    }

    while(r--)
    {
        cout<<username<<"'s Score: "<<user_score<<endl;
        cout<<"Computer Score: "<<pc_score<<endl;

        int pc_choice=computer_choice();

        cout<<"\n0. Rock\n";
        cout<<"1. Paper\n";
        cout<<"2. Scissor\n";

        cout<<"\n"<<username<<"'s choice : ";
        int n;
        cin>>n;

        cout<<"Computers Choice: "<<pc_choice<<endl;

        if(pc_choice==0 && n==1)
        {
            user_score++;
        }
        else if(pc_choice==0 && n==2)
        {
            pc_score++;
        }
        else if(pc_choice==1 && n==0)
        {
            pc_score++;
        }
        else if(pc_choice==1 && n==2)
        {
            user_score++;
        }
        else if(pc_choice==2 && n==0)
        {
            user_score++;
        }
        else if(pc_choice==2 && n==1)
        {
            pc_score++;
        }
        else if(pc_choice==n)
        {
            cout<<"Computers Choice & "<<username<<"'s Choice are same.\nSo no one scored!\n"<<endl;
        }
        if(n>=3 || n<0)
        {
            cout<<"Invalid input!!\n"<<endl;
            r++;
            continue;
        }

    }

    cout<<"Final score of "<<username<<" :"<<user_score<<endl;
    cout<<"Final score of Computer :"<<pc_score<<endl;

    saveScore(username, user_score, pc_score);

    if(user_score > pc_score)
    {
        cout<<username<<" Wins the game"<<endl;
    }
    else if(user_score < pc_score)
    {
        cout<<"Computer wins the game"<<endl;
    }
    else
    {
        cout<<"Scores are equal.\nSo it's a tie!!"<<endl<<endl;
    }

    //cout << "Let's start the " << team2 << " team batting .\n\n";

}

void RPS()
{
    system("color 6");
    welcomeRPS();

    int c;
    while(1)
    {
        cout<<"\n1. load Previous score\n";
        cout<<"2. Play Game\n";
        cout<<"3. Reset All score\n";
        cout<<"4. Exit\n";
        cout<<"\nEnter Your Choice: ";
        cin>>c;

        while(c>=5 || c<=0)
        {
            cout<<"Invalid input!!\n"<<endl;
            cout<<"Enter Your Choice: ";
            cin>>c;
        }

        switch(c)
        {
        case 1:
            cout<<"\nPlayer name\tPlayer score\tcomputer";
            loadedscore();
            break;
        case 2:
            game();
            break;
        case 3:
            resetRpsHistory();
            break;
        default:
            cout << "Let's start the " << team2 << " team batting .\n\n";
            return;
        }
        cout<<endl;

    }

}


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
void Reset()
{
    fstream file;
    file.open("Finger_Cricket_Game_Overview.txt", ios::out);
    file.close();
}

void FCG()
{

    system("cls");
    system("Color 5");
    cout<<"\t\t\t\t\t*************************************"<<endl;
    cout<<"\t\t\t\t\t\tFinger Cricket Game"<<endl;
    cout<<"\t\t\t\t\t*************************************"<<endl;
    cout<<endl;


    ofstream file; //file
    file.open("Finger_Cricket_Game_Overview.txt", ios::out | ios::app);  //file

    string player;
    cout<<"Enter the player name : ";
    cin>>player;
    // getline(cin,player);
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
        cout<<player<<" won the Toss! & "<<player<<" chooce Bat first"<<endl;
        file<<player<<" won the Toss! & "<<player<<" chooce Bat first"<<endl; //file
    }
    else
    {
        cout<<"The number is "<<sumF<<" It's a EVEN number"<<endl<<endl;
        cout<<"Computer won the Toss! & Computer chooce Bat first"<<endl;
        file<<"Computer won the Toss! & Computer chooce Bat first"<<endl; //file
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
        if(player_score > computer_score)
        {
            cout<<player<<" is win the match!"<<endl;
            file<<player<<" is win the match!"<<endl; //file
        }
        else if(player_score < computer_score)
        {
            cout<<"Computer is win the match!"<<endl;
            file<<"Computer is win the match!"<<endl; //file
        }
        else
        {
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

        if(player_score > computer_score)
        {
            cout<<"Computer is win the match!"<<endl;
            file<<"Computer is win the match!"<<endl; //file
        }
        else if(player_score < computer_score)
        {
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

}

void ENTERTAINMENT()
{

    cout << "\nWhich game do you want to play ? \n";
    cout << "1. Finger Cricket Game.\n";
    cout << "2. Rock Paper Scissor (RPS).\n";

    int choice;

    cout << "\nEnter your choice. ";
    cin >> choice;

    if (choice == 1)
    {
        FCG();
    }
    else
    {
        RPS();
    }
}

void WELCOME()
{
    // cout<<"\t\t\t  ====================================\n";
    Sleep(50);

    cout<<"\n\t\t\t\t\tW";Sleep(50);
    cout<<"E";Sleep(50);
    cout<<"L";Sleep(50);
    cout<<"C";Sleep(50);
    cout<<"O";Sleep(50);
    cout<<"M";Sleep(50);
    cout<<"E\n";Sleep(50);
    cout<<"\t\t\t\tC";Sleep(50);
    cout<<"R";Sleep(50);
    cout<<"I";Sleep(50);
    cout<<"C";Sleep(50);
    cout<<"K";Sleep(50);
    cout<<"E";Sleep(50);
    cout<<"T ";Sleep(50);
    cout<<"G";Sleep(50);
    cout<<"A";Sleep(50);
    cout<<"M";Sleep(50);
    cout<<"E ";Sleep(50);
    cout<<"& ";Sleep(50);
    cout<<"S";Sleep(50);
    cout<<"C";Sleep(50);
    cout<<"O";Sleep(50);
    cout<<"R";Sleep(50);
    cout<<"E";Sleep(50);
    cout<<"B";Sleep(50);
    cout<<"O";Sleep(50);
    cout<<"A";Sleep(50);
    cout<<"R";Sleep(50);
    cout<<"D\n";Sleep(50);
    cout<<"\t\t\t---------------------------------------\n\n";Sleep(50);
}

void CRIC()
{

    system("Color 3");
    //freopen("in.txt", "r", stdin);

    WELCOME();

    cout << "Enter the name of Team1 ";
    cin >> team1;
    cout << "Enter the name of Team2 ";
    cin >> team2;

    cout << "\nEnter the number of over in this match ";
    int over, ball;
    cin >> over;
    over *= 6;
    ball = over;

    int tossresult = Toss();

    cout << "\nNote: \n";
    cout << "If toss result 1," << team1 << " won the toss\nOtherwise " << team2 << " won the toss\n";

    cout << "\nToss result is " << tossresult << "\n";
    cout << (tossresult ? team1 : team2);
    cout << " won the toss and elected to bat first\n";

    if (!tossresult)
        swap(team1, team2);

    cout << endl << team1 << " team playing eleven.\n";
    cout << "-------------------------------\n\n";

    for (int i = 0; i < 11; i++)
    {
        cout << "Enter the name of player" << i + 1 << " ";
        cin >> name1[i];
        cout << "\n";
    }

    cout << "\n\n"
         << team2 << " team playing eleven.\n";
    cout << "-------------------------------\n\n";
    for (int i = 0; i < 11; i++)
    {
        cout << "Enter the name of player" << i + 1 << " ";
        cin >> name2[i];
        cout << "\n";
    }

    int id = 0;
    for (int i = 10; i >= 6; i--)
    {
        bowler1[id] = name1[i];
        bowler2[id++] = name2[i];
    }

    cout << "\n"
         << name1[0] << " and " << name1[1] << " are opeing today.\n";

    int numbat1 = 3, numbat2 = 3, y = 0, z = 1, inat = 2, X = 0, Y = 0;

    while (ball-- && out1 < 10)
    {

        if (Y == 6)Y = 0;
        if (X % 6 == 0)
        {
            cout << bowler2[Y++] << " comes to bowling.\n";
        }

        cout << "\n1. Wide ball\n";
        cout << "2. No ball\n";
        cout << "3. Wicket\n";
        cout << "4. Run\n";

        cout << "\nEnter a number ";
        int l;
        cin >> l;

        if(l == 1 || l == 2)
        {

            runteam1++;
            ball++;
            brun2[Y - 1]++;
            cout << (l == 1 ? "This is wide ball\n" : "This is no ball\n");

            if(l == 2)goto T;
            if(l == 1)goto K;
        }
        else if (l == 3)
        {
            cout << "That's out. " << name1[y] << " is gone.";
            cout << " \n\n";
            out1++;
            fball1[y]++;
            y = inat++;
            bwick2[Y - 1]++;

            X++;
            if (out1 != 10)
            {
                cout << name1[numbat1++ - 1] << " come to bat.\n";
            }
            goto K;
        }

        X++;
        T:
        cout << "Enter Run ";
        int x;
        cin >> x;
        runteam1 += x;
        Run1[y] += x;
        brun2[Y - 1] += x;
        fball1[y]++;
        if (x == 1 || x == 3 || X % 6 == 0)
        {
            swap(y, z);
        }

        if (x == 4)
            cout << "What a shot!! It's Boundary!!\n";
        else if (x == 6)
            cout << "Huge one!! It's a six!!\n";

        K:
        float cr = ((float)runteam1 / X) * 6;
        cout << team1 << " " << runteam1 << "-" << out1 << " | " << name1[y] << " "
             << Run1[y] << "(" << fball1[y] << ") | ";
        cout << name1[z] << " " << Run1[z] << "(" << fball1[z] << ") | Over " << X / 6 << "." << X % 6; //<<" | Current Runrate: "<<cr;
        cout << "\n-------------------------------------\n";
    }

    cout << "\n"
         << team1 << " scored " << runteam1 << " runs.\n"
         << team2 << " needs " << runteam1 + 1 << " runs to win\n\n";

    cout << "1. Goto " << team2 << " team battintg.\n";
    cout << "2. Wanna have some fun? Enter 2.\n";
    cout << "\nEnter your choice: ";

    int choice;
    cin >> choice;
    if (choice == 2)
    {
        ENTERTAINMENT();
    }

    cout << "\n\n"
         << name2[0] << " and " << name2[1] << " are opeing today.\n";

    inat = 2, y = 0, z = 1, X = 0, Y = 0;

    //system("cls");
    system("color 3");

    while (over-- && out2 < 10)
    {

        if (Y == 6)
            Y = 0;
        if (X % 6 == 0)
        {
            cout << bowler1[Y++] << " comes to bowling.\n";
        }

        cout << "\n1. Wide ball\n";
        cout << "2. No ball\n";
        cout << "3. Wicket\n";
        cout << "4. Run\n";

        cout << "\nEnter a number ";
        int l;
        cin >> l;

        if (l == 1 || l == 2)
        {
            runteam2++;
            ball++;
            brun1[Y - 1]++;
            cout << (l == 1 ? "This is wide ball\n" : "This is no ball\n");

            if (l == 2)
                goto TT;
            if (l == 1)
                goto KK;
        }
        else if (l == 3)
        {

            cout << "That's out. " << name2[y] << " is gone.";
            cout << " \n\n";
            out2++;
            fball2[y]++;
            y = inat++;
            bwick1[Y - 1]++;

            X++;
            if (out2 != 10)
            {
                cout << name2[numbat2++ - 1] << " come to bat.\n";
            }
            goto KK;
        }

        X++;

        TT:
        cout << "Enter Run ";
        int x;
        cin >> x;
        runteam2 += x;
        Run2[y] += x;
        brun1[Y - 1] += x;
        fball2[y]++;
        if (x == 1 || x == 3 || X % 6 == 0)
        {
            swap(y, z);
        }

        if (x == 4)
            cout << "What a shot!! It's Boundary!!\n";
        else if (x == 6)
            cout << "Huge one!! It's a six!!\n";

KK:
        cout << team2 << " " << runteam2 << "-" << out2 << " | " << name2[y] << " "
             << Run2[y] << "(" << fball2[y] << ") | ";
        cout << name2[z] << " " << Run2[z] << "(" << fball2[z] << ") | Over " << X / 6 << "." << X % 6;
        cout << "\n\n";

        if (runteam2 > runteam1)
        {
            cout << team2 << " won the match by " << 10 - out2 << " wickets.\n";
            goto here;
        }
        if (over)
            cout << team2 << " needs " << runteam1 - runteam2 + 1 << " more run in " << over << " balls.\n";
    }
    if (runteam1 == runteam2)
    {
        cout << "The match is drawn.\n";
        goto here;
    }
    cout << team1 << " won the match by " << runteam1 - runteam2 << " runs.\n";

here:
    SCOREBOARD();
    SUMMARY();

    cout << "\n\n\nPress 1 to load history\npress 2 to clear history\npress 3 to quit\nEnter your choice: ";
    int p;
    cin >> p;
    switch (p)
    {
    case 1:
        loadEverything();
        break;
    case 2:
        resetHistory();
        break;
    case 3:
        exit(0);
        // Added 
     cout<<"Developer by Tajil Ahmed / Saif Uddin / Dewan Nafim / Abir / Arian"<<endl;
        break;
    default:
        break;
    }
}

int main()
{

    CRIC();
    //FCG();
    //RPS();

    return 0;
}