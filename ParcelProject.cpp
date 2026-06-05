#include <iostream>
using namespace std;

int main()
{
    int n;
    double capacity;

    cout << "Enter Van Capacity: ";
    cin >> capacity;

    cout << "Enter Number of Parcels: ";
    cin >> n;

    string name[n];
    double weight[n], fee[n], ratio[n];

    // Input
    for(int i = 0; i < n; i++)
    {
        cout << "\nParcel " << i + 1 << " Name: ";
        cin >> name[i];

        cout << "Weight: ";
        cin >> weight[i];

        cout << "Fee: ";
        cin >> fee[i];

        ratio[i] = fee[i] / weight[i];
    }

    // Sort by ratio (descending)
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(ratio[j] < ratio[j + 1])
            {
                swap(ratio[j], ratio[j + 1]);
                swap(name[j], name[j + 1]);
                swap(weight[j], weight[j + 1]);
                swap(fee[j], fee[j + 1]);
            }
        }
    }

    double totalProfit = 0;
    double currentWeight = 0;

    cout << "\nSelected Parcels:\n";

    // Selection (NO FRACTION, ONLY FULL PARCEL OR SKIP)
    for(int i = 0; i < n; i++)
    {
        if(currentWeight + weight[i] <= capacity)
        {
            currentWeight += weight[i];
            totalProfit += fee[i];

            cout << name[i] << " Selected (Full)\n";
        }
        else
        {
            cout << name[i] << " Skipped (Cannot fit fully)\n";
        }
    }

    cout << "\nTotal Weight = " << currentWeight << endl;
    cout << "Total Profit = " << totalProfit << endl;

    return 0;
}


