int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int count = 0;
    int row = -1;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        int low = 0;
        int high = m;
        count = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[i][mid] == 1)
            {
                count = m - mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            row = i;
        }
    }
    return row;
}