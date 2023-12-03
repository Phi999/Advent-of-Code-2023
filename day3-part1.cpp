#include <fstream>

using namespace std;
ifstream cin("c.in");
ofstream cout("c.out");
char m[10005][10005];
long long sum = 0;
string s;
bool verif(int x, int y)
{
    //x + 1, y
    //x, y + 1
    //x + 1, y + 1
    //x -1, y
    //x, y-1
    //x-1, y-1
    //x+1, y - 1
    //x-1, y + 1
    if(m[x+1][y] != '.' &&!isdigit(m[x+1][y]))return true;
    if(m[x][y+1] != '.' &&!isdigit(m[x][y+1]))return true;
    if(m[x+1][y+1] != '.' &&!isdigit(m[x+1][y+1]))return true;
    if(m[x-1][y] != '.' &&!isdigit(m[x-1][y]))return true;
    if(m[x-1][y-1] != '.' &&!isdigit(m[x-1][y-1]))return true;
    if(m[x][y-1] != '.' &&!isdigit(m[x][y-1]))return true;
    if(m[x+1][y-1] != '.' &&!isdigit(m[x+1][y-1]))return true;
    if(m[x-1][y+1] != '.' &&!isdigit(m[x-1][y+1]))return true;
    return false;
}
int main()
{
    for(int i = 0; i<=500; i++)
        for(int j = 0; j<=500; j++)
            m[i][j] = '.';

    long long n = 140;//the size of the input!
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cin >> m[i][j];
        }
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            int nr = 0;
            int x = 1;
            if(isdigit(m[i][j]))
            {
                nr = m[i][j] - '0';
                m[i][j] = '.';
                if(isdigit(m[i][j+1]))
                {
                    x++;
                    nr = nr * 10 + (m[i][j+1]-'0');
                    m[i][j+1] = '.';
                    if(isdigit(m[i][j+2]))
                    {
                        x++;
                        nr = nr * 10 + (m[i][j + 2] - '0');
                        m[i][j+2] = '.';
                    }
                }
                //for x = 1
                if(x == 1) //one cif.
                {
                    if(verif(i, j))//True
                        sum+=nr;

                }
                if(x == 2) //2 cif.
                {
                    if(verif(i, j) || verif(i, j +1))sum+=nr;

                }
                if(x == 3) //3 cif.
                {
                    if(verif(i, j) || verif(i, j +1) || verif(i, j + 2))sum+=nr;

                }


                //
                //  cout<<nr<<endl;
            }
        }
    }
    cout<< sum;


    return 0;
}
