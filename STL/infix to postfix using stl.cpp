#include<iostream>
#include<queue>
using namespace std;

class Stack
{
   queue<char> q1,q2;

   public:
   
   void Push(char x)
   {
       q1.push(x);
       return;
   }
   void Pop()
   {
     if(!q1.empty())
     {
        int Size=q1.size();
        for(int i=0;i<Size-1;i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        for(int j=0;j<Size-1;j++)
        {
            q1.push(q2.front());
            q2.pop();
        }


     }
   }
   
   char Top()
   {
    if(q1.empty())
    return -1;
    else
    return q1.back();
   }

   int empty()
   {
    int x=0;
        try
        {
            if(q1.empty())
            throw x;
        }
        catch(int x)
        {
            cout<<"stack is empty!!"<<endl;
            return 0;
        }
        return 1;
   }

};
bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int preced(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
}

string InfixToPostfix(string infix)
{
	string postfix="";   //initially the postfix string is empty
    Stack stk;
	stk.Push('#');               //add some extra character to avoid underflow
          
   string::iterator it;

   for(it = infix.begin(); it!=infix.end(); it++) 
   {
      if(isalnum(char(*it)))  // number or letter
         postfix += *it;     
      else if(*it == '(')
         stk.Push('(');
      else if(*it == '^')
         stk.Push('^');
      else if(*it == ')') 
      {
         while(stk.Top() != '#' && stk.Top() != '(') 
         {
            postfix += stk.Top(); 
            stk.Pop();
         }
         stk.Pop();          
      }
      else 
      {
         if(preced(*it) > preced(stk.Top()))
            stk.Push(*it); 
         else 
         {
            while(stk.Top() != '#' && preced(*it) <= preced(stk.Top())) 
            {
               postfix += stk.Top();        
               stk.Pop();
            }
            stk.Push(*it);
         }
      }
   }

   while(stk.Top() != '#') 
   {
      postfix += stk.Top();     
      stk.Pop();
   }

	
	return postfix;
}

bool is_infix_crct(string infix)
{   
    Stack s1;
    bool valid=true;
    char top;
   
         
           string::iterator it;

           for(it = infix.begin(); it!=infix.end(); it++) 
           {
              if(isalnum(char(*it)))
              valid=true;
              else if(char(*it)=='+' || char(*it)=='-' || char(*it)=='*' || char(*it)=='/' )
              valid=true;
              else
              {
              valid=false;
              break;
              }
           }
              return valid;
           }

int main()
{
      int ch;
    string s1;
    cout<<"****menu****"<<endl;
    cout<<"1.Get Infix Expression\n2.Print Infix Expression\n3.Print Postfix Expression\n4.Exit"<<endl;
    cout<<"enter your choice : ";
    cin>>ch;
    while(ch<0 & ch>4)
    {
        cout<<"enter valid choice : ";
        cin>>ch;
    }
    while(ch)
    {
        switch(ch)
        {
            case 1 :
            {
                cin>>s1;
                try
                {
                    if(is_infix_crct(s1) == false)
                    throw is_infix_crct(s1);
                }
                catch(bool is_infix_crct)
                {
                    cout<<"enter a valid expression"<<endl;
                }
                cout<<"\n****menu****"<<endl;
                cout<<"1.Get Infix Expression\n2.Print Infix Expression\n3.Print Postfix Expression\n4.Exit"<<endl;
                cout<<"enter your choice : ";
                cin>>ch;
                break;
            }

            case 2 :
            {
               
               cout<<s1;
               cout<<"\n****menu****"<<endl;
               cout<<"1.Get Infix Expression\n2.Print Infix Expression\n3.Print Postfix Expression\n4.Exit"<<endl;
               cout<<"enter your choice : ";
               cin>>ch;

               break;

            }
            case 3 : 
            {
                string s2;
                s2=InfixToPostfix(s1);
                cout<<s2<<endl;
                cout<<"\n****menu****"<<endl;
                cout<<"1.Get Infix Expression\n2.Print Infix Expression\n3.Print Postfix Expression\n4.Exit"<<endl;
                cout<<"enter your choice : ";
                cin>>ch;

               break;



            }
            case 4 : 
            {
                cout<<"closing programme....";
                return 0;

            }
        }
    }
    

}