#include <iostream>
#include <vector>
using namespace std;

// This a non-greedy approach
int findMaxDeadline(vector<vector<int>> &jobs)
{
  if (jobs.size() == 0)
  {
    return 0;
  }

  int max = INT_MIN;

  for (int i = 0; i < jobs.size(); i++)
  {
    if (jobs[i][0] > max)
    {
      max = jobs[i][0];
    }
  }

  return max;
}

int findMaximumJobOutput(vector<vector<int>> &jobs)
{
  int result = 0;

  int maxDeadline = findMaxDeadline(jobs);

  vector<int> jobQueue(maxDeadline + 1, 0);

  for (int i = 0; i < jobs.size(); i++)
  {
    int jobIndex = jobs[i][0];
    int jobValue = jobs[i][1];

    if (jobQueue[jobIndex] == 0)
    {
      jobQueue[jobIndex] = jobValue;
    }
    else
    {
      for (int k = jobIndex; k > 0; k--)
      {
        if (jobQueue[k] < jobValue)
        {
          swap(jobQueue[k], jobValue);
        }
        else if (jobQueue[k] == 0)
        {
          jobQueue[k] = jobValue;
          break;
        }
      }
    }
  }

  for (int i = 0; i < jobQueue.size(); i++)
  {
    result += jobQueue[i];
  }
  return result;
}

int main()
{
  vector<vector<int>> jobs1 = {{1, 10}, {2, 40}, {1, 90}, {2, 30}};
  cout << findMaximumJobOutput(jobs1) << "\n";

  vector<vector<int>> jobs2 = {{2, 50}, {2, 60}, {3, 20}, {3, 30}};
  cout << findMaximumJobOutput(jobs2) << "\n";

  vector<vector<int>> jobs3 = {{2, 100}, {1, 50}, {2, 10}, {1, 20}, {3, 30}};
  cout << findMaximumJobOutput(jobs3) << "\n";

  return 0;
}