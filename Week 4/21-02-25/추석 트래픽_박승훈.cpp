#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

typedef struct {
    string hour;
    string min;
    string sec;
    string msec;
    string check;
}Time;

bool cmp(pair<int,int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

vector<pair<int,int>> Res;

int solution(vector<string> lines) {
    int answer = 0;
    Time t1;

    /* �ð��� ����*/
    for (int i = 0; i < lines.size(); i++) {

        istringstream ss(lines[i]); // ���ڿ� ���� parsing �Ҷ� ���.
        string buffer;
        int idx=0;

        while (getline(ss, buffer, ' ')) { // ' ' �������� ���ڿ� parsing
            if (idx == 1) {
                istringstream ss_(buffer);
                string buffer_;
                int idx_ = 0;

                while (getline(ss_, buffer_, ':')) { // ':' �������� ���ڿ� parsing (�ð�)
                    if (idx_ == 0) t1.hour = buffer_; // h
                    else if (idx_ == 1) t1.min = buffer_; // m
                    else if (idx_ == 2) { 
                        t1.sec = buffer_.substr(0,2);  // s
                        t1.msec = buffer_.substr(3, buffer_.size() - 2); // ms
                    }
                    idx_++;
                }
            }
            else if (idx == 2) {
                buffer.pop_back();
                t1.check = buffer;
            } // ó�� �ð�
            idx++;
        }


        int end = (stoi(t1.hour) * 3600 + stoi(t1.min) * 60 + stoi(t1.sec)) * 1000 + stoi(t1.msec);
        int start = end +1 - int(stof(t1.check)*1000);
        
        Res.push_back(make_pair(start,0));
        Res.push_back(make_pair(end + 999,1)); // 999 ������ ������ ������ ������ �ٸ� ���� ������ 1�� �̳��� ���� ���� ����ϱ� ���ؼ�.
    }
    sort(Res.begin(), Res.end(), cmp); // �۾��� ���۰� �� �ð��� ���캸�� ���� ����.

    int Max = 0, cnt = 0;

    for (int i = 0; i < Res.size(); i++) {
        if (Res[i].second == 0) { // �۾��� ���� �ɶ�
            cnt++;
        }
        else { // �۾��� ���� ��
            cnt--;
        }
        Max = max(Max, cnt);
    }
    answer = Max;
    return answer;
}