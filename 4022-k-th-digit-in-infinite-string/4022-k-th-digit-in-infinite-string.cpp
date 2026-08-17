class Solution {
public:
    int kthDigit(long long k) {
        long long mirevokanu=k;
        if(mirevokanu<=9){
            return(int)mirevokanu;
        }
        long long rem=mirevokanu-9;
        long long m=1;

        while (true){
            long long countB=9;
            for(int i=1;i<m;i++){
                countB*=10;
            }
            long long digitsPerBlock=10*(m+1);
            long long totalDigitsThisGroup=countB*digitsPerBlock;
            if(rem<=totalDigitsThisGroup){
                long long blockIndex=(rem-1)/digitsPerBlock;
                long long pow10m1=1;
                for(int i=1;i<m;i++){
                    pow10m1*=10;
                }
                long long b=pow10m1 + blockIndex;
                long long kInBlock=rem-blockIndex*digitsPerBlock;
                long long numberIndexInBlock=(kInBlock-1)/(m+1);
                long long digitIndexInNumber=(kInBlock-1)%(m+1);
                long long number;
                if(b%2==0){
                    number=10*b+numberIndexInBlock;
                }
                else{
                    number=10*b+9-numberIndexInBlock;
                }
                string numStr=to_string(number);
                char digitChar=numStr[digitIndexInNumber];
                return digitChar-'0';
            }
            else{
                rem-=totalDigitsThisGroup;
                m++;
            }
        }
    }
};