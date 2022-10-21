vector<int> factors(int n) {
  vector<int> f;
  for (int x = 1; x * x <= n; x++) {
    if(n % x == 0) {
      f.push_back(x);
      if(n / x != x)
        f.push_back(n / x);
    }
  }
  return f;
}