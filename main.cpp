#include<vector>
#include<iostream>
#include<exception>

using namespace std;
int tf1[]={0,0,1};
int tf2[]={1,2,2};
string teams[] = {"Dehli Warriors","Chennai Stingers","Bangalore knights"};
int matchwinners[]={};
int final_teams[]={};
string d_team[6],d_role[6],c_team[5],c_role[6],b_team[5],b_role[6];


class tournament{

public:
    string tourname;
    int touryear,total_teams,total_players;
    string *teams;

    tournament(string tn,int ty,int tt,int tp,string tm[])
    {
        tourname=tn;
        touryear=ty;
        total_teams=tt;
        total_players=tp;
        teams=tm;
    }
};

class makechoiceexception:public exception
{
public:
    const char* what()  const throw()
    {
        return "You have entered wrong choice\n         Please enter choice between 1 to 8";
    }
};
class min_bid:public exception
{
    public:
        const char* what()  const throw()
        {
            return "BID IS TOO SMALL\n";

        }

};
class team_noo:public exception
{
    public:
        const char* what()  const throw()
        {
            return "WRONG TEAM CALL\n\t0->DELHI\n\t1->CHENNAI\n\t2->BANGALORE";

        }

};

class players{
public:
    string *player;
    int *min_bid;
    string *role;

    players(string p[],int mb[],string roles[]){
        player=p;
        min_bid=mb;
        role=roles;
    }

    void playerlist(){
        cout<<"\nsl.no\tplayername\tminimum bid\t\t\tRole"<<endl;
    for(int i=0;i<15;i++)

        cout<<"\n"<<i+1<<"\t"<<player[i]<<"\t\t\t"<<min_bid[i]<<"\t\t\t"<<role[i]<<"\t"<<"\n";

    }

};


class auction1{

    public:

    int bid_amount[15];
    int curteam,d=0,c=0,b=0,lo=100;
    int teamno[15];//should be under 3
    char cc;




    void startauction(string players[],int mb[],string teams[],string role[]){
        int j=0;
        cout<<"\n\n\n\tHere comes the most awaited moment of tournament\n\n";
        cout<<"\t\t\tAuction\n";

        while(j<6){

            cout<<"\n\t\tBIDDDING for PLAYES=>\t"<<players[j]<<"\n\t\tMINIMUM BID IS=>\t"<<mb[j]<<"\n\t\tROLE IS=>\t"<<role[j];
            do{
            try{cout<<"\n\n\tTeam number and bid amount";
            cin>>curteam;
            if(curteam<0 || curteam>2)
            {
                throw team_noo();
            }
            cin>>bid_amount[j];

            if(bid_amount[j]<mb[j])
            {
                throw min_bid();
            }

            }
                catch(team_noo &c)
                {
                cout<<"\n                         !!!!!!!!!! EXCEPTION:  "<<c.what()<<endl;
                }
                catch(min_bid &c)
                {
                cout<<"\n                         !!!!!!!!!! EXCEPTION:  "<<c.what()<<endl;
                }

             cout<<"\n\tis this final bid:y/n \t";
             cin>>cc;
            }while(cc!='y');

            cout<<"\n\t\t"<<players[j]<<"sold to\t"<<teams[curteam]<<"for\t"<<bid_amount[j];
            if(curteam==0)
            {

                d_team[d]=players[j];
                d_role[d]=role[j];
                d++;

            }
            else if(curteam==1)
            {
                c_team[c]=players[j];
                c_role[c]=role[j];
                c++;

            }
            else if(curteam==2)
            {
                b_team[b]=players[j];
                b_role[b]=role[j];
                b++;

            }



            j++;
        }


    }


void showDelhiteam(){
        cout<<"\n\n\t\tTEAM DELHI\n\n";
        for(int i=0;i<d;i++)
            cout<<"\n\t\t"<<d_team[i]<<"\t"<<d_role[i];
}
void showBangalore(){
        cout<<"\n\n\t\tTEAM BANGALORE\n\n";
        for(int i=0;i<b;i++)
            cout<<"\n\t\t"<<b_team[i]<<"\t"<<b_role[i];
}
    void showChennai(){
        cout<<"\n\n\t\tTEAM CHENNAI\n\n";
        for(int i=0;i<auction1::c;i++)
            cout<<"\n\t\t"<<c_team[i]<<"\t"<<c_role[i];
}


};

class match
{
  public:

    static match *make_match(int choice);
    virtual void winner() = 0;
};

class normal: public match
{
  public:

