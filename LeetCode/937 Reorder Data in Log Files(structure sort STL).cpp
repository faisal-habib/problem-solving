class Solution {
public:
    struct Info
    {
        int index;
        string identifier,log;
    }infoAr[102];

    static bool cmp(Info a,Info b)
    {
        if(a.log<b.log || (a.log==b.log && a.identifier<b.identifier) ) return true;
        return false;
    }

    bool isLetter(char ch)
    {
        if(ch>='a' && ch<='z') return true;
        return false;
    }

    vector<string> reorderLogFiles(vector<string>& logs)
    {
        vector<string>outputOrderedLogs;

        vector<int>digitLogIndex;

        int sz=logs.size();
        int infoSz=0;

        for(int i=0;i<sz;i++)
        {
            int j=0;
            string identifier="";

            for(j=0;j<logs[i][j];j++)
            {
                if(logs[i][j]==' ') break;
                identifier+=logs[i][j];
            }

            while(logs[i][j] && logs[i][j] == ' ' ) j++;

            if( isLetter(logs[i][j]) )
            {
                // letter log
                string letter="";
                while(logs[i][j])
                {
                    letter+=logs[i][j];
                    j++;
                }

                infoAr[infoSz].index=i;
                infoAr[infoSz].log=letter;
                infoAr[infoSz].identifier=identifier;
                infoSz++;
            }
            else
            {
                digitLogIndex.push_back(i);
            }
        }

        sort(infoAr, infoAr+infoSz, cmp);

        for(int i=0;i<infoSz;i++)
        {
            int ind=infoAr[i].index;
            outputOrderedLogs.push_back(logs[ind]);
        }

        int dsz=digitLogIndex.size();
        for(int i=0;i<dsz;i++)
        {
            int ind=digitLogIndex[i];
            outputOrderedLogs.push_back(logs[ind]);
        }

        return outputOrderedLogs;
    }
};
