#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// mid ��ŭ�� �ο��� ¡�˴ٸ��� �ǳ� �� 0�� �Ǵ� ���� ���� ã��
int check(int mid, vector<int>& stone) {
    int cnt = 0,Max = 0;

    for (int i = 0; i < stone.size(); i++) {
        if (stone[i] - mid <= 0) cnt++; // 0�� �Ǵ� ���� ���� ����
        else {
            Max = max(Max, cnt); // �������� 0�� �Ǵ� �� = Max
            cnt = 0;
        }
    }
    Max = max(Max, cnt);
    return Max; 
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left=1,right= *max_element(stones.begin(), stones.end());


    if (k > 1) {
    // �ǳ� �� �ִ� ������� ������ 1������ ���ٸ� �̺� Ž��

        while (left != right) {
            int mid = (left + right) / 2; // ¡�˴ٸ��� �ǳ� �ο�
            int tmp = check(mid, stones);

            if (tmp >= k) right = mid; // �������� 0�� �Ǵ� ���� ������ k���� ũ�ų� ������ => �ǳ� �ο��� ���δ�.
            else left = mid + 1; // �������� 0�̵Ǵ� ���� ������ ���� �� => �ǳ� �ο��� �ø���.
        }
    }
    else left = *min_element(stones.begin(), stones.end()); 
    // �ǳ� �� �ִ� ������� ������ 1���̸� �ּҰ� ��ŭ ģ������ �ǳ� �� �ִ�.

    answer = left;
    return answer;
}

/*
    �����̵� ������ �������� ���� => �ð��ʰ�
    int answer = max_element(stones.begin(), stones.end());

    if (k > 1) {
        for (int i = 0; i < stones.size() - k+1; i++) {
            int Max = *max_element(stones.begin() + i, stones.begin() + i + k); -> ������ ũ�⸸ŭ üũ�ؼ� �ִ� �� ã��
           answer = min(answer,Max); -> �ִ� ���� �ּ� �� ã��
        }
    }
    else answer = *min_element(stones.begin(), stones.end());
    return answer;

*/

/*
    1. r=5 l=1 , mid = 3 , tmp = 3 
    2. r=3 l=1 , mid = 2 , tmp = 2 
    3. r=3 l=3 , break, answer=left  
*/