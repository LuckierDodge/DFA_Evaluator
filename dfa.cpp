#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


int main() {
	//Read from File

	string buffer1;
	string buffer2;
	cin >> buffer1 >> buffer2;
	int nstates = stoi(buffer1, nullptr);
	int naccepting = stoi(buffer2, nullptr);
	
	buffer1 = "";
	buffer2 = "";

	int accepting[naccepting];

	for (int i = 0; i < naccepting; i++) {
		cin >> buffer1;
		accepting[i] = stoi(buffer1, nullptr);
	}

	buffer1 = "";
	int transitions[nstates][2];

	for (int j = 0; j < nstates; j++) {
		cin >> buffer1 >> buffer2;
		transitions[j][0] = stoi(buffer1, nullptr);
		transitions[j][1] = stoi(buffer2, nullptr);
	}

	buffer1 = "";
	int nwords;
	cin >> buffer1;
	nwords = stoi(buffer1, nullptr);

	string words[nwords];

	for (int k = 0; k < nwords; k++) {
		cin >> words[k];
	}


	// Print Table
	cout << "    | a b" << endl;
	cout << "----+------" << endl;

	for (int i = 0; i < nstates; i++) {
		bool accepts = false;

		for (int j = 0; j < naccepting; j++)
			accepts = (accepting[j] == i ? true : accepts);
		
		cout << (accepts ? "* " : "  ") << i << " | " << transitions[i][0] << " " << transitions[i][1] << endl;
	}

	// Process Words
	for (int w = 0; w < nwords; w++) {
		string word = words[w];
		int state = 0;
		for ( string::iterator it=word.begin(); it != word.end(); ++it) {
			if (*it == 'a')
				state = transitions[state][0];
			else
				state = transitions[state][1];
		}

		bool accepts = false;
		for (int a = 0; a < naccepting; a++)
			accepts = (accepting[a] == state ? true: accepts);
		cout << word << (accepts ? " accepted" : " rejected") << endl;
	}
}
