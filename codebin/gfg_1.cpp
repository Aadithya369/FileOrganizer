#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    double maxAverage(vector<int>& arr) {
        float max = 0;
        float avg = 0;
        for(int i = 1;i<arr.size();i++){
            avg = (arr[i] + arr[i-1]) / 2 ;
            if(avg < max){
                max = avg; 
            }
        }
        return avg + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int v;
        vector<int> arr;
        while (ss >> v)
            arr.push_back(v);
        Solution ob;
        double ans = ob.maxAverage(arr);
        cout << fixed << setprecision(5) << ans << endl;
    }
}

