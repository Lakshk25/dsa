class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> ans;
        int i, j, k;
        i = j = k = 0;
        int aPrev, bPrev, cPrev;
        aPrev = bPrev = cPrev = INT_MIN;
        while (i < n1 && j < n2 && k < n3)
        {
            while (aPrev == A[i] && i < n1)
            {
                i++;
            }
            while (bPrev == B[j] && j < n2)
            {
                j++;
            }
            while (cPrev == C[k] && k < n3)
            {
                k++;
            }
            if (A[i] == B[j] && B[j] == C[k])
            {
                aPrev = A[i];
                bPrev = B[j];
                cPrev = C[k];
                ans.push_back(A[i]);
            }
            else if (A[i] < B[j])
            {
                aPrev = A[i];
                i++;
            }
            else if (B[j] < C[k])
            {
                bPrev = B[j];
                j++;
            }
            else
            {
                cPrev = C[k];
                k++;
            }
        }
        return ans;
    }
};