    void winner()
    {
        int score1=0,score2=0,wicket1=0,wicket2=0,choice;
        cout << "\n\t\tNORMAL MATCH STARTED\n\n";
        cout<<"\n\n\t\tEnter Match No:\t";
        cin>>choice;
        cout<<"\n\t\t"<<teams[tf1[choice-1]]<<"VS"<<teams[tf2[choice-1]]<<"\n\n";
        cout<<"\n\n\t\tEnter score of :\t"<<teams[tf1[choice-1]];
        cin>>score1;
        cout<<"\n\n\t\tEnter wickets of :\t"<<teams[tf1[choice-1]];
        cin>>wicket1;
        cout<<"\n\n\tFirst Inning Results :->\t"<<score1<<"-"<<wicket1;
        cout<<"\n\n\t\tEnter score of :\t"<<teams[tf2[choice-1]];
        cin>>score2;
        cout<<"\n\n\t\tEnter wickets of :\t"<<teams[tf2[choice-1]];
        cin>>wicket2;
        cout<<"\n\n\tSecond Inning Results :->\t"<<score2<<"-"<<wicket2;
        if(score1>score2)
        {
        matchwinners[choice-1]=tf1[choice-1];
             cout<<"\n\n\t\t"<<teams[matchwinners[choice-1]]<<"Won the match";

        }

        else if(score1<score2){

             matchwinners[choice-1]=tf2[choice-1];
             cout<<"\n\n\t\t"<<teams[matchwinners[choice-1]]<<"Won the match";
        }

        else{
            cout<<"\n\n\t\tSuperOver\n\n";
            cout<<"\n\n\t\tEnter score of :\t"<<teams[tf1[choice-1]];
        cin>>score1;
        cout<<"\n\n\t\tEnter wickets of :\t"<<teams[tf1[choice-1]];
        cin>>wicket1;
        cout<<"\n\n\tFirst Inning Results :->\t"<<score1<<"-"<<wicket1;
        cout<<"\n\n\t\tEnter score of :\t"<<teams[tf2[choice-1]];
        cin>>score2;
        cout<<"\n\n\t\tEnter wickets of :\t"<<teams[tf2[choice-1]];
        cin>>wicket2;
        cout<<"\n\n\tSecond Inning Results :->\t"<<score2<<"-"<<wicket2;
        if(score1>score2)
        {
        matchwinners[choice-1]=tf1[choice-1];
             cout<<"\n\n\t\t"<<teams[matchwinners[choice-1]]<<"Won the match";
        }

        else if(score1<score2){

             matchwinners[choice-1]=tf2[choice-1];
             cout<<"\n\n\t\t"<<teams[matchwinners[choice-1]]<<"Won the match";
        }
        else{
            cout<<"\n\n\t\tMatch Tie \t 1 point to each teams\n";
        }
    }}
};

class final: public match
{
  public:
    void winner()
    {

          int score1=0,score2=0,wicket1=0,wicket2=0,choice=4;
        cout << "\n\t\tFINAL MATCH STARTED\n\n";
        cout<<"\n\n\t\tFinal Playing teams\n";
        cin>>final_teams[0]>>final_teams[1];
        cout<<"\n\t\t"<<teams[final_teams[0]]<<"VS"<<teams[final_teams[1]]<<"\n\n";
        cout<<"\n\n\t\tEnter score of :\t"<<teams[final_teams[0]];
        cin>>score1;
        cout<<"\n\n\t\tEnter wickets of :\t"<<teams[final_teams[0]];
        cin>>wicket1;
        cout<<"\n\n\tFirst Inning Results :->\t"<<score1<<"-"<<wicket1;
        cout<<"\n\n\t\tEnter score of :\t"<<teams[final_teams[1]];
        cin>>score2;
        cout<<"\n\n\t\tEnter wickets of :\t"<<teams[final_teams[1]];
        cin>>wicket2;
        cout<<"\n\n\tSecond Inning Results :->\t"<<score2<<"-"<<wicket2;
        if(score1>score2)
        {
        matchwinners[choice-1]=final_teams[0];
             cout<<"\n\n\t\t"<<teams[matchwinners[choice-1]]<<"Won the match";

        }

        else if(score1<score2){

             matchwinners[choice-1]=final_teams[1];
             cout<<"\n\n\t\t"<<teams[matchwinners[choice-1]]<<"Won the match";
        }

        else{
            cout<<"\n\n\t\tSuperOver\n\n";
            cout<<"\n\n\t\tEnter score of :\t"<<teams[final_teams[0]];
        cin>>score1;
        cout<<"\n\n\t\tEnter wickets of :\t"<<teams[final_teams[0]];
        cin>>wicket1;
        cout<<"\n\n\tFirst Inning Results :->\t"<<score1<<"-"<<wicket1;
        cout<<"\n\n\t\tEnter score of :\t"<<teams[final_teams[1]];
        cin>>score2;
        cout<<"\n\n\t\tEnter wickets of :\t"<<teams[final_teams[1]];
        cin>>wicket2;
        cout<<"\n\n\tSecond Inning Results :->\t"<<score2<<"-"<<wicket2;
        if(score1>score2)
        {
        matchwinners[choice-1]=final_teams[0];
             cout<<"\n\n\t\t"<<teams[matchwinners[choice-1]]<<"Won the match";
        }

        else if(score1<score2){

             matchwinners[choice-1]=final_teams[1];
             cout<<"\n\n\t\t"<<teams[matchwinners[choice-1]]<<"Won the match";
        }
        else{
            cout<<"\n\n\t\tMatch Tie";
        }
        }
    }
};
match *match::make_match(int choice)
{
  if (choice == 1)
    return new normal;
  else if (choice == 2)
    return new final;

}

