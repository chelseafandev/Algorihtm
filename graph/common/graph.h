#include <set>

namespace chelseafandev
{
    namespace algorithm
    {
        class graph
        {
        public:
            static const int CAPACITY = 100;

            graph()
            {
                // init
                for (int i = 0; i < CAPACITY; i++)
                {
                    labels_[i] = -1;
                }

                for (int i = 0; i < CAPACITY; i++)
                {
                    for (int j = 0; j < CAPACITY; j++)
                    {
                        edges_[i][j] = false;
                    }
                }

                size_ = 0;
            }

            int size() const
            {
                return size_;
            }

            void add_vertex(int val)
            {
                if (size_ < CAPACITY)
                {
                    int new_vertex_index = size_;
                    size_++;

                    // set new edge
                    for (int i = 0; i < size_; i++)
                    {
                        edges_[new_vertex_index][i] = false;
                        edges_[i][new_vertex_index] = false;
                    }

                    // set new vertex label
                    labels_[new_vertex_index] = val;
                }
            }

            void add_edge(int src, int dst)
            {
                if (src < 0 || src >= size_)
                {
                    return;
                }

                if (dst < 0 || dst >= size_)
                {
                    return;
                }

                edges_[src][dst] = true;
            }

            std::set<int> neighbors(int vertex)
            {
                std::set<int> result;

                for (int i = 0; i < size_; i++)
                {
                    if (edges_[vertex][i])
                    {
                        result.insert(i);
                    }
                }

                return result;
            }

        private:
            bool edges_[CAPACITY][CAPACITY]; // adjacency matrix를 통해서 그래프 정보를 표현함
            int labels_[CAPACITY]; // vertex의 label 정보
            int size_; // 현재 그래프 내에 존재하는 vertex의 개수
        };
    }
}