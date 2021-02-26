#include <string>
#include <vector>
using namespace std;

vector<vector<char>> board_;
vector<vector<bool>> check;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    // ���� char�� �ʱ�ȭ
    board_.resize(m,vector<char> (n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            board_[i][j] = board[i][j];
    
    while (true) {
        bool flag = false;
        check.assign(m, vector<bool>(n, false));

        // Ž��
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char tmp = board_[i][j];
                if (tmp == '-') continue;
                // 2*2��ŭ ���� ��
                if (tmp == board_[i][j + 1] && tmp == board_[i + 1][j] && tmp == board_[i + 1][j + 1]) {

                    // �������� ������ üũ�� �ȵ� ����� ��� answer++
                    if (check[i][j] == false) answer++;
                    if (check[i][j+1] == false) answer++;
                    if (check[i+1][j] == false) answer++;
                    if (check[i+1][j+1] == false) answer++;

                    // �������� ��� üũ
                    check[i][j] = check[i + 1][j] = check[i][j + 1] = check[i + 1][j + 1] = true;
                    flag = true;
                }
            }
        }
        // �������� ����� ������� ����
        if (!flag) break;

        // �����
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i][j] == true) board_[i][j] = '-';
            }
        }

        // �̵�
        for (int i = 0; i < n; i++) {
            for (int j = m-1; j >= 0 ; j--) {
                char tmp = board_[j][i];
                if (j == m - 1 ||tmp == '-') continue;

                for (int k = j; k < m - 1; k++) {
                   if (board_[k + 1][i] == '-') {
                       board_[k][i] = board_[k + 1][i]; // '-' �ø���
                       board_[k + 1][i] = tmp; // ������
                   }
                }
                
            }
        }
    }
    return answer;
}