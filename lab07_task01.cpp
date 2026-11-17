
#include <iostream>
#include <string>

using namespace std;

struct Patient {
    string name;
    int urgency;
    int arrivalTime;
};

int comparisons = 0;

void printPatients(Patient arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i].name<<"(Urgency: "<<arr[i].urgency<<", Arrival: "<<arr[i].arrivalTime<<") ";
    }
    cout<<endl;
}

void merge(Patient arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Patient L[100], R[100];

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        comparisons++;

        if(L[i].urgency > R[j].urgency ||(L[i].urgency == R[j].urgency &&L[i].arrivalTime <= R[j].arrivalTime)){
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

    cout<<endl<<"Join: ";
    printPatients(arr + left, right - left + 1);
}

void mergeSort(Patient arr[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = (left + right) / 2;

    cout<<endl<<"Cut:";

    cout<<"\nLeft Part: ";
    for(int i = left; i <= mid; i++){
        cout<<arr[i].name<<" ";
    }

    cout<<"\nRight Part: ";
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

    cout<<"Enter number of patients: ";
    cin>>N;

    if(N <= 0 || N > 100){
        cout<<"Invalid number of patients!"<<endl;
        return 0;
    }

    Patient patients[100];

    for(int i = 0; i < N; i++){
        cout<<"\nEnter patient name: ";
        cin>>patients[i].name;

        cout<<"Enter urgency score (1-100): ";
        cin>>patients[i].urgency;

        cout<<"Enter arrival time: ";
        cin>>patients[i].arrivalTime;
    }

    cout<<"MERGE SORT"<<endl;

    mergeSort(patients, 0, N - 1);

    cout<<"FINAL PATIENT LIST\n";

    printPatients(patients, N);

    cout<<endl;
    cout<<"Total Comparisons: "<<comparisons<<endl;

    cout<<"First Patient to See Doctor: "<<patients[0].name<<endl;

    return 0;
}
