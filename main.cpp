#include <bits/stdc++.h>
using namespace std;
class Screen {
    int row, size;
    char* seat;
    public:
        Screen (vector<string> vect) {
            row = stoi(vect[2]);
            size = stoi(vect[3]) * row;
            seat = new char[size];
            for (int i = 0; i < size; i++) {
                seat[i] = 'E';
            }
            for (int i = 4; i < vect.size(); i++) {
                seat[stoi(vect[i])-1] = 'A';
            }
            cout<<"Screen added."<<endl;
        }
        
        void vacant() {
            cout<<"Vacant seats are given below: \n"<<endl;
            for (int i=0; i<size; i++) {
                cout<<seat[i]<<" ";
                if ((i+1)%row == 0)
                    cout<<"\n";
            }
            cout<<"\n";
        }
        void book(int k) {
            int st = 0;
            for (int i=0; i<size; i++) {
                if (seat[i] == 'E') {
                    st++;
                    if (st == k) {
                        while (st != 0) {
                            seat[i--] = 'B';
                            st--;
                        }
                        cout<<"Seats booked."<<endl;
                        return;
                    }
                } else {
                    st = 0;
                }
            }
            cout<<"Not awailable."<<endl;
        }
};
vector<string> words(string str) { 
    string word = "";
    vector<string> st;
    for (auto x : str) { 
        if (x == ' ') { 
            st.push_back(word);
            word = ""; 
        } 
        else
           word = word + x; 
    }
    st.push_back(word);
    return st;
}
int main() {
	int n;
	map<string, Screen*> mp;
	vector<string> line;
	string str;
	getline (cin, str);
	n = stoi(str);
	for (int i=0; i<n; i++) {
	    getline (cin, str);
	    line = words(str);
	    if (line[0] == "add-screen")
	        mp[line[1]] = new Screen(line);
	    else if (line[0] == "vacant") {
	        mp[line[1]]->vacant();
	    }
	    else if (line[0] == "book-seat") {
	        mp[line[1]]->book(stoi(line[2]));
	    }
	}
	return 0;
}