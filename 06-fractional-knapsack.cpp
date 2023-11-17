#include <iostream>
using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

struct Item
{
	int value;
	int weight;
};

int function(const void *a, const void *b)
{
	struct Item *itemA = (struct Item *) a;
	struct Item *itemB = (struct Item *) b;
	double ratioA = (double) itemA->value / itemA->weight;
	double ratioB = (double) itemB->value / itemB->weight;
	if (ratioA < ratioB)
		return 1;
	else if (ratioA > ratioB)
		return -1;
	else
		return 0;
}

double fractionalKnapsack(struct Item items[], int n, int capacity)
{
	qsort (items, n, sizeof (struct Item), function);
	double totalValue = 0.0;
	for (int i = 0; i < n; ++i)
    {
    	if (capacity == 0)
			break;
    	if (items[i].weight <= capacity)
		{
			totalValue += items[i].value;
			capacity -= items[i].weight;
		}
    	else
		{
	  		totalValue += ((double) items[i].value / items[i].weight) * capacity;
	  		break;
		}
    }
  	return totalValue;
}

int main()
{
	details();

	int n;
	printf ("Please enter the number of items required: ");
	scanf ("%d", &n);
	struct Item items[n];
	printf ("Please enter the value and weight for every item:\n");
	for (int i = 0; i < n; ++i)
	{
		scanf ("%d %d", &items[i].value, &items[i].weight);
	}
	int capacity;
	printf ("Please enter the max capacity: ");
	scanf ("%d", &capacity);
	double maxValue = fractionalKnapsack (items, n, capacity);
	printf ("The Maximum value= %.2lf\n", maxValue);
	return 0;
}
