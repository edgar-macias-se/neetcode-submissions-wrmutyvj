class Solution {
public:
    string minWindow(string s, string t) {
        
        //si t es mayor que s no puede ser un substring
        if(t.size() > s.size()){
            return "";
        }

        unordered_map<char,int> tCount;
        //variable para controlar los caracteres que vayan apareciendo
        unordered_map<char,int> sControl;

        //contamos la aparicion de cada caracter en t
        for(char &c : t){
            tCount[c]++;
        }

        //need and have
        int need = tCount.size(), have = 0;
        pair<int, int> res = {-1, -1};
        //Utilizaremos sliding window para obtener la longitud 
        // del string que contiene t
        int L = 0, minWindow = INT_MAX;
        for(int R = 0; R < s.length(); R++){
            char c = s[R];
            sControl[c]++;

            if(tCount.count(c) && sControl[c] == tCount[c]){
                have++;
            }

            while (have == need) {
                if ((R - L + 1) < minWindow) {
                    minWindow = R - L + 1;
                    res = {L, R};
                }

                sControl[s[L]]--;
                if (tCount.count(s[L]) && sControl[s[L]] < tCount[s[L]]) {
                    have--;
                }
                L++;
            }
        }

        return minWindow == INT_MAX ? "" : s.substr(res.first, minWindow);
    }
};
