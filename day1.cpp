#include <fstream>
#include <algorithm>
#include <string>

using namespace std;
ifstream cin("c.in");
ofstream cout("c.out");
string s;
long long sum;
int main()
{
    while(cin >> s)
    {

        int nr = 0;
        int v[10];
        v[1] = s.find("one");
        v[2] = s.find("two");
        v[3] = s.find("three");
        v[4] = s.find("four");
        v[5] = s.find("five");
        v[6] = s.find("six");
        v[7] = s.find("seven");
        v[8] = s.find("eight");
        v[9] = s.find("nine");
        int c[10];
        c[1] = s.find("1");
        c[2] = s.find("2");
        c[3] = s.find("3");
        c[4] = s.find("4");
        c[5] = s.find("5");
        c[6] = s.find("6");
        c[7] = s.find("7");
        c[8] = s.find("8");
        c[9] = s.find("9");
        int mini1 = 999, indicemin1, maxi1 = -2, indicemax1;
        int mini2 = 999, indicemin2, maxi2 = -2, indicemax2;

        for(int i = 1; i<=9; i++)
        {
            if(v[i] != -1){
            if(mini1 > v[i])
            {
                mini1 = v[i];//poz
                indicemin1 = i;
            }

            }

            //pt 2
            if(c[i] != -1){
            if(mini2 > c[i])
            {
                mini2 = c[i];//poz
                indicemin2 = i;
            }

            }
        }
        //mini1, indicemin1, mini2, indicemin2;
        int minisuprem;
        if(mini1 < mini2)minisuprem = indicemin1;
        else minisuprem = indicemin2;
//for(int i = 1; i<=9; i++)cout<<v[i]<<" "<<c[i]<<endl;
        v[1] = s.rfind("one");
        v[2] = s.rfind("two");
        v[3] = s.rfind("three");
        v[4] = s.rfind("four");
        v[5] = s.rfind("five");
        v[6] = s.rfind("six");
        v[7] = s.rfind("seven");
        v[8] = s.rfind("eight");
        v[9] = s.rfind("nine");
        c[1] = s.rfind("1");
        c[2] = s.rfind("2");
        c[3] = s.rfind("3");
        c[4] = s.rfind("4");
        c[5] = s.rfind("5");
        c[6] = s.rfind("6");
        c[7] = s.rfind("7");
        c[8] = s.rfind("8");
        c[9] = s.rfind("9");
//cout<<"***********"<<endl;
//for(int i = 1; i<=9; i++)cout<<v[i]<<" "<<c[i]<<endl;
        for(int i = 1; i<=9; i++)
        {
            if(v[i] != -1){
            if(maxi1 < v[i])
            {
                maxi1 = v[i];//poz
                indicemax1 = i;
            }

            }

            //pt 2
            if(c[i] != -1){
            if(maxi2 < c[i])
            {
                maxi2 = c[i];//poz
                indicemax2 = i;
            }

            }
        }
        int maxisuprem;

        if(maxi1 > maxi2)maxisuprem = indicemax1;
        else maxisuprem = indicemax2;


        if(mini1 == 999 && mini2 == 999 && maxi1 == -2 && maxi2 == -2)nr = 0;
        else if(maxisuprem == 0)nr = minisuprem*10 + minisuprem;
            else         nr = minisuprem*10 + maxisuprem;




        sum +=nr;
       // cout<<minisuprem<<" "<<maxisuprem<<endl<<s<<" "<<nr<<endl;
    }
    cout<<sum;
    return 0;
}
