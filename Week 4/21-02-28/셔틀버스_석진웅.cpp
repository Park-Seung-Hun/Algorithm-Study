#include <bits/stdc++.h>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> list;
    int res=0;
    //시간을 전부 분 단위로 맞추는 과정
    for(int i=0;i<timetable.size();i++){
        istringstream ss(timetable[i]);
        string buf;
        vector<int> v;
        while(getline(ss,buf,':')){
            v.push_back(stoi(buf));
        }
        int time=0;
        time+=v[0]*60;
        time+=v[1];
        list.push_back(time);
    }
    //오름차순으로 정렬
    sort(list.begin(),list.end());
    //변수들 초기화
    int crew=list.size();
    int bus=540;
    int idx=0;
    vector<int> tmp[11];
    //i는 몇 번째 버스인지 나타냄
    for(int i=1;i<=n;i++){
        //idx는 현재 크루의 인덱스를 나타냄
        //idx가 크루보다 작고 버스도착시간과 같거나 작은 크루 시간들일때 수행
        while(idx<crew && bus>=list[idx]){
            //만약 승객 꽉찬다면 중지
            if(tmp[i].size()==m){
                break;
            }
            tmp[i].push_back(list[idx]);
            idx++;
        }
        //버스 다음 배차로 업데이트
        bus+=t;
    }
    //마지막 버스가 꽉 차있다면
    if(tmp[n].size()==m){
        int MAX=*max_element(tmp[n].begin(),tmp[n].end());
        res=MAX-1;
    }
    //꽉 차있지 않은 경우는 마지막 버스 배차시간에 가면된다.
    else{
        res=bus-t;
    }
    string hour=to_string(res/60);
    string minute=to_string(res%60);
    if(hour.size()==1){
        hour="0"+hour;
    }
    if(minute.size()==1){
        minute="0"+minute;
    }
    answer+=hour;
    answer+=":";
    answer+=minute;
    return answer;
}
