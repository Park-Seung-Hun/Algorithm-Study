#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> cache;
vector<string>::iterator iter;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize > 0) {
        for (int i = 0; i < cities.size(); i++) {
            // cities�� ���� �ҹ��ڷ� �ٲ��ִ� ����
            for (int k = 0; k < cities[i].size(); k++) {
                cities[i][k] = tolower(cities[i][k]);
            }

            // find �Լ��� �̿��� cache���� cities[i]�� iter�� Ȯ��
            iter = find(cache.begin(), cache.end(), cities[i]);

            // erase�Լ��� ����� �����ش�. ( �ش� ��ġ�� ����� ��ĭ�� ���ܿ��� �Լ� )
            if (iter == cache.end()) { // cache miss
                if (cache.size() == cacheSize) cache.erase(cache.begin());
                answer += 5;
            }
            else { // cache hit
                cache.erase(iter);
                answer += 1;
            }
            cache.push_back(cities[i]);
        }
    }
    else answer = cities.size() * 5;

    return answer;
}