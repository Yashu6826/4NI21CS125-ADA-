#include <iostream>
int queens[30];
int solutionCount = 0;
bool canPlace(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        if (queens[i] == col || std::abs(queens[i] - col) == std::abs(i - row))
        {
            return false;
        }
    }
    return true;
}
void printSolution(int n)
{
    solutionCount++;
    std::cout << "\n\nSolution #" << solutionCount << ":\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (queens[i] == j)
            {
                std::cout << "Q\t";
            }
            else
            {
                std::cout << "*\t";
            }
        }
        std::cout << "\n";
    }
}
void solveNQueens(int n)
{
    int k = 1;
    queens[k] = 0;
    while (k != 0)
    {
        queens[k]++;
        while (queens[k] <= n && !canPlace(k, queens[k]))
        {
            queens[k]++;
        }
        if (queens[k] <= n)
        {
            if (k == n)
            {
                printSolution(n);
            }
            else
            {
                k++;
                queens[k] = 0;
            }
        }
        else
        {
            k--;
        }
    }
}
int main()
{
    int n;
    std::cout << "Enter the number of Queens\n";
    std::cin >> n;
    solveNQueens(n);
    std::cout << "\nTotal solutions = " << solutionCount;
    return 0;
}