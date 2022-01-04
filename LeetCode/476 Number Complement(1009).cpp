/*
Target is to convert all 0 to 1 and 1 to 0.
Idea is to generate a binary number with all 1.
Then xor this number with the given number.
Result of xor will be the expected answer.
*/

class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0) return 1;
        int p = 0, tmp = N;

        while( tmp != 0 ) {
            p++;
            tmp >>= 1;
        }
        p = pow(2, p) - 1;
        return ( N^p );
    }
};

/* another approach */

/*
class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0) return 1;

        int sz=0;
        int num=N,bin[33],output=0;

        while(num!=0) {
            bin[sz++]=(num%2);
            num/=2;
        }

        //    bin = 100
        //    dec = 0 * 2 ^ 0 + 0 * 2 ^ 1 + 1 * 2 ^ 2 = 4

        for(int i=sz-1;i>=0;i--) {
            if(bin[i]) continue;

            output += (1 << i);
        }

        return output;
    }
};
*/
