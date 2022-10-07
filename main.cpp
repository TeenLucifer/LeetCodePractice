#include "MultiQuestions.h"
#include "t-rex.h"//for test

int main()
{
    MultiQuestions *multiQuestions = new MultiQuestions();
    vector<vector<char>> board = {{'X','O','X','O','X','O'},
                                  {'O','X','O','X','O','X'},
                                  {'X','O','X','O','X','O'},
                                  {'O','X','O','X','O','X'}};
    multiQuestions->question130(board);
    return 0;
}
