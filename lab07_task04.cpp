
#include <iostream>
#include <string>

using namespace std;

struct Player {
    string name;
    int runs;
    int matches;
};

int comparisons = 0;
int tieCount = 0;

void printPlayers(Player arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i].name<<"(Runs: "<<arr[i].runs<<", Matches: "<<arr[i].matches<<") ";
    }
    cout<<endl;
}

void merge(Player arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Player L[100], R[100];

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        comparisons++;

        if(L[i].runs == R[j].runs){
            tieCount++;

            if(L[i].matches <= R[j].matches){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
        }
        else if(L[i].runs > R[j].runs){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    cout<<"Join: ";
    printPlayers(arr + left, right - left + 1);
}

void mergeSort(Player arr[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = (left + right) / 2;

    cout<<"Cut:"<<endl;

    cout<<"Left Part: "<<endl;
    for(int i = left; i <= mid; i++){
        cout<<arr[i].name<<" ";
    }

    cout<<"Right Part: "<<endl;
    for(int i = mid + 1; i <= right; i++){
        cout<<arr[i].name<<" ";
    }

    cout<<endl;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main(){
    int N;

    cout<<"Enter number of players: ";
    cin>>N;

    if(N <= 0 || N > 100){
        cout<<"Invalid number of players!"<<endl;
        return 0;
    }

    Player players[100];

    for(int i = 0; i < N; i++){
        cout<<"\nEnter player name: ";
        cin>>players[i].name;

        cout<<"Enter total runs: ";
        cin>>players[i].runs;

        cout<<"Enter matches played: ";
        cin>>players[i].matches;
    }

    cout<<"MERGE SORT PROCESS"<<endl;

    mergeSort(players, 0, N - 1);

    cout<<"FINAL RANKING LIST"<<endl;

    printPlayers(players, N);

    cout<<"Total Comparisons: "<<comparisons<<endl;

    cout<<"Ties Decided Using Matches: "<<tieCount<<endl;

    return 0;
}
