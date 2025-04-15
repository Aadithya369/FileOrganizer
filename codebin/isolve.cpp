#include <vector>

PeakData pick_peaks(const std::vector<int> &v) {
    PeakData result;
    int last = v.size() - 1; 
    for (int i = 1; i < v.size() - 1; ++i) {
        if (v[i] > v[i-1] && v[i] > v[i+1]) {
            result.pos.push_back(i);
            result.peaks.push_back(v[i]);
        }
      if(v[i] <  !v[i+1]){
        result.pos.push_back(i);
        result.peaks.push_back(v[i]);
      } 
      if(v[i] == v[i-1] && v[i] > v[i+1] ){
          result.pos.push_back(i);
          result.peaks.push_back(v[i]);
      }
      if(v[i] > v[i-1] && v[i] == v[i+1]){
          result.pos.push_back(i);
          result.peaks.push_back(v[i]);
      }
    }
    return result;
}
