#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// This function will give I2 index where the minimum delta j is found✅✅✅.
int index_of_minimum_delta_j(vector<float> delta_j)
{
    int min = delta_j[0], i;
    for (i = 1; i < delta_j.size(); i++)
    {
        if (delta_j[i] < min)
            min = delta_j[i];
    }
    for (i = 0; i < delta_j.size(); i++)
    {
        if (delta_j[i] == min)
            break;
    }
    return i;
}

// Function to return the index position of minimum, minimum ratio✅✅✅.
int index_of_minimum_ratio(vector<float> mr)
{
    // as there are only two element in minimum ratio so i would use only if else to return
    // the index containing the minimum of minimum ratio.
    int min = mr[0], i;
    for (i = 1; i < mr.size(); i++)
    {
        if ((mr[i] < min) && (mr[i]>0))
            min = mr[i];
    }
    for (i = 0; i < mr.size(); i++)
    {
        if (mr[i] == min)
            break;
    }
    return i;
}

// Function to calculate Zj✅✅✅.
vector<float> calculate_Z_j(vector<float> cb, vector<float> table, int n, int equation)
{
    // As from the table we know the first element of table starts from index 1
    // and the next element of x1 occurs after 5 iteration so cb's first element at
    // index 0 is multiplied with i and the next cb element is multiplied with i+5.
    int new_n = n + 1;
    vector<float> zj;
    for (int i = 1; i < new_n; i++)
    {
        float value = 0, k = i;
        // We will take the value and push it in the zj and in order to traverse the right element
        // We are taking k to multiply the correct element in the table and which starts from i
        // That means that after every iteration i will change and the value of k will also change and
        // After every iteration of the below loop k will add up the value of number of element in a row present
        // That is n here.
        for (int j = 0; j < equation; j++, k += new_n)
        {
            value = value + (cb[j] * table[k]);
        }
        zj.push_back(value);
    }
    return zj;
}

// Function to calculate delta j✅✅✅.
vector<float> calculate_delta_j(vector<float> zj, vector<float> cj, int n)
{
    vector<float> delta_j;
    for (int i = 0; i < n; i++)
    {
        delta_j.push_back(zj[i] - cj[i]);
    }
    return delta_j;
}

// Function to calculate minimum ratio✅✅✅.
vector<float> calculate_minimum_ratio(vector<float> delta_j, vector<float> table, int equation, int n)
{
    // As minimum ratio has only two element so i am pushing them without actual formulation.
    vector<float> mr;
    int index2 = index_of_minimum_delta_j(delta_j) + 1;

    int new_n = n + 1;
    // As we know here index 2 will give the corresponding index of the minimum column from the table
    // and its next element will be after n elements so we are iterating k and index2 with addition of n
    // and we also know that the XB value starts from index 0 in the given table so we are taking k = 0
    // and we are iterating it with n.
    int k = 0;
    for (int i = 0; i < equation; i++, k += new_n, index2 += new_n)
    {
        mr.push_back(table[k] / table[index2]);
    }
    return mr;
}

// Function to transform the whole table✅✅✅.
vector<float> transform_table(vector<float> table, vector<float> mr, vector<float> delta_j, int equation, int n)
{
    int index_2 = index_of_minimum_delta_j(delta_j) + 1;
    int index_1 = index_of_minimum_ratio(mr);
    int new_n = n + 1, i;
    vector<float> req_row;

    float element = table[index_1 * new_n + index_2];

    // I am dividing the all the values of the min ratio min index row by the selected element.
    for (i = (index_1 * new_n); i < ((index_1 * new_n) + new_n); i++)
    {
        table[i] = table[i] / element;
        req_row.push_back(table[i]);
    }

    for (i = 0; i < equation; i++)
    {
        if (i == index_1)
            continue;
        else
        {
            float mag = table[i * new_n + index_2];
            int k = 0; // K is taken to iterate the value of the required row.
            for (int j = i * new_n; j < ((i * new_n) + new_n); j++)
            {
                table[j] = (table[j] - (mag * req_row[k++]));
            }
        }
    }

    return table;
}

// Function to change the cb value in the table✅✅✅.
vector<float> transform_cb(vector<float> delta_j, vector<float> mr, vector<float> cb, vector<float> cj)
{
    // Here in cb i just have to change the value of the element leaving with that of element entering.
    // Entering element will be the one in cj with index which will have the same index of the minimum delta j.
    // Leaving element from cb will be the one at index equal to the minimum of the minimum ratio.
    int index_1 = index_of_minimum_ratio(mr);
    int index_2 = index_of_minimum_delta_j(delta_j);
    cb[index_1] = cj[index_2];
    return cb;
}

// Function to show final result✅✅✅.
void show_result(vector<float> cb, vector<float> table, int equation, int n)
{
    int k = 0, new_n = n + 1;
    float result = 0;
    for (int i = 0; i < equation; i++, k += new_n)
    {
        result = result + (table[k] * cb[i]);
    }
    cout << "The optimum vlaue of Z = " << result << endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
}