class team{
    public:
int a=0,b=0,c=0;
void teams_stand(){
for(int i=0;i<3;i++){
    if(matchwinners[i]==0){
        a++;

    }
    else if(matchwinners[i]==1){
        b++;
    }
    else if(matchwinners[i]==2){
        c++;

    }
    cout<<a;
    cout<<b;
    cout<<c;

}
}
void display(){
    int mno;
cin>>mno;
cout<<"\n\t\tWINNERS OF TOURNAMENT MATCHES\n\n";

for(int i=0;i<mno;i++)
    cout<<"\n\n\t\tMatch "<<i+1<<"\t-->"<<teams[matchwinners[i]];
}

};




int main(){

    auction1 aa;
    team tt;
    string teams[] = {"Dehli Warriors","Chennai Stingers","Bangalore knights"};
    tournament t("IPL",2021,3,15,teams);
    string pla[]={"Rabada","dhoni","bravo","yuvraj","pant","hetmeyer","boult","ngidi","starc","rahul","shami","karthik","shiraj","iyer","raina","jadeja"};
    int mb[]={10000,20000,30000,40000,20000,30000,14000,12000,10500,10060,10000,11000,90000,55000,100000,};
    string role[]={"bat","bat","bat","bat","bat","bat","bowl","bowl","bowl","bowl","bowl","bowl","ALL-ROUNDER","All-Rounder","All-Rounder"};
    players p(pla,mb,role);

        while(1){
        cout<<"\n\n";

        cout<<"\t\t\tWELCOME TO\t"<<t.tourname<<"\tYEAR"<<t.touryear<<"\n"<<endl;
        cout<<"================================================================\n";
        cout<<"|                           1.DISPLAY PLAYERS LIST         |\n";
        cout<<"================================================================\n";
        cout<<"|                           2.CONDUCT AUCTION              |\n";
        cout<<"================================================================\n";
        cout<<"|                           3.DISPLAY TEAMS                |\n";
        cout<<"================================================================\n";
        cout<<"|                           4.DISPLAY MATCH FIXTURE        |\n";
        cout<<"================================================================\n";
        cout<<"|                           5.MATCH DAY                    |\n";
        cout<<"================================================================\n";
        cout<<"|                           6.DISPLAY MATCHES WINNERS LIST     |\n";
        cout<<"================================================================\n";
        cout<<"|                           7.FINAL WINNER                 |\n";
        cout<<"================================================================\n";
        cout<<"|                           8.QUIT                         |\n";
        cout<<"================================================================\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

        cout<<"\n\n                   ENTER CHOICE:----                         \n";

int x;

        cin>>x;
 try{


        if(x==1)
        {
            p.playerlist();
        }
        else if(x==2)
        {

            if(aa.b==0)
               aa.startauction(pla,mb,teams,role);
            else
                cout<<"\n\n\t\t\tAuction is Done";


        }
        else if(x==3)
        {
            aa.showDelhiteam();
            aa.showChennai();
            aa.showBangalore();
        }
        else if(x==4)
        {

            cout<<"\n\t\t\tFixture of Tournament\n\n";
            for(int i=0;i<3;i++)
            cout<<"\n\n\t\tMatch"<<i+1<<".\t "<<t.teams[tf1[i]]<<"VS"<<t.teams[tf2[i]];
        }
        else if(x==5)
        {
            vector<match*> roles;
            int choice;
            cout << "\n\n\t\tNormal Match(1)\n\n\t\tFinal Match(2)\n\n\t\tGo(0): ";

            while (true)
            {
    cin >> choice;
    if (choice == 0)
      break;
    roles.push_back(match::make_match(choice));
  }
  for (int i = 0; i < roles.size(); i++)
    roles[i]->winner();
  for (int i = 0; i < roles.size(); i++)
    delete roles[i];

        }

        else if(x==6)
        {
           tt.display();
        }
        else if(x==7)
        {

             int f;
            cin>>f;

            if(f==1){

            cout<<"\n\t\tFinal Winner of tournament"<<teams[matchwinners[3]];}
            else
                cout<<"\t\t\tFirst Play Final\n";
        }

        else if(x==8)
        {
            exit(0);

        }

        else
        {
            if(x<0 || x>8)
               throw makechoiceexception();
        }

    }

     catch(makechoiceexception &c)
    {
        cout<<"\n  !!!!!!!!!! EXCEPTION:  "<<c.what()<<endl;
    }
        }
    return 0;
}
