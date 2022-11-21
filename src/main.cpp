#include "MultiQuestions.h"

int main()
{
    MultiQuestions* multiQuestions = new MultiQuestions();
    vector<vector<int>> gridObstacle = {{1, 0}};
    int res = multiQuestions->question63(gridObstacle);

    return 0;
}
