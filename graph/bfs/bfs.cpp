#include <iostream>
#include <queue>

#include "../common/graph.h"

bool visited[chelseafandev::algorithm::graph::CAPACITY];

void bfs(chelseafandev::algorithm::graph g, int vertex)
{
    for (auto& flag : visited)
    {
        flag = false;
    }

    std::queue<int> q;
    q.push(vertex);

    while(!q.empty())
    {
        auto popped = q.front();
        q.pop();
        std::cout << popped << " ";
        visited[popped] = true;
        
        for (const auto& v : g.neighbors(popped))
        {
            if (!visited[v])
            {
                q.push(v);
            }
        }
    }

    std::cout << std::endl;
}

int main()
{
    chelseafandev::algorithm::graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    std::cout << "Following is Breadth First Traversal " << "(starting from vertex 2) \n";
    bfs(g, 2);

    // binary tree
    chelseafandev::algorithm::graph g2;
    g2.add_vertex(0);
    g2.add_vertex(1);
    g2.add_vertex(2);
    g2.add_vertex(3);
    g2.add_vertex(4);
    g2.add_edge(0, 1);
    g2.add_edge(0, 2);
    g2.add_edge(1, 3);
    g2.add_edge(1, 4);
    
    std::cout << "Following is Depth First Traversal "
              << "(starting from vertex 0) \n";
    bfs(g2, 0);

    return 0;
}