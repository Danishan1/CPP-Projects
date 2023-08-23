#include "src/CreateTree.hpp"
#include "src/Traversal.hpp"

class Run : public Traversal
{
public:
};

int main()
{
    system("cls");
    Run run;
    Run run2;
    run.dfsIn();
    run2.dfsPost();

    return 0;
}