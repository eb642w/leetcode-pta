#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


struct patCode{
    string code;
    int score;
};

struct class3{
    string site;
    int num;
};

bool levelCmp(patCode a, patCode b)
{
    if(a.score == b.score)
        return a.code < b.code;
    return a.score > b.score;
}

bool levelCmp2(class3 a, class3 b)
{
    if(a.num == b.num)
        return a.site < b.site;
    return a.num > b.num;
}

int main()
{
    vector<patCode> inputCode;
    //vector<patCode> res;
    patCode toInput;
    int totalNum, caseNum;

    cin >> totalNum >> caseNum;
    //res.resize(totalNum);
    for(int i = 0;i <totalNum;++i)
    {
        cin >> toInput.code >> toInput.score;
        inputCode.push_back(toInput);
    }

    for(int i = 1;i <= caseNum;++i)
    {
        int caseConfig;
        cin >> caseConfig;
        if(caseConfig == 1)
        {
            char level;
            cin >> level;
            vector<patCode> toOut;
            for(int j = 0;j < totalNum;++j)
            {
                if(inputCode[j].code[0] == level)
                    toOut.push_back(inputCode[j]);
            }
            cout << "Case " << i <<": " << caseConfig << " " << level << "\n";
            if(toOut.empty())
            {
                cout << "NA" <<"\n";
                continue;
            }
            sort(toOut.begin(), toOut.end(), levelCmp);

            for(int j = 0;j < toOut.size();++j)
            {
                cout << toOut[j].code << " " << toOut[j].score << "\n";
            }
        }

        if(caseConfig == 2)
        {
            string testSite;
            cin >> testSite;
            vector<patCode> toOut;
            int testSiteNum(0), testSiteScore(0);
            cout << "Case " << i <<": " << caseConfig << " " << testSite << "\n";
            for(int j = 0;j < totalNum;++j){
                if(testSite ==  inputCode[j].code.substr(1,3))
                    testSiteNum++, testSiteScore += inputCode[j].score;
            }
            if(testSiteNum == 0)
            {
                cout << "NA" <<"\n";
                continue;
            }
            cout << testSiteNum << " " << testSiteScore << "\n";
        }

        if(caseConfig == 3)
        {
            string testeeDate;
            cin >> testeeDate;
            vector<patCode> toOut;
            vector<class3> toRes;
            cout << "Case " << i <<": " << caseConfig << " " << testeeDate << "\n";
            for(int j = 0;j < totalNum;++j)
            {
                if(testeeDate == inputCode[j].code.substr(4, 6))
                {
                    string site = inputCode[j].code.substr(1,3);

                    bool flag = false;
                    for(auto& p:toRes)
                    {
                        if(p.site == site)
                        {
                            p.num++;
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        class3 r;
                        r.site = site;
                        r.num = 1;
                        toRes.push_back(r);
                    }
                }
            }
            if(toRes.empty())
            {
                cout << "NA" <<"\n";
                continue;
            }
            sort(toRes.begin(),toRes.end(),levelCmp2);
            for(int j = 0;j < toRes.size();++j)
            {
                cout << toRes[j].site << " " << toRes[j].num << "\n";
            }
        }
    }

}
