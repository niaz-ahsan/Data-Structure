// A Graph produced with int nodes represented by adjacency list
// We're running Breadth First Traversal/Search there 

#include <iostream>
#include <vector>

class Graph {
public:
    Graph(int l) : _limit(l) {
        _lists = new std::vector<int>[_limit];
    };

    ~Graph() {
        //delete _lists;
    }

    void add_edge(int src, int des) {
        _lists[src].push_back(des);
    }

    bool BFS(int search_for) {
        bool found = false;
        for(int i=0; i<_limit; i++) {
            if(search_within_inner_list(search_for, _lists[i])) {
                found = true;
                break;
            }
        }
        return found;
    }

    void BFT(int start) {

    }
private:
    int _limit;
    std::vector<int> *_lists;
    
    bool search_within_inner_list(int val, std::vector<int> &list) {
        bool found = false;
        std::vector<int>::iterator it;
        for(it = list.begin(); it < list.end(); it++) {
            if(list[*it] == val) {
                found = true;
                break;
            }
        }
        return found;  
    }
};

int main() {
    Graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(2,0);
    g.add_edge(3,3);

    std::cout << g.BFS(5) << std::endl;
}