// The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.

#include <iostream>
using namespace std;

void toh(int n, char src, char help, char dest)
{
    if (n == 0)
        return;
    // cout << "moving disk from " << src << " " << dest << endl;
    toh(n - 1, src, dest, help);
    cout << "moving disk from " << src << " to " << dest << endl;
    toh(n - 1, help, src, dest);
}

void hanoi(int n, char src, char helper, char dest)
{
    // base case
    if (n == 0)
        return;

    // rec case
    hanoi(n - 1, src, dest, helper);
    cout << "Shift disk " << n << " from " << src << " to " << dest << endl;
    hanoi(n - 1, helper, src, dest);
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    toh(n, 'a', 'b', 'c');
}