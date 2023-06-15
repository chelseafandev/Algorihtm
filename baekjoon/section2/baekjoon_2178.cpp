#include <iostream>
#include <vector>
#include <queue>

int N, M = 0;
int min = 0;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

// 시간 초과!
void proceed(int y, int x, std::vector<bool> *adj, std::vector<bool> *visited, int count)
{
    if (min != 0 && count >= min)
    {
        return;
    }

    // arrive destination!
    if (y == (N - 1) && x == (M - 1))
    {
        if (min == 0)
        {
            min = count;
        }
        else
        {
            min = count > min ? min : count;
        }

        return;
    }

    // check 4 direction!
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // check validation!
        if (ny < 0 || nx < 0 || ny > (N - 1) || nx > (M - 1)) continue;
        if (!adj[ny][nx]) continue;
        if (visited[ny][nx]) continue;
        
        // update visited!
        visited[ny][nx] = true;

        // recursive call!
        proceed(ny, nx, adj, visited, count + 1);
        visited[ny][nx] = false; // 다시 되돌아갈때는 visited 값을 원래대로 돌린다(!)
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    std::cin >> M;

    std::vector<bool> adj[N];
    std::vector<bool> visited[N];
    std::vector<int> visited_for_shortest_path_using_bfs[N];

    std::string line;
    for (int i = 0; i < N; i++)
    {
        std::cin >> line;
        for (const auto& movable : line)
        {
            // fill `adj`
            if (movable == '1')
            {
                adj[i].push_back(true);
            }
            else
            {
                adj[i].push_back(false);    
            }

            // fill `visited` (initialization)
            visited[i].push_back(false);
            visited_for_shortest_path_using_bfs[i].push_back(0);
        }
    }

    // 시간 초과!
    // int count = 1;
    // visited[0][0] = true;
    // proceed(0, 0, adj, visited, count);
    // printf("%d\n", min);

    // BFS로 최단거리 구할 때, visited를 활용한다는 것을 꼭 기억하자!!
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, 0));
    visited_for_shortest_path_using_bfs[0][0] = 1;

    while(!q.empty())
    {
        auto popped = q.front();
        q.pop();

        // 인접한 4방향에서 접근이 가능한 좌표를 queue에 push!
        for (int i = 0; i < 4; i++)
        {
            int ny = popped.first + dy[i];
            int nx = popped.second + dx[i];

            // check validation!
            if (ny < 0 || nx < 0 || ny > (N - 1) || nx > (M - 1)) continue;
            if (!adj[ny][nx]) continue;
            if (visited_for_shortest_path_using_bfs[ny][nx]) continue;

            visited_for_shortest_path_using_bfs[ny][nx] = visited_for_shortest_path_using_bfs[popped.first][popped.second] + 1;
            q.push(std::make_pair(ny, nx));
        }
    }

    printf("%d\n", visited_for_shortest_path_using_bfs[N-1 ][M-1]);

    return 0;
}