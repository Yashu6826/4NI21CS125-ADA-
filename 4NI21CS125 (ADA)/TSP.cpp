#include <iostream>
int graph[10][10], visited[10], numCities, totalCost = 0;
int getLeast(int c);
void inputData()
{
    int i, j;
    std::cout << "Enter Number of Cities: ";
    std::cin >> numCities;
    std::cout << "\nEnter Cost Matrix:\n";
    for (i = 0; i < numCities; i++)
    {
        std::cout << "\nEnter Elements of Row #" << i + 1 << ":\n";
        for (j = 0; j < numCities; j++)
            std::cin >> graph[i][j];
        visited[i] = 0;
    }
    std::cout << "\n\nThe Cost List is:\n\n";
    for (i = 0; i < numCities; i++)
    {
        std::cout << "\n\n";
        for (j = 0; j < numCities; j++)
            std::cout
                << "\t" << graph[i][j];
    }
}
void findMinCost(int city)
{
    int i, nextCity;
    visited[city] = 1;
    std::cout << city + 1 << " -> ";
    nextCity = getLeast(city);
    if (nextCity == 999)
    {
        nextCity = 0;
        std::cout << nextCity + 1;
        totalCost += graph[city][nextCity];
        return;
    }
    findMinCost(nextCity);
}
int getLeast(int c)
{
    int i, nearestCity = 999;
    int minCost = 999, kmin;
    for (i = 0; i < numCities; i++)
    {
        if ((graph[c][i] != 0) && (visited[i] == 0))
            if (graph[c][i] < minCost)
            {
                minCost = graph[i][0] + graph[c][i];
                kmin = graph[c][i];
                nearestCity = i;
            }
    }
    if (minCost != 999)
        totalCost += kmin;
    return nearestCity;
}
void displayResult()
{
    std::cout << "\n\nMinimum Cost: " << totalCost;
}
int main()
{
    inputData();
    std::cout << "\n\nThe Path is:\n\n";
    findMinCost(0);
    displayResult();
    return 0;
}