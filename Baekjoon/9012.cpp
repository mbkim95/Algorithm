#include <iostream>
#include <stack>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
   string str;
   stack<char> st;
   cin >> str;

   bool find = true;
   for(char c : str){
     if(c == '(') st.push('(');
     else{
       if(st.empty()) {
         find = false;
         break;
       }
       st.pop();
     }
   } 
   if(!st.empty() || !find) cout << "NO\n";
   else cout << "YES\n";
  }
  return 0;
}
