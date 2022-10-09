#include "MultiQuestions.h"
#include "t-rex.h"//for test

int main()
{
    MultiQuestions *multiQuestions = new MultiQuestions();
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};

    multiQuestions->question207_BFS(2, prerequisites);
    return 0;
}
