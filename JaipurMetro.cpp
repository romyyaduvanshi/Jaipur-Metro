#include<bits/stdc++.h>
using namespace std;
class Graph
{
      private:
      unordered_map<string,list<pair<string,int> > > l;
       public:
       void addedge(string x,string y,int wt){
           l[x].push_back(make_pair(y,wt));
           l[y].push_back(make_pair(x,wt));
       }
      
      void display_Stations(){
            for(auto p:l){
               cout<<" "<<p.first<<endl;   
           }
      }
      
      void display_Map(){
           cout<<"\t Jaipur Metro Map"<<endl;
      cout<<"\t------------------"<<endl;
      cout<<"----------------------------------------------------\n"<<endl;
       
        for(auto p:l){
               cout<<p.first<<" => "<<endl;
               for(auto x:p.second){
                   cout<<"\t\t"<<x.first<<"\t\t"<<x.second<<endl;
               }
               cout<<endl;
           }
       cout<<"\t------------------"<<endl;
      cout<<"---------------------------------------------------\n"<<endl;
      }
      
         void dijkstra(string src){
           unordered_map<string,int> dist;
           for(auto p:l){
               dist[p.first]=INT_MAX;
           }
           set<pair<int,string> > s;
           dist[src]=0;
           s.insert(make_pair(0,src));
           while(!s.empty()){
               auto p=*(s.begin());
               int citydistance=p.first;
               string city=p.second;
               s.erase(s.begin());
               for(auto nbrcity:l[city]){
                   if(citydistance+nbrcity.second < dist[nbrcity.first]){
                       string destination=nbrcity.first;
                       auto f=s.find(make_pair(dist[destination],destination));
                       if(f!=s.end()){
                           s.erase(f);
                       }
                       dist[destination]=citydistance+nbrcity.second;
                       s.insert(make_pair(dist[destination],destination));
                   }
               }
           }
           cout<<"***********************************************************"<<endl;
           cout<<"-------------------------------------------------------------"<<endl;
           for(auto d:dist){
               cout<<src<<" to "<<d.first<<"\t"<<d.second<<endl;
           }
           cout<<"-------------------------------------------------------------"<<endl;
           cout<<"***********************************************************"<<endl;
       }
      
};
 

int main(){

Graph g;
        g.addedge("sindhi camp","jaipurrailway",6);
        g.addedge("jaipurrailway","civil lines",6);
        g.addedge("civil lines","ram nagar",6);
        g.addedge("ram nagar","shyam nagar",6);
        g.addedge("shyam nagar","vivek vihar",6);
        g.addedge("vivek vihar","aatish market",6);
        g.addedge("aatish market","mansarovar",6);
        int choice=1 ;
         
       while(choice){
       cout<<"\n\t\t\t****WELCOME TO THE METRO APP*****"<<endl;
       cout<<"\t\t\t\t~~LIST OF ACTIONS~~\n\n"<<endl;
       cout<<"1. LIST ALL THE STATIONS IN THE MAP"<<endl;
       cout<<"2. SHOW THE METRO MAP"<<endl;
       cout<<"3. GET SHORTEST DISTANCE FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
      /* cout<<"4. GET SHORTEST TIME TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
       cout<<"5. GET SHORTEST PATH (DISTANCE WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
       cout<<"6. GET SHORTEST PATH (TIME WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;*/
       cout<<"4. EXIT THE MENU"<<endl;
       cout<<"\nENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 4) : ";
       cin>>choice;
       cout<<"\n***********************************************************\n"<<endl;
      switch (choice)
      {
      case 1:
           g.display_Stations();
           cout<<"*************************************************************"<<endl;
          break;
      case 2:
           g.display_Map();
           break;
     case 3:
           g.dijkstra("ram nagar");
           break;
    case 4:
         exit(0);
      default:
          break;
      }
    }
           return 0;

}

