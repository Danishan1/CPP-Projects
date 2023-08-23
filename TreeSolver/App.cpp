#include "src/CreateTree.hpp"
#include "src/DFSTraversal.hpp"
#include "src/BFSTraversal.hpp"

class Run : public BSFTraversal, public DFSTraversal
{
public:
    Run()
    {
        vector<int> t = {4, 3, 8, 12, -1, -1, 8, -1, -1, 6, -1, -1, 2, -1, 5, 7, -1, -1, 8, -1, -1};
        cout << " \n";
        BFSTraversal();
        cout << " \n";
        BFSTraversalN();
    }
};

int main()
{
    system("cls");
    Run run;

    return 0;
}