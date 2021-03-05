#include <bits/stdc++.h> 

using namespace std; 

vector<string> stringToVector(char delimiter, string line) { 
    vector <string> tokens; 
    
    stringstream check1(line); 
      
    string intermediate; 
      
    // Tokenizing w.r.t. space ' ' 
    while(getline(check1, intermediate, delimiter)) 
    { 
        tokens.push_back(intermediate); 
    } 
      
    return tokens;
} 