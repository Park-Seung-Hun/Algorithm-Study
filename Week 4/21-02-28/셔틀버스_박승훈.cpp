#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    // ũ��� �����ð��� ������������ ����.
    sort(timetable.begin(), timetable.end());

        queue<int> bus;
    map<int, vector<int>> line;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        int busTime = 540 + i * t;
        bus.push(busTime); // ���� �ð�


        for (int j = idx; j < timetable.size(); j++) {
            int Hour = stoi(timetable[j].substr(0, 2));
            int Min = stoi(timetable[j].substr(3, 2));
            int Time = Hour * 60 + Min; // ũ��� ���� �ð�

            if (line[busTime].size() < m && Time <= busTime) line[busTime].push_back(Time); // ���� �ð��� ũ��� �����ð��� �°� �� �����
            else { 
                idx = j;
                break; 
            }

        }
    }

    /* ���� ���� �ð� ���ϱ� */
    int ans = 0;
    while (!bus.empty()) {
        int bus_ = bus.front();
        bus.pop();

        /* �� ���� �ο�(line[bus_].size())�� ��Ʋ ������ ���� ���� ���� ��� ���� ���� �ð��� ����
        *  �� ���� �ο�(line[bus_].size())�� ��Ʋ ������ ���� ���� ���ų� ���� ��� ���� �� �� ������ ��� �ð� -1 
        */ 
        if (line[bus_].size() < m) ans = bus_; 
        else ans = line[bus_][line[bus_].size() - 1]-1;
    }

    string H, M;
    if (ans / 60 > 9) H = to_string(ans / 60);
    else H = '0' + to_string(ans / 60);

    if (ans % 60 > 9) M = to_string(ans % 60);
    else M = '0' + to_string(ans % 60);

    answer = H + ':' + M;
    return answer;
}