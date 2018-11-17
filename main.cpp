#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void word_ladder(vector <string> &dectionary,vector <string> chain,string start_word,string end_word)
{
    char new_letter;
    int n,c,counter=0;
    string new_word;
            cout<<"do you have a ladder word\n1-Yes\n2-No\n";
            cin>>c;
            switch (c)
            {
            case 1:
            {
                cout<<"enter the number of the letter that you want to change : ";
                cin>>n;
                cout<<"enter the new letter : ";
                cin>>new_letter;
                for(int i=0; i<start_word.length(); i++)
                {
                    if(i==n-1)
                    {
                        start_word[i]=new_letter;
                        chain.push_back(start_word);
                        cout<<start_word<<endl;
                    }
                }
                break;
            }
            case 2:
                {

                    while(counter<dectionary.size())
                    {
                        int m=0,choice;
                        if(start_word.length()==dectionary[counter].length())
                        {
                            new_word=dectionary[counter];
                        }
                        else
                            {
                                counter++;
                        continue;
                        }
                        for(int i=0;i<start_word.length();i++)
                        {
                            if(start_word[i]!=new_word[i])
                                m++;
                        }
                        if(m==1)
                        {
                            cout<<new_word<<endl;
                            cout<<"do you want this word ?\n1-yes\n2-No\n ";
                            cin>>choice;
                        }
                        else
                        {
                            counter++;
                            continue;
                        }
                        if(choice==1)
                        {
                            chain.push_back(new_word);
                            counter++;
                            break;
                        }
                        else
                        {
                            counter++;
                            continue;
                        }
                    }
                    break;
                }

            }
            if(start_word!=end_word)
                return word_ladder(dectionary,chain,start_word,end_word);
}
int main()
{
    string word;
    vector <string> dectionary;
    vector <string> chain;
    string start_word,end_word;
    ifstream file;
    file.open("words.txt");
    while(file>>word)
    {
        dectionary.push_back(word);
    }
    cout<<"please enter the start word and the end word"<<endl;
    cin>>start_word>>end_word;
    if(start_word.length()==end_word.length())
    {
        word_ladder(dectionary,chain,start_word,end_word);
    }
    cout<<"congratulation !"<<endl;
    return 0;
}
