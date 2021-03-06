#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    //시작하기전 캐시를 map<string, int> 를 사용해 도시이름을 키값으로하고 cities의 인덱스 업데이트 해주는 방식 사용했음
    for(int i=0;i<cities.size();i++){
        //전부 소문자로 통일시키기
        for(int j=0;j<cities[i].size();j++){
            if(cities[i][j]>='A' && cities[i][j]<='Z'){
                cities[i][j]+=32;
            }
        }
        //캐시사이즈가 0이면 계속 +5한다.
        if(cacheSize==0){
            answer+=5;
        }
        //만약 캐시가 꽉차있다면
        else if(m.size()==cacheSize){
            //캐시에 도시 이름 저장 안되있을시
            if(m.find(cities[i])==m.end()){
                int del=987654321;
                //사용한지 가장 오래된 정보 찾아 지우기
                for(auto& j:m){
                    del=min(del,j.second);
                }
                for(auto& j:m){
                    if(j.second==del){
                        m.erase(j.first);
                    }
                }
                //지운 뒤 새로운 도시 정보 업데이트
                m[cities[i]]=i;
                answer+=5;
            }
            //캐시에 도시 이름 저장되어 있을 시 그저 인덱스만 업데이트하기
            else{
                m[cities[i]]=i;
                answer+=1;
            }
        }
        //캐시가 꽉차있지않고 채워가는 과정
        else{
            //캐시에 도시 이름 저장 안된 경우
            if(m.find(cities[i])==m.end()){
                m[cities[i]]=i;
                answer+=5;
            }
            //캐시에 도시 이름 존재하는 경우
            else{
                m[cities[i]]=i;
                answer+=1;
            }
        }
    }
    return answer;
}
