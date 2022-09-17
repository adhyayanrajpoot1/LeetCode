class Solution {
public:
    //to extract the count of days before month number given
    int days_convert(int month){
        vector<int> a{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int count=0;
        //we won't include the arrival month number days because its not complete yet.
        for(int i=0;i<=(month-1-1);i++) count+= a[i];
        return count;
    }

    int countDaysTogether(string a, string la, string b, string lb) {
        //Step A:  Get the integer form of day & month for Bob and Alice

        //First: For alice
        // 1: Start day and month
        int alice_arrive_month= (a[0]-'0')*10+(a[1]-'0');
        int alice_arrive_day  = (a[3]-'0')*10+(a[4]-'0');
        // 2: End day and month
        int alice_end_month   = (la[0]-'0')*10+(la[1]-'0');
        int alice_end_day     = (la[3]-'0')*10+(la[4]-'0');

        //Second: For Bob
        // 1: Start day and month
        int bob_arrive_month= (b[0]-'0')*10+(b[1]-'0'); 
        int bob_arrive_day  = (b[3]-'0')*10+(b[4]-'0');
        // 2: End day and month
        int bob_end_month   = (lb[0]-'0')*10+(lb[1]-'0');
        int bob_end_day     = (lb[3]-'0')*10+(lb[4]-'0');

        //Get count of day number according to 365 numbering with help of function days_convert()
        int alice_arrive_day_count=  days_convert(alice_arrive_month)+alice_arrive_day;
        int alice_end_day_count   =  days_convert(alice_end_month)+alice_end_day;
        int bob_arrive_day_count  =  days_convert(bob_arrive_month)+bob_arrive_day;
        int bob_end_day_count     =  days_convert(bob_end_month)+bob_end_day;


        //Step B : Line Sweep Technique

        int cnt[370]{};
        //Step 1 : Mark Boundaries
        cnt[alice_arrive_day_count]++;
        cnt[alice_end_day_count+1]--;
        cnt[bob_arrive_day_count]++;
        cnt[bob_end_day_count+1]--;

        //Take prefix and count days with overlapping count of 2
        int days=0, sum=0;
        for(int i:cnt){
            sum+= i;
            //found a count of 2 means , a day where both have their days common
            if(sum==2) days++;
        }
        return days;
    }
};