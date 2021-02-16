#include <string>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};
point left;
point right;
point arr[10]={
    {1,3},
    {0,0},
    {1,0},
    {2,0},
    {0,1},
    {1,1},
    {2,1},
    {0,2},
    {1,2},
    {2,2}
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    left.x=0;
    left.y=3;
    right.x=2;
    right.y=3;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            left.x=arr[numbers[i]].x;
            left.y=arr[numbers[i]].y;
            answer+="L";
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            right.x=arr[numbers[i]].x;
            right.y=arr[numbers[i]].y;
            answer+="R";
        }
        else{
            int ll = abs(left.x-arr[numbers[i]].x)+abs(left.y-arr[numbers[i]].y);
            int rr = abs(right.x-arr[numbers[i]].x)+abs(right.y-arr[numbers[i]].y);
            if(ll>rr){
                right.x=arr[numbers[i]].x;
                right.y=arr[numbers[i]].y;
                answer+="R";
            }
            else if(ll<rr){
                left.x=arr[numbers[i]].x;
                left.y=arr[numbers[i]].y;
                answer+="L";
            }
            else{
                if(hand=="left"){
                    left.x=arr[numbers[i]].x;
                    left.y=arr[numbers[i]].y;
                    answer+="L";
                }
                else{
                    right.x=arr[numbers[i]].x;
                    right.y=arr[numbers[i]].y;
                    answer+="R";
                }
            }
        }
    }
    return answer;
}
