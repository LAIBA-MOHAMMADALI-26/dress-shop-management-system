#include<string.h>
#include<string>
#include<stdio.h>
#include<fstream>
#include<iostream>
using namespace std;

class dress{

        protected:

            char filename[20];
            char dressname[60];
            char dressid[10];
            float price;
            void get();
};


void dress::get()
           {
        cout<<"\n ENTER DRESS ID  NO : ";
        cin>>dressid;
        cout<<"\n ENTER  DRESS NAME  : ";
        cin>>dressname;
        cout<<"\n ENTER DRESS PRICE  : ";
        cin>>price;

        

           }

class male:protected dress
{
   public:
        male();

};
male::male()
        {
         get();
         

        strcpy(filename,dressid);
        strcat(filename,".txt");
        ifstream test(filename);
        if(test){
          cout<<"\n\n\tDress with this id already exists, try a different id\n\n\n";
          }
        else{
        ofstream  a(filename);
        a<<"MALE\n";
        a<<"\n\nDRESS NAME  :"<<dressname;
        a<<"\n\nDRESS ID  :"<<dressid;
        a<<"\n\nPRICE     :"<<price;

        fstream x("MALE.txt",ios::app|ios::out);
        x<<dressid;
        x<<"\t"<<dressname;
        x<<"\t "<<price<<endl;
        x.close();
        a.close();
        }
        test.close();
        }



class female:protected dress{

                public:
                     female();

                 };

female::female()
        {
         get();
         

        strcpy(filename,dressid);
        strcat(filename,".txt");
        ifstream test(filename);
        if(test){
          cout<<"\n\n\tDress with this id already exists, try a different id\n\n\n";
          }
        else{
        ofstream  a(filename);
        a<<"FEMALE\n";
        a<<"\n\nDRESS NAME  :"<<dressname;
        a<<"\n\nDRESS ID  :"<<dressid;
        a<<"\n\nPRICE     :"<<price;

        fstream x("FEMALE.txt",ios::app|ios::out);
         x<<dressid;
         x<<"\t"<<dressname;
         x<<"\t "<<price<<endl;
         x.close();
        a.close();
        }
        test.close();
        
        }

class childrn:protected dress

{

          public:
              childrn();
};


childrn::childrn()
        {
         get();
         

        strcpy(filename,dressid);
        strcat(filename,".txt");
        ifstream test(filename);
        if(test){
          cout<<"\n\n\tDress with this id already exists, try a different id\n\n\n";
          }
        else{
        ofstream  a(filename);
        a<<"CHILD\n";
        a<<"\n\nDRESS NAME  :"<<dressname;
        a<<"\n\nDRESS ID  :"<<dressid;
        a<<"\n\nPRICE     :"<<price;

        fstream x("CHILD.txt",ios::app|ios::out);
         x<<dressid;
         x<<"\t"<<dressname;
         x<<"\t "<<price<<endl;
         x.close();
        a.close();
        }
        test.close();
        }


class add {

     private:
             int i;

     public:
             add();

       };

add::add()
{
    

      while(1)
     {
        
        cout<<"\n";
        cout<<"\t\t Categories of the dress products\n\n";
        cout<<"\n\n01. MALE. \n\n02. FEMALE. \n\n03. CHILDREN  OR";
        cout<<"\n\n04. EXIT. ";
        cout<<"\n\n\n\t Enter your option :";
        cin>>i;


        if(i==1)
        {
            male m;
        }

        if(i==2)
        {
            female f;
        }

        if(i==3)
        {
            childrn c;
        }
        if(i==4)

        break;

     }
}


class seearch{

      private:
               int m;
               char ch;

      public:
               seearch();

         };


seearch::seearch(){

              while(1)

                {


                     cout<<"\n\n 01.Male";
                     cout<<"\n\n 02.Female";
                     cout<<"\n\n 03.Children";
                     cout<<"\n\n 04.Search by id";
                     cout<<"\n\n 05.Exit";
                     cout<<"\n\n\t Select an option :";
                     cin>>m;


                       if(m==1)

                        {

                         ifstream m("MALE.txt");
                         while(m)

                           {
                            m.get(ch);
                            cout<<ch;


                           }


                          }

                       if(m==2)

                        {
                         ifstream m("FEMALE.txt");
                         while(m)

                           {
                             m.get(ch);
                             cout<<ch;


                           }


                        }


                       if(m==3)
                        {
                          ifstream m("CHILD.txt");
                          while(m)
                           {
                             m.get(ch);
                             cout<<ch;


                           }


                         }

                       if(m==4)
                        {
                          char id[10],filename[20];

                          cout<<"input id for search:";
                          cin>>id;
                          strcpy(filename,id);
                          strcat(filename,".txt");
                          ifstream m(filename);

                          while(m)

                               {
                               m.get(ch);
                               cout<<ch;


                            }

                        }

                        if(m==5)
                        break;




          }

        }


class cut{

    public:
         cut();

      };

cut::cut()
     {         string idd; string file;
              string category;
           cout<<"\n\nEnter the id to delete : ";
           cin>>idd;
           file = idd + ".txt";
           ifstream in(file);
           getline(in,category);
           
           in.close();
           remove(file.c_str());
           
                  string line;

                  category+=".txt";
                  
                  in.open(category);
                  ofstream temp;
                  temp.open("temp.txt");

                  while (!in.eof()) {
                          getline(in, line);
                          if(line[0]!= idd[0] && line[1]!=idd[1]){
                            temp<< line << std::endl;}
                  }

                  temp.close();
                  in.close();

                  // required conversion for remove and rename functions
                  const char * p = category.c_str();
                  remove(p);
                  rename("temp.txt", p);

     }

class manager{
    public:
        manager();
};

manager::manager(){
    int i;

         

        while(1)
               {

                cout<< "Choose an option\n\n";
                cout<< "\n\t01. Add a product.\n";
                cout<< "\n\t02. Search any product.\n";
                cout<< "\n\t03. Delete any product.\n";
                cout<< "\n\t04. Exit.";
                cout<< "\n\n\nEnter an option :";
                cin>>i;

                if(i==1)
                   {
                   add a;
                   }

                if(i==2)
                {

                    seearch s;

                }

                 if(i==3)
                {
                    cut c;
                }

                  if(i==4)
                  break;

               }
}
  int main()

     {
         manager m;

       return 0;

     }