// Function to check whether it is optimal or not✅✅✅ -> 🤔🤔🤔.
bool is_optimal(vector<float> delta_j)
{
    for (int i = 0; i < delta_j.size(); i++)
    {
        if (delta_j[i] < 0)
            return false; // as soon as it will find that there is a delta j that is smaller than 0
    }                     // it will give that the table is not optimal.
    return true;
}

/*
// To check the unbounded condition✅✅✅.
bool is_unbounded(vector<float> delta_j, vector<float> table, int equation, int n)
{
    int index_2 = index_of_minimum_delta_j(delta_j) + 1, flag = 0, new_n = n+1;
    for (int i = 1; i < n; i++)
    {
        int k = i;
        for (int j = 0; j < equation; j++, k+=new_n)
        {
            if(table[k]<0)
                return true;
        }
        
    }
    return false;
}
*/

// Function to display table ✅✅✅.
void display_table(vector<float> cj, vector<float> cb, vector<float> zj, vector<float> delta_j, vector<float> table, vector<float> mr, int n, int equation)
{
    int i;
    cout << "Values of CJ are :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << cj[i] << "     ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    int take = n + 1; // actually in a row i have n+1 element including xb.
    cout << "Values of the table are :" << endl;
    for (i = 0; i < equation; i++)
    {
        for (int j = i * take; j < i * take + take; j++)
        {
            cout << table[j] <<setw(15);
        }
        cout << mr[i];
        cout << endl;
        cout << endl;
    }

    cout << "Values of Z_j are:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << zj[i] << "     ";
    }
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Values of delta_j are:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << delta_j[i] << "     ";
    }
    cout << endl;
    cout << endl;
    cout<<"***********************************************************************************"<<endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

int main()
{
    vector<float> table, delta_j, zj, min_ratio, cj, cb;

    int var, equations, i;
    cout << "Enter number of variable" << endl;
    cin >> var;

    // Number of equation = number of slag variable.
    cout << "Enter the number of equations:" << endl;
    cin >> equations;

    int no_of_element_in_a_row = var + equations; // In the above functions i have added 1 separately.

    int inp; // For taking various inputs.
    cout << "Enter the coefficiet of the objective function" << endl;
    for (i = 0; i < var; i++)
    {
        cin >> inp;
        cj.push_back(inp); // Pushing the coefficient of the obj. function x1, x2 etc..
    }

    // Pushing the coefficient for the slag variables in cj.
    for (i = 0; i < equations; i++)
    {
        cj.push_back(0);
    }

    // For pushing the elements in the table in a sequential order.
    int j = 0;
    for (i = 0; i < equations; i++)
    {
        for (j = 0; j < var + 1; j++)
        {
            if (j == 0)
            {
                cout << "Enter the value of the RHS of the equation:" << endl;
                cin >> inp;
                table.push_back(inp);
            }
            else
            {
                cout << "Enter the coefficient of one of the variable of subjective equation" << endl;
                cin >> inp;
                table.push_back(inp);
            }
        }
        for (; j <= no_of_element_in_a_row; j++)
        {
            table.push_back(0);
        }
    }

    // as slack variables will be haveing some 1's in the table so this loop works for that.
    int temp = var + 1;
    for (i = 0; i < equations; i++)
    {
        table[i * (no_of_element_in_a_row + 1) + temp] = 1;
        temp++;
    }

    // For pushing the element in CB .
    for (i = 0; i < equations; i++)
    {
        cb.push_back(0);
    }

    zj = calculate_Z_j(cb, table, no_of_element_in_a_row, equations);

    delta_j = calculate_delta_j(zj, cj, no_of_element_in_a_row);

    min_ratio = calculate_minimum_ratio(delta_j, table, equations, no_of_element_in_a_row);

    // Display first table.
    display_table(cj, cb, zj, delta_j, table, min_ratio, no_of_element_in_a_row, equations);

    /*    Initial **************************************************  Table Preparation  */

    while (!is_optimal(delta_j))
    {
        // if(is_unbounded(delta_j, table, equations, no_of_element_in_a_row))
        // {
        //     cout<<"The solution is unbounded "<<endl;
        //     return 0;
        // }
        cout << "Index of minimum ratio = " << index_of_minimum_ratio(min_ratio) << endl;
        cout << "Index of minimum delta_j = " << index_of_minimum_delta_j(delta_j) << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        table = transform_table(table, min_ratio, delta_j, equations, no_of_element_in_a_row);
        cb = transform_cb(delta_j, min_ratio, cb, cj);
        zj = calculate_Z_j(cb, table, no_of_element_in_a_row, equations);
        delta_j = calculate_delta_j(zj, cj, no_of_element_in_a_row);
        min_ratio = calculate_minimum_ratio(delta_j, table, equations, no_of_element_in_a_row);
        display_table(cj, cb, zj, delta_j, table, min_ratio, no_of_element_in_a_row, equations);
    }

    // table = transform_table(table, min_ratio, delta_j, equations, no_of_element_in_a_row);
    // display_table(cj, cb, zj, delta_j, table, min_ratio, no_of_element_in_a_row, equations);

    
    show_result(cb, table, equations, no_of_element_in_a_row);

    return 0;
}