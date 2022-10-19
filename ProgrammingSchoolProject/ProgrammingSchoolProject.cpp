// ProgrammingSchoolProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

// Maximum number of digits in output
#define MAX 500

int multiply(int x, int res[], int res_size);

// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
	int res[MAX];

	// Initialize result
	res[0] = 1;
	int res_size = 1;

	// Apply simple factorial formula n! = 1 * 2 * 3
	// * 4...*n
	for (int x = 2; x <= n; x++)
		res_size = multiply(x, res, res_size);
}
int multiply(int x, int res[], int res_size)
{
	int carry = 0; // Initialize carry

	// One by one multiply n with individual digits of res[]
	for (int i = 0; i < res_size; i++) {
		int prod = res[i] * x + carry;

		// Store last digit of 'prod' in res[]
		res[i] = prod % 10;

		// Put rest in carry
		carry = prod / 10;
	}

	// Put carry in res and increase result size
	while (carry) {
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}

#define N 2	 // Number of unknowns

// function to reduce matrix to r.e.f. Returns a value to
// indicate whether matrix is singular or not
int forwardElim(double mat[N][N + 1]);

// function to calculate the values of the unknowns
void backSub(double mat[N][N + 1]);

// function to get matrix content
void gaussianElimination(double mat[N][N + 1])
{
	/* reduction into r.e.f. */
	int singular_flag = forwardElim(mat);

	/* if matrix is singular */
	if (singular_flag != -1)
	{
		printf("Singular Matrix.\n");

		/* if the RHS of equation corresponding to
		zero row is 0, * system has infinitely
		many solutions, else inconsistent*/
		if (mat[singular_flag][N])
			printf("Inconsistent System.");
		else
			printf("May have infinitely many "
				"solutions.");

		return;
	}

	/* get solution to system and print it using
	backward substitution */
	backSub(mat);
}

// function for elementary operation of swapping two rows
void swap_row(double mat[N][N + 1], int i, int j)
{
	//printf("Swapped rows %d and %d\n", i, j);

	for (int k = 0; k <= N; k++)
	{
		double temp = mat[i][k];
		mat[i][k] = mat[j][k];
		mat[j][k] = temp;
	}
}

// function to print matrix content at any stage
void print(double mat[N][N + 1])
{
	for (int i = 0; i < N; i++, printf("\n"))
		for (int j = 0; j <= N; j++)
			printf("%lf ", mat[i][j]);

	printf("\n");
}

// function to reduce matrix to r.e.f.
int forwardElim(double mat[N][N + 1])
{
	for (int k = 0; k < N; k++)
	{
		// Initialize maximum value and index for pivot
		int i_max = k;
		int v_max = mat[i_max][k];

		/* find greater amplitude for pivot if any */
		for (int i = k + 1; i < N; i++)
			if (abs(mat[i][k]) > v_max)
				v_max = mat[i][k], i_max = i;

		/* if a principal diagonal element is zero,
		* it denotes that matrix is singular, and
		* will lead to a division-by-zero later. */
		if (!mat[k][i_max])
			return k; // Matrix is singular

		/* Swap the greatest value row with current row */
		if (i_max != k)
			swap_row(mat, k, i_max);


		for (int i = k + 1; i < N; i++)
		{
			/* factor f to set current row kth element to 0,
			* and subsequently remaining kth column to 0 */
			double f = mat[i][k] / mat[k][k];

			/* subtract fth multiple of corresponding kth
			row element*/
			for (int j = k + 1; j <= N; j++)
				mat[i][j] -= mat[k][j] * f;

			/* filling lower triangular matrix with zeros*/
			mat[i][k] = 0;
		}

		//print(mat);	 //for matrix state
	}
	//print(mat);		 //for matrix state
	return -1;
}

// function to calculate the values of the unknowns
void backSub(double mat[N][N + 1])
{
	double x[N]; // An array to store solution

	/* Start calculating from last equation up to the
	first */
	for (int i = N - 1; i >= 0; i--)
	{
		/* start with the RHS of the equation */
		x[i] = mat[i][N];

		/* Initialize j to i+1 since matrix is upper
		triangular*/
		for (int j = i + 1; j < N; j++)
		{
			/* subtract all the lhs values
			* except the coefficient of the variable
			* whose value is being calculated */
			x[i] -= mat[i][j] * x[j];
		}

		/* divide the RHS by the coefficient of the
		unknown being calculated */
		x[i] = x[i] / mat[i][i];
	}

}
int vectorsum() {
	int yaxis1 = 12;
	int xaxis1 = 21;
	int yaxis2 = 14;
	int xaxis2 = 123;
	int yaxisr = yaxis1 + yaxis2;
    int xaxisr=xaxis1+xaxis2;
	return 0;
}

int textwriter() {
    std::ofstream myfile;

    myfile.open("RickRolled.txt", std::ios_base::app);//std::ios_base::app append instead of overwrite
    myfile << "We're no strangers to love You know the rules and so do I (do I) A full commitment's what I'm thinking of You wouldn't get this from any other guy I just wanna tell you how I'm feeling Gotta make you understand Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you We've known each other for so long Your heart's been aching, but you're too shy to say it (say it) Inside, we both know what's been going on (going on) We know the game and we're gonna play it And if you ask me how I'm feeling Don't tell me you're too blind to see Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you We've known each other for so long Your heart's been aching, but you're too shy to say it (to say it) Inside, we both know what's been going on (going on) We know the game and we're gonna play it I just wanna tell you how I'm feeling Gotta make you understand Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you\n";
    return 0;
}

int factorialtt() {
	factorial(100);
	return 0;
}



int main() {
    // Start measuring time
    

    // do some stuff here
    for (int i = 0; i < 20; i++) {
        auto start = chrono::steady_clock::now();
 
        textwriter();

        auto end = chrono::steady_clock::now();
        ofstream RawData;
        RawData.open("RawData.txt", std::ios_base::app);
        RawData << "Elapsed time in nanoseconds for writing text #" << i+1 << " " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
    }

    for (int i = 0; i < 20; i++) {
        auto start = chrono::steady_clock::now();

        factorialtt();

        auto end = chrono::steady_clock::now();
        ofstream RawData;
        RawData.open("RawData.txt", std::ios_base::app);
        RawData << "Elapsed time in nanoseconds for calculating Factorial of 100 #"<< i+1 <<" " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
    }
	for (int i = 0; i < 20; i++) {
		double mat[N][N + 1] = { {3.0, 2.0,-4.0},
					{2.0, 3.0, 3.0},
		};
		auto start = chrono::steady_clock::now();

		gaussianElimination(mat);

		auto end = chrono::steady_clock::now();
		ofstream RawData;
		RawData.open("RawData.txt", std::ios_base::app);
		RawData << "Elapsed time in nanoseconds for calculating Matrix #" << i + 1 << " " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
	}
	for (int i = 0; i < 20; i++) {
		auto start = chrono::steady_clock::now();

		vectorsum();

		auto end = chrono::steady_clock::now();
		ofstream RawData;
		RawData.open("RawData.txt", std::ios_base::app);
		RawData << "Elapsed time in nanoseconds for calculating the sum of vectors #" << i + 1 << " " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
	}



   
    // Stop measuring time and calculate the elapsed time
  
    

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
