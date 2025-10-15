//          TOWER OF HANOI
#include <stdio.h>

void towersOfHanoi(int n, char fromTower, char toTower, char auxTower)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from %c tower to %c tower\n", fromTower, toTower);
        return;
    }
    towersOfHanoi(n - 1, fromTower, auxTower, toTower);
    printf("\nMove disk %d from %c tower to %c tower\n", n, fromTower, toTower);
    towersOfHanoi(n - 1, auxTower, toTower, fromTower);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towersOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
