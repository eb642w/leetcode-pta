#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <limits.h>
using namespace std;

struct studentGR
{
    string id;
    int C, E, M, A;
    int bestRank;
    string bestSub;
};

vector<studentGR> totalStudents;

bool cmpA(studentGR& a, studentGR& b){
    if(a.A == b.A)
    {
        if(a.C == b.C)
        {
            if(a.M == b.M)
            {
                return a.E > b.E;
            }
            return a.M > b.M;
        }
        return a.C > b.C;
    }
    return a.A > b.A;
};

bool cmpC(studentGR& a, studentGR& b){
    if(a.C == b.C)
    {
        if(a.M == b.M)
        {
            return a.E > b.E;
        }
        return a.M > b.M;
    }
    return a.C > b.C;
};

bool cmpM(studentGR& a, studentGR& b){
    if(a.M == b.M)
    {
        return a.E > b.E;
    }
    return a.M > b.M;
};

bool cmpE(studentGR& a, studentGR& b){
    return a.E > b.E;
};

int main()
{
    int n, m;
    cin >> n >> m;
    totalStudents.resize(n);
    for(int i = 0;i < n;++i)
    {
        cin >> totalStudents[i].id >>totalStudents[i].C>> totalStudents[i].M >> totalStudents[i].E;
        totalStudents[i].A = (totalStudents[i].M + totalStudents[i].E + totalStudents[i].C)/3;
        totalStudents[i].bestRank = INT_MAX;
    }





    int lastGeade;
    sort(totalStudents.begin(), totalStudents.end(),cmpA);
    for(int i = 0;i <n;++i)
    {
        /*int rank;
        if(i >= 1 and totalStudents[i].A == lastGeade)
        {
            rank = i - 1;
        }*/
        if(totalStudents[i].bestRank > i+1)
        {
            totalStudents[i].bestRank = i+1;
            totalStudents[i].bestSub = "A";

        }

        lastGeade = totalStudents[i].A;

    }

    sort(totalStudents.begin(), totalStudents.end(),cmpC);
    for(int i = 0;i <n;++i)
    {
        if(totalStudents[i].bestRank > i+1)
        {
            totalStudents[i].bestRank = i+1;
            totalStudents[i].bestSub = "C";
        }
    }

    sort(totalStudents.begin(), totalStudents.end(),cmpM);
    for(int i = 0;i <n;++i)
    {
        if(totalStudents[i].bestRank > i+1)
        {
            totalStudents[i].bestRank = i+1;
            totalStudents[i].bestSub = "M";
        }
    }

    sort(totalStudents.begin(), totalStudents.end(),cmpE);
    for(int i = 0;i <n;++i)
    {
        if(totalStudents[i].bestRank > i+1)
        {
            totalStudents[i].bestRank = i+1;
            totalStudents[i].bestSub = "E";
        }
    }


















    for(int i = 0;i < m;++i)
    {

        string toSea;
        cin >> toSea;
        bool flag = false;
        for(int j = 0;j < n;++j)
        {
            flag = false;
            if(totalStudents[j].id == toSea)
            {
                flag = true;
                cout << totalStudents[j].bestRank << " " << totalStudents[j].bestSub <<"\n";
                break;
            }
        }
        if(!flag)
            cout << "N/A\n";
    }
    return 0;
}
