#include "MultiQuestions.h"

int main()
{
    MultiQuestions* multiQuestions = new MultiQuestions();
    vector<int> nums = {6, 5, 9, 6, 3, 5, 1, 10, 4, 1, 4, 3, 9, 9, 3, 3};
    int k = 9;
    int res = multiQuestions->question698(nums, k);
    int tmp = (1 << 16) - 1;
    return 0;
}
