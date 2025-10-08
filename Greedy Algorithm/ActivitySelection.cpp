#include <iostream>
#include <vector>
using namespace std;

void sortActivities(vector<vector<int>> &activities)
{
  for (int i = 0; i < activities.size(); i++)
  {
    int ind = i;

    for (int j = i + 1; j < activities.size(); j++)
    {
      if (activities[ind][1] > activities[j][1])
      {

        ind = j;
      }
    }
    swap(activities[ind], activities[i]);
  }
}

int getActivities(vector<vector<int>> &activities)
{
  sortActivities(activities);

  vector<vector<int>> selectedActivities;
  selectedActivities.push_back(activities[0]);

  for (int i = 1; i < activities.size(); i++)
  {
    if (activities[i][0] > selectedActivities.back()[1])
    {
      selectedActivities.push_back(activities[i]);
    }
  }
  return selectedActivities.size();
}

int main()
{
  vector<vector<int>> activities = {{2, 3}, {1, 4}, {5, 8}, {6, 10}};
  vector<vector<int>> activities1 = {{3, 8}, {2, 4}, {1, 2}, {10, 11}};

  cout << getActivities(activities) << "\n";
  cout << getActivities(activities1);

  return 0;
}