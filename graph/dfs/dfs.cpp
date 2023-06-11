#include <iostream>
#include <stack>

#include "../common/graph.h"

bool visited[chelseafandev::algorithm::graph::CAPACITY];

void dfs(chelseafandev::algorithm::graph g, int vertex)
{
    for(auto& flag : visited)
    {
        flag = false;
    }

    std::stack<int> s;
    s.push(vertex);

    while (!s.empty())
    {
        int popped = s.top();
        s.pop();
        std::cout << popped << " ";
        visited[popped] = true;
        for (const auto v : g.neighbors(popped))
        {
            if (!visited[v])
            {
                s.push(v);
            }
        }
    }
    std::cout << std::endl;
}

int main()
{
    chelseafandev::algorithm::graph g1;
    g1.add_vertex(0);
    g1.add_vertex(1);
    g1.add_vertex(2);
    g1.add_vertex(3);
    g1.add_edge(0, 1);
    g1.add_edge(0, 2);
    g1.add_edge(1, 2);
    g1.add_edge(2, 0);
    g1.add_edge(2, 3);
    g1.add_edge(3, 3);

    std::cout << "Following is Depth First Traversal "
              << "(starting from vertex 1) \n";
    dfs(g1, 1);

    chelseafandev::algorithm::graph g2;
    g2.add_vertex(0);
    g2.add_vertex(1);
    g2.add_vertex(2);
    g2.add_vertex(3);
    g2.add_edge(0, 1);
    g2.add_edge(0, 2);
    g2.add_edge(1, 2);
    g2.add_edge(1, 3);
    g2.add_edge(2, 0);
    g2.add_edge(3, 3);

    std::cout << "Following is Depth First Traversal "
              << "(starting from vertex 2) \n";
    dfs(g2, 2);

    // binary tree
    chelseafandev::algorithm::graph g3;
    g3.add_vertex(0);
    g3.add_vertex(1);
    g3.add_vertex(2);
    g3.add_vertex(3);
    g3.add_vertex(4);
    g3.add_edge(0, 1);
    g3.add_edge(0, 2);
    g3.add_edge(1, 3);
    g3.add_edge(1, 4);
    
    std::cout << "Following is Depth First Traversal "
              << "(starting from vertex 0) \n";
    dfs(g3, 0);

    return 0;
}