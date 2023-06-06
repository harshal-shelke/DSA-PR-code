//B5

#include <iostream>
#include <vector>
using namespace std;
class Tree
{
public:
    string value;
    vector<Tree *> child;
    Tree(string val)
    {
        value = val;
    }
};
void insertchap(Tree *head)
{
    string chapname;
    cout << "Enter the chapter name - " << endl;
    cin >> chapname;
    cout << endl;
    Tree *newchap = new Tree(chapname);
    int subsect;
    cout << "Enter no of subsection - " << endl;
    cin >> subsect;
    cout << endl;
    for (int i = 0; i < subsect; i++)
    {
        string subname;
        cout << "Enter the subsection name - ";
        cin >> subname;
        cout << endl;
        Tree *subsection = new Tree(subname);
        newchap->child.push_back(subsection);
    }
    head->child.push_back(newchap);
}
void display(Tree *head, string temp)
{
    if (head)
    {
        cout << temp + head->value << endl;
        temp += "  ";
        for (int i = 0; i < head->child.size(); i++)
        {
            display(head->child[i], temp);
        }
    }
}
int main()
{
    Tree *head = new Tree("--INDEX--");
    int chapters;
    cout << "Enter no of chapters:" << endl;
    cin >> chapters;
    for (int i = 0; i < chapters; i++)
    {
        insertchap(head);
    }
    string temp = "";
    display(head, temp);
    return 0;
}