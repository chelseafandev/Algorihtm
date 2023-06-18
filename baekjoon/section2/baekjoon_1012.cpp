#include <iostream>
#include <vector>
#include <stack>

// M, N의 최대 범위로 전역 변수로 잡고 사용하자
int M, N, K;
bool adj[51][51];
bool visited[51][51];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin >> T;
    int result[T];
    for (int tc = 0; tc < T; tc++)
    {
        result[tc] = 0;
        M = 0;
        N = 0;
        K = 0;
        std::cin >> M;
        std::cin >> N;
        std::cin >> K;

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                adj[i][j] = false;
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < K; i++)
        {
            int y, x;
            std::cin >> y;
            std::cin >> x;
            adj[y][x] = true;
        }

        // dfs로 풀기위해 스택 선언!
        std::stack<std::pair<int,int>> s;

        // matrix 전체 좌표를 순회하며 dfs로 완성되는 컴포넌트가 몇개인지 찾는다
        for (int y = 0; y < M; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (!adj[y][x] || visited[y][x]) continue;

                s.push(std::make_pair(y, x));
                while(!s.empty())
                {
                    auto popped = s.top();
                    s.pop();
                    visited[popped.first][popped.second] = true;

                    for (int i = 0; i < 4; i++)
                    {
                        int ny = popped.first + dy[i];
                        int nx = popped.second + dx[i];
                        if (ny < 0 || nx < 0 || ny > M - 1 || nx > N -1) continue;
                        if (!adj[ny][nx]) continue;
                        if (visited[ny][nx]) continue;

                        s.push(std::make_pair(ny, nx));
                    }    
                }
                result[tc]++;
            }
        }
    }

    for (const auto& r : result)
    {
        printf("%d\n", r);
    }

    return 0;
}