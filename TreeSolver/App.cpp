#include "src/Traversal.hpp"
#include "src/General.hpp"
#include <conio.h>

class Run : public Traversal, public General
{
};

class Main
{
    int treeCount = 0;
    vector<Run> run;

public:
    Main();
};

Main::Main()
{
    if (treeCount == 0)
    {
        cout << "You haven't created tree yet. Please Create a tree\n";
        run.push_back(Run());
        treeCount++;
        cout << "Added Succesfully.\n\nNow add tree : " << treeCount + 1 << "\n";
        run.push_back(Run());
        treeCount++;
        cout << "Added Succesfully.\n\nNow add Tree : " << treeCount + 1 << "\n";
        run.push_back(Run());
        treeCount++;
        cout << "\n\nTree Added Successfully. Enter any key to move further,  Enter : ";
        getch();
    }
    int op, optionFlag = 21;

    while (1)
    {
    repeat:
        system("cls");
        cout << "\nYou haven " << treeCount << " Tree. Select a appropreate Operation\n\n";
        cout << "Enter 1 : Count Nodes\n";
        cout << "Enter 2 : Min & Max Value\n";
        cout << "Enter 3 : DFS Traversal - PreOrder\n";
        cout << "Enter 4 : DFS Traversal - InOrder\n";
        cout << "Enter 5 : DFS Traversal - PostOrder\n";
        cout << "Enter 6 : Converse DFS Traversal - PreOrder\n";
        cout << "Enter 7 : Converse DFS Traversal - InOrder\n";
        cout << "Enter 8 : Converse DFS Traversal - PostOrder\n";
        cout << "Enter 9 : BFS Traversal - In one line\n";
        cout << "Enter 10 : BFS Traversal - Level wise\n";
        cout << "Enter 11 : Boundry Traversal - Clockwise\n";
        cout << "Enter 12 : Boundry Traversal - Anti Clockwise\n";
        cout << "Enter 13 : Virtical Traversal\n";
        cout << "Enter 14 : Height\n";
        cout << "Enter 15 : Diameter\n";
        cout << "Enter 16 : Left View\n";
        cout << "Enter 17 : Right View\n";
        cout << "Enter 18 : Top View\n";
        cout << "Enter 19 : Bottom View\n";
        cout << "Enter 20 : All Operation\n";
        cout << "Enter 21 : Exit\n";

        cout << "\nEnter your selection (1 to " << optionFlag << " ) : ";
        cin >> op;
        if (op < 1 || op > optionFlag)
        {
            cout << "\nERROR : You Must Enter between 1 to " << optionFlag << ".";
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            goto repeat;
        }

        int treeNo, countFlag = 1;
        system("cls");
        cout << "\nYou select " << op << " to perform ";

        // if (treeCount == 1)
        // {
        //     system("cls");
        //     cout << "\nYou select " << op << " to perform ";
        // }
        // else if (treeCount > 1)
        // {
        // WrongTreeNo:
        //     system("cls");
        //     cout << "\nYou select " << op << " to perform ";
        //     cout << "As you have " << treeCount << " on which tree you want to perfrom Opeation.";
        //     cin >> treeNo;
        //     if (treeNo < 1 && treeNo > treeCount + 1)
        //     {
        //         cout << "Tree No. must be greater than 1 and less than " << treeCount + 1 << endl;
        //         goto WrongTreeNo;
        //     }
        // }

        switch (op)
        {
        case 1:
            cout << "Count Nodes\n";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                cout << "No of Nodes : " << i.count();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 2:
            cout << "Min & Max Value \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                cout << "Minimun Element :- " << i.miniEle() << " , Maximum Element :- " << i.maxEle();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 3:
            cout << "DFS Traversal - PreOrder\n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.dfsPre();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 4:
            cout << "DFS Traversal - InOrder \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.dfsIn();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 5:
            cout << "DFS Traversal - PostOrder \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.dfsPost();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 6:
            cout << "Converse DFS Traversal - PreOrder \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.conDFSPre();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 7:
            cout << "Converse DFS Traversal - InOrder \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.conDFSIn();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 8:
            cout << "Converse DFS Traversal - PostOrder \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.conDFSPost();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 9:
            cout << "BFS Traversal - In one line \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.BFS();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 10:
            cout << "BFS Traversal - Level wise \n ";
            for (auto i : run)
            {
                cout << "\n\nTree " << countFlag++ << " : \n";
                i.BFSn();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 11:
            cout << "Boundry Traversal - Clockwise \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.BoundryClock();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 12:
            cout << "Boundry Traversal - Anti Clockwise \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.BoundryAntiClock();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 13:
            cout << "Virtical Traversal \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.VirticalTraversal();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 14:
            cout << "Height\n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << ", ";
                auto a = i.height();
                cout << "Height : " << a;
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 15:
            cout << "Diameter \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << ", ";
                auto a = i.daiHeight();
                cout << " Diameter : " << a.second;
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 16:
            cout << "Left View \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.leftView();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 17:
            cout << "Right View \n ";
            for (auto i : run)
            {

                cout << "\nTree " << countFlag++ << " : ";
                i.rightView();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 18:
            cout << "Top View \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.topView();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 19:
            cout << "Bottom View \n ";
            for (auto i : run)
            {
                cout << "\nTree " << countFlag++ << " : ";
                i.bottomView();
            }
            cout << "\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 20:
            cout << "All Opearations \n ";
            for (auto i : run)
            {
                cout << "\n\n\nTree " << countFlag++ << " \n ";
                cout << "\nNo of Nodes : " << i.count();
                cout << "\nMinimun Element : " << i.miniEle() << " , Maximum Element : " << i.maxEle();
                cout << "\nDFS Traversal - PreOrder : ";
                i.dfsPre();
                cout << "\nDFS Traversal - InOrder : ";
                i.dfsIn();
                cout << "\nDFS Traversal - PostOrder : ";
                i.dfsPost();
                cout << "\nConverse DFS Traversal - PreOrder : ";
                i.conDFSPre();
                cout << "\nConverse DFS Traversal - InOrder : ";
                i.conDFSIn();
                cout << "\nConverse DFS Traversal - PostOrder : ";
                i.conDFSPost();
                cout << "\nBFS Traversal - In One Line : ";
                i.BFS();
                cout << "\nBFS Traversal - Level wise \n";
                i.BFSn();
                cout << "\nBoundry Traversal - Clockwise : ";
                i.BoundryClock();
                cout << "\nBoundry Traversal - Anti Clockwise : ";
                i.BoundryAntiClock();
                cout << "\nVirtical Traversal : ";
                i.VirticalTraversal();
                cout << "\nHeight : " << i.height();
                cout << "\nDiameter : " << i.daiHeight().second;
                cout << "\nLeft View : ";
                i.leftView();
                cout << "\nRight View : ";
                i.rightView();
                cout << "\nTop View : ";
                i.topView();
                cout << "\nBottom View : ";
                i.bottomView();
            }
            cout << "\n\n Enter any key to move further, Enter : ";
            getch();
            break;
        case 21:
            cout << "Exit \n \n Thanks for using our Service ~ Danishan\n\n\n";
            return;

            break;
        }
    }
}

int main()
{

    system("cls");
    Main m;

    return 0;
}