#include "MultiQuestions.h"
#include "t-rex.h"//for test

int main()
{
    MultiQuestions *multiQuestions = new MultiQuestions();
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    vector<vector<int>> isConnected = {{1, 1, 0},
                                       {1, 1, 0},
                                       {0, 0, 1}};
    multiQuestions->question547_BFS(isConnected);
    return 0;
}
