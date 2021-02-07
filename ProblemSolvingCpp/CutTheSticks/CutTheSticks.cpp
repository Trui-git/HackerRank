#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {
    vector<int> result;
    result.push_back(arr.size());

    for(;;){
        vector<int> temp;
        for (int i=0; i<arr.size();i++){
            arr[i]--;
            if(arr[i] == 0)
                temp.push_back(i);   
                     
        }
        for (int i=temp.size()-1; i>=0;i--){
            arr.erase (arr.begin()+temp[i]);
        }
        if(arr.size() > 0)
            result.push_back(arr.size());
        if(arr.size() <= 1)
            break;
    }

    result.erase( unique( result.begin(), result.end() ), result.end() );
    for (int i: result)
        cout << i << " "; 
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = cutTheSticks(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
/*
6
5 4 4 2 2 8
6 4 2 1

6
1 1 1 1 1 1
*